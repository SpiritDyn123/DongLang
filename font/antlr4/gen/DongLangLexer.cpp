
// Generated from D:/vsprojects/DongLang/font/antlr4/DongLang.g4 by ANTLR 4.13.1


#include "DongLangLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct DongLangLexerStaticData final {
  DongLangLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  DongLangLexerStaticData(const DongLangLexerStaticData&) = delete;
  DongLangLexerStaticData(DongLangLexerStaticData&&) = delete;
  DongLangLexerStaticData& operator=(const DongLangLexerStaticData&) = delete;
  DongLangLexerStaticData& operator=(DongLangLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag donglanglexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
DongLangLexerStaticData *donglanglexerLexerStaticData = nullptr;

void donglanglexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (donglanglexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(donglanglexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<DongLangLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "FUNC", "RETURN", "VOID", "TRUE", "FALSE", "FOR", 
      "BREAK", "CONTINUE", "IF", "ELSE", "ELIF", "POINTADDR", "COND_AND", 
      "COND_OR", "COND_NOT", "POINT", "INCREMENT", "DECREMENT", "COND_SPE", 
      "NIL", "TYPE", "ADD", "SUB", "MUL", "DIV", "OR", "XOR", "NOT", "CMP_EQ", 
      "CMP_NE", "CMP_GT", "CMP_LT", "CMP_GE", "CMP_LE", "SPACE", "LINE_COMMENT", 
      "COMMENT", "IDENTIFIER", "NUMBER", "INTEGER", "ALPHA_DIGIT", "ALPHA", 
      "DIGIT", "NULL", "STRING_LITERAL", "FSTAR", "EscapeSequence", "HexDigit"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'extern'", "'C'", "'{'", "'}'", "','", "'...'", 
      "'\\u003F'", "':'", "'['", "']'", "'int'", "'string'", "'float'", 
      "'bool'", "'byte'", "'='", "'class'", "'func'", "'return'", "'void'", 
      "'true'", "'false'", "'for'", "'break'", "'continue'", "'if'", "'else'", 
      "'elif'", "'&'", "'&&'", "'||'", "'!'", "", "'++'", "'--'", "';'", 
      "'NIL'", "'type'", "'+'", "'-'", "", "'/'", "'|'", "'^'", "'~'", "'=='", 
      "'!='", "'>'", "'<'", "'>='", "'<='", "", "", "", "", "", "", "", 
      "", "", "'NULL'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "FUNC", "RETURN", "VOID", "TRUE", "FALSE", "FOR", "BREAK", 
      "CONTINUE", "IF", "ELSE", "ELIF", "POINTADDR", "COND_AND", "COND_OR", 
      "COND_NOT", "POINT", "INCREMENT", "DECREMENT", "COND_SPE", "NIL", 
      "TYPE", "ADD", "SUB", "MUL", "DIV", "OR", "XOR", "NOT", "CMP_EQ", 
      "CMP_NE", "CMP_GT", "CMP_LT", "CMP_GE", "CMP_LE", "SPACE", "LINE_COMMENT", 
      "COMMENT", "IDENTIFIER", "NUMBER", "INTEGER", "ALPHA_DIGIT", "ALPHA", 
      "DIGIT", "NULL", "STRING_LITERAL"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,64,445,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,2,66,7,66,1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,7,1,8,1,8,1,9,
  	1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,16,
  	1,16,1,16,1,16,1,16,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,19,1,19,
  	1,19,1,19,1,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,
  	1,21,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,1,23,1,24,1,24,
  	1,24,1,24,1,25,1,25,1,25,1,25,1,25,1,25,1,26,1,26,1,26,1,26,1,26,1,26,
  	1,26,1,26,1,26,1,27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,
  	1,29,1,29,1,30,1,30,1,31,1,31,1,31,1,32,1,32,1,32,1,33,1,33,1,34,1,34,
  	1,35,1,35,1,35,1,36,1,36,1,36,1,37,1,37,1,38,1,38,1,38,1,38,1,39,1,39,
  	1,39,1,39,1,39,1,40,1,40,1,41,1,41,1,42,1,42,1,43,1,43,1,44,1,44,1,45,
  	1,45,1,46,1,46,1,47,1,47,1,47,1,48,1,48,1,48,1,49,1,49,1,50,1,50,1,51,
  	1,51,1,51,1,52,1,52,1,52,1,53,4,53,322,8,53,11,53,12,53,323,1,53,1,53,
  	1,54,1,54,1,54,1,54,5,54,332,8,54,10,54,12,54,335,9,54,1,54,1,54,1,55,
  	1,55,1,55,1,55,5,55,343,8,55,10,55,12,55,346,9,55,1,55,1,55,1,55,1,55,
  	1,55,1,56,1,56,5,56,355,8,56,10,56,12,56,358,9,56,1,57,1,57,5,57,362,
  	8,57,10,57,12,57,365,9,57,1,57,3,57,368,8,57,1,57,1,57,4,57,372,8,57,
  	11,57,12,57,373,3,57,376,8,57,1,58,1,58,5,58,380,8,58,10,58,12,58,383,
  	9,58,1,59,1,59,1,59,3,59,388,8,59,1,60,1,60,1,61,1,61,1,62,1,62,1,62,
  	1,62,1,62,1,63,1,63,1,63,5,63,402,8,63,10,63,12,63,405,9,63,1,63,1,63,
  	1,63,1,63,5,63,411,8,63,10,63,12,63,414,9,63,1,63,3,63,417,8,63,1,64,
  	1,64,1,65,1,65,1,65,1,65,3,65,425,8,65,1,65,3,65,428,8,65,1,65,1,65,1,
  	65,4,65,433,8,65,11,65,12,65,434,1,65,1,65,1,65,1,65,1,65,3,65,442,8,
  	65,1,66,1,66,1,344,0,67,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,
  	21,11,23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,
  	22,45,23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,
  	67,34,69,35,71,36,73,37,75,38,77,39,79,40,81,41,83,42,85,43,87,44,89,
  	45,91,46,93,47,95,48,97,49,99,50,101,51,103,52,105,53,107,54,109,55,111,
  	56,113,57,115,58,117,59,119,60,121,61,123,62,125,63,127,64,129,0,131,
  	0,133,0,1,0,10,3,0,9,10,13,13,32,32,2,0,10,10,13,13,1,0,49,57,2,0,65,
  	90,97,122,1,0,48,57,4,0,10,10,13,13,34,34,92,92,8,0,34,34,39,39,92,92,
  	98,98,102,102,110,110,114,114,116,116,1,0,48,51,1,0,48,55,3,0,48,57,65,
  	70,97,102,462,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,
  	0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,
  	0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,
  	1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,
  	0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,
  	0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,
  	1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,
  	0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,
  	0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,
  	1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,
  	0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,0,111,1,0,0,0,0,113,1,0,0,0,0,115,1,
  	0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,0,121,1,0,0,0,0,123,1,0,0,0,0,125,1,
  	0,0,0,0,127,1,0,0,0,1,135,1,0,0,0,3,137,1,0,0,0,5,139,1,0,0,0,7,146,1,
  	0,0,0,9,148,1,0,0,0,11,150,1,0,0,0,13,152,1,0,0,0,15,154,1,0,0,0,17,158,
  	1,0,0,0,19,160,1,0,0,0,21,162,1,0,0,0,23,164,1,0,0,0,25,166,1,0,0,0,27,
  	170,1,0,0,0,29,177,1,0,0,0,31,183,1,0,0,0,33,188,1,0,0,0,35,193,1,0,0,
  	0,37,195,1,0,0,0,39,201,1,0,0,0,41,206,1,0,0,0,43,213,1,0,0,0,45,218,
  	1,0,0,0,47,223,1,0,0,0,49,229,1,0,0,0,51,233,1,0,0,0,53,239,1,0,0,0,55,
  	248,1,0,0,0,57,251,1,0,0,0,59,256,1,0,0,0,61,261,1,0,0,0,63,263,1,0,0,
  	0,65,266,1,0,0,0,67,269,1,0,0,0,69,271,1,0,0,0,71,273,1,0,0,0,73,276,
  	1,0,0,0,75,279,1,0,0,0,77,281,1,0,0,0,79,285,1,0,0,0,81,290,1,0,0,0,83,
  	292,1,0,0,0,85,294,1,0,0,0,87,296,1,0,0,0,89,298,1,0,0,0,91,300,1,0,0,
  	0,93,302,1,0,0,0,95,304,1,0,0,0,97,307,1,0,0,0,99,310,1,0,0,0,101,312,
  	1,0,0,0,103,314,1,0,0,0,105,317,1,0,0,0,107,321,1,0,0,0,109,327,1,0,0,
  	0,111,338,1,0,0,0,113,352,1,0,0,0,115,367,1,0,0,0,117,377,1,0,0,0,119,
  	387,1,0,0,0,121,389,1,0,0,0,123,391,1,0,0,0,125,393,1,0,0,0,127,416,1,
  	0,0,0,129,418,1,0,0,0,131,441,1,0,0,0,133,443,1,0,0,0,135,136,5,40,0,
  	0,136,2,1,0,0,0,137,138,5,41,0,0,138,4,1,0,0,0,139,140,5,101,0,0,140,
  	141,5,120,0,0,141,142,5,116,0,0,142,143,5,101,0,0,143,144,5,114,0,0,144,
  	145,5,110,0,0,145,6,1,0,0,0,146,147,5,67,0,0,147,8,1,0,0,0,148,149,5,
  	123,0,0,149,10,1,0,0,0,150,151,5,125,0,0,151,12,1,0,0,0,152,153,5,44,
  	0,0,153,14,1,0,0,0,154,155,5,46,0,0,155,156,5,46,0,0,156,157,5,46,0,0,
  	157,16,1,0,0,0,158,159,5,63,0,0,159,18,1,0,0,0,160,161,5,58,0,0,161,20,
  	1,0,0,0,162,163,5,91,0,0,163,22,1,0,0,0,164,165,5,93,0,0,165,24,1,0,0,
  	0,166,167,5,105,0,0,167,168,5,110,0,0,168,169,5,116,0,0,169,26,1,0,0,
  	0,170,171,5,115,0,0,171,172,5,116,0,0,172,173,5,114,0,0,173,174,5,105,
  	0,0,174,175,5,110,0,0,175,176,5,103,0,0,176,28,1,0,0,0,177,178,5,102,
  	0,0,178,179,5,108,0,0,179,180,5,111,0,0,180,181,5,97,0,0,181,182,5,116,
  	0,0,182,30,1,0,0,0,183,184,5,98,0,0,184,185,5,111,0,0,185,186,5,111,0,
  	0,186,187,5,108,0,0,187,32,1,0,0,0,188,189,5,98,0,0,189,190,5,121,0,0,
  	190,191,5,116,0,0,191,192,5,101,0,0,192,34,1,0,0,0,193,194,5,61,0,0,194,
  	36,1,0,0,0,195,196,5,99,0,0,196,197,5,108,0,0,197,198,5,97,0,0,198,199,
  	5,115,0,0,199,200,5,115,0,0,200,38,1,0,0,0,201,202,5,102,0,0,202,203,
  	5,117,0,0,203,204,5,110,0,0,204,205,5,99,0,0,205,40,1,0,0,0,206,207,5,
  	114,0,0,207,208,5,101,0,0,208,209,5,116,0,0,209,210,5,117,0,0,210,211,
  	5,114,0,0,211,212,5,110,0,0,212,42,1,0,0,0,213,214,5,118,0,0,214,215,
  	5,111,0,0,215,216,5,105,0,0,216,217,5,100,0,0,217,44,1,0,0,0,218,219,
  	5,116,0,0,219,220,5,114,0,0,220,221,5,117,0,0,221,222,5,101,0,0,222,46,
  	1,0,0,0,223,224,5,102,0,0,224,225,5,97,0,0,225,226,5,108,0,0,226,227,
  	5,115,0,0,227,228,5,101,0,0,228,48,1,0,0,0,229,230,5,102,0,0,230,231,
  	5,111,0,0,231,232,5,114,0,0,232,50,1,0,0,0,233,234,5,98,0,0,234,235,5,
  	114,0,0,235,236,5,101,0,0,236,237,5,97,0,0,237,238,5,107,0,0,238,52,1,
  	0,0,0,239,240,5,99,0,0,240,241,5,111,0,0,241,242,5,110,0,0,242,243,5,
  	116,0,0,243,244,5,105,0,0,244,245,5,110,0,0,245,246,5,117,0,0,246,247,
  	5,101,0,0,247,54,1,0,0,0,248,249,5,105,0,0,249,250,5,102,0,0,250,56,1,
  	0,0,0,251,252,5,101,0,0,252,253,5,108,0,0,253,254,5,115,0,0,254,255,5,
  	101,0,0,255,58,1,0,0,0,256,257,5,101,0,0,257,258,5,108,0,0,258,259,5,
  	105,0,0,259,260,5,102,0,0,260,60,1,0,0,0,261,262,5,38,0,0,262,62,1,0,
  	0,0,263,264,5,38,0,0,264,265,5,38,0,0,265,64,1,0,0,0,266,267,5,124,0,
  	0,267,268,5,124,0,0,268,66,1,0,0,0,269,270,5,33,0,0,270,68,1,0,0,0,271,
  	272,3,129,64,0,272,70,1,0,0,0,273,274,5,43,0,0,274,275,5,43,0,0,275,72,
  	1,0,0,0,276,277,5,45,0,0,277,278,5,45,0,0,278,74,1,0,0,0,279,280,5,59,
  	0,0,280,76,1,0,0,0,281,282,5,78,0,0,282,283,5,73,0,0,283,284,5,76,0,0,
  	284,78,1,0,0,0,285,286,5,116,0,0,286,287,5,121,0,0,287,288,5,112,0,0,
  	288,289,5,101,0,0,289,80,1,0,0,0,290,291,5,43,0,0,291,82,1,0,0,0,292,
  	293,5,45,0,0,293,84,1,0,0,0,294,295,3,69,34,0,295,86,1,0,0,0,296,297,
  	5,47,0,0,297,88,1,0,0,0,298,299,5,124,0,0,299,90,1,0,0,0,300,301,5,94,
  	0,0,301,92,1,0,0,0,302,303,5,126,0,0,303,94,1,0,0,0,304,305,5,61,0,0,
  	305,306,5,61,0,0,306,96,1,0,0,0,307,308,5,33,0,0,308,309,5,61,0,0,309,
  	98,1,0,0,0,310,311,5,62,0,0,311,100,1,0,0,0,312,313,5,60,0,0,313,102,
  	1,0,0,0,314,315,5,62,0,0,315,316,5,61,0,0,316,104,1,0,0,0,317,318,5,60,
  	0,0,318,319,5,61,0,0,319,106,1,0,0,0,320,322,7,0,0,0,321,320,1,0,0,0,
  	322,323,1,0,0,0,323,321,1,0,0,0,323,324,1,0,0,0,324,325,1,0,0,0,325,326,
  	6,53,0,0,326,108,1,0,0,0,327,328,5,47,0,0,328,329,5,47,0,0,329,333,1,
  	0,0,0,330,332,8,1,0,0,331,330,1,0,0,0,332,335,1,0,0,0,333,331,1,0,0,0,
  	333,334,1,0,0,0,334,336,1,0,0,0,335,333,1,0,0,0,336,337,6,54,1,0,337,
  	110,1,0,0,0,338,339,5,47,0,0,339,340,5,42,0,0,340,344,1,0,0,0,341,343,
  	9,0,0,0,342,341,1,0,0,0,343,346,1,0,0,0,344,345,1,0,0,0,344,342,1,0,0,
  	0,345,347,1,0,0,0,346,344,1,0,0,0,347,348,5,42,0,0,348,349,5,47,0,0,349,
  	350,1,0,0,0,350,351,6,55,1,0,351,112,1,0,0,0,352,356,3,121,60,0,353,355,
  	3,119,59,0,354,353,1,0,0,0,355,358,1,0,0,0,356,354,1,0,0,0,356,357,1,
  	0,0,0,357,114,1,0,0,0,358,356,1,0,0,0,359,363,7,2,0,0,360,362,3,123,61,
  	0,361,360,1,0,0,0,362,365,1,0,0,0,363,361,1,0,0,0,363,364,1,0,0,0,364,
  	368,1,0,0,0,365,363,1,0,0,0,366,368,5,48,0,0,367,359,1,0,0,0,367,366,
  	1,0,0,0,368,375,1,0,0,0,369,371,5,46,0,0,370,372,3,123,61,0,371,370,1,
  	0,0,0,372,373,1,0,0,0,373,371,1,0,0,0,373,374,1,0,0,0,374,376,1,0,0,0,
  	375,369,1,0,0,0,375,376,1,0,0,0,376,116,1,0,0,0,377,381,7,2,0,0,378,380,
  	3,123,61,0,379,378,1,0,0,0,380,383,1,0,0,0,381,379,1,0,0,0,381,382,1,
  	0,0,0,382,118,1,0,0,0,383,381,1,0,0,0,384,388,3,121,60,0,385,388,3,123,
  	61,0,386,388,5,95,0,0,387,384,1,0,0,0,387,385,1,0,0,0,387,386,1,0,0,0,
  	388,120,1,0,0,0,389,390,7,3,0,0,390,122,1,0,0,0,391,392,7,4,0,0,392,124,
  	1,0,0,0,393,394,5,78,0,0,394,395,5,85,0,0,395,396,5,76,0,0,396,397,5,
  	76,0,0,397,126,1,0,0,0,398,403,5,34,0,0,399,402,8,5,0,0,400,402,3,131,
  	65,0,401,399,1,0,0,0,401,400,1,0,0,0,402,405,1,0,0,0,403,401,1,0,0,0,
  	403,404,1,0,0,0,404,406,1,0,0,0,405,403,1,0,0,0,406,417,5,34,0,0,407,
  	412,5,96,0,0,408,411,8,5,0,0,409,411,3,131,65,0,410,408,1,0,0,0,410,409,
  	1,0,0,0,411,414,1,0,0,0,412,410,1,0,0,0,412,413,1,0,0,0,413,415,1,0,0,
  	0,414,412,1,0,0,0,415,417,5,96,0,0,416,398,1,0,0,0,416,407,1,0,0,0,417,
  	128,1,0,0,0,418,419,5,42,0,0,419,130,1,0,0,0,420,421,5,92,0,0,421,442,
  	7,6,0,0,422,427,5,92,0,0,423,425,7,7,0,0,424,423,1,0,0,0,424,425,1,0,
  	0,0,425,426,1,0,0,0,426,428,7,8,0,0,427,424,1,0,0,0,427,428,1,0,0,0,428,
  	429,1,0,0,0,429,442,7,8,0,0,430,432,5,92,0,0,431,433,5,117,0,0,432,431,
  	1,0,0,0,433,434,1,0,0,0,434,432,1,0,0,0,434,435,1,0,0,0,435,436,1,0,0,
  	0,436,437,3,133,66,0,437,438,3,133,66,0,438,439,3,133,66,0,439,440,3,
  	133,66,0,440,442,1,0,0,0,441,420,1,0,0,0,441,422,1,0,0,0,441,430,1,0,
  	0,0,442,132,1,0,0,0,443,444,7,9,0,0,444,134,1,0,0,0,20,0,323,333,344,
  	356,363,367,373,375,381,387,401,403,410,412,416,424,427,434,441,2,6,0,
  	0,0,1,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  donglanglexerLexerStaticData = staticData.release();
}

}

DongLangLexer::DongLangLexer(CharStream *input) : Lexer(input) {
  DongLangLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *donglanglexerLexerStaticData->atn, donglanglexerLexerStaticData->decisionToDFA, donglanglexerLexerStaticData->sharedContextCache);
}

DongLangLexer::~DongLangLexer() {
  delete _interpreter;
}

std::string DongLangLexer::getGrammarFileName() const {
  return "DongLang.g4";
}

const std::vector<std::string>& DongLangLexer::getRuleNames() const {
  return donglanglexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& DongLangLexer::getChannelNames() const {
  return donglanglexerLexerStaticData->channelNames;
}

const std::vector<std::string>& DongLangLexer::getModeNames() const {
  return donglanglexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& DongLangLexer::getVocabulary() const {
  return donglanglexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView DongLangLexer::getSerializedATN() const {
  return donglanglexerLexerStaticData->serializedATN;
}

const atn::ATN& DongLangLexer::getATN() const {
  return *donglanglexerLexerStaticData->atn;
}




void DongLangLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  donglanglexerLexerInitialize();
#else
  ::antlr4::internal::call_once(donglanglexerLexerOnceFlag, donglanglexerLexerInitialize);
#endif
}
