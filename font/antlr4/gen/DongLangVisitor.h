
// Generated from D:/studyCode/DongLang/font/antlr4/DongLang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DongLangParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by DongLangParser.
 */
class  DongLangVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by DongLangParser.
   */
    virtual std::any visitProg(DongLangParser::ProgContext *context) = 0;

    virtual std::any visitStatement(DongLangParser::StatementContext *context) = 0;

    virtual std::any visitFunction_def(DongLangParser::Function_defContext *context) = 0;

    virtual std::any visitExternC(DongLangParser::ExternCContext *context) = 0;

    virtual std::any visitFunction_body(DongLangParser::Function_bodyContext *context) = 0;

    virtual std::any visitFarg(DongLangParser::FargContext *context) = 0;

    virtual std::any visitF_varargs(DongLangParser::F_varargsContext *context) = 0;

    virtual std::any visitFarg_list(DongLangParser::Farg_listContext *context) = 0;

    virtual std::any visitRet_expression(DongLangParser::Ret_expressionContext *context) = 0;

    virtual std::any visitExpression(DongLangParser::ExpressionContext *context) = 0;

    virtual std::any visitCond_statement(DongLangParser::Cond_statementContext *context) = 0;

    virtual std::any visitIf_expression(DongLangParser::If_expressionContext *context) = 0;

    virtual std::any visitElif_expr(DongLangParser::Elif_exprContext *context) = 0;

    virtual std::any visitElse_expr(DongLangParser::Else_exprContext *context) = 0;

    virtual std::any visitElif(DongLangParser::ElifContext *context) = 0;

    virtual std::any visitIf_cond(DongLangParser::If_condContext *context) = 0;

    virtual std::any visitFor_expression(DongLangParser::For_expressionContext *context) = 0;

    virtual std::any visitFor_cond(DongLangParser::For_condContext *context) = 0;

    virtual std::any visitGlobal_var_expression(DongLangParser::Global_var_expressionContext *context) = 0;

    virtual std::any visitVar_expression(DongLangParser::Var_expressionContext *context) = 0;

    virtual std::any visitParan_expr(DongLangParser::Paran_exprContext *context) = 0;

    virtual std::any visitCall_expr(DongLangParser::Call_exprContext *context) = 0;

    virtual std::any visitExpr_list(DongLangParser::Expr_listContext *context) = 0;

    virtual std::any visitNum_primary(DongLangParser::Num_primaryContext *context) = 0;

    virtual std::any visitStr_primary(DongLangParser::Str_primaryContext *context) = 0;

    virtual std::any visitBool_primary(DongLangParser::Bool_primaryContext *context) = 0;

    virtual std::any visitValue_primary(DongLangParser::Value_primaryContext *context) = 0;

    virtual std::any visitArray_index(DongLangParser::Array_indexContext *context) = 0;

    virtual std::any visitId_primary_p_addrs(DongLangParser::Id_primary_p_addrsContext *context) = 0;

    virtual std::any visitId_primary(DongLangParser::Id_primaryContext *context) = 0;

    virtual std::any visitPrimary(DongLangParser::PrimaryContext *context) = 0;

    virtual std::any visitPrimary_type(DongLangParser::Primary_typeContext *context) = 0;

    virtual std::any visitArray_type(DongLangParser::Array_typeContext *context) = 0;

    virtual std::any visitType_type(DongLangParser::Type_typeContext *context) = 0;

    virtual std::any visitType_type_void(DongLangParser::Type_type_voidContext *context) = 0;

    virtual std::any visitVar_value(DongLangParser::Var_valueContext *context) = 0;

    virtual std::any visitVar_arr_value(DongLangParser::Var_arr_valueContext *context) = 0;

    virtual std::any visitAssign(DongLangParser::AssignContext *context) = 0;

    virtual std::any visitAssigns(DongLangParser::AssignsContext *context) = 0;

    virtual std::any visitVar(DongLangParser::VarContext *context) = 0;

    virtual std::any visitVars(DongLangParser::VarsContext *context) = 0;

    virtual std::any visitVar_declares(DongLangParser::Var_declaresContext *context) = 0;

    virtual std::any visitTemplate(DongLangParser::TemplateContext *context) = 0;

    virtual std::any visitClass_def(DongLangParser::Class_defContext *context) = 0;


};

