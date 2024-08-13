#pragma once

#include "font/antlr4/gen/DongLangBaseListener.h"
#include "font/ast/DongLangBaseAST.h"
using namespace antlr4;

class DongLangLLVMExprTypeListener;
class DongLangLLVMErrorListener : public ANTLRErrorListener {
public:
	DongLangLLVMErrorListener(int defaultLine): defaultLine(defaultLine) {}

	virtual void syntaxError(Recognizer* recognizer, Token* offendingSymbol, size_t line,
		size_t charPositionInLine, const std::string& msg, std::exception_ptr e) override;

	virtual void reportAmbiguity(Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex, bool exact,
		const antlrcpp::BitSet& ambigAlts, atn::ATNConfigSet* configs) override {}

	virtual void reportAttemptingFullContext(Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex,
		const antlrcpp::BitSet& conflictingAlts, atn::ATNConfigSet* configs) override {}

	virtual void reportContextSensitivity(Parser* recognizer, const dfa::DFA& dfa, size_t startIndex, size_t stopIndex,
		size_t prediction, atn::ATNConfigSet* configs) override {}
private:
	int defaultLine;
};

class DongLangLLVMListener : public DongLangBaseListener {
public:
	 void enterProg(DongLangParser::ProgContext* ctx) override;
	 void exitProg(DongLangParser::ProgContext* ctx) override;

	 void exitFunction_def(DongLangParser::Function_defContext* ctx) override;

	 void enterStatement(DongLangParser::StatementContext* ctx) override;
	 void exitStatement(DongLangParser::StatementContext* ctx) override;
	 void exitCond_statement(DongLangParser::Cond_statementContext* ctx) override;

	 void enterExpression(DongLangParser::ExpressionContext* ctx) override;
	 void exitExpression(DongLangParser::ExpressionContext* ctx) override;

	void enterFarg(DongLangParser::FargContext* ctx) override { }
	void exitFarg(DongLangParser::FargContext* ctx) override { }

	void enterF_varargs(DongLangParser::F_varargsContext* ctx) override { }
	void exitF_varargs(DongLangParser::F_varargsContext* ctx) override { }

	void enterFarg_list(DongLangParser::Farg_listContext* ctx) override { }
	void exitFarg_list(DongLangParser::Farg_listContext* ctx) override { }

	void enterRet_expression(DongLangParser::Ret_expressionContext*) override;
	void exitRet_expression(DongLangParser::Ret_expressionContext*) override;

	void enterIf_expression(DongLangParser::If_expressionContext* ctx) override;
	void exitIf_expression(DongLangParser::If_expressionContext* ctx) override;

	void enterFor_expression(DongLangParser::For_expressionContext* ctx) override;
	void exitFor_expression(DongLangParser::For_expressionContext* ctx) override;

	void enterFor_cond(DongLangParser::For_condContext* ctx) override { }
	void exitFor_cond(DongLangParser::For_condContext* ctx) override { }


	void enterGlobal_var_expression(DongLangParser::Global_var_expressionContext* ctx) override;
	void exitGlobal_var_expression(DongLangParser::Global_var_expressionContext* ctx) override;

	void enterVar_expression(DongLangParser::Var_expressionContext* ctx) override { }
	void exitVar_expression(DongLangParser::Var_expressionContext* ctx) override;

	 void enterParan_expr(DongLangParser::Paran_exprContext* ctx) override;
	 void exitParan_expr(DongLangParser::Paran_exprContext* ctx) override;

	 void enterCall_expr(DongLangParser::Call_exprContext* ctx) override;
	 void exitCall_expr(DongLangParser::Call_exprContext* ctx) override;

	 void enterExpr_list(DongLangParser::Expr_listContext* ctx) override;
	 void exitExpr_list(DongLangParser::Expr_listContext* ctx) override;

	 void enterValue_primary(DongLangParser::Value_primaryContext* ctx) override;
	 void exitValue_primary(DongLangParser::Value_primaryContext* ctx) override;

	 void enterPrimary(DongLangParser::PrimaryContext* ctx) override;
	 void exitPrimary(DongLangParser::PrimaryContext* ctx) override;

	 void enterId_primary(DongLangParser::Id_primaryContext* ctx) override;
	 void exitId_primary(DongLangParser::Id_primaryContext* ctx) override;

	 void enterPrimary_type(DongLangParser::Primary_typeContext* ctx) override { }
	 void exitPrimary_type(DongLangParser::Primary_typeContext* ctx) override { }

	 void enterType_type(DongLangParser::Type_typeContext* ctx) override { }
	 void exitType_type(DongLangParser::Type_typeContext* ctx) override { }

	 void enterType_type_void(DongLangParser::Type_type_voidContext* ctx) override { }
	 void exitType_type_void(DongLangParser::Type_type_voidContext* ctx) override { }

	 void enterVar_value(DongLangParser::Var_valueContext* ctx) override;
	 void exitVar_value(DongLangParser::Var_valueContext* ctx) override;

	 void enterVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) override;
	 void exitVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) override;

	 void enterVar(DongLangParser::VarContext* ctx) override;
	 void exitVar(DongLangParser::VarContext* ctx) override;

	 void enterVars(DongLangParser::VarsContext* ctx) override;
	 void exitVars(DongLangParser::VarsContext* ctx) override;

	 void enterVar_declares(DongLangParser::Var_declaresContext* ctx) override;
	 void exitVar_declares(DongLangParser::Var_declaresContext* ctx) override;

	  void enterAssign(DongLangParser::AssignContext* /*ctx*/) override;
	  void exitAssign(DongLangParser::AssignContext* /*ctx*/) override;

	  void enterAssigns(DongLangParser::AssignsContext* /*ctx*/) override;
	  void exitAssigns(DongLangParser::AssignsContext* /*ctx*/) override;

	 void enterEveryRule(antlr4::ParserRuleContext* ctx) override { }
	 void exitEveryRule(antlr4::ParserRuleContext* ctx) override { }
	 void visitTerminal(antlr4::tree::TerminalNode* /*node*/) override { }
	 void visitErrorNode(antlr4::tree::ErrorNode* /*node*/) override {}

public:
	DongLangLLVMListener(DongLangLLVMExprTypeListener* etListener, int defaultLine);
	DongLangBaseAST* GetRootAST();

private:
	DongLangBaseAST* rootAST;
	DongLangLLVMExprTypeListener* etListener;
	std::map<antlr4::ParserRuleContext*, DongLangTypeInfo*> mExprTypes;
	std::map<antlr4::ParserRuleContext*, DongLangBaseAST*> mAsts;
	int defaultLine;
};