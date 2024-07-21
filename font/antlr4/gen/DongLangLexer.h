
// Generated from D:/studyCode/DongLang/font/antlr4/DongLang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  DongLangLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, FUNC = 19, RETURN = 20, 
    VOID = 21, TRUE = 22, FALSE = 23, FOR = 24, BREAK = 25, CONTINUE = 26, 
    IF = 27, ELSE = 28, ELIF = 29, POINTADDR = 30, COND_AND = 31, COND_OR = 32, 
    COND_NOT = 33, POINT = 34, INCREMENT = 35, DECREMENT = 36, COND_SPE = 37, 
    ADD = 38, SUB = 39, MUL = 40, DIV = 41, OR = 42, XOR = 43, NOT = 44, 
    CMP_EQ = 45, CMP_NE = 46, CMP_GT = 47, CMP_LT = 48, CMP_GE = 49, CMP_LE = 50, 
    SPACE = 51, LINE_COMMENT = 52, COMMENT = 53, IDENTIFIER = 54, NUMBER = 55, 
    ALPHA_DIGIT = 56, ALPHA = 57, DIGIT = 58, NULL_ = 59, STRING_LITERAL = 60
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

