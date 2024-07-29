#include "DongLangLLVMVarListener.h"
#include "font/ast/DongLangExprAST.h"
#include "font/ast/DongLangExprAST.h"
#include "font/ast/DongLangExpressionAST.h"
#include "font/ast/DongLangProgAST.h"
#include "font/ast/DongLangFunctionDefAST.h"
#include "font/ast/DongLangVarAST.h"
#include "font/ast/DongLangPrimaryAST.h"
#include <memory>

using namespace std;

DongLangTypeInfo* DongLangLLVMVarListener::analyseDLTypeInfo(DongLangParser::Type_typeContext* typeTypeCtx) {
	DongLangTypeInfo ttypeInfo;
	if (typeTypeCtx->IDENTIFIER()) {
		auto curScope = DongLangBaseAST::CurScope(typeTypeCtx);
		auto ttName = typeTypeCtx->IDENTIFIER()->getText();
		auto symbol = curScope->FindSymbol(ttName);
		if (!symbol || symbol->type() != DLSymbol::symbolType_Type) {
			DongLangBaseAST::llvmCtx->emitError(typeTypeCtx->getText() + " no type name:" + ttName);
			return NULL;
		}

		ttypeInfo = *(symbol->getVarType());
	}
	else {
		ttypeInfo.primary_type = typeTypeCtx->primary_type()->getText();
	}

	for (auto paCtx : typeTypeCtx->children) {
		if (paCtx->getText() == "*") { //*
			ttypeInfo.pas.push_back(PointOrArray(true));
		}
		else if (auto arrChild = dynamic_cast<DongLangParser::Array_typeContext*>(paCtx)) { // []
			int array_len = arrChild->NUMBER() ? std::stoi(arrChild->NUMBER()->getText()) : -1;
			if (arrChild->NUMBER() && array_len <= 0) {
				DongLangBaseAST::llvmCtx->emitError(typeTypeCtx->getText() + " array length err");
				return NULL;
			}

			ttypeInfo.pas.push_back(PointOrArray(false, array_len));
		}
	}

	//检查指针
	if (ttypeInfo.pas.size()) {
		int paIndex = 0;
		for (auto pa : ttypeInfo.pas) {
			if (paIndex == 0 || pa.pointOrArr) {
				paIndex++;
				continue;
			}

			auto lastPa = ttypeInfo.pas[paIndex - 1];
			if (!lastPa.pointOrArr && pa.array_len < 0) {// [][]
				DongLangBaseAST::llvmCtx->emitError(typeTypeCtx->getText() + " type array length format err");
				return NULL;
			}

			paIndex++;
		}
	}
	

	return new DongLangTypeInfo(ttypeInfo);
}

void DongLangLLVMVarListener::enterProg(DongLangParser::ProgContext * ctx) {
	DongLangBaseAST::AddScope(ctx, true, "ROOT");
}

void DongLangLLVMVarListener::enterFunction_def(DongLangParser::Function_defContext * ctx) {
	DongLangBaseAST::AddScope(ctx, false, ctx->IDENTIFIER()->getText());
}

#define FARG_ANALYZE(argCtx, argDefaultValueID) auto argId = argCtx->IDENTIFIER()->getText(); \
	auto varSb = curScope->FindSymbol(argId);\
	if (varSb && varSb->getScope() == curScope) {\
		DongLangBaseAST::llvmCtx->emitError(ctx->getText() + " repeated var declare:" + argId);\
		return;\
	}\
	\
	auto typeInfo = analyseDLTypeInfo(argCtx->type_type());\
	auto argTypeInfo = new DongLangTypeInfo(*typeInfo);\
	DongLangTypeInfo::arrToPtr(typeInfo); \ 
	\
	auto argSymbol = VarDLSymbol::Create(argId, typeInfo, NULL, argDefaultValueID); \
	curScope->AddSymbol(argId, SYMBOL_ID(argCtx), argSymbol); \
	argTypes.push_back(argTypeInfo); \
	argSymbols.push_back(argSymbol);\

