#pragma once

#include "font/antlr4/gen/DongLangBaseListener.h"
#include "font/ast/DongLangBaseAST.h"
#include "DongLangLLVMBaseListener.h"

/**
 vars scopes
 */
class DongLangLLVMVarListener : public DongLangBaseListener, public DongLangLLVMBaseListener {
public:
	void enterProg(DongLangParser::ProgContext* ctx) override;

	void enterFunction_def(DongLangParser::Function_defContext* ctx) override;
	void exitFunction_def(DongLangParser::Function_defContext* ctx) override;

	void enterGlobal_var_expression(DongLangParser::Global_var_expressionContext* ctx) override;


	void exitVar_declares(DongLangParser::Var_declaresContext* ctx) override;

	void enterIf_cond(DongLangParser::If_condContext* ctx) override;

	void enterIf_expression(DongLangParser::If_expressionContext* ctx) override;

	void enterFor_expression(DongLangParser::For_expressionContext* ctx) override;

	void enterCond_statement(DongLangParser::Cond_statementContext* ctx) override;

public:
	DongLangLLVMVarListener(int defaultLine) : DongLangLLVMBaseListener(defaultLine) {}

	static DongLangTypeInfo* analyseDLTypeInfo(DongLangParser::Type_typeContext* typeTypeCtx);
};
