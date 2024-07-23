#include "DongLangLLVMVarListener.h"
#include "font/ast/DongLangExprAST.h"
#include "font/ast/DongLangExprAST.h"
#include "font/ast/DongLangExpressionAST.h"
#include "font/ast/DongLangProgAST.h"
#include "font/ast/DongLangFunctionDefAST.h"
#include "font/ast/DongLangVarAST.h"
#include "font/ast/DongLangPrimaryAST.h"
#include <memory>
#include "DongLangLLVMListener.h"

using namespace std;
//=========================DongLangLLVMVarListener==============================
void DongLangLLVMVarListener::enterProg(DongLangParser::ProgContext * ctx) {
	DongLangBaseAST::AddScope(ctx, true, "ROOT");
}

void DongLangLLVMVarListener::enterFunction_def(DongLangParser::Function_defContext * ctx) {
	DongLangBaseAST::AddScope(ctx, false, ctx->IDENTIFIER()->getText());
}

void DongLangLLVMVarListener::exitFunction_def(DongLangParser::Function_defContext* ctx) {//fnName 
	string fnName = ctx->IDENTIFIER()->getText();

	//args
	vector<DongLangTypeInfo*> argTypes;
	argTypes.clear();

	auto curScope = DongLangBaseAST::CurScope(ctx);

	for (auto argCtx : ctx->farg_list()->farg()) {
		int arrIndex = 0;
		for (auto stypeChild : argCtx->type_type()->children) {
			if (auto arrChild = dynamic_cast<DongLangParser::Array_typeContext*>(stypeChild)) {
				if (arrIndex > 0 && (!arrChild->NUMBER() || std::stoi(arrChild->NUMBER()->getText()) <= 0)) {
					DongLangBaseAST::llvmCtx->emitError("function's return or arg array must has correct length:" + ctx->getText());
					return;
				}

				arrIndex++;
			}
		}

		ANALYSE_POINT_ARRAY(argCtx);

		auto argId = argCtx->IDENTIFIER()->getText();
		DongLangTypeInfo* spType = new DongLangTypeInfo(stype->primary_type()->getText(), pas);
		auto varSb = curScope->FindSymbol(argId);
		if (varSb && varSb->getScope() == curScope) {
			DongLangBaseAST::llvmCtx->emitError("repeated var declare:" + argId);
			return;
		}
		
		curScope->AddSymbol(argId, SYMBOL_ID(argCtx), VarSLSymbol::Create(argId, spType, NULL));
		argTypes.push_back(spType);
	}

	//return type
	auto retTypeCtx = ctx->type_type_void();
	string retPriType;
	vector<PointOrArray> retPas;
	retPas.clear();
	if (retTypeCtx->type_type() != NULL) {
		int arrIndex = 0;
		for (auto stypeChild : retTypeCtx->type_type()->children) {
			if (auto arrChild = dynamic_cast<DongLangParser::Array_typeContext*>(stypeChild)) {
				if (arrIndex > 0 && (!arrChild->NUMBER() || std::stoi(arrChild->NUMBER()->getText()) <= 0)) {
					DongLangBaseAST::llvmCtx->emitError("function's return or arg array must has correct length:" + ctx->getText());
					return;
				}

				arrIndex++;
			}
		}

		retPriType = retTypeCtx->type_type()->primary_type()->getText();
		ANALYSE_POINT_ARRAY(retTypeCtx);


		retPas = pas;
	}
	else {
		retPriType = retTypeCtx->VOID()->getText();
	}

	
	//var arg
	bool isVarArg = ctx->farg_list()->f_varargs();

	auto funcScope = DongLangBaseAST::CurScope((DongLangBaseAST::antlr4Ctx)ctx->parent);
	bool externC = ctx->externC();
	if (auto funcSymbol = funcScope->FindFuncSymbol(fnName, argTypes, isVarArg)) {
		DongLangBaseAST::llvmCtx->emitError("repeated function declare:" + funcSymbol->ID());
		return;
	}

	DongLangTypeInfo* spRetType = new DongLangTypeInfo(retPriType, retPas);
	argTypes.insert(argTypes.begin(), spRetType);

	funcScope->AddSymbol(fnName, SYMBOL_ID(ctx), FuncSLSymbol::Create(fnName, argTypes, NULL, externC, isVarArg));
}

