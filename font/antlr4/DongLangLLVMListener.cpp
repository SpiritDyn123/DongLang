#include "DongLangLLVMListener.h"
#include "font/ast/DongLangExprAST.h"
#include "font/ast/DongLangExprAST.h"
#include "font/ast/DongLangExpressionAST.h"
#include "font/ast/DongLangProgAST.h"
#include "font/ast/DongLangFunctionDefAST.h"
#include "font/ast/DongLangVarAST.h"
#include "font/ast/DongLangPrimaryAST.h"
#include "font/ast/DongLangArrayAST.h"
#include "font/ast/DongLangCondAST.h"
#include <memory>
#include "font/antlr4/DongLangLLVMExprTypeListener.h"
#include "DongLangLLVMVarListener.h"

using namespace std;
using namespace antlr4;

void DongLangLLVMErrorListener::syntaxError(Recognizer* recognizer, 
	Token* offendingSymbol, 
	size_t line,
	size_t charPositionInLine, const std::string& msg, 
	std::exception_ptr e) {
	lC.emitError("syntaxError line:" + std::to_string(line) + 
		",offset:" + std::to_string(charPositionInLine) + " :" + msg);
}


DongLangBaseAST* DongLangLLVMListener::GetRootAST() {
	return rootAST;
}

DongLangLLVMListener::DongLangLLVMListener(DongLangLLVMExprTypeListener* etListener):
	etListener(etListener) {
	rootAST = NULL;
	mExprTypes.clear();
	mAsts.clear();
}

void DongLangLLVMListener::enterProg(DongLangParser::ProgContext* ctx) {
	if (rootAST) {
		delete rootAST;
	}

	rootAST = NULL;
	mExprTypes.clear();
	mAsts.clear();
}

void DongLangLLVMListener::exitProg(DongLangParser::ProgContext* ctx) {
	vector<DongLangBaseAST*> lineAsts;
	lineAsts.clear();
	for (auto child : ctx->children) {
		if (dynamic_cast<DongLangParser::Global_var_expressionContext*>(child) ||
			dynamic_cast<DongLangParser::Function_defContext*>(child)) {
			auto ast = mAsts[dynamic_cast<antlr4::ParserRuleContext*>(child)];
			if(ast) lineAsts.push_back(ast);

			//cout << "exitProg:" << child->getText() << endl;
		}
	}

	rootAST = new DongLangProgAST(lineAsts);
}

void DongLangLLVMListener::exitFunction_def(DongLangParser::Function_defContext* ctx) {
	//argnames 
	vector<DongLangFunctionDefAST::ArgInfo> args;
	args.clear();
	for (auto argCtx : ctx->farg_list()->farg()) {
		DongLangTypeInfo* argType = DongLangLLVMVarListener::analyseDLTypeInfo(argCtx->type_type());
		args.push_back(DongLangFunctionDefAST::ArgInfo(argCtx->IDENTIFIER()->getText(), argCtx, argType));
	}

	//body
	vector<DongLangBaseAST*> body;
	body.clear();
	if (ctx->function_body()) {
		for (auto child : ctx->function_body()->statement()) {
			body.push_back(mAsts[child]);
		}
	}
	
	bool isVarArg = ctx->farg_list()->f_varargs();
	mAsts[ctx] = new DongLangFunctionDefAST(ctx, ctx->IDENTIFIER()->getText(), args, isVarArg,
		ctx->function_body(), body);
}


void DongLangLLVMListener::enterStatement(DongLangParser::StatementContext* ctx) {
		
}

void DongLangLLVMListener::exitStatement(DongLangParser::StatementContext* ctx) { 
	antlr4::ParserRuleContext* child = ctx->var_expression();
	if (child) {
		mAsts[ctx] = mAsts[child];
		return;
	}
	
	child = ctx->ret_expression();
	if (child) {
		mAsts[ctx] = mAsts[child];
		return;
	}

	child = ctx->if_expression();
	if (child) {
		mAsts[ctx] = mAsts[child];
		return;
	}

	child = ctx->for_expression();
	if (child) {
		mAsts[ctx] = mAsts[child];
		return;
	}
}

