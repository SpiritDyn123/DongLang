
// Generated from D:/studyCode/DongLang/font/antlr4/DongLang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  DongLangParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, FUNC = 20, 
    RETURN = 21, VOID = 22, TRUE = 23, FALSE = 24, FOR = 25, BREAK = 26, 
    CONTINUE = 27, IF = 28, ELSE = 29, ELIF = 30, POINTADDR = 31, COND_AND = 32, 
    COND_OR = 33, COND_NOT = 34, POINT = 35, INCREMENT = 36, DECREMENT = 37, 
    COND_SPE = 38, NIL = 39, TYPE = 40, ADD = 41, SUB = 42, MUL = 43, DIV = 44, 
    OR = 45, XOR = 46, NOT = 47, CMP_EQ = 48, CMP_NE = 49, CMP_GT = 50, 
    CMP_LT = 51, CMP_GE = 52, CMP_LE = 53, SPACE = 54, LINE_COMMENT = 55, 
    COMMENT = 56, IDENTIFIER = 57, NUMBER = 58, INTEGER = 59, ALPHA_DIGIT = 60, 
    ALPHA = 61, DIGIT = 62, NULL_ = 63, STRING_LITERAL = 64
  };

  enum {
    RuleProg = 0, RuleStatement = 1, RuleFunction_def = 2, RuleExternC = 3, 
    RuleFunction_body = 4, RuleFarg = 5, RuleF_varargs = 6, RuleFarg_list = 7, 
    RuleRet_expression = 8, RuleExpression = 9, RuleCond_statement = 10, 
    RuleIf_expression = 11, RuleElif_expr = 12, RuleElse_expr = 13, RuleElif = 14, 
    RuleIf_cond = 15, RuleFor_expression = 16, RuleFor_cond = 17, RuleGlobal_var_expression = 18, 
    RuleVar_expression = 19, RuleParan_expr = 20, RuleCall_expr = 21, RuleExpr_list = 22, 
    RuleNum_primary = 23, RuleStr_primary = 24, RuleBool_primary = 25, RuleValue_primary = 26, 
    RuleArray_index = 27, RuleId_primary_p_addrs = 28, RuleId_primary = 29, 
    RulePrimary = 30, RulePrimary_type = 31, RuleArray_type = 32, RuleType_type = 33, 
    RuleType_type_void = 34, RuleVar_value = 35, RuleVar_arr_value = 36, 
    RuleAssign = 37, RuleAssigns = 38, RuleVar = 39, RuleVars = 40, RuleVar_declares = 41, 
    RuleTemplate = 42, RuleClass_def = 43
  };

  explicit DongLangParser(antlr4::TokenStream *input);

  DongLangParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~DongLangParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgContext;
  class StatementContext;
  class Function_defContext;
  class ExternCContext;
  class Function_bodyContext;
  class FargContext;
  class F_varargsContext;
  class Farg_listContext;
  class Ret_expressionContext;
  class ExpressionContext;
  class Cond_statementContext;
  class If_expressionContext;
  class Elif_exprContext;
  class Else_exprContext;
  class ElifContext;
  class If_condContext;
  class For_expressionContext;
  class For_condContext;
  class Global_var_expressionContext;
  class Var_expressionContext;
  class Paran_exprContext;
  class Call_exprContext;
  class Expr_listContext;
  class Num_primaryContext;
  class Str_primaryContext;
  class Bool_primaryContext;
  class Value_primaryContext;
  class Array_indexContext;
  class Id_primary_p_addrsContext;
  class Id_primaryContext;
  class PrimaryContext;
  class Primary_typeContext;
  class Array_typeContext;
  class Type_typeContext;
  class Type_type_voidContext;
  class Var_valueContext;
  class Var_arr_valueContext;
  class AssignContext;
  class AssignsContext;
  class VarContext;
  class VarsContext;
  class Var_declaresContext;
  class TemplateContext;
  class Class_defContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Global_var_expressionContext *> global_var_expression();
    Global_var_expressionContext* global_var_expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COND_SPE();
    antlr4::tree::TerminalNode* COND_SPE(size_t i);
    std::vector<Function_defContext *> function_def();
    Function_defContext* function_def(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgContext* prog();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_expressionContext *var_expression();
    antlr4::tree::TerminalNode *COND_SPE();
    Ret_expressionContext *ret_expression();
    If_expressionContext *if_expression();
    For_expressionContext *for_expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  Function_defContext : public antlr4::ParserRuleContext {
  public:
    Function_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNC();
    Type_type_voidContext *type_type_void();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Farg_listContext *farg_list();
    Function_bodyContext *function_body();
    antlr4::tree::TerminalNode *COND_SPE();
    ExternCContext *externC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_defContext* function_def();

  class  ExternCContext : public antlr4::ParserRuleContext {
  public:
    ExternCContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExternCContext* externC();

  class  Function_bodyContext : public antlr4::ParserRuleContext {
  public:
    Function_bodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_bodyContext* function_body();

  class  FargContext : public antlr4::ParserRuleContext {
  public:
    FargContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_typeContext *type_type();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FargContext* farg();

  class  F_varargsContext : public antlr4::ParserRuleContext {
  public:
    F_varargsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  F_varargsContext* f_varargs();

  class  Farg_listContext : public antlr4::ParserRuleContext {
  public:
    Farg_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FargContext *> farg();
    FargContext* farg(size_t i);
    F_varargsContext *f_varargs();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Farg_listContext* farg_list();

  class  Ret_expressionContext : public antlr4::ParserRuleContext {
  public:
    Ret_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Ret_expressionContext* ret_expression();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *opr = nullptr;
    antlr4::Token *threeOpr = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COND_NOT();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *NOT();
    PrimaryContext *primary();
    antlr4::tree::TerminalNode *POINT();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *POINTADDR();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *CMP_EQ();
    antlr4::tree::TerminalNode *CMP_NE();
    antlr4::tree::TerminalNode *CMP_GT();
    antlr4::tree::TerminalNode *CMP_GE();
    antlr4::tree::TerminalNode *CMP_LT();
    antlr4::tree::TerminalNode *CMP_LE();
    antlr4::tree::TerminalNode *COND_AND();
    antlr4::tree::TerminalNode *COND_OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  Cond_statementContext : public antlr4::ParserRuleContext {
  public:
    Cond_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    antlr4::tree::TerminalNode *COND_SPE();
    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *CONTINUE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Cond_statementContext* cond_statement();

  class  If_expressionContext : public antlr4::ParserRuleContext {
  public:
    If_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    If_condContext *if_cond();
    std::vector<Cond_statementContext *> cond_statement();
    Cond_statementContext* cond_statement(size_t i);
    std::vector<Elif_exprContext *> elif_expr();
    Elif_exprContext* elif_expr(size_t i);
    Else_exprContext *else_expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_expressionContext* if_expression();

  class  Elif_exprContext : public antlr4::ParserRuleContext {
  public:
    Elif_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ElifContext *elif();
    If_condContext *if_cond();
    std::vector<Cond_statementContext *> cond_statement();
    Cond_statementContext* cond_statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Elif_exprContext* elif_expr();

  class  Else_exprContext : public antlr4::ParserRuleContext {
  public:
    Else_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELSE();
    std::vector<Cond_statementContext *> cond_statement();
    Cond_statementContext* cond_statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Else_exprContext* else_expr();

  class  ElifContext : public antlr4::ParserRuleContext {
  public:
    ElifContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ELIF();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *IF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElifContext* elif();

  class  If_condContext : public antlr4::ParserRuleContext {
  public:
    If_condContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_expressionContext *var_expression();
    antlr4::tree::TerminalNode *COND_SPE();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_condContext* if_cond();

  class  For_expressionContext : public antlr4::ParserRuleContext {
  public:
    For_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    For_condContext *for_cond();
    std::vector<Cond_statementContext *> cond_statement();
    Cond_statementContext* cond_statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_expressionContext* for_expression();

  class  For_condContext : public antlr4::ParserRuleContext {
  public:
    For_condContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> COND_SPE();
    antlr4::tree::TerminalNode* COND_SPE(size_t i);
    Var_expressionContext *var_expression();
    AssignsContext *assigns();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_condContext* for_cond();

  class  Global_var_expressionContext : public antlr4::ParserRuleContext {
  public:
    Global_var_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declaresContext *var_declares();
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Type_typeContext *type_type();
    Class_defContext *class_def();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Global_var_expressionContext* global_var_expression();

  class  Var_expressionContext : public antlr4::ParserRuleContext {
  public:
    Var_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AssignsContext *assigns();
    Var_declaresContext *var_declares();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_expressionContext* var_expression();

  class  Paran_exprContext : public antlr4::ParserRuleContext {
  public:
    Paran_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Paran_exprContext* paran_expr();

  class  Call_exprContext : public antlr4::ParserRuleContext {
  public:
    Call_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    Expr_listContext *expr_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Call_exprContext* call_expr();

  class  Expr_listContext : public antlr4::ParserRuleContext {
  public:
    Expr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr_listContext* expr_list();

  class  Num_primaryContext : public antlr4::ParserRuleContext {
  public:
    Num_primaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *NIL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Num_primaryContext* num_primary();

  class  Str_primaryContext : public antlr4::ParserRuleContext {
  public:
    Str_primaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Str_primaryContext* str_primary();

  class  Bool_primaryContext : public antlr4::ParserRuleContext {
  public:
    Bool_primaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Bool_primaryContext* bool_primary();

  class  Value_primaryContext : public antlr4::ParserRuleContext {
  public:
    Value_primaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Num_primaryContext *num_primary();
    Bool_primaryContext *bool_primary();
    Str_primaryContext *str_primary();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Value_primaryContext* value_primary();

  class  Array_indexContext : public antlr4::ParserRuleContext {
  public:
    Array_indexContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_indexContext* array_index();

  class  Id_primary_p_addrsContext : public antlr4::ParserRuleContext {
  public:
    Id_primary_p_addrsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> POINT();
    antlr4::tree::TerminalNode* POINT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> POINTADDR();
    antlr4::tree::TerminalNode* POINTADDR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Id_primary_p_addrsContext* id_primary_p_addrs();

  class  Id_primaryContext : public antlr4::ParserRuleContext {
  public:
    Id_primaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Id_primary_p_addrsContext *id_primary_p_addrs();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Call_exprContext *call_expr();
    Paran_exprContext *paran_expr();
    std::vector<Array_indexContext *> array_index();
    Array_indexContext* array_index(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Id_primaryContext* id_primary();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Value_primaryContext *value_primary();
    Id_primaryContext *id_primary();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryContext* primary();

  class  Primary_typeContext : public antlr4::ParserRuleContext {
  public:
    Primary_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Primary_typeContext* primary_type();

  class  Array_typeContext : public antlr4::ParserRuleContext {
  public:
    Array_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_typeContext* array_type();

  class  Type_typeContext : public antlr4::ParserRuleContext {
  public:
    Type_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Primary_typeContext *primary_type();
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<antlr4::tree::TerminalNode *> POINT();
    antlr4::tree::TerminalNode* POINT(size_t i);
    std::vector<Array_typeContext *> array_type();
    Array_typeContext* array_type(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_typeContext* type_type();

  class  Type_type_voidContext : public antlr4::ParserRuleContext {
  public:
    Type_type_voidContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_typeContext *type_type();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_type_voidContext* type_type_void();

  class  Var_valueContext : public antlr4::ParserRuleContext {
  public:
    Var_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    Var_arr_valueContext *var_arr_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_valueContext* var_value();

  class  Var_arr_valueContext : public antlr4::ParserRuleContext {
  public:
    Var_arr_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Var_arr_valueContext *> var_arr_value();
    Var_arr_valueContext* var_arr_value(size_t i);
    Expr_listContext *expr_list();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_arr_valueContext* var_arr_value();

  class  AssignContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *opr = nullptr;
    AssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Id_primaryContext *id_primary();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *POINT();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *XOR();
    antlr4::tree::TerminalNode *POINTADDR();
    antlr4::tree::TerminalNode *INCREMENT();
    antlr4::tree::TerminalNode *DECREMENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignContext* assign();

  class  AssignsContext : public antlr4::ParserRuleContext {
  public:
    AssignsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AssignContext *> assign();
    AssignContext* assign(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignsContext* assigns();

  class  VarContext : public antlr4::ParserRuleContext {
  public:
    VarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    Var_valueContext *var_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarContext* var();

  class  VarsContext : public antlr4::ParserRuleContext {
  public:
    VarsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VarContext *> var();
    VarContext* var(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarsContext* vars();

  class  Var_declaresContext : public antlr4::ParserRuleContext {
  public:
    Var_declaresContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_typeContext *type_type();
    VarsContext *vars();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declaresContext* var_declares();

  class  TemplateContext : public antlr4::ParserRuleContext {
  public:
    TemplateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemplateContext* template_();

  class  Class_defContext : public antlr4::ParserRuleContext {
  public:
    Class_defContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Class_defContext* class_def();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

