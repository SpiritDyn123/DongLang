#pragma once

#include "font/antlr4/gen/DongLangBaseListener.h"
#include "font/ast/DongLangBaseAST.h"

class DongLangLLVMExprTypeListener : public DongLangBaseListener {
public:
	DongLangLLVMExprTypeListener();
	DongLangTypeInfo* ExprType(DongLangParser::ExpressionContext* ctx, bool hasDefault = false);
	DongLangTypeInfo* ExprDefaultType(DongLangParser::ExpressionContext* ctx);
	DongLangTypeInfo* VarArrValueType(DongLangParser::Var_arr_valueContext* ctx);
	DongLangTypeInfo* AssignType(DongLangParser::AssignContext* ctx);
	DongLangTypeInfo* VarExprTypes(DongLangParser::Var_expressionContext* ctx);

	
	FuncDLSymbol* CallFuncDLSymbol(antlr4::ParserRuleContext* callCtx);

	string getExprOpr(DongLangParser::ExpressionContext* exprCtx);
public:

	void enterExpression(DongLangParser::ExpressionContext* ctx) override;
	void exitExpression(DongLangParser::ExpressionContext* ctx) override;
	void enterAssign(DongLangParser::AssignContext* ctx) override;
	void exitAssign(DongLangParser::AssignContext* ctx) override;
	void enterVar_expression(DongLangParser::Var_expressionContext* ctx) override;
	void exitVar_expression(DongLangParser::Var_expressionContext* ctx) override;

	void enterVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) override;
	void exitVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) override;

	void enterId_primary(DongLangParser::Id_primaryContext* ctx) override;
	void exitId_primary(DongLangParser::Id_primaryContext* ctx) override;

	void enterValue_primary(DongLangParser::Value_primaryContext* ctx) override;
	void exitValue_primary(DongLangParser::Value_primaryContext* ctx) override;

	void enterCall_expr(DongLangParser::Call_exprContext* ctx) override;
	void exitCall_expr(DongLangParser::Call_exprContext* ctx) override;

	void enterParan_expr(DongLangParser::Paran_exprContext* ctx) override;
	void exitParan_expr(DongLangParser::Paran_exprContext* ctx) override;

	void enterArray_type(DongLangParser::Array_typeContext* ctx) override;

	void exitRet_expression(DongLangParser::Ret_expressionContext* ctx) override;


private:
	typedef  map<antlr4::ParserRuleContext*, DongLangTypeInfo*> MTYPES;
	MTYPES mExprTypes;
	MTYPES mDefaultExprTypes;
	MTYPES mVarArrValueTypes;
	MTYPES mAssignTypes;
	MTYPES mVarExprTypes; //存储mAssignTypes的最终（官方）类型，类似mExprTypes之余mDefaultExprTypes
	map< antlr4::ParserRuleContext*, FuncDLSymbol*> mCallFuncSymbol;
};