void DongLangLLVMListener::exitCond_statement(DongLangParser::Cond_statementContext* ctx) {
	if (ctx->statement()) {
		mAsts[ctx] = mAsts[ctx->statement()];
		return;
	}

	antlr4::ParserRuleContext* forCtx = NULL;
	for (auto pCtx = ctx->parent; pCtx; pCtx = pCtx->parent) {
		if (auto fCtx = dynamic_cast<DongLangParser::For_expressionContext*>(pCtx)) {
			forCtx = fCtx;
			break;
		}
	}

	if (ctx->BREAK()) {
		mAsts[ctx] = new DongLangBreakAST(forCtx);
	}

	if (ctx->CONTINUE()) {
		mAsts[ctx] = new DongLangContinueAST(forCtx);
	}
}

void DongLangLLVMListener::enterRet_expression(DongLangParser::Ret_expressionContext* ctx) { }

void DongLangLLVMListener::exitRet_expression(DongLangParser::Ret_expressionContext* ctx) { 
	if (ctx->expression()) {
		mAsts[ctx] = new DongLangRetExprAST(mAsts[ctx->expression()], 
			etListener->ExprType(ctx->expression()), 
			etListener->ExprDefaultType(ctx->expression()));
	}
	else {
		mAsts[ctx] = new DongLangRetExprAST();
	}
}

void DongLangLLVMListener::enterExpression(DongLangParser::ExpressionContext* ctx) {}

void DongLangLLVMListener::exitExpression(DongLangParser::ExpressionContext* ctx) { 
	if (ctx->primary()) {
		mAsts[ctx] = mAsts[ctx->primary()];
		return;
	}

	string opr = "";
	if (ctx->COND_NOT()) {
		opr = ctx->COND_NOT()->getText();
	} else if (ctx->NOT()) {
		opr = ctx->NOT()->getText();
	}
	else if(ctx->opr) {
		opr = ctx->opr->getText();
	}
	else {
		opr = "?:";
	}

	DongLangBaseAST* rhs = NULL;
	DongLangBaseAST* exths = NULL;
	if (ctx->expression().size() > 1) {
		rhs = mAsts[ctx->expression(1)];
		if (ctx->threeOpr) {
			exths = mAsts[ctx->expression(2)];
		}
		/*cout << "expression:" << ctx->getText() <<
			",exprtypeInfo:" << etListener->ExprType(ctx)->String() <<
			",defaultTypeInfo:" << etListener->ExprDefaultType(ctx)->String() <<
			",left:" << etListener->ExprType(ctx->expression(0))->String() << "==" <<  etListener->ExprDefaultType(ctx->expression(0))->String() <<
			",right:" << etListener->ExprType(ctx->expression(1))->String() << "==" <<  etListener->ExprDefaultType(ctx->expression(1))->String() <<
			endl;*/
	}

	mAsts[ctx] = new DongLangExpressionAST(opr,
		mAsts[ctx->expression(0)],
		rhs,
		exths,
		etListener->ExprType(ctx),
		//etListener->ExprDefaultType(ctx),
		etListener->ExprDefaultType(ctx));
}

void DongLangLLVMListener::enterGlobal_var_expression(DongLangParser::Global_var_expressionContext* ctx)  { }
void DongLangLLVMListener::exitGlobal_var_expression(DongLangParser::Global_var_expressionContext* ctx)  {
	antlr4::ParserRuleContext* child = ctx->var_declares();
	if(child) mAsts[ctx] = mAsts[child];
}

void DongLangLLVMListener::enterIf_expression(DongLangParser::If_expressionContext* ctx) {
}

void DongLangLLVMListener::exitVar_expression(DongLangParser::Var_expressionContext* ctx) {
	antlr4::ParserRuleContext* child = ctx->var_declares();

	if (!child) {
		child = ctx->assigns();
	}
	
	mAsts[ctx] = mAsts[child];
}

#define GEN_COND_AST(condExprCtx, condName) DongLangBaseAST* initAst = NULL; \
	DongLangBaseAST* condAst = NULL; \
	auto condCtx = condExprCtx->condName(); \
	if (condCtx->var_expression()) { \
		initAst = mAsts[condCtx->var_expression()]; \
	} \
	 \
	if (condCtx->expression()) { \
		condAst = mAsts[condCtx->expression()]; \
	} \
	 \
	vector<DongLangBaseAST*> statements; \
	statements.clear(); \
	for (auto smCtx : condExprCtx->cond_statement()) { \
		statements.push_back(mAsts[smCtx]);  \
	} 


