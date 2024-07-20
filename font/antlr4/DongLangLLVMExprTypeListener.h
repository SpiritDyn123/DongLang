#pragma once

#include "font/antlr4/gen/DongLangBaseListener.h"
#include "font/ast/DongLangBaseAST.h"

/**
 expression types analyse
	value_primary:
		num_primary
		| bool_primary
		| str_primary
		;

	id_primary_p_addrs:
		(POINT|POINTADDR)? (POINT POINTADDR?)*
		|POINT? (POINTADDR? POINT)*
		;
	id_primary:
		id_primary_p_addrs (IDENTIFIER|call_expr|paran_expr) array_index*
		;
	primary:
		  value_primary //1,"cc",true
		 | id_primary //
		 | call_expr  //ff()
		 | paran_expr //(1+2)
		 ;

	expression: expression opr=(MUL|DIV) expression
		| expression opr=(ADD|SUB) expression
		| expression opr=(CMP_EQ|CMP_NE|CMP_GT|CMP_GE|CMP_LT|CMP_LE) expression
		| primary
		;
 */

class DongLangLLVMExprTypeListener : public DongLangBaseListener {
public:
	DongLangLLVMExprTypeListener();
	DongLangTypeInfo* ExprType(DongLangParser::ExpressionContext* ctx, bool hasDefault = false);
	DongLangTypeInfo* ExprDefaultType(DongLangParser::ExpressionContext* ctx);
	DongLangTypeInfo* IdPrimaryType(DongLangParser::Id_primaryContext* ctx);
	DongLangTypeInfo* VarArrValueType(DongLangParser::Var_arr_valueContext* ctx);
	DongLangTypeInfo* AssignType(DongLangParser::AssignContext* ctx);
	DongLangTypeInfo* VarExprTypes(DongLangParser::Var_expressionContext* ctx);

	
	FuncSLSymbol* CallFuncSLSymbol(antlr4::ParserRuleContext* callCtx);

public:

	void enterExpression(DongLangParser::ExpressionContext* ctx) override;
	void exitExpression(DongLangParser::ExpressionContext* ctx) override;
	void exitVar_expression(DongLangParser::Var_expressionContext* ctx) override;
	void enterAssign(DongLangParser::AssignContext* ctx) override;
	void exitAssign(DongLangParser::AssignContext* ctx) override;

	void enterVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) override;
	void exitVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) override;

	void enterPrimary(DongLangParser::PrimaryContext* ctx) override;
	void exitPrimary(DongLangParser::PrimaryContext* ctx) override;

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
	MTYPES mIdPrimaryTypes;
	MTYPES mVarArrValueTypes;
	MTYPES mAssignTypes;
	MTYPES mVarExprTypes;
	map< antlr4::ParserRuleContext*, FuncSLSymbol*> mCallFuncSymbol;
};
