
// Generated from D:/studyCode/DongLang/font/antlr4/DongLang.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  DongLangLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, FUNC = 17, RETURN = 18, VOID = 19, TRUE = 20, 
    FALSE = 21, FOR = 22, BREAK = 23, CONTINUE = 24, IF = 25, ELSE = 26, 
    ELIF = 27, POINTADDR = 28, COND_AND = 29, COND_OR = 30, COND_NOT = 31, 
    POINT = 32, INCREMENT = 33, DECREMENT = 34, COND_SPE = 35, ADD = 36, 
    SUB = 37, MUL = 38, DIV = 39, OR = 40, XOR = 41, NOT = 42, CMP_EQ = 43, 
    CMP_NE = 44, CMP_GT = 45, CMP_LT = 46, CMP_GE = 47, CMP_LE = 48, SPACE = 49, 
    LINE_COMMENT = 50, COMMENT = 51, IDENTIFIER = 52, NUMBER = 53, ALPHA_DIGIT = 54, 
    ALPHA = 55, DIGIT = 56, NULL_ = 57, STRING_LITERAL = 58
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