#define GEN_IF_COND_AST(condExprCtx) GEN_COND_AST(condExprCtx, if_cond) \
	ifExprItems.push_back(new DongLangIfExprAST::DongLangIfExprItem(initAst, condAst, statements));

void DongLangLLVMListener::exitIf_expression(DongLangParser::If_expressionContext* ctx)  { 
	vector<DongLangIfExprAST::DongLangIfExprItem*> ifExprItems;
	ifExprItems.clear();
	{
		GEN_IF_COND_AST(ctx)
	}

	for (auto elifCtx : ctx->elif_expr()) {
		GEN_IF_COND_AST(elifCtx)
	}

	if (ctx->else_expr()) {
		vector<DongLangBaseAST*> statements; 
		statements.clear(); 
		for (auto smCtx : ctx->else_expr()->cond_statement()) {
			statements.push_back(mAsts[smCtx]);  
		}
		ifExprItems.push_back(new DongLangIfExprAST::DongLangIfExprItem(NULL, NULL, statements));
	}

	mAsts[ctx] = new DongLangIfExprAST(ifExprItems);
}

void DongLangLLVMListener::enterFor_expression(DongLangParser::For_expressionContext* ctx) { 
}

void DongLangLLVMListener::exitFor_expression(DongLangParser::For_expressionContext* ctx) {
	GEN_COND_AST(ctx, for_cond)

	DongLangBaseAST* iterAst = NULL;
	if (condCtx->assigns()) {
		iterAst = mAsts[condCtx->assigns()];
	} 

	auto forAst = new DongLangForExprAST(initAst, condAst, iterAst, statements);
	DongLangBaseAST::CurScope(ctx)->AddForInfo(forAst);
	mAsts[ctx] = forAst;
}

void DongLangLLVMListener::enterParan_expr(DongLangParser::Paran_exprContext* ctx) { }
void DongLangLLVMListener::exitParan_expr(DongLangParser::Paran_exprContext* ctx) {}

void DongLangLLVMListener::enterCall_expr(DongLangParser::Call_exprContext* ctx) {}
void DongLangLLVMListener::exitCall_expr(DongLangParser::Call_exprContext* ctx) {
	vector<DongLangBaseAST*> args;
	vector<DongLangTypeInfo*> argDefaultTypes;
	args.clear();
	if (ctx->expr_list()) {
		for (auto argCtx : ctx->expr_list()->expression()) {
			args.push_back(mAsts[argCtx]);
			argDefaultTypes.push_back(etListener->ExprDefaultType(argCtx));
		}
	}

	string fnName = ctx->IDENTIFIER()->getText();
	auto funcSymbol = etListener->CallFuncDLSymbol(ctx);

	bool isGlobal = false;
	for (auto pCtx = ctx->parent; pCtx != NULL; pCtx = pCtx->parent) {
		if (dynamic_cast<DongLangParser::Global_var_expressionContext*>(pCtx)) { //全局变量
			isGlobal = true;
			break;
		}
		else if (dynamic_cast<DongLangParser::Function_defContext*>(pCtx)) { //函数内
			break;
		}
	}

	mAsts[ctx] = new DongLangCallExprAST(funcSymbol, args, argDefaultTypes, isGlobal);
}

void DongLangLLVMListener::enterExpr_list(DongLangParser::Expr_listContext* ctx) { }
void DongLangLLVMListener::exitExpr_list(DongLangParser::Expr_listContext* ctx) { 
	
}

void DongLangLLVMListener::enterValue_primary(DongLangParser::Value_primaryContext* ctx) { }
void DongLangLLVMListener::exitValue_primary(DongLangParser::Value_primaryContext* ctx) { 
	auto exprCtx = (DongLangParser::ExpressionContext*)ctx->parent->parent;
	antlr4::ParserRuleContext* child = ctx->num_primary();
	if (child) {
		string numStr = ctx->num_primary()->NIL() ? "0" : child->getText();
		mAsts[ctx] = new DongLangNumPrimaryAST(child->getText(), etListener->ExprType(exprCtx, true));
		return;
	}

	child = ctx->bool_primary();
	if (child) {
		mAsts[ctx] = new DongLangBoolPrimaryAST(child->getText(), etListener->ExprType(exprCtx, true));
		return;
	}

	child = ctx->str_primary();
	if (child) {
		mAsts[ctx] = new DongLangStrPrimaryAST(((DongLangParser::Str_primaryContext*)child)->STRING_LITERAL()->getText(),
			etListener->ExprType(exprCtx, true));
		return;
	}
}

