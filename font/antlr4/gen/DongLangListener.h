
// Generated from D:/vsprojects/DongLang/font/antlr4/DongLang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DongLangParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by DongLangParser.
 */
class  DongLangListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(DongLangParser::ProgContext *ctx) = 0;
  virtual void exitProg(DongLangParser::ProgContext *ctx) = 0;

  virtual void enterStatement(DongLangParser::StatementContext *ctx) = 0;
  virtual void exitStatement(DongLangParser::StatementContext *ctx) = 0;

  virtual void enterFunction_def(DongLangParser::Function_defContext *ctx) = 0;
  virtual void exitFunction_def(DongLangParser::Function_defContext *ctx) = 0;

  virtual void enterExternC(DongLangParser::ExternCContext *ctx) = 0;
  virtual void exitExternC(DongLangParser::ExternCContext *ctx) = 0;

  virtual void enterFunction_body(DongLangParser::Function_bodyContext *ctx) = 0;
  virtual void exitFunction_body(DongLangParser::Function_bodyContext *ctx) = 0;

  virtual void enterFarg(DongLangParser::FargContext *ctx) = 0;
  virtual void exitFarg(DongLangParser::FargContext *ctx) = 0;

  virtual void enterF_varargs(DongLangParser::F_varargsContext *ctx) = 0;
  virtual void exitF_varargs(DongLangParser::F_varargsContext *ctx) = 0;

  virtual void enterFarg_list(DongLangParser::Farg_listContext *ctx) = 0;
  virtual void exitFarg_list(DongLangParser::Farg_listContext *ctx) = 0;

  virtual void enterRet_expression(DongLangParser::Ret_expressionContext *ctx) = 0;
  virtual void exitRet_expression(DongLangParser::Ret_expressionContext *ctx) = 0;

  virtual void enterExpression(DongLangParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(DongLangParser::ExpressionContext *ctx) = 0;

  virtual void enterCond_statement(DongLangParser::Cond_statementContext *ctx) = 0;
  virtual void exitCond_statement(DongLangParser::Cond_statementContext *ctx) = 0;

  virtual void enterIf_expression(DongLangParser::If_expressionContext *ctx) = 0;
  virtual void exitIf_expression(DongLangParser::If_expressionContext *ctx) = 0;

  virtual void enterElif_expr(DongLangParser::Elif_exprContext *ctx) = 0;
  virtual void exitElif_expr(DongLangParser::Elif_exprContext *ctx) = 0;

  virtual void enterElse_expr(DongLangParser::Else_exprContext *ctx) = 0;
  virtual void exitElse_expr(DongLangParser::Else_exprContext *ctx) = 0;

  virtual void enterElif(DongLangParser::ElifContext *ctx) = 0;
  virtual void exitElif(DongLangParser::ElifContext *ctx) = 0;

  virtual void enterIf_cond(DongLangParser::If_condContext *ctx) = 0;
  virtual void exitIf_cond(DongLangParser::If_condContext *ctx) = 0;

  virtual void enterFor_expression(DongLangParser::For_expressionContext *ctx) = 0;
  virtual void exitFor_expression(DongLangParser::For_expressionContext *ctx) = 0;

  virtual void enterFor_cond(DongLangParser::For_condContext *ctx) = 0;
  virtual void exitFor_cond(DongLangParser::For_condContext *ctx) = 0;

  virtual void enterGlobal_var_expression(DongLangParser::Global_var_expressionContext *ctx) = 0;
  virtual void exitGlobal_var_expression(DongLangParser::Global_var_expressionContext *ctx) = 0;

  virtual void enterVar_expression(DongLangParser::Var_expressionContext *ctx) = 0;
  virtual void exitVar_expression(DongLangParser::Var_expressionContext *ctx) = 0;

  virtual void enterParan_expr(DongLangParser::Paran_exprContext *ctx) = 0;
  virtual void exitParan_expr(DongLangParser::Paran_exprContext *ctx) = 0;

  virtual void enterCall_expr(DongLangParser::Call_exprContext *ctx) = 0;
  virtual void exitCall_expr(DongLangParser::Call_exprContext *ctx) = 0;

  virtual void enterExpr_list(DongLangParser::Expr_listContext *ctx) = 0;
  virtual void exitExpr_list(DongLangParser::Expr_listContext *ctx) = 0;

  virtual void enterNum_primary(DongLangParser::Num_primaryContext *ctx) = 0;
  virtual void exitNum_primary(DongLangParser::Num_primaryContext *ctx) = 0;

  virtual void enterStr_primary(DongLangParser::Str_primaryContext *ctx) = 0;
  virtual void exitStr_primary(DongLangParser::Str_primaryContext *ctx) = 0;

  virtual void enterBool_primary(DongLangParser::Bool_primaryContext *ctx) = 0;
  virtual void exitBool_primary(DongLangParser::Bool_primaryContext *ctx) = 0;

  virtual void enterValue_primary(DongLangParser::Value_primaryContext *ctx) = 0;
  virtual void exitValue_primary(DongLangParser::Value_primaryContext *ctx) = 0;

  virtual void enterArray_index(DongLangParser::Array_indexContext *ctx) = 0;
  virtual void exitArray_index(DongLangParser::Array_indexContext *ctx) = 0;

  virtual void enterId_primary_p_addrs(DongLangParser::Id_primary_p_addrsContext *ctx) = 0;
  virtual void exitId_primary_p_addrs(DongLangParser::Id_primary_p_addrsContext *ctx) = 0;

  virtual void enterId_primary(DongLangParser::Id_primaryContext *ctx) = 0;
  virtual void exitId_primary(DongLangParser::Id_primaryContext *ctx) = 0;

  virtual void enterPrimary(DongLangParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(DongLangParser::PrimaryContext *ctx) = 0;

  virtual void enterPrimary_type(DongLangParser::Primary_typeContext *ctx) = 0;
  virtual void exitPrimary_type(DongLangParser::Primary_typeContext *ctx) = 0;

  virtual void enterArray_type(DongLangParser::Array_typeContext *ctx) = 0;
  virtual void exitArray_type(DongLangParser::Array_typeContext *ctx) = 0;

  virtual void enterType_type(DongLangParser::Type_typeContext *ctx) = 0;
  virtual void exitType_type(DongLangParser::Type_typeContext *ctx) = 0;

  virtual void enterType_type_void(DongLangParser::Type_type_voidContext *ctx) = 0;
  virtual void exitType_type_void(DongLangParser::Type_type_voidContext *ctx) = 0;

  virtual void enterVar_value(DongLangParser::Var_valueContext *ctx) = 0;
  virtual void exitVar_value(DongLangParser::Var_valueContext *ctx) = 0;

  virtual void enterVar_arr_value(DongLangParser::Var_arr_valueContext *ctx) = 0;
  virtual void exitVar_arr_value(DongLangParser::Var_arr_valueContext *ctx) = 0;

  virtual void enterAssign(DongLangParser::AssignContext *ctx) = 0;
  virtual void exitAssign(DongLangParser::AssignContext *ctx) = 0;

  virtual void enterAssigns(DongLangParser::AssignsContext *ctx) = 0;
  virtual void exitAssigns(DongLangParser::AssignsContext *ctx) = 0;

  virtual void enterVar(DongLangParser::VarContext *ctx) = 0;
  virtual void exitVar(DongLangParser::VarContext *ctx) = 0;

  virtual void enterVars(DongLangParser::VarsContext *ctx) = 0;
  virtual void exitVars(DongLangParser::VarsContext *ctx) = 0;

  virtual void enterVar_declares(DongLangParser::Var_declaresContext *ctx) = 0;
  virtual void exitVar_declares(DongLangParser::Var_declaresContext *ctx) = 0;

  virtual void enterTemplate(DongLangParser::TemplateContext *ctx) = 0;
  virtual void exitTemplate(DongLangParser::TemplateContext *ctx) = 0;

  virtual void enterClass_def(DongLangParser::Class_defContext *ctx) = 0;
  virtual void exitClass_def(DongLangParser::Class_defContext *ctx) = 0;


};

