
// Generated from D:/studyCode/DongLang/font/antlr4/DongLang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DongLangVisitor.h"


/**
 * This class provides an empty implementation of DongLangVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  DongLangBaseVisitor : public DongLangVisitor {
public:

  virtual std::any visitProg(DongLangParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(DongLangParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_def(DongLangParser::Function_defContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExternC(DongLangParser::ExternCContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction_body(DongLangParser::Function_bodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFarg(DongLangParser::FargContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitF_varargs(DongLangParser::F_varargsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFarg_list(DongLangParser::Farg_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRet_expression(DongLangParser::Ret_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpression(DongLangParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCond_statement(DongLangParser::Cond_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_expression(DongLangParser::If_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElif_expr(DongLangParser::Elif_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElse_expr(DongLangParser::Else_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElif(DongLangParser::ElifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_cond(DongLangParser::If_condContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_expression(DongLangParser::For_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_cond(DongLangParser::For_condContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGlobal_var_expression(DongLangParser::Global_var_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_expression(DongLangParser::Var_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParan_expr(DongLangParser::Paran_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall_expr(DongLangParser::Call_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_list(DongLangParser::Expr_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNum_primary(DongLangParser::Num_primaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStr_primary(DongLangParser::Str_primaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBool_primary(DongLangParser::Bool_primaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue_primary(DongLangParser::Value_primaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_index(DongLangParser::Array_indexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitId_primary_p_addrs(DongLangParser::Id_primary_p_addrsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitId_primary(DongLangParser::Id_primaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary(DongLangParser::PrimaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimary_type(DongLangParser::Primary_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_type(DongLangParser::Array_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_type(DongLangParser::Type_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_type_void(DongLangParser::Type_type_voidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_value(DongLangParser::Var_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_arr_value(DongLangParser::Var_arr_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(DongLangParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssigns(DongLangParser::AssignsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar(DongLangParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVars(DongLangParser::VarsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_declares(DongLangParser::Var_declaresContext *ctx) override {
    return visitChildren(ctx);
  }


};