void DongLangLLVMListener::enterPrimary(DongLangParser::PrimaryContext* ctx) { }
void DongLangLLVMListener::exitPrimary(DongLangParser::PrimaryContext* ctx) { 
	antlr4::ParserRuleContext* child = ctx->value_primary();
	if(!child && ctx->id_primary()){ //id_primary
		child = ctx->id_primary();
	}

	if (child) {
		mAsts[ctx] = mAsts[child];
	}
}

void DongLangLLVMListener::enterId_primary(DongLangParser::Id_primaryContext* ctx) {}
void DongLangLLVMListener::exitId_primary(DongLangParser::Id_primaryContext* ctx) {

	DongLangBaseAST* idAst = NULL;
	string id = "";
	DongLangParser::ExpressionContext* paranExprCtx = NULL;
	if (ctx->call_expr()) {
		idAst = mAsts[ctx->call_expr()];
	}
	else if (ctx->paran_expr()) {
		paranExprCtx = ctx->paran_expr()->expression();
		idAst = mAsts[paranExprCtx];
	}
	else if (ctx->IDENTIFIER()) {
		id = ctx->IDENTIFIER()->getText();
	}

	vector<DongLangBaseAST*> arrAsts;
	arrAsts.clear();
	for (auto arrIndexCtx : ctx->array_index()) {
		arrAsts.push_back(mAsts[arrIndexCtx->expression()]);
	}

	DongLangTypeInfo* exprTypeInfo = NULL;
	DongLangTypeInfo* exprDefaultTypeInfo = NULL;
	if (auto exprCtx = dynamic_cast<DongLangParser::ExpressionContext*>(ctx->parent->parent)) { //expression
		 exprTypeInfo = etListener->ExprType(exprCtx);
		 exprDefaultTypeInfo = etListener->ExprDefaultType(exprCtx);
	}
	else { //assign
		auto assignCtx = dynamic_cast<DongLangParser::AssignContext*>(ctx->parent);
		exprTypeInfo = etListener->AssignType(assignCtx);
		exprDefaultTypeInfo = exprTypeInfo;
		if (assignCtx->expression() && assignCtx->opr || assignCtx->INCREMENT() || assignCtx->DECREMENT()) { // 存在运算符
			auto assignTypeInfo = exprTypeInfo->isPoint() ?
				exprTypeInfo : (
					assignCtx->opr ? 
					etListener->ExprType(assignCtx->expression()) : 
					DongLangTypeInfo::typeCheckTrans(exprDefaultTypeInfo, DongLangTypeInfo::IntType, assignCtx->INCREMENT() ? "+" : "-"));
			mAsts[assignCtx] =
				new DongLangIdPrimaryAST(ctx, id, idAst, arrAsts, assignTypeInfo, exprDefaultTypeInfo);
		}
	}

	/*if (paranExprCtx) {
		cout << "id_primary:" << ctx->getText()
			<< ",tInfo:" << (exprTypeInfo ? exprTypeInfo->String() : "NULL")
			<< ",defaultTInfo:" << (exprDefaultTypeInfo ? exprDefaultTypeInfo->String() : "NULL")
			<< ",idTInfo:" << (idTypeInfo ? idTypeInfo->String() : "NULL")
			//<< ",paran_tinfo:" << (etListener->ExprType(paranExprCtx) ? etListener->ExprType(paranExprCtx)->String():"NULL")
			//<< ",paran_defaultTinfo:" << (etListener->ExprDefaultType(paranExprCtx) ? etListener->ExprDefaultType(paranExprCtx)->String():"NULL")
			<< endl;
	}*/
	mAsts[ctx] = new DongLangIdPrimaryAST(ctx, id, idAst, arrAsts, exprTypeInfo, exprDefaultTypeInfo);

}

void DongLangLLVMListener::enterVar_value(DongLangParser::Var_valueContext* ctx) { }
void DongLangLLVMListener::exitVar_value(DongLangParser::Var_valueContext* ctx) { 
	antlr4::ParserRuleContext* child = ctx->expression();
	if (child != NULL) {
		mAsts[ctx] = mAsts[child];
		return;
	}

	child = ctx->var_arr_value();
	if (child != NULL) {
		mAsts[ctx] = mAsts[child];
		return;
	}
}