void DongLangLLVMVarListener::exitVar_declares(DongLangParser::Var_declaresContext* ctx) {
	bool isGlobal = dynamic_cast<DongLangParser::Global_var_expressionContext*>(ctx->parent) != NULL;
	vector<DongLangBaseAST*> vars;
	vars.clear();

	ANALYSE_POINT_ARRAY(ctx);
	DongLangTypeInfo* spType = new DongLangTypeInfo(stype->primary_type()->getText(), pas);
	auto curScope = DongLangBaseAST::CurScope(ctx);

	for (auto child : ctx->vars()->var()) {
		auto id = child->IDENTIFIER()->getText();
		auto varSb = curScope->FindSymbol(id);
		if (varSb && varSb->getScope() == curScope) {
			DongLangBaseAST::llvmCtx->emitError("repeated var declare:" + id);
			return;
		}

		curScope->AddSymbol(id, SYMBOL_ID(child), VarSLSymbol::Create(id, spType, NULL));
	}
}

void DongLangLLVMVarListener::enterIf_cond(DongLangParser::If_condContext* ctx) {
	/*
	  if(expression)
	  if(var_expression)
	  if(var_expression;expression)
	  if(;)// like for(;;) true forever
	*/
	//基本格式检查
	//cout << "var_expression:" << (ctx->var_expression() ? ctx->var_expression()->getText() : "NULL") << endl;
	if (ctx->getText() == "" || 
		ctx->var_expression() && ctx->expression() && !ctx->COND_SPE() ||
		ctx->var_expression() && !ctx->expression() && ctx->COND_SPE() ||
		!ctx->var_expression() && ctx->COND_SPE()) {
		lC.emitError("if cond format err:" + ctx->getText());
		return;
	}

	//var 定义和expression条件检查
	auto varExprCtx = ctx->var_expression();
	if (varExprCtx) {
		DongLangParser::VarsContext* varsCtx = NULL;
		if (varExprCtx->var_declares()) {
			varsCtx = varExprCtx->var_declares()->vars();
			//var 定义必须赋值
			for (auto varCtx : varsCtx->var()) {
				if (!varCtx->var_value()) {
					lC.emitError("if cond var declaration must have an initializer:" + ctx->getText());
					return;
				}
			}
		}

		//var 的数量> 1,数组情况下，必须有expr
		auto assignCtx = varExprCtx->assigns();
		if ((varsCtx && (varsCtx->var().size() > 1)
			|| assignCtx && (assignCtx->assign().size() > 1))
			&& !ctx->expression()) {
			lC.emitError("if cond var > 1 must has cond expression:" + ctx->getText());
			return;
		}
	}

}

void DongLangLLVMVarListener::enterIf_expression(DongLangParser::If_expressionContext* ctx) {
	DongLangBaseAST::AddScope(ctx);
}

void DongLangLLVMVarListener::enterElif_expr(DongLangParser::Elif_exprContext* ctx) {
	DongLangBaseAST::AddScope(ctx);
}

void DongLangLLVMVarListener::enterElse_expr(DongLangParser::Else_exprContext* ctx) {
	DongLangBaseAST::AddScope(ctx);
}

void DongLangLLVMVarListener::enterFor_expression(DongLangParser::For_expressionContext* ctx) {
	DongLangBaseAST::AddScope(ctx);
}

void DongLangLLVMVarListener::enterCond_statement(DongLangParser::Cond_statementContext* ctx) {
	if (ctx->statement()) {
		return;
	}
	//break  continue
	for (auto pCtx = ctx->parent; pCtx; pCtx = pCtx->parent) {
		if (dynamic_cast<DongLangParser::For_expressionContext*>(pCtx)) {
			return;
		}
	}

	lC.emitError("break or continue must in for expression");
}
