
// Generated from D:/studyCode/DongLang/font/antlr4/DongLang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  DongLangLexer : public antlr4::Lexer {
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

  explicit DongLangLexer(antlr4::CharStream *input);

  ~DongLangLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