void DongLangLLVMVarListener::exitFunction_def(DongLangParser::Function_defContext* ctx) {//fnName 
	string fnName = ctx->IDENTIFIER()->getText();

	//args
	vector<DongLangTypeInfo*> argTypes = {};

	auto curScope = DongLangBaseAST::CurScope(ctx);
	vector<VarDLSymbol*> argSymbols = {};
	for (auto argCtx : ctx->farg_list()->farg()) {
		FARG_ANALYZE(argCtx, 0);
	}

	for (auto argDCtx : ctx->farg_list()->farg_default()) {
		auto argCtx = argDCtx->farg();
		FARG_ANALYZE(argCtx, SYMBOL_ID(argDCtx->expression()));
	}

	//return type
	auto retTypeCtx = ctx->type_type_void();
	DongLangTypeInfo* retTypeInfo;
	if (retTypeCtx->type_type() != NULL) {
		int arrIndex = 0;
		retTypeInfo = analyseDLTypeInfo(retTypeCtx->type_type());
		if (retTypeInfo->isArray()) {
			DongLangBaseAST::llvmCtx->emitError(ctx->getText() + " function can not return array type");
			return;
		}
	}
	else {
		retTypeInfo = new DongLangTypeInfo(retTypeCtx->VOID()->getText());
	}

	//var arg
	bool isVarArg = ctx->farg_list()->f_varargs();

	auto funcScope = DongLangBaseAST::CurScope((DongLangBaseAST::antlr4Ctx)ctx->parent);
	bool externC = ctx->externC();
	if (auto funcSymbol = funcScope->FindFuncSymbol(fnName, argTypes, isVarArg)) {
		DongLangBaseAST::llvmCtx->emitError(ctx->getText() + " repeated function declare:" + funcSymbol->ID());
		return;
	}

	funcScope->AddSymbol(fnName, SYMBOL_ID(ctx), FuncDLSymbol::Create(fnName, retTypeInfo, argSymbols, argTypes, NULL, externC, isVarArg));
}

void DongLangLLVMVarListener::enterGlobal_var_expression(DongLangParser::Global_var_expressionContext* ctx) {
	if (ctx->var_declares()) {
		return;
	}

	//分析 type 变量
	string typeName = ctx->IDENTIFIER()->getText();
	auto curScope = DongLangBaseAST::CurScope(ctx);
	if (curScope->FindSymbol(typeName)) {
		DongLangBaseAST::llvmCtx->emitError(ctx->getText() + " type name symbol repeated:" + typeName);
		return;
	}

	DongLangTypeInfo* typeInfo = analyseDLTypeInfo(ctx->type_type());
	curScope->AddSymbol(typeName, SYMBOL_ID(ctx->type_type()), TypeDLSymbol::Create(typeName, typeInfo));
}

void DongLangLLVMVarListener::exitVar_declares(DongLangParser::Var_declaresContext* ctx) {
	DongLangTypeInfo* typeInfo = analyseDLTypeInfo(ctx->type_type());
	auto curScope = DongLangBaseAST::CurScope(ctx);

	for (auto varCtx : ctx->vars()->var()) {
		//检查如果是默认长度数组需要 立刻初始化
		if (typeInfo->needInitial()) {
			if (!varCtx->var_value()) {
				DongLangBaseAST::llvmCtx->emitError(ctx->getText() + " value need initialize");
				return;
			}
		}

		auto id = varCtx->IDENTIFIER()->getText();
		auto varSb = curScope->FindSymbol(id);
		if (varSb && varSb->getScope() == curScope) {
			DongLangBaseAST::llvmCtx->emitError("repeated var declare:" + id);
			return;
		}

		curScope->AddSymbol(id, SYMBOL_ID(varCtx), VarDLSymbol::Create(id, typeInfo, NULL));
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