#define PRINT_VAR_TYPE 0

void DongLangLLVMListener::enterVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) { }
void DongLangLLVMListener::exitVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) {
	vector<DongLangBaseAST*> arrAsts;
	arrAsts.clear();
	DongLangTypeInfo* typeInfo = etListener->VarArrValueType(ctx);

	DongLangTypeInfo* varExprTypeInfo = NULL;
	for (auto pCtx = ctx->parent; pCtx != NULL && !dynamic_cast<DongLangParser::Var_arr_valueContext*>(pCtx); pCtx = pCtx->parent) {
		if (auto varExprCtx = dynamic_cast<DongLangParser::Var_expressionContext*>(ctx->parent)) {
			varExprTypeInfo = etListener->VarExprTypes(varExprCtx);
			break;
		}
	}

#if PRINT_VAR_TYPE
	if (varExprTypeInfo) {
		cout << "exitVar_arr_value:" << ctx->getText() << ",varExprTypeInfo:" << varExprTypeInfo->String() << endl;
	}
#endif


	string id = "";
	if (auto varCtx = dynamic_cast<DongLangParser::VarContext*>(ctx->parent->parent)) {
		id = varCtx->IDENTIFIER()->getText();
	} 

	DLSymbol* idSymbol = NULL;
	if (id != "") {
		idSymbol = DongLangBaseAST::FindSymbol(ctx, id);
	}

	bool isPrimary = true;
	if (ctx->expr_list()) {
		for (auto exprCtx : ctx->expr_list()->expression()) {
			if (isPrimary && (!exprCtx->primary() || !exprCtx->primary()->value_primary())) {
				isPrimary = false;
			}

			arrAsts.push_back(mAsts[exprCtx]);
		}
	}
	else {
		for (auto arrCtx : ctx->var_arr_value()) {
			DongLangArrayAST* arrAst = (DongLangArrayAST*)mAsts[arrCtx];
			isPrimary = isPrimary ? arrAst->primary() : isPrimary;
			arrAsts.push_back(arrAst);
		}
	}


	mAsts[ctx] = new DongLangArrayAST(idSymbol, isPrimary, arrAsts, typeInfo, varExprTypeInfo);
}

void DongLangLLVMListener::enterVar(DongLangParser::VarContext* ctx) {
}

void DongLangLLVMListener::exitVar(DongLangParser::VarContext* ctx) {
}

void DongLangLLVMListener::enterVars(DongLangParser::VarsContext* ctx) {
}


void DongLangLLVMListener::exitVars(DongLangParser::VarsContext* ctx) {
	bool isDeclare = dynamic_cast<DongLangParser::Var_declaresContext*>(ctx->parent) != NULL;
	if (isDeclare) {
		return;
	}

	DongLangTypeInfo* varExprTypeInfo = NULL;
	if (auto pCtx = dynamic_cast<DongLangParser::Var_expressionContext*>(ctx->parent)) {
		varExprTypeInfo = etListener->VarExprTypes(pCtx);
	}

#if PRINT_VAR_TYPE
	if (varExprTypeInfo) {
		cout << "exitVars:" << ctx->getText() << ",varExprTypeInfo:" << varExprTypeInfo->String() << endl;
	}
#endif

	vector<DongLangBaseAST*> vars;
	vars.clear();
	for (auto child : ctx->var()) {
		auto valueCtx = child->var_value();
		auto value = valueCtx ? mAsts[valueCtx] : NULL;
		bool isPrimary = valueCtx &&
			valueCtx->expression() &&
			valueCtx->expression()->primary() &&
			valueCtx->expression()->primary()->value_primary();
		vars.push_back(new DongLangVarAST(ctx,
			child->IDENTIFIER()->getText(),
			value,
			varExprTypeInfo,
			isPrimary));
	}

	mAsts[ctx] = new DongLangVarsAST(vars);
}


void DongLangLLVMListener::enterVar_declares(DongLangParser::Var_declaresContext* ctx) {
}

