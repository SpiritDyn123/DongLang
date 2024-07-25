
// Generated from D:/vsprojects/DongLang/font/antlr4/DongLang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DongLangListener.h"


/**
 * This class provides an empty implementation of DongLangListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  DongLangBaseListener : public DongLangListener {
public:

  virtual void enterProg(DongLangParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(DongLangParser::ProgContext * /*ctx*/) override { }

  virtual void enterStatement(DongLangParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(DongLangParser::StatementContext * /*ctx*/) override { }

  virtual void enterFunction_def(DongLangParser::Function_defContext * /*ctx*/) override { }
  virtual void exitFunction_def(DongLangParser::Function_defContext * /*ctx*/) override { }

  virtual void enterExternC(DongLangParser::ExternCContext * /*ctx*/) override { }
  virtual void exitExternC(DongLangParser::ExternCContext * /*ctx*/) override { }

  virtual void enterFunction_body(DongLangParser::Function_bodyContext * /*ctx*/) override { }
  virtual void exitFunction_body(DongLangParser::Function_bodyContext * /*ctx*/) override { }

  virtual void enterFarg(DongLangParser::FargContext * /*ctx*/) override { }
  virtual void exitFarg(DongLangParser::FargContext * /*ctx*/) override { }

  virtual void enterF_varargs(DongLangParser::F_varargsContext * /*ctx*/) override { }
  virtual void exitF_varargs(DongLangParser::F_varargsContext * /*ctx*/) override { }

  virtual void enterFarg_list(DongLangParser::Farg_listContext * /*ctx*/) override { }
  virtual void exitFarg_list(DongLangParser::Farg_listContext * /*ctx*/) override { }

  virtual void enterRet_expression(DongLangParser::Ret_expressionContext * /*ctx*/) override { }
  virtual void exitRet_expression(DongLangParser::Ret_expressionContext * /*ctx*/) override { }

  virtual void enterExpression(DongLangParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(DongLangParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterCond_statement(DongLangParser::Cond_statementContext * /*ctx*/) override { }
  virtual void exitCond_statement(DongLangParser::Cond_statementContext * /*ctx*/) override { }

  virtual void enterIf_expression(DongLangParser::If_expressionContext * /*ctx*/) override { }
  virtual void exitIf_expression(DongLangParser::If_expressionContext * /*ctx*/) override { }

  virtual void enterElif_expr(DongLangParser::Elif_exprContext * /*ctx*/) override { }
  virtual void exitElif_expr(DongLangParser::Elif_exprContext * /*ctx*/) override { }

  virtual void enterElse_expr(DongLangParser::Else_exprContext * /*ctx*/) override { }
  virtual void exitElse_expr(DongLangParser::Else_exprContext * /*ctx*/) override { }

  virtual void enterElif(DongLangParser::ElifContext * /*ctx*/) override { }
  virtual void exitElif(DongLangParser::ElifContext * /*ctx*/) override { }

  virtual void enterIf_cond(DongLangParser::If_condContext * /*ctx*/) override { }
  virtual void exitIf_cond(DongLangParser::If_condContext * /*ctx*/) override { }

  virtual void enterFor_expression(DongLangParser::For_expressionContext * /*ctx*/) override { }
  virtual void exitFor_expression(DongLangParser::For_expressionContext * /*ctx*/) override { }

  virtual void enterFor_cond(DongLangParser::For_condContext * /*ctx*/) override { }
  virtual void exitFor_cond(DongLangParser::For_condContext * /*ctx*/) override { }

  virtual void enterGlobal_var_expression(DongLangParser::Global_var_expressionContext * /*ctx*/) override { }
  virtual void exitGlobal_var_expression(DongLangParser::Global_var_expressionContext * /*ctx*/) override { }

  virtual void enterVar_expression(DongLangParser::Var_expressionContext * /*ctx*/) override { }
  virtual void exitVar_expression(DongLangParser::Var_expressionContext * /*ctx*/) override { }

  virtual void enterParan_expr(DongLangParser::Paran_exprContext * /*ctx*/) override { }
  virtual void exitParan_expr(DongLangParser::Paran_exprContext * /*ctx*/) override { }

  virtual void enterCall_expr(DongLangParser::Call_exprContext * /*ctx*/) override { }
  virtual void exitCall_expr(DongLangParser::Call_exprContext * /*ctx*/) override { }

  virtual void enterExpr_list(DongLangParser::Expr_listContext * /*ctx*/) override { }
  virtual void exitExpr_list(DongLangParser::Expr_listContext * /*ctx*/) override { }

  virtual void enterNum_primary(DongLangParser::Num_primaryContext * /*ctx*/) override { }
  virtual void exitNum_primary(DongLangParser::Num_primaryContext * /*ctx*/) override { }

  virtual void enterStr_primary(DongLangParser::Str_primaryContext * /*ctx*/) override { }
  virtual void exitStr_primary(DongLangParser::Str_primaryContext * /*ctx*/) override { }

  virtual void enterBool_primary(DongLangParser::Bool_primaryContext * /*ctx*/) override { }
  virtual void exitBool_primary(DongLangParser::Bool_primaryContext * /*ctx*/) override { }

  virtual void enterValue_primary(DongLangParser::Value_primaryContext * /*ctx*/) override { }
  virtual void exitValue_primary(DongLangParser::Value_primaryContext * /*ctx*/) override { }

  virtual void enterArray_index(DongLangParser::Array_indexContext * /*ctx*/) override { }
  virtual void exitArray_index(DongLangParser::Array_indexContext * /*ctx*/) override { }

  virtual void enterId_primary_p_addrs(DongLangParser::Id_primary_p_addrsContext * /*ctx*/) override { }
  virtual void exitId_primary_p_addrs(DongLangParser::Id_primary_p_addrsContext * /*ctx*/) override { }

  virtual void enterId_primary(DongLangParser::Id_primaryContext * /*ctx*/) override { }
  virtual void exitId_primary(DongLangParser::Id_primaryContext * /*ctx*/) override { }

  virtual void enterPrimary(DongLangParser::PrimaryContext * /*ctx*/) override { }
  virtual void exitPrimary(DongLangParser::PrimaryContext * /*ctx*/) override { }

  virtual void enterPrimary_type(DongLangParser::Primary_typeContext * /*ctx*/) override { }
  virtual void exitPrimary_type(DongLangParser::Primary_typeContext * /*ctx*/) override { }

  virtual void enterArray_type(DongLangParser::Array_typeContext * /*ctx*/) override { }
  virtual void exitArray_type(DongLangParser::Array_typeContext * /*ctx*/) override { }

  virtual void enterType_type(DongLangParser::Type_typeContext * /*ctx*/) override { }
  virtual void exitType_type(DongLangParser::Type_typeContext * /*ctx*/) override { }

  virtual void enterType_type_void(DongLangParser::Type_type_voidContext * /*ctx*/) override { }
  virtual void exitType_type_void(DongLangParser::Type_type_voidContext * /*ctx*/) override { }

  virtual void enterVar_value(DongLangParser::Var_valueContext * /*ctx*/) override { }
  virtual void exitVar_value(DongLangParser::Var_valueContext * /*ctx*/) override { }

  virtual void enterVar_arr_value(DongLangParser::Var_arr_valueContext * /*ctx*/) override { }
  virtual void exitVar_arr_value(DongLangParser::Var_arr_valueContext * /*ctx*/) override { }

  virtual void enterAssign(DongLangParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(DongLangParser::AssignContext * /*ctx*/) override { }

  virtual void enterAssigns(DongLangParser::AssignsContext * /*ctx*/) override { }
  virtual void exitAssigns(DongLangParser::AssignsContext * /*ctx*/) override { }

  virtual void enterVar(DongLangParser::VarContext * /*ctx*/) override { }
  virtual void exitVar(DongLangParser::VarContext * /*ctx*/) override { }

  virtual void enterVars(DongLangParser::VarsContext * /*ctx*/) override { }
  virtual void exitVars(DongLangParser::VarsContext * /*ctx*/) override { }

  virtual void enterVar_declares(DongLangParser::Var_declaresContext * /*ctx*/) override { }
  virtual void exitVar_declares(DongLangParser::Var_declaresContext * /*ctx*/) override { }

  virtual void enterTemplate(DongLangParser::TemplateContext * /*ctx*/) override { }
  virtual void exitTemplate(DongLangParser::TemplateContext * /*ctx*/) override { }

  virtual void enterClass_def(DongLangParser::Class_defContext * /*ctx*/) override { }
  virtual void exitClass_def(DongLangParser::Class_defContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