void DongLangLLVMListener::exitVar_declares(DongLangParser::Var_declaresContext* ctx) {
	bool isGlobal = dynamic_cast<DongLangParser::Global_var_expressionContext *>(ctx->parent) != NULL;


	DongLangTypeInfo* varTypeInfo = DongLangLLVMVarListener::analyseDLTypeInfo(ctx->type_type());


	vector<DongLangBaseAST*> vars;
	vars.clear();

	DongLangTypeInfo* varExprTypeInfo = NULL;
	if (auto pCtx = dynamic_cast<DongLangParser::Var_expressionContext*>(ctx->parent)) {
		varExprTypeInfo = etListener->VarExprTypes(pCtx);
	}

#if PRINT_VAR_TYPE
	if (varExprTypeInfo) {
		cout << "exitVars_declare:" << ctx->getText() << ",varExprTypeInfo:" << varExprTypeInfo->String() << endl;
	}
#endif

	for (auto child : ctx->vars()->var()) {
		auto valueCtx = child->var_value();
		auto valueAst = valueCtx ? mAsts[valueCtx] : NULL;
		bool isPrimary = valueCtx &&
			valueCtx->expression() &&
			valueCtx->expression()->primary() &&
			valueCtx->expression()->primary()->value_primary();
		vars.push_back(new DongLangVarDeclareAST(ctx,
			varTypeInfo,
			child->IDENTIFIER()->getText(),
			valueAst,
			isGlobal, varExprTypeInfo, isPrimary));

		//cout <<"exitVar_declares "<< ctx->type_type()->getText() << ":" << child->IDENTIFIER()->getText() << endl;
	}

	mAsts[ctx] = new DongLangVarsAST(vars);
}

void DongLangLLVMListener::enterAssign(DongLangParser::AssignContext* ctx) {

}

void DongLangLLVMListener::exitAssign(DongLangParser::AssignContext* ctx) {

}

void DongLangLLVMListener::enterAssigns(DongLangParser::AssignsContext* ctx) {

}

void DongLangLLVMListener::exitAssigns(DongLangParser::AssignsContext* ctx) {
	DongLangTypeInfo* varExprTypeInfo = NULL;
	if (auto pCtx = dynamic_cast<DongLangParser::Var_expressionContext*>(ctx->parent)) {
		varExprTypeInfo = etListener->VarExprTypes(pCtx);
	}

#if PRINT_VAR_TYPE
	if (varExprTypeInfo) {
		cout << "exitAssigns:" << ctx->getText() << ",varExprTypeInfo:" << varExprTypeInfo->String() << endl;
	}
#endif

	vector<DongLangAssignAST*> assigns;
	assigns.clear();
	for (auto child : ctx->assign()) {
		auto idAst = mAsts[child->id_primary()];
		auto exprCtx = child->expression();
		DongLangBaseAST* valueAst = exprCtx ? mAsts[exprCtx] : NULL;

		bool isPrimary = exprCtx &&
			exprCtx->primary() &&
			exprCtx->primary()->value_primary();

		if (child->opr || child->INCREMENT() || child->DECREMENT()) {
			string opr = child->opr ? child->opr->getText() : (child->INCREMENT() ? "+" : "-");
			auto cTypeInfo = etListener->AssignType(child);
			DongLangTypeInfo* defaultCTypeInfo = NULL;
			if (child->opr) {
				defaultCTypeInfo = cTypeInfo->isPoint() ? cTypeInfo : etListener->ExprType(exprCtx);
			}
			else {
				defaultCTypeInfo = cTypeInfo->isPoint() ? cTypeInfo : DongLangTypeInfo::typeCheckTrans(cTypeInfo,
					DongLangTypeInfo::IntType, opr);
				valueAst = new DongLangNumPrimaryAST("1", cTypeInfo->isPoint() ? DongLangTypeInfo::IntType :
					DongLangTypeInfo::typeCheckTrans(cTypeInfo, DongLangTypeInfo::IntType, opr));
			}

			valueAst = new DongLangExpressionAST(opr,
				mAsts[child],
				valueAst,
				NULL,
				cTypeInfo,
				defaultCTypeInfo);

			isPrimary = false;
		}
		
		assigns.push_back(new DongLangAssignAST(idAst, valueAst, varExprTypeInfo, isPrimary));
	}

	mAsts[ctx] = new DongLangVectorAST<DongLangAssignAST>(assigns);
}