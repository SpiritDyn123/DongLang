
// Generated from D:/studyCode/DongLang/font/antlr4/DongLang.g4 by ANTLR 4.13.1


#include "DongLangListener.h"
#include "DongLangVisitor.h"

#include "DongLangParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct DongLangParserStaticData final {
  DongLangParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  DongLangParserStaticData(const DongLangParserStaticData&) = delete;
  DongLangParserStaticData(DongLangParserStaticData&&) = delete;
  DongLangParserStaticData& operator=(const DongLangParserStaticData&) = delete;
  DongLangParserStaticData& operator=(DongLangParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag donglangParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
DongLangParserStaticData *donglangParserStaticData = nullptr;

void donglangParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (donglangParserStaticData != nullptr) {
    return;
  }
#else
  assert(donglangParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<DongLangParserStaticData>(
    std::vector<std::string>{
      "prog", "statement", "function_def", "externC", "function_body", "farg", 
      "f_varargs", "farg_list", "ret_expression", "expression", "cond_statement", 
      "if_expression", "elif_expr", "else_expr", "elif", "if_cond", "for_expression", 
      "for_cond", "global_var_expression", "var_expression", "paran_expr", 
      "call_expr", "expr_list", "num_primary", "str_primary", "bool_primary", 
      "value_primary", "array_index", "id_primary_p_addrs", "id_primary", 
      "primary", "primary_type", "array_type", "type_type", "type_type_void", 
      "var_value", "var_arr_value", "assign", "assigns", "var", "vars", 
      "var_declares"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'extern'", "'C'", "'{'", "'}'", "','", "'...'", 
      "'['", "']'", "'int'", "'string'", "'float'", "'bool'", "'byte'", 
      "'='", "'func'", "'return'", "'void'", "'true'", "'false'", "'for'", 
      "'break'", "'continue'", "'if'", "'else'", "'elif'", "'&'", "'&&'", 
      "'||'", "'!'", "", "'++'", "'--'", "';'", "'+'", "'-'", "", "'/'", 
      "'|'", "'^'", "'~'", "'=='", "'!='", "'>'", "'<'", "'>='", "'<='", 
      "", "", "", "", "", "", "", "", "'NULL'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "FUNC", "RETURN", "VOID", "TRUE", "FALSE", "FOR", "BREAK", "CONTINUE", 
      "IF", "ELSE", "ELIF", "POINTADDR", "COND_AND", "COND_OR", "COND_NOT", 
      "POINT", "INCREMENT", "DECREMENT", "COND_SPE", "ADD", "SUB", "MUL", 
      "DIV", "OR", "XOR", "NOT", "CMP_EQ", "CMP_NE", "CMP_GT", "CMP_LT", 
      "CMP_GE", "CMP_LE", "SPACE", "LINE_COMMENT", "COMMENT", "IDENTIFIER", 
      "NUMBER", "ALPHA_DIGIT", "ALPHA", "DIGIT", "NULL", "STRING_LITERAL"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,58,447,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,1,0,1,
  	0,1,0,1,0,5,0,89,8,0,10,0,12,0,92,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,3,1,105,8,1,1,2,3,2,108,8,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,3,2,118,8,2,1,3,1,3,1,3,1,4,1,4,5,4,125,8,4,10,4,12,4,128,9,4,1,4,1,
  	4,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,7,5,7,142,8,7,10,7,12,7,145,9,
  	7,1,7,3,7,148,8,7,3,7,150,8,7,1,8,1,8,3,8,154,8,8,1,9,1,9,1,9,1,9,1,9,
  	1,9,3,9,162,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,5,9,182,8,9,10,9,12,9,185,9,9,1,10,1,10,1,10,3,10,190,
  	8,10,1,11,1,11,1,11,1,11,1,11,1,11,5,11,198,8,11,10,11,12,11,201,9,11,
  	1,11,1,11,5,11,205,8,11,10,11,12,11,208,9,11,1,11,3,11,211,8,11,1,12,
  	1,12,1,12,1,12,1,12,1,12,5,12,219,8,12,10,12,12,12,222,9,12,1,12,1,12,
  	1,13,1,13,1,13,5,13,229,8,13,10,13,12,13,232,9,13,1,13,1,13,1,14,1,14,
  	1,14,3,14,239,8,14,1,15,3,15,242,8,15,1,15,3,15,245,8,15,1,15,3,15,248,
  	8,15,1,16,1,16,1,16,1,16,1,16,1,16,5,16,256,8,16,10,16,12,16,259,9,16,
  	1,16,1,16,1,17,1,17,3,17,265,8,17,1,17,1,17,3,17,269,8,17,1,17,1,17,3,
  	17,273,8,17,3,17,275,8,17,1,18,1,18,1,19,1,19,1,19,3,19,282,8,19,1,20,
  	1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,5,22,297,
  	8,22,10,22,12,22,300,9,22,3,22,302,8,22,1,23,3,23,305,8,23,1,23,1,23,
  	1,24,1,24,1,25,1,25,1,26,1,26,1,26,3,26,316,8,26,1,27,1,27,1,27,1,27,
  	1,28,3,28,323,8,28,1,28,1,28,3,28,327,8,28,5,28,329,8,28,10,28,12,28,
  	332,9,28,1,28,3,28,335,8,28,1,28,3,28,338,8,28,1,28,5,28,341,8,28,10,
  	28,12,28,344,9,28,3,28,346,8,28,1,29,1,29,1,29,1,29,3,29,352,8,29,1,29,
  	5,29,355,8,29,10,29,12,29,358,9,29,1,30,1,30,3,30,362,8,30,1,31,1,31,
  	1,32,1,32,3,32,368,8,32,1,32,1,32,1,33,1,33,5,33,374,8,33,10,33,12,33,
  	377,9,33,1,33,5,33,380,8,33,10,33,12,33,383,9,33,1,34,1,34,3,34,387,8,
  	34,1,35,1,35,3,35,391,8,35,1,36,1,36,1,36,1,36,5,36,397,8,36,10,36,12,
  	36,400,9,36,1,36,1,36,1,36,1,36,1,36,1,36,3,36,408,8,36,1,37,1,37,3,37,
  	412,8,37,1,37,1,37,3,37,416,8,37,1,37,1,37,1,37,3,37,421,8,37,1,38,1,
  	38,1,38,5,38,426,8,38,10,38,12,38,429,9,38,1,39,1,39,1,39,3,39,434,8,
  	39,1,40,1,40,1,40,5,40,439,8,40,10,40,12,40,442,9,40,1,41,1,41,1,41,1,
  	41,0,1,18,42,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,
  	42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,0,10,2,
  	0,32,32,39,39,1,0,36,37,2,0,28,28,40,41,1,0,43,48,1,0,23,24,1,0,20,21,
  	2,0,28,28,32,32,1,0,11,15,4,0,28,28,32,32,36,37,39,41,1,0,33,34,471,0,
  	90,1,0,0,0,2,104,1,0,0,0,4,107,1,0,0,0,6,119,1,0,0,0,8,122,1,0,0,0,10,
  	131,1,0,0,0,12,134,1,0,0,0,14,149,1,0,0,0,16,151,1,0,0,0,18,161,1,0,0,
  	0,20,189,1,0,0,0,22,191,1,0,0,0,24,212,1,0,0,0,26,225,1,0,0,0,28,238,
  	1,0,0,0,30,241,1,0,0,0,32,249,1,0,0,0,34,274,1,0,0,0,36,276,1,0,0,0,38,
  	281,1,0,0,0,40,283,1,0,0,0,42,287,1,0,0,0,44,301,1,0,0,0,46,304,1,0,0,
  	0,48,308,1,0,0,0,50,310,1,0,0,0,52,315,1,0,0,0,54,317,1,0,0,0,56,345,
  	1,0,0,0,58,347,1,0,0,0,60,361,1,0,0,0,62,363,1,0,0,0,64,365,1,0,0,0,66,
  	371,1,0,0,0,68,386,1,0,0,0,70,390,1,0,0,0,72,407,1,0,0,0,74,420,1,0,0,
  	0,76,422,1,0,0,0,78,430,1,0,0,0,80,435,1,0,0,0,82,443,1,0,0,0,84,85,3,
  	36,18,0,85,86,5,35,0,0,86,89,1,0,0,0,87,89,3,4,2,0,88,84,1,0,0,0,88,87,
  	1,0,0,0,89,92,1,0,0,0,90,88,1,0,0,0,90,91,1,0,0,0,91,1,1,0,0,0,92,90,
  	1,0,0,0,93,94,3,18,9,0,94,95,5,35,0,0,95,105,1,0,0,0,96,97,3,38,19,0,
  	97,98,5,35,0,0,98,105,1,0,0,0,99,100,3,16,8,0,100,101,5,35,0,0,101,105,
  	1,0,0,0,102,105,3,22,11,0,103,105,3,32,16,0,104,93,1,0,0,0,104,96,1,0,
  	0,0,104,99,1,0,0,0,104,102,1,0,0,0,104,103,1,0,0,0,105,3,1,0,0,0,106,
  	108,3,6,3,0,107,106,1,0,0,0,107,108,1,0,0,0,108,109,1,0,0,0,109,110,5,
  	17,0,0,110,111,3,68,34,0,111,112,5,52,0,0,112,113,5,1,0,0,113,114,3,14,
  	7,0,114,117,5,2,0,0,115,118,3,8,4,0,116,118,5,35,0,0,117,115,1,0,0,0,
  	117,116,1,0,0,0,118,5,1,0,0,0,119,120,5,3,0,0,120,121,5,4,0,0,121,7,1,
  	0,0,0,122,126,5,5,0,0,123,125,3,2,1,0,124,123,1,0,0,0,125,128,1,0,0,0,
  	126,124,1,0,0,0,126,127,1,0,0,0,127,129,1,0,0,0,128,126,1,0,0,0,129,130,
  	5,6,0,0,130,9,1,0,0,0,131,132,3,66,33,0,132,133,5,52,0,0,133,11,1,0,0,
  	0,134,135,5,7,0,0,135,136,5,8,0,0,136,13,1,0,0,0,137,150,1,0,0,0,138,
  	143,3,10,5,0,139,140,5,7,0,0,140,142,3,10,5,0,141,139,1,0,0,0,142,145,
  	1,0,0,0,143,141,1,0,0,0,143,144,1,0,0,0,144,147,1,0,0,0,145,143,1,0,0,
  	0,146,148,3,12,6,0,147,146,1,0,0,0,147,148,1,0,0,0,148,150,1,0,0,0,149,
  	137,1,0,0,0,149,138,1,0,0,0,150,15,1,0,0,0,151,153,5,18,0,0,152,154,3,
  	18,9,0,153,152,1,0,0,0,153,154,1,0,0,0,154,17,1,0,0,0,155,156,6,9,-1,
  	0,156,157,5,31,0,0,157,162,3,18,9,9,158,159,5,42,0,0,159,162,3,18,9,6,
  	160,162,3,60,30,0,161,155,1,0,0,0,161,158,1,0,0,0,161,160,1,0,0,0,162,
  	183,1,0,0,0,163,164,10,8,0,0,164,165,7,0,0,0,165,182,3,18,9,9,166,167,
  	10,7,0,0,167,168,7,1,0,0,168,182,3,18,9,8,169,170,10,5,0,0,170,171,7,
  	2,0,0,171,182,3,18,9,6,172,173,10,4,0,0,173,174,7,3,0,0,174,182,3,18,
  	9,5,175,176,10,3,0,0,176,177,5,29,0,0,177,182,3,18,9,4,178,179,10,2,0,
  	0,179,180,5,30,0,0,180,182,3,18,9,3,181,163,1,0,0,0,181,166,1,0,0,0,181,
  	169,1,0,0,0,181,172,1,0,0,0,181,175,1,0,0,0,181,178,1,0,0,0,182,185,1,
  	0,0,0,183,181,1,0,0,0,183,184,1,0,0,0,184,19,1,0,0,0,185,183,1,0,0,0,
  	186,190,3,2,1,0,187,188,7,4,0,0,188,190,5,35,0,0,189,186,1,0,0,0,189,
  	187,1,0,0,0,190,21,1,0,0,0,191,192,5,25,0,0,192,193,5,1,0,0,193,194,3,
  	30,15,0,194,195,5,2,0,0,195,199,5,5,0,0,196,198,3,20,10,0,197,196,1,0,
  	0,0,198,201,1,0,0,0,199,197,1,0,0,0,199,200,1,0,0,0,200,202,1,0,0,0,201,
  	199,1,0,0,0,202,206,5,6,0,0,203,205,3,24,12,0,204,203,1,0,0,0,205,208,
  	1,0,0,0,206,204,1,0,0,0,206,207,1,0,0,0,207,210,1,0,0,0,208,206,1,0,0,
  	0,209,211,3,26,13,0,210,209,1,0,0,0,210,211,1,0,0,0,211,23,1,0,0,0,212,
  	213,3,28,14,0,213,214,5,1,0,0,214,215,3,30,15,0,215,216,5,2,0,0,216,220,
  	5,5,0,0,217,219,3,20,10,0,218,217,1,0,0,0,219,222,1,0,0,0,220,218,1,0,
  	0,0,220,221,1,0,0,0,221,223,1,0,0,0,222,220,1,0,0,0,223,224,5,6,0,0,224,
  	25,1,0,0,0,225,226,5,26,0,0,226,230,5,5,0,0,227,229,3,20,10,0,228,227,
  	1,0,0,0,229,232,1,0,0,0,230,228,1,0,0,0,230,231,1,0,0,0,231,233,1,0,0,
  	0,232,230,1,0,0,0,233,234,5,6,0,0,234,27,1,0,0,0,235,239,5,27,0,0,236,
  	237,5,26,0,0,237,239,5,25,0,0,238,235,1,0,0,0,238,236,1,0,0,0,239,29,
  	1,0,0,0,240,242,3,38,19,0,241,240,1,0,0,0,241,242,1,0,0,0,242,244,1,0,
  	0,0,243,245,5,35,0,0,244,243,1,0,0,0,244,245,1,0,0,0,245,247,1,0,0,0,
  	246,248,3,18,9,0,247,246,1,0,0,0,247,248,1,0,0,0,248,31,1,0,0,0,249,250,
  	5,22,0,0,250,251,5,1,0,0,251,252,3,34,17,0,252,253,5,2,0,0,253,257,5,
  	5,0,0,254,256,3,20,10,0,255,254,1,0,0,0,256,259,1,0,0,0,257,255,1,0,0,
  	0,257,258,1,0,0,0,258,260,1,0,0,0,259,257,1,0,0,0,260,261,5,6,0,0,261,
  	33,1,0,0,0,262,275,3,18,9,0,263,265,3,38,19,0,264,263,1,0,0,0,264,265,
  	1,0,0,0,265,266,1,0,0,0,266,268,5,35,0,0,267,269,3,18,9,0,268,267,1,0,
  	0,0,268,269,1,0,0,0,269,270,1,0,0,0,270,272,5,35,0,0,271,273,3,76,38,
  	0,272,271,1,0,0,0,272,273,1,0,0,0,273,275,1,0,0,0,274,262,1,0,0,0,274,
  	264,1,0,0,0,275,35,1,0,0,0,276,277,3,82,41,0,277,37,1,0,0,0,278,282,3,
  	80,40,0,279,282,3,76,38,0,280,282,3,82,41,0,281,278,1,0,0,0,281,279,1,
  	0,0,0,281,280,1,0,0,0,282,39,1,0,0,0,283,284,5,1,0,0,284,285,3,18,9,0,
  	285,286,5,2,0,0,286,41,1,0,0,0,287,288,5,52,0,0,288,289,5,1,0,0,289,290,
  	3,44,22,0,290,291,5,2,0,0,291,43,1,0,0,0,292,302,1,0,0,0,293,298,3,18,
  	9,0,294,295,5,7,0,0,295,297,3,18,9,0,296,294,1,0,0,0,297,300,1,0,0,0,
  	298,296,1,0,0,0,298,299,1,0,0,0,299,302,1,0,0,0,300,298,1,0,0,0,301,292,
  	1,0,0,0,301,293,1,0,0,0,302,45,1,0,0,0,303,305,5,37,0,0,304,303,1,0,0,
  	0,304,305,1,0,0,0,305,306,1,0,0,0,306,307,5,53,0,0,307,47,1,0,0,0,308,
  	309,5,58,0,0,309,49,1,0,0,0,310,311,7,5,0,0,311,51,1,0,0,0,312,316,3,
  	46,23,0,313,316,3,50,25,0,314,316,3,48,24,0,315,312,1,0,0,0,315,313,1,
  	0,0,0,315,314,1,0,0,0,316,53,1,0,0,0,317,318,5,9,0,0,318,319,3,18,9,0,
  	319,320,5,10,0,0,320,55,1,0,0,0,321,323,7,6,0,0,322,321,1,0,0,0,322,323,
  	1,0,0,0,323,330,1,0,0,0,324,326,5,32,0,0,325,327,5,28,0,0,326,325,1,0,
  	0,0,326,327,1,0,0,0,327,329,1,0,0,0,328,324,1,0,0,0,329,332,1,0,0,0,330,
  	328,1,0,0,0,330,331,1,0,0,0,331,346,1,0,0,0,332,330,1,0,0,0,333,335,5,
  	32,0,0,334,333,1,0,0,0,334,335,1,0,0,0,335,342,1,0,0,0,336,338,5,28,0,
  	0,337,336,1,0,0,0,337,338,1,0,0,0,338,339,1,0,0,0,339,341,5,32,0,0,340,
  	337,1,0,0,0,341,344,1,0,0,0,342,340,1,0,0,0,342,343,1,0,0,0,343,346,1,
  	0,0,0,344,342,1,0,0,0,345,322,1,0,0,0,345,334,1,0,0,0,346,57,1,0,0,0,
  	347,351,3,56,28,0,348,352,5,52,0,0,349,352,3,42,21,0,350,352,3,40,20,
  	0,351,348,1,0,0,0,351,349,1,0,0,0,351,350,1,0,0,0,352,356,1,0,0,0,353,
  	355,3,54,27,0,354,353,1,0,0,0,355,358,1,0,0,0,356,354,1,0,0,0,356,357,
  	1,0,0,0,357,59,1,0,0,0,358,356,1,0,0,0,359,362,3,52,26,0,360,362,3,58,
  	29,0,361,359,1,0,0,0,361,360,1,0,0,0,362,61,1,0,0,0,363,364,7,7,0,0,364,
  	63,1,0,0,0,365,367,5,9,0,0,366,368,5,53,0,0,367,366,1,0,0,0,367,368,1,
  	0,0,0,368,369,1,0,0,0,369,370,5,10,0,0,370,65,1,0,0,0,371,375,3,62,31,
  	0,372,374,5,32,0,0,373,372,1,0,0,0,374,377,1,0,0,0,375,373,1,0,0,0,375,
  	376,1,0,0,0,376,381,1,0,0,0,377,375,1,0,0,0,378,380,3,64,32,0,379,378,
  	1,0,0,0,380,383,1,0,0,0,381,379,1,0,0,0,381,382,1,0,0,0,382,67,1,0,0,
  	0,383,381,1,0,0,0,384,387,3,66,33,0,385,387,5,19,0,0,386,384,1,0,0,0,
  	386,385,1,0,0,0,387,69,1,0,0,0,388,391,3,18,9,0,389,391,3,72,36,0,390,
  	388,1,0,0,0,390,389,1,0,0,0,391,71,1,0,0,0,392,393,5,5,0,0,393,398,3,
  	72,36,0,394,395,5,7,0,0,395,397,3,72,36,0,396,394,1,0,0,0,397,400,1,0,
  	0,0,398,396,1,0,0,0,398,399,1,0,0,0,399,401,1,0,0,0,400,398,1,0,0,0,401,
  	402,5,6,0,0,402,408,1,0,0,0,403,404,5,5,0,0,404,405,3,44,22,0,405,406,
  	5,6,0,0,406,408,1,0,0,0,407,392,1,0,0,0,407,403,1,0,0,0,408,73,1,0,0,
  	0,409,415,3,58,29,0,410,412,7,8,0,0,411,410,1,0,0,0,411,412,1,0,0,0,412,
  	413,1,0,0,0,413,414,5,16,0,0,414,416,3,18,9,0,415,411,1,0,0,0,415,416,
  	1,0,0,0,416,421,1,0,0,0,417,418,3,58,29,0,418,419,7,9,0,0,419,421,1,0,
  	0,0,420,409,1,0,0,0,420,417,1,0,0,0,421,75,1,0,0,0,422,427,3,74,37,0,
  	423,424,5,7,0,0,424,426,3,74,37,0,425,423,1,0,0,0,426,429,1,0,0,0,427,
  	425,1,0,0,0,427,428,1,0,0,0,428,77,1,0,0,0,429,427,1,0,0,0,430,433,5,
  	52,0,0,431,432,5,16,0,0,432,434,3,70,35,0,433,431,1,0,0,0,433,434,1,0,
  	0,0,434,79,1,0,0,0,435,440,3,78,39,0,436,437,5,7,0,0,437,439,3,78,39,
  	0,438,436,1,0,0,0,439,442,1,0,0,0,440,438,1,0,0,0,440,441,1,0,0,0,441,
  	81,1,0,0,0,442,440,1,0,0,0,443,444,3,66,33,0,444,445,3,80,40,0,445,83,
  	1,0,0,0,56,88,90,104,107,117,126,143,147,149,153,161,181,183,189,199,
  	206,210,220,230,238,241,244,247,257,264,268,272,274,281,298,301,304,315,
  	322,326,330,334,337,342,345,351,356,361,367,375,381,386,390,398,407,411,
  	415,420,427,433,440
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  donglangParserStaticData = staticData.release();
}

}

DongLangParser::DongLangParser(TokenStream *input) : DongLangParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

DongLangParser::DongLangParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  DongLangParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *donglangParserStaticData->atn, donglangParserStaticData->decisionToDFA, donglangParserStaticData->sharedContextCache, options);
}

DongLangParser::~DongLangParser() {
  delete _interpreter;
}

const atn::ATN& DongLangParser::getATN() const {
  return *donglangParserStaticData->atn;
}

std::string DongLangParser::getGrammarFileName() const {
  return "DongLang.g4";
}

const std::vector<std::string>& DongLangParser::getRuleNames() const {
  return donglangParserStaticData->ruleNames;
}

const dfa::Vocabulary& DongLangParser::getVocabulary() const {
  return donglangParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView DongLangParser::getSerializedATN() const {
  return donglangParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

DongLangParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DongLangParser::Global_var_expressionContext *> DongLangParser::ProgContext::global_var_expression() {
  return getRuleContexts<DongLangParser::Global_var_expressionContext>();
}

DongLangParser::Global_var_expressionContext* DongLangParser::ProgContext::global_var_expression(size_t i) {
  return getRuleContext<DongLangParser::Global_var_expressionContext>(i);
}

std::vector<tree::TerminalNode *> DongLangParser::ProgContext::COND_SPE() {
  return getTokens(DongLangParser::COND_SPE);
}

tree::TerminalNode* DongLangParser::ProgContext::COND_SPE(size_t i) {
  return getToken(DongLangParser::COND_SPE, i);
}

std::vector<DongLangParser::Function_defContext *> DongLangParser::ProgContext::function_def() {
  return getRuleContexts<DongLangParser::Function_defContext>();
}

DongLangParser::Function_defContext* DongLangParser::ProgContext::function_def(size_t i) {
  return getRuleContext<DongLangParser::Function_defContext>(i);
}


size_t DongLangParser::ProgContext::getRuleIndex() const {
  return DongLangParser::RuleProg;
}

void DongLangParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void DongLangParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


std::any DongLangParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::ProgContext* DongLangParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, DongLangParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 194568) != 0)) {
      setState(88);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DongLangParser::T__10:
        case DongLangParser::T__11:
        case DongLangParser::T__12:
        case DongLangParser::T__13:
        case DongLangParser::T__14: {
          setState(84);
          global_var_expression();
          setState(85);
          match(DongLangParser::COND_SPE);
          break;
        }

        case DongLangParser::T__2:
        case DongLangParser::FUNC: {
          setState(87);
          function_def();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

DongLangParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::ExpressionContext* DongLangParser::StatementContext::expression() {
  return getRuleContext<DongLangParser::ExpressionContext>(0);
}

tree::TerminalNode* DongLangParser::StatementContext::COND_SPE() {
  return getToken(DongLangParser::COND_SPE, 0);
}

DongLangParser::Var_expressionContext* DongLangParser::StatementContext::var_expression() {
  return getRuleContext<DongLangParser::Var_expressionContext>(0);
}

DongLangParser::Ret_expressionContext* DongLangParser::StatementContext::ret_expression() {
  return getRuleContext<DongLangParser::Ret_expressionContext>(0);
}

DongLangParser::If_expressionContext* DongLangParser::StatementContext::if_expression() {
  return getRuleContext<DongLangParser::If_expressionContext>(0);
}

DongLangParser::For_expressionContext* DongLangParser::StatementContext::for_expression() {
  return getRuleContext<DongLangParser::For_expressionContext>(0);
}


size_t DongLangParser::StatementContext::getRuleIndex() const {
  return DongLangParser::RuleStatement;
}

void DongLangParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void DongLangParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any DongLangParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::StatementContext* DongLangParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, DongLangParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(104);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      expression(0);
      setState(94);
      match(DongLangParser::COND_SPE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(96);
      var_expression();
      setState(97);
      match(DongLangParser::COND_SPE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(99);
      ret_expression();
      setState(100);
      match(DongLangParser::COND_SPE);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(102);
      if_expression();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(103);
      for_expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_defContext ------------------------------------------------------------------

DongLangParser::Function_defContext::Function_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::Function_defContext::FUNC() {
  return getToken(DongLangParser::FUNC, 0);
}

DongLangParser::Type_type_voidContext* DongLangParser::Function_defContext::type_type_void() {
  return getRuleContext<DongLangParser::Type_type_voidContext>(0);
}

tree::TerminalNode* DongLangParser::Function_defContext::IDENTIFIER() {
  return getToken(DongLangParser::IDENTIFIER, 0);
}

DongLangParser::Farg_listContext* DongLangParser::Function_defContext::farg_list() {
  return getRuleContext<DongLangParser::Farg_listContext>(0);
}

DongLangParser::Function_bodyContext* DongLangParser::Function_defContext::function_body() {
  return getRuleContext<DongLangParser::Function_bodyContext>(0);
}

tree::TerminalNode* DongLangParser::Function_defContext::COND_SPE() {
  return getToken(DongLangParser::COND_SPE, 0);
}

DongLangParser::ExternCContext* DongLangParser::Function_defContext::externC() {
  return getRuleContext<DongLangParser::ExternCContext>(0);
}


size_t DongLangParser::Function_defContext::getRuleIndex() const {
  return DongLangParser::RuleFunction_def;
}

void DongLangParser::Function_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_def(this);
}

void DongLangParser::Function_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_def(this);
}


std::any DongLangParser::Function_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitFunction_def(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Function_defContext* DongLangParser::function_def() {
  Function_defContext *_localctx = _tracker.createInstance<Function_defContext>(_ctx, getState());
  enterRule(_localctx, 4, DongLangParser::RuleFunction_def);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::T__2) {
      setState(106);
      externC();
    }
    setState(109);
    match(DongLangParser::FUNC);
    setState(110);
    type_type_void();
    setState(111);
    match(DongLangParser::IDENTIFIER);
    setState(112);
    match(DongLangParser::T__0);
    setState(113);
    farg_list();
    setState(114);
    match(DongLangParser::T__1);
    setState(117);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__4: {
        setState(115);
        function_body();
        break;
      }

      case DongLangParser::COND_SPE: {
        setState(116);
        match(DongLangParser::COND_SPE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternCContext ------------------------------------------------------------------

DongLangParser::ExternCContext::ExternCContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DongLangParser::ExternCContext::getRuleIndex() const {
  return DongLangParser::RuleExternC;
}

void DongLangParser::ExternCContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternC(this);
}

void DongLangParser::ExternCContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternC(this);
}


std::any DongLangParser::ExternCContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitExternC(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::ExternCContext* DongLangParser::externC() {
  ExternCContext *_localctx = _tracker.createInstance<ExternCContext>(_ctx, getState());
  enterRule(_localctx, 6, DongLangParser::RuleExternC);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    match(DongLangParser::T__2);
    setState(120);
    match(DongLangParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_bodyContext ------------------------------------------------------------------

DongLangParser::Function_bodyContext::Function_bodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DongLangParser::StatementContext *> DongLangParser::Function_bodyContext::statement() {
  return getRuleContexts<DongLangParser::StatementContext>();
}

DongLangParser::StatementContext* DongLangParser::Function_bodyContext::statement(size_t i) {
  return getRuleContext<DongLangParser::StatementContext>(i);
}


size_t DongLangParser::Function_bodyContext::getRuleIndex() const {
  return DongLangParser::RuleFunction_body;
}

void DongLangParser::Function_bodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_body(this);
}

void DongLangParser::Function_bodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_body(this);
}


std::any DongLangParser::Function_bodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitFunction_body(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Function_bodyContext* DongLangParser::function_body() {
  Function_bodyContext *_localctx = _tracker.createInstance<Function_bodyContext>(_ctx, getState());
  enterRule(_localctx, 8, DongLangParser::RuleFunction_body);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(DongLangParser::T__4);
    setState(126);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 301745717271394306) != 0)) {
      setState(123);
      statement();
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(129);
    match(DongLangParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FargContext ------------------------------------------------------------------

DongLangParser::FargContext::FargContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::Type_typeContext* DongLangParser::FargContext::type_type() {
  return getRuleContext<DongLangParser::Type_typeContext>(0);
}

tree::TerminalNode* DongLangParser::FargContext::IDENTIFIER() {
  return getToken(DongLangParser::IDENTIFIER, 0);
}


size_t DongLangParser::FargContext::getRuleIndex() const {
  return DongLangParser::RuleFarg;
}

void DongLangParser::FargContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFarg(this);
}

void DongLangParser::FargContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFarg(this);
}


std::any DongLangParser::FargContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitFarg(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::FargContext* DongLangParser::farg() {
  FargContext *_localctx = _tracker.createInstance<FargContext>(_ctx, getState());
  enterRule(_localctx, 10, DongLangParser::RuleFarg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    type_type();
    setState(132);
    match(DongLangParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- F_varargsContext ------------------------------------------------------------------

DongLangParser::F_varargsContext::F_varargsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DongLangParser::F_varargsContext::getRuleIndex() const {
  return DongLangParser::RuleF_varargs;
}

void DongLangParser::F_varargsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterF_varargs(this);
}

void DongLangParser::F_varargsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitF_varargs(this);
}


std::any DongLangParser::F_varargsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitF_varargs(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::F_varargsContext* DongLangParser::f_varargs() {
  F_varargsContext *_localctx = _tracker.createInstance<F_varargsContext>(_ctx, getState());
  enterRule(_localctx, 12, DongLangParser::RuleF_varargs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    match(DongLangParser::T__6);
    setState(135);
    match(DongLangParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Farg_listContext ------------------------------------------------------------------

DongLangParser::Farg_listContext::Farg_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DongLangParser::FargContext *> DongLangParser::Farg_listContext::farg() {
  return getRuleContexts<DongLangParser::FargContext>();
}

DongLangParser::FargContext* DongLangParser::Farg_listContext::farg(size_t i) {
  return getRuleContext<DongLangParser::FargContext>(i);
}

DongLangParser::F_varargsContext* DongLangParser::Farg_listContext::f_varargs() {
  return getRuleContext<DongLangParser::F_varargsContext>(0);
}


size_t DongLangParser::Farg_listContext::getRuleIndex() const {
  return DongLangParser::RuleFarg_list;
}

void DongLangParser::Farg_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFarg_list(this);
}

void DongLangParser::Farg_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFarg_list(this);
}


std::any DongLangParser::Farg_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitFarg_list(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Farg_listContext* DongLangParser::farg_list() {
  Farg_listContext *_localctx = _tracker.createInstance<Farg_listContext>(_ctx, getState());
  enterRule(_localctx, 14, DongLangParser::RuleFarg_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__1: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case DongLangParser::T__10:
      case DongLangParser::T__11:
      case DongLangParser::T__12:
      case DongLangParser::T__13:
      case DongLangParser::T__14: {
        enterOuterAlt(_localctx, 2);
        setState(138);
        farg();
        setState(143);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(139);
            match(DongLangParser::T__6);
            setState(140);
            farg(); 
          }
          setState(145);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
        }
        setState(147);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DongLangParser::T__6) {
          setState(146);
          f_varargs();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ret_expressionContext ------------------------------------------------------------------

DongLangParser::Ret_expressionContext::Ret_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::Ret_expressionContext::RETURN() {
  return getToken(DongLangParser::RETURN, 0);
}

DongLangParser::ExpressionContext* DongLangParser::Ret_expressionContext::expression() {
  return getRuleContext<DongLangParser::ExpressionContext>(0);
}


size_t DongLangParser::Ret_expressionContext::getRuleIndex() const {
  return DongLangParser::RuleRet_expression;
}

void DongLangParser::Ret_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRet_expression(this);
}

void DongLangParser::Ret_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRet_expression(this);
}


std::any DongLangParser::Ret_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitRet_expression(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Ret_expressionContext* DongLangParser::ret_expression() {
  Ret_expressionContext *_localctx = _tracker.createInstance<Ret_expressionContext>(_ctx, getState());
  enterRule(_localctx, 16, DongLangParser::RuleRet_expression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(DongLangParser::RETURN);
    setState(153);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 301745717233319938) != 0)) {
      setState(152);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

DongLangParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::ExpressionContext::COND_NOT() {
  return getToken(DongLangParser::COND_NOT, 0);
}

std::vector<DongLangParser::ExpressionContext *> DongLangParser::ExpressionContext::expression() {
  return getRuleContexts<DongLangParser::ExpressionContext>();
}

DongLangParser::ExpressionContext* DongLangParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<DongLangParser::ExpressionContext>(i);
}

tree::TerminalNode* DongLangParser::ExpressionContext::NOT() {
  return getToken(DongLangParser::NOT, 0);
}

DongLangParser::PrimaryContext* DongLangParser::ExpressionContext::primary() {
  return getRuleContext<DongLangParser::PrimaryContext>(0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::POINT() {
  return getToken(DongLangParser::POINT, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::DIV() {
  return getToken(DongLangParser::DIV, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::ADD() {
  return getToken(DongLangParser::ADD, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::SUB() {
  return getToken(DongLangParser::SUB, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::POINTADDR() {
  return getToken(DongLangParser::POINTADDR, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::OR() {
  return getToken(DongLangParser::OR, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::XOR() {
  return getToken(DongLangParser::XOR, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::CMP_EQ() {
  return getToken(DongLangParser::CMP_EQ, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::CMP_NE() {
  return getToken(DongLangParser::CMP_NE, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::CMP_GT() {
  return getToken(DongLangParser::CMP_GT, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::CMP_GE() {
  return getToken(DongLangParser::CMP_GE, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::CMP_LT() {
  return getToken(DongLangParser::CMP_LT, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::CMP_LE() {
  return getToken(DongLangParser::CMP_LE, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::COND_AND() {
  return getToken(DongLangParser::COND_AND, 0);
}

tree::TerminalNode* DongLangParser::ExpressionContext::COND_OR() {
  return getToken(DongLangParser::COND_OR, 0);
}


size_t DongLangParser::ExpressionContext::getRuleIndex() const {
  return DongLangParser::RuleExpression;
}

void DongLangParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void DongLangParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


std::any DongLangParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}


DongLangParser::ExpressionContext* DongLangParser::expression() {
   return expression(0);
}

DongLangParser::ExpressionContext* DongLangParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  DongLangParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  DongLangParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, DongLangParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(161);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::COND_NOT: {
        setState(156);
        match(DongLangParser::COND_NOT);
        setState(157);
        expression(9);
        break;
      }

      case DongLangParser::NOT: {
        setState(158);
        match(DongLangParser::NOT);
        setState(159);
        expression(6);
        break;
      }

      case DongLangParser::T__0:
      case DongLangParser::TRUE:
      case DongLangParser::FALSE:
      case DongLangParser::POINTADDR:
      case DongLangParser::POINT:
      case DongLangParser::SUB:
      case DongLangParser::IDENTIFIER:
      case DongLangParser::NUMBER:
      case DongLangParser::STRING_LITERAL: {
        setState(160);
        primary();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(183);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(181);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(163);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(164);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == DongLangParser::POINT

          || _la == DongLangParser::DIV)) {
            antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(165);
          expression(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(166);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(167);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == DongLangParser::ADD

          || _la == DongLangParser::SUB)) {
            antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(168);
          expression(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(169);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(170);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 3298803318784) != 0))) {
            antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(171);
          expression(6);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(172);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(173);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 554153860399104) != 0))) {
            antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(174);
          expression(5);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(175);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(176);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = match(DongLangParser::COND_AND);
          setState(177);
          expression(4);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(178);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(179);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = match(DongLangParser::COND_OR);
          setState(180);
          expression(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(185);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Cond_statementContext ------------------------------------------------------------------

DongLangParser::Cond_statementContext::Cond_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::StatementContext* DongLangParser::Cond_statementContext::statement() {
  return getRuleContext<DongLangParser::StatementContext>(0);
}

tree::TerminalNode* DongLangParser::Cond_statementContext::COND_SPE() {
  return getToken(DongLangParser::COND_SPE, 0);
}

tree::TerminalNode* DongLangParser::Cond_statementContext::BREAK() {
  return getToken(DongLangParser::BREAK, 0);
}

tree::TerminalNode* DongLangParser::Cond_statementContext::CONTINUE() {
  return getToken(DongLangParser::CONTINUE, 0);
}


size_t DongLangParser::Cond_statementContext::getRuleIndex() const {
  return DongLangParser::RuleCond_statement;
}

void DongLangParser::Cond_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond_statement(this);
}

void DongLangParser::Cond_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond_statement(this);
}


std::any DongLangParser::Cond_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitCond_statement(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Cond_statementContext* DongLangParser::cond_statement() {
  Cond_statementContext *_localctx = _tracker.createInstance<Cond_statementContext>(_ctx, getState());
  enterRule(_localctx, 20, DongLangParser::RuleCond_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(189);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__0:
      case DongLangParser::T__10:
      case DongLangParser::T__11:
      case DongLangParser::T__12:
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::RETURN:
      case DongLangParser::TRUE:
      case DongLangParser::FALSE:
      case DongLangParser::FOR:
      case DongLangParser::IF:
      case DongLangParser::POINTADDR:
      case DongLangParser::COND_NOT:
      case DongLangParser::POINT:
      case DongLangParser::SUB:
      case DongLangParser::NOT:
      case DongLangParser::IDENTIFIER:
      case DongLangParser::NUMBER:
      case DongLangParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(186);
        statement();
        break;
      }

      case DongLangParser::BREAK:
      case DongLangParser::CONTINUE: {
        enterOuterAlt(_localctx, 2);
        setState(187);
        _la = _input->LA(1);
        if (!(_la == DongLangParser::BREAK

        || _la == DongLangParser::CONTINUE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(188);
        match(DongLangParser::COND_SPE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_expressionContext ------------------------------------------------------------------

DongLangParser::If_expressionContext::If_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::If_expressionContext::IF() {
  return getToken(DongLangParser::IF, 0);
}

DongLangParser::If_condContext* DongLangParser::If_expressionContext::if_cond() {
  return getRuleContext<DongLangParser::If_condContext>(0);
}

std::vector<DongLangParser::Cond_statementContext *> DongLangParser::If_expressionContext::cond_statement() {
  return getRuleContexts<DongLangParser::Cond_statementContext>();
}

DongLangParser::Cond_statementContext* DongLangParser::If_expressionContext::cond_statement(size_t i) {
  return getRuleContext<DongLangParser::Cond_statementContext>(i);
}

std::vector<DongLangParser::Elif_exprContext *> DongLangParser::If_expressionContext::elif_expr() {
  return getRuleContexts<DongLangParser::Elif_exprContext>();
}

DongLangParser::Elif_exprContext* DongLangParser::If_expressionContext::elif_expr(size_t i) {
  return getRuleContext<DongLangParser::Elif_exprContext>(i);
}

DongLangParser::Else_exprContext* DongLangParser::If_expressionContext::else_expr() {
  return getRuleContext<DongLangParser::Else_exprContext>(0);
}


size_t DongLangParser::If_expressionContext::getRuleIndex() const {
  return DongLangParser::RuleIf_expression;
}

void DongLangParser::If_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_expression(this);
}

void DongLangParser::If_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_expression(this);
}


std::any DongLangParser::If_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitIf_expression(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::If_expressionContext* DongLangParser::if_expression() {
  If_expressionContext *_localctx = _tracker.createInstance<If_expressionContext>(_ctx, getState());
  enterRule(_localctx, 22, DongLangParser::RuleIf_expression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(DongLangParser::IF);
    setState(192);
    match(DongLangParser::T__0);
    setState(193);
    if_cond();
    setState(194);
    match(DongLangParser::T__1);
    setState(195);
    match(DongLangParser::T__4);
    setState(199);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 301745717296560130) != 0)) {
      setState(196);
      cond_statement();
      setState(201);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(202);
    match(DongLangParser::T__5);
    setState(206);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(203);
        elif_expr(); 
      }
      setState(208);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
    setState(210);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::ELSE) {
      setState(209);
      else_expr();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Elif_exprContext ------------------------------------------------------------------

DongLangParser::Elif_exprContext::Elif_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::ElifContext* DongLangParser::Elif_exprContext::elif() {
  return getRuleContext<DongLangParser::ElifContext>(0);
}

DongLangParser::If_condContext* DongLangParser::Elif_exprContext::if_cond() {
  return getRuleContext<DongLangParser::If_condContext>(0);
}

std::vector<DongLangParser::Cond_statementContext *> DongLangParser::Elif_exprContext::cond_statement() {
  return getRuleContexts<DongLangParser::Cond_statementContext>();
}

DongLangParser::Cond_statementContext* DongLangParser::Elif_exprContext::cond_statement(size_t i) {
  return getRuleContext<DongLangParser::Cond_statementContext>(i);
}


size_t DongLangParser::Elif_exprContext::getRuleIndex() const {
  return DongLangParser::RuleElif_expr;
}

void DongLangParser::Elif_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElif_expr(this);
}

void DongLangParser::Elif_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElif_expr(this);
}


std::any DongLangParser::Elif_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitElif_expr(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Elif_exprContext* DongLangParser::elif_expr() {
  Elif_exprContext *_localctx = _tracker.createInstance<Elif_exprContext>(_ctx, getState());
  enterRule(_localctx, 24, DongLangParser::RuleElif_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    elif();
    setState(213);
    match(DongLangParser::T__0);
    setState(214);
    if_cond();
    setState(215);
    match(DongLangParser::T__1);
    setState(216);
    match(DongLangParser::T__4);
    setState(220);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 301745717296560130) != 0)) {
      setState(217);
      cond_statement();
      setState(222);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(223);
    match(DongLangParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_exprContext ------------------------------------------------------------------

DongLangParser::Else_exprContext::Else_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::Else_exprContext::ELSE() {
  return getToken(DongLangParser::ELSE, 0);
}

std::vector<DongLangParser::Cond_statementContext *> DongLangParser::Else_exprContext::cond_statement() {
  return getRuleContexts<DongLangParser::Cond_statementContext>();
}

DongLangParser::Cond_statementContext* DongLangParser::Else_exprContext::cond_statement(size_t i) {
  return getRuleContext<DongLangParser::Cond_statementContext>(i);
}


size_t DongLangParser::Else_exprContext::getRuleIndex() const {
  return DongLangParser::RuleElse_expr;
}

void DongLangParser::Else_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElse_expr(this);
}

void DongLangParser::Else_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElse_expr(this);
}


std::any DongLangParser::Else_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitElse_expr(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Else_exprContext* DongLangParser::else_expr() {
  Else_exprContext *_localctx = _tracker.createInstance<Else_exprContext>(_ctx, getState());
  enterRule(_localctx, 26, DongLangParser::RuleElse_expr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    match(DongLangParser::ELSE);
    setState(226);
    match(DongLangParser::T__4);
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 301745717296560130) != 0)) {
      setState(227);
      cond_statement();
      setState(232);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(233);
    match(DongLangParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElifContext ------------------------------------------------------------------

DongLangParser::ElifContext::ElifContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::ElifContext::ELIF() {
  return getToken(DongLangParser::ELIF, 0);
}

tree::TerminalNode* DongLangParser::ElifContext::ELSE() {
  return getToken(DongLangParser::ELSE, 0);
}

tree::TerminalNode* DongLangParser::ElifContext::IF() {
  return getToken(DongLangParser::IF, 0);
}


size_t DongLangParser::ElifContext::getRuleIndex() const {
  return DongLangParser::RuleElif;
}

void DongLangParser::ElifContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElif(this);
}

void DongLangParser::ElifContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElif(this);
}


std::any DongLangParser::ElifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitElif(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::ElifContext* DongLangParser::elif() {
  ElifContext *_localctx = _tracker.createInstance<ElifContext>(_ctx, getState());
  enterRule(_localctx, 28, DongLangParser::RuleElif);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(238);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::ELIF: {
        enterOuterAlt(_localctx, 1);
        setState(235);
        match(DongLangParser::ELIF);
        break;
      }

      case DongLangParser::ELSE: {
        enterOuterAlt(_localctx, 2);
        setState(236);
        match(DongLangParser::ELSE);
        setState(237);
        match(DongLangParser::IF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_condContext ------------------------------------------------------------------

DongLangParser::If_condContext::If_condContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::Var_expressionContext* DongLangParser::If_condContext::var_expression() {
  return getRuleContext<DongLangParser::Var_expressionContext>(0);
}

tree::TerminalNode* DongLangParser::If_condContext::COND_SPE() {
  return getToken(DongLangParser::COND_SPE, 0);
}

DongLangParser::ExpressionContext* DongLangParser::If_condContext::expression() {
  return getRuleContext<DongLangParser::ExpressionContext>(0);
}


size_t DongLangParser::If_condContext::getRuleIndex() const {
  return DongLangParser::RuleIf_cond;
}

void DongLangParser::If_condContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_cond(this);
}

void DongLangParser::If_condContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_cond(this);
}


std::any DongLangParser::If_condContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitIf_cond(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::If_condContext* DongLangParser::if_cond() {
  If_condContext *_localctx = _tracker.createInstance<If_condContext>(_ctx, getState());
  enterRule(_localctx, 30, DongLangParser::RuleIf_cond);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(240);
      var_expression();
      break;
    }

    default:
      break;
    }
    setState(244);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::COND_SPE) {
      setState(243);
      match(DongLangParser::COND_SPE);
    }
    setState(247);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 301745717233319938) != 0)) {
      setState(246);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_expressionContext ------------------------------------------------------------------

DongLangParser::For_expressionContext::For_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::For_expressionContext::FOR() {
  return getToken(DongLangParser::FOR, 0);
}

DongLangParser::For_condContext* DongLangParser::For_expressionContext::for_cond() {
  return getRuleContext<DongLangParser::For_condContext>(0);
}

std::vector<DongLangParser::Cond_statementContext *> DongLangParser::For_expressionContext::cond_statement() {
  return getRuleContexts<DongLangParser::Cond_statementContext>();
}

DongLangParser::Cond_statementContext* DongLangParser::For_expressionContext::cond_statement(size_t i) {
  return getRuleContext<DongLangParser::Cond_statementContext>(i);
}


size_t DongLangParser::For_expressionContext::getRuleIndex() const {
  return DongLangParser::RuleFor_expression;
}

void DongLangParser::For_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_expression(this);
}

void DongLangParser::For_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_expression(this);
}


std::any DongLangParser::For_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitFor_expression(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::For_expressionContext* DongLangParser::for_expression() {
  For_expressionContext *_localctx = _tracker.createInstance<For_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, DongLangParser::RuleFor_expression);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(DongLangParser::FOR);
    setState(250);
    match(DongLangParser::T__0);
    setState(251);
    for_cond();
    setState(252);
    match(DongLangParser::T__1);
    setState(253);
    match(DongLangParser::T__4);
    setState(257);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 301745717296560130) != 0)) {
      setState(254);
      cond_statement();
      setState(259);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(260);
    match(DongLangParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_condContext ------------------------------------------------------------------

DongLangParser::For_condContext::For_condContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::ExpressionContext* DongLangParser::For_condContext::expression() {
  return getRuleContext<DongLangParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> DongLangParser::For_condContext::COND_SPE() {
  return getTokens(DongLangParser::COND_SPE);
}

tree::TerminalNode* DongLangParser::For_condContext::COND_SPE(size_t i) {
  return getToken(DongLangParser::COND_SPE, i);
}

DongLangParser::Var_expressionContext* DongLangParser::For_condContext::var_expression() {
  return getRuleContext<DongLangParser::Var_expressionContext>(0);
}

DongLangParser::AssignsContext* DongLangParser::For_condContext::assigns() {
  return getRuleContext<DongLangParser::AssignsContext>(0);
}


size_t DongLangParser::For_condContext::getRuleIndex() const {
  return DongLangParser::RuleFor_cond;
}

void DongLangParser::For_condContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_cond(this);
}

void DongLangParser::For_condContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_cond(this);
}


std::any DongLangParser::For_condContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitFor_cond(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::For_condContext* DongLangParser::for_cond() {
  For_condContext *_localctx = _tracker.createInstance<For_condContext>(_ctx, getState());
  enterRule(_localctx, 34, DongLangParser::RuleFor_cond);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(274);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(262);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(264);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4503604190836738) != 0)) {
        setState(263);
        var_expression();
      }
      setState(266);
      match(DongLangParser::COND_SPE);
      setState(268);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 301745717233319938) != 0)) {
        setState(267);
        expression(0);
      }
      setState(270);
      match(DongLangParser::COND_SPE);
      setState(272);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4503604190773250) != 0)) {
        setState(271);
        assigns();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Global_var_expressionContext ------------------------------------------------------------------

DongLangParser::Global_var_expressionContext::Global_var_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::Var_declaresContext* DongLangParser::Global_var_expressionContext::var_declares() {
  return getRuleContext<DongLangParser::Var_declaresContext>(0);
}


size_t DongLangParser::Global_var_expressionContext::getRuleIndex() const {
  return DongLangParser::RuleGlobal_var_expression;
}

void DongLangParser::Global_var_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobal_var_expression(this);
}

void DongLangParser::Global_var_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobal_var_expression(this);
}


std::any DongLangParser::Global_var_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitGlobal_var_expression(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Global_var_expressionContext* DongLangParser::global_var_expression() {
  Global_var_expressionContext *_localctx = _tracker.createInstance<Global_var_expressionContext>(_ctx, getState());
  enterRule(_localctx, 36, DongLangParser::RuleGlobal_var_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(276);
    var_declares();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_expressionContext ------------------------------------------------------------------

DongLangParser::Var_expressionContext::Var_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::VarsContext* DongLangParser::Var_expressionContext::vars() {
  return getRuleContext<DongLangParser::VarsContext>(0);
}

DongLangParser::AssignsContext* DongLangParser::Var_expressionContext::assigns() {
  return getRuleContext<DongLangParser::AssignsContext>(0);
}

DongLangParser::Var_declaresContext* DongLangParser::Var_expressionContext::var_declares() {
  return getRuleContext<DongLangParser::Var_declaresContext>(0);
}


size_t DongLangParser::Var_expressionContext::getRuleIndex() const {
  return DongLangParser::RuleVar_expression;
}

void DongLangParser::Var_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_expression(this);
}

void DongLangParser::Var_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_expression(this);
}


std::any DongLangParser::Var_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitVar_expression(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Var_expressionContext* DongLangParser::var_expression() {
  Var_expressionContext *_localctx = _tracker.createInstance<Var_expressionContext>(_ctx, getState());
  enterRule(_localctx, 38, DongLangParser::RuleVar_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(281);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(278);
      vars();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(279);
      assigns();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(280);
      var_declares();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Paran_exprContext ------------------------------------------------------------------

DongLangParser::Paran_exprContext::Paran_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::ExpressionContext* DongLangParser::Paran_exprContext::expression() {
  return getRuleContext<DongLangParser::ExpressionContext>(0);
}


size_t DongLangParser::Paran_exprContext::getRuleIndex() const {
  return DongLangParser::RuleParan_expr;
}

void DongLangParser::Paran_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParan_expr(this);
}

void DongLangParser::Paran_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParan_expr(this);
}


std::any DongLangParser::Paran_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitParan_expr(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Paran_exprContext* DongLangParser::paran_expr() {
  Paran_exprContext *_localctx = _tracker.createInstance<Paran_exprContext>(_ctx, getState());
  enterRule(_localctx, 40, DongLangParser::RuleParan_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    match(DongLangParser::T__0);
    setState(284);
    expression(0);
    setState(285);
    match(DongLangParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Call_exprContext ------------------------------------------------------------------

DongLangParser::Call_exprContext::Call_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::Call_exprContext::IDENTIFIER() {
  return getToken(DongLangParser::IDENTIFIER, 0);
}

DongLangParser::Expr_listContext* DongLangParser::Call_exprContext::expr_list() {
  return getRuleContext<DongLangParser::Expr_listContext>(0);
}


size_t DongLangParser::Call_exprContext::getRuleIndex() const {
  return DongLangParser::RuleCall_expr;
}

void DongLangParser::Call_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall_expr(this);
}

void DongLangParser::Call_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall_expr(this);
}


std::any DongLangParser::Call_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitCall_expr(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Call_exprContext* DongLangParser::call_expr() {
  Call_exprContext *_localctx = _tracker.createInstance<Call_exprContext>(_ctx, getState());
  enterRule(_localctx, 42, DongLangParser::RuleCall_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(DongLangParser::IDENTIFIER);
    setState(288);
    match(DongLangParser::T__0);
    setState(289);
    expr_list();
    setState(290);
    match(DongLangParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_listContext ------------------------------------------------------------------

DongLangParser::Expr_listContext::Expr_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DongLangParser::ExpressionContext *> DongLangParser::Expr_listContext::expression() {
  return getRuleContexts<DongLangParser::ExpressionContext>();
}

DongLangParser::ExpressionContext* DongLangParser::Expr_listContext::expression(size_t i) {
  return getRuleContext<DongLangParser::ExpressionContext>(i);
}


size_t DongLangParser::Expr_listContext::getRuleIndex() const {
  return DongLangParser::RuleExpr_list;
}

void DongLangParser::Expr_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_list(this);
}

void DongLangParser::Expr_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_list(this);
}


std::any DongLangParser::Expr_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitExpr_list(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Expr_listContext* DongLangParser::expr_list() {
  Expr_listContext *_localctx = _tracker.createInstance<Expr_listContext>(_ctx, getState());
  enterRule(_localctx, 44, DongLangParser::RuleExpr_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(301);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__1:
      case DongLangParser::T__5: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case DongLangParser::T__0:
      case DongLangParser::TRUE:
      case DongLangParser::FALSE:
      case DongLangParser::POINTADDR:
      case DongLangParser::COND_NOT:
      case DongLangParser::POINT:
      case DongLangParser::SUB:
      case DongLangParser::NOT:
      case DongLangParser::IDENTIFIER:
      case DongLangParser::NUMBER:
      case DongLangParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(293);
        expression(0);
        setState(298);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == DongLangParser::T__6) {
          setState(294);
          match(DongLangParser::T__6);
          setState(295);
          expression(0);
          setState(300);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Num_primaryContext ------------------------------------------------------------------

DongLangParser::Num_primaryContext::Num_primaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::Num_primaryContext::NUMBER() {
  return getToken(DongLangParser::NUMBER, 0);
}

tree::TerminalNode* DongLangParser::Num_primaryContext::SUB() {
  return getToken(DongLangParser::SUB, 0);
}


size_t DongLangParser::Num_primaryContext::getRuleIndex() const {
  return DongLangParser::RuleNum_primary;
}

void DongLangParser::Num_primaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNum_primary(this);
}

void DongLangParser::Num_primaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNum_primary(this);
}


std::any DongLangParser::Num_primaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitNum_primary(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Num_primaryContext* DongLangParser::num_primary() {
  Num_primaryContext *_localctx = _tracker.createInstance<Num_primaryContext>(_ctx, getState());
  enterRule(_localctx, 46, DongLangParser::RuleNum_primary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::SUB) {
      setState(303);
      match(DongLangParser::SUB);
    }
    setState(306);
    match(DongLangParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Str_primaryContext ------------------------------------------------------------------

DongLangParser::Str_primaryContext::Str_primaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::Str_primaryContext::STRING_LITERAL() {
  return getToken(DongLangParser::STRING_LITERAL, 0);
}


size_t DongLangParser::Str_primaryContext::getRuleIndex() const {
  return DongLangParser::RuleStr_primary;
}

void DongLangParser::Str_primaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStr_primary(this);
}

void DongLangParser::Str_primaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStr_primary(this);
}


std::any DongLangParser::Str_primaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitStr_primary(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Str_primaryContext* DongLangParser::str_primary() {
  Str_primaryContext *_localctx = _tracker.createInstance<Str_primaryContext>(_ctx, getState());
  enterRule(_localctx, 48, DongLangParser::RuleStr_primary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    match(DongLangParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_primaryContext ------------------------------------------------------------------

DongLangParser::Bool_primaryContext::Bool_primaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::Bool_primaryContext::TRUE() {
  return getToken(DongLangParser::TRUE, 0);
}

tree::TerminalNode* DongLangParser::Bool_primaryContext::FALSE() {
  return getToken(DongLangParser::FALSE, 0);
}


size_t DongLangParser::Bool_primaryContext::getRuleIndex() const {
  return DongLangParser::RuleBool_primary;
}

void DongLangParser::Bool_primaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool_primary(this);
}

void DongLangParser::Bool_primaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool_primary(this);
}


std::any DongLangParser::Bool_primaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitBool_primary(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Bool_primaryContext* DongLangParser::bool_primary() {
  Bool_primaryContext *_localctx = _tracker.createInstance<Bool_primaryContext>(_ctx, getState());
  enterRule(_localctx, 50, DongLangParser::RuleBool_primary);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(310);
    _la = _input->LA(1);
    if (!(_la == DongLangParser::TRUE

    || _la == DongLangParser::FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_primaryContext ------------------------------------------------------------------

DongLangParser::Value_primaryContext::Value_primaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::Num_primaryContext* DongLangParser::Value_primaryContext::num_primary() {
  return getRuleContext<DongLangParser::Num_primaryContext>(0);
}

DongLangParser::Bool_primaryContext* DongLangParser::Value_primaryContext::bool_primary() {
  return getRuleContext<DongLangParser::Bool_primaryContext>(0);
}

DongLangParser::Str_primaryContext* DongLangParser::Value_primaryContext::str_primary() {
  return getRuleContext<DongLangParser::Str_primaryContext>(0);
}


size_t DongLangParser::Value_primaryContext::getRuleIndex() const {
  return DongLangParser::RuleValue_primary;
}

void DongLangParser::Value_primaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue_primary(this);
}

void DongLangParser::Value_primaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue_primary(this);
}


std::any DongLangParser::Value_primaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitValue_primary(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Value_primaryContext* DongLangParser::value_primary() {
  Value_primaryContext *_localctx = _tracker.createInstance<Value_primaryContext>(_ctx, getState());
  enterRule(_localctx, 52, DongLangParser::RuleValue_primary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(315);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::SUB:
      case DongLangParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(312);
        num_primary();
        break;
      }

      case DongLangParser::TRUE:
      case DongLangParser::FALSE: {
        enterOuterAlt(_localctx, 2);
        setState(313);
        bool_primary();
        break;
      }

      case DongLangParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(314);
        str_primary();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_indexContext ------------------------------------------------------------------

DongLangParser::Array_indexContext::Array_indexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::ExpressionContext* DongLangParser::Array_indexContext::expression() {
  return getRuleContext<DongLangParser::ExpressionContext>(0);
}


size_t DongLangParser::Array_indexContext::getRuleIndex() const {
  return DongLangParser::RuleArray_index;
}

void DongLangParser::Array_indexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_index(this);
}

void DongLangParser::Array_indexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_index(this);
}


std::any DongLangParser::Array_indexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitArray_index(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Array_indexContext* DongLangParser::array_index() {
  Array_indexContext *_localctx = _tracker.createInstance<Array_indexContext>(_ctx, getState());
  enterRule(_localctx, 54, DongLangParser::RuleArray_index);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(317);
    match(DongLangParser::T__8);

    setState(318);
    expression(0);
    setState(319);
    match(DongLangParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Id_primary_p_addrsContext ------------------------------------------------------------------

DongLangParser::Id_primary_p_addrsContext::Id_primary_p_addrsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DongLangParser::Id_primary_p_addrsContext::POINT() {
  return getTokens(DongLangParser::POINT);
}

tree::TerminalNode* DongLangParser::Id_primary_p_addrsContext::POINT(size_t i) {
  return getToken(DongLangParser::POINT, i);
}

std::vector<tree::TerminalNode *> DongLangParser::Id_primary_p_addrsContext::POINTADDR() {
  return getTokens(DongLangParser::POINTADDR);
}

tree::TerminalNode* DongLangParser::Id_primary_p_addrsContext::POINTADDR(size_t i) {
  return getToken(DongLangParser::POINTADDR, i);
}


size_t DongLangParser::Id_primary_p_addrsContext::getRuleIndex() const {
  return DongLangParser::RuleId_primary_p_addrs;
}

void DongLangParser::Id_primary_p_addrsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId_primary_p_addrs(this);
}

void DongLangParser::Id_primary_p_addrsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId_primary_p_addrs(this);
}


std::any DongLangParser::Id_primary_p_addrsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitId_primary_p_addrs(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Id_primary_p_addrsContext* DongLangParser::id_primary_p_addrs() {
  Id_primary_p_addrsContext *_localctx = _tracker.createInstance<Id_primary_p_addrsContext>(_ctx, getState());
  enterRule(_localctx, 56, DongLangParser::RuleId_primary_p_addrs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(345);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(322);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
      case 1: {
        setState(321);
        _la = _input->LA(1);
        if (!(_la == DongLangParser::POINTADDR

        || _la == DongLangParser::POINT)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      default:
        break;
      }
      setState(330);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DongLangParser::POINT) {
        setState(324);
        match(DongLangParser::POINT);
        setState(326);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DongLangParser::POINTADDR) {
          setState(325);
          match(DongLangParser::POINTADDR);
        }
        setState(332);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(334);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
      case 1: {
        setState(333);
        match(DongLangParser::POINT);
        break;
      }

      default:
        break;
      }
      setState(342);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DongLangParser::POINTADDR

      || _la == DongLangParser::POINT) {
        setState(337);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DongLangParser::POINTADDR) {
          setState(336);
          match(DongLangParser::POINTADDR);
        }
        setState(339);
        match(DongLangParser::POINT);
        setState(344);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Id_primaryContext ------------------------------------------------------------------

DongLangParser::Id_primaryContext::Id_primaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::Id_primary_p_addrsContext* DongLangParser::Id_primaryContext::id_primary_p_addrs() {
  return getRuleContext<DongLangParser::Id_primary_p_addrsContext>(0);
}

tree::TerminalNode* DongLangParser::Id_primaryContext::IDENTIFIER() {
  return getToken(DongLangParser::IDENTIFIER, 0);
}

DongLangParser::Call_exprContext* DongLangParser::Id_primaryContext::call_expr() {
  return getRuleContext<DongLangParser::Call_exprContext>(0);
}

DongLangParser::Paran_exprContext* DongLangParser::Id_primaryContext::paran_expr() {
  return getRuleContext<DongLangParser::Paran_exprContext>(0);
}

std::vector<DongLangParser::Array_indexContext *> DongLangParser::Id_primaryContext::array_index() {
  return getRuleContexts<DongLangParser::Array_indexContext>();
}

DongLangParser::Array_indexContext* DongLangParser::Id_primaryContext::array_index(size_t i) {
  return getRuleContext<DongLangParser::Array_indexContext>(i);
}


size_t DongLangParser::Id_primaryContext::getRuleIndex() const {
  return DongLangParser::RuleId_primary;
}

void DongLangParser::Id_primaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId_primary(this);
}

void DongLangParser::Id_primaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId_primary(this);
}


std::any DongLangParser::Id_primaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitId_primary(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Id_primaryContext* DongLangParser::id_primary() {
  Id_primaryContext *_localctx = _tracker.createInstance<Id_primaryContext>(_ctx, getState());
  enterRule(_localctx, 58, DongLangParser::RuleId_primary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(347);
    id_primary_p_addrs();
    setState(351);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(348);
      match(DongLangParser::IDENTIFIER);
      break;
    }

    case 2: {
      setState(349);
      call_expr();
      break;
    }

    case 3: {
      setState(350);
      paran_expr();
      break;
    }

    default:
      break;
    }
    setState(356);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(353);
        array_index(); 
      }
      setState(358);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

DongLangParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::Value_primaryContext* DongLangParser::PrimaryContext::value_primary() {
  return getRuleContext<DongLangParser::Value_primaryContext>(0);
}

DongLangParser::Id_primaryContext* DongLangParser::PrimaryContext::id_primary() {
  return getRuleContext<DongLangParser::Id_primaryContext>(0);
}


size_t DongLangParser::PrimaryContext::getRuleIndex() const {
  return DongLangParser::RulePrimary;
}

void DongLangParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void DongLangParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}


std::any DongLangParser::PrimaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitPrimary(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::PrimaryContext* DongLangParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 60, DongLangParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(361);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::TRUE:
      case DongLangParser::FALSE:
      case DongLangParser::SUB:
      case DongLangParser::NUMBER:
      case DongLangParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(359);
        value_primary();
        break;
      }

      case DongLangParser::T__0:
      case DongLangParser::POINTADDR:
      case DongLangParser::POINT:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(360);
        id_primary();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Primary_typeContext ------------------------------------------------------------------

DongLangParser::Primary_typeContext::Primary_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DongLangParser::Primary_typeContext::getRuleIndex() const {
  return DongLangParser::RulePrimary_type;
}

void DongLangParser::Primary_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary_type(this);
}

void DongLangParser::Primary_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary_type(this);
}


std::any DongLangParser::Primary_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitPrimary_type(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Primary_typeContext* DongLangParser::primary_type() {
  Primary_typeContext *_localctx = _tracker.createInstance<Primary_typeContext>(_ctx, getState());
  enterRule(_localctx, 62, DongLangParser::RulePrimary_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 63488) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_typeContext ------------------------------------------------------------------

DongLangParser::Array_typeContext::Array_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::Array_typeContext::NUMBER() {
  return getToken(DongLangParser::NUMBER, 0);
}


size_t DongLangParser::Array_typeContext::getRuleIndex() const {
  return DongLangParser::RuleArray_type;
}

void DongLangParser::Array_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_type(this);
}

void DongLangParser::Array_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_type(this);
}


std::any DongLangParser::Array_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitArray_type(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Array_typeContext* DongLangParser::array_type() {
  Array_typeContext *_localctx = _tracker.createInstance<Array_typeContext>(_ctx, getState());
  enterRule(_localctx, 64, DongLangParser::RuleArray_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
    match(DongLangParser::T__8);
    setState(367);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::NUMBER) {
      setState(366);
      match(DongLangParser::NUMBER);
    }
    setState(369);
    match(DongLangParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_typeContext ------------------------------------------------------------------

DongLangParser::Type_typeContext::Type_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::Primary_typeContext* DongLangParser::Type_typeContext::primary_type() {
  return getRuleContext<DongLangParser::Primary_typeContext>(0);
}

std::vector<tree::TerminalNode *> DongLangParser::Type_typeContext::POINT() {
  return getTokens(DongLangParser::POINT);
}

tree::TerminalNode* DongLangParser::Type_typeContext::POINT(size_t i) {
  return getToken(DongLangParser::POINT, i);
}

std::vector<DongLangParser::Array_typeContext *> DongLangParser::Type_typeContext::array_type() {
  return getRuleContexts<DongLangParser::Array_typeContext>();
}

DongLangParser::Array_typeContext* DongLangParser::Type_typeContext::array_type(size_t i) {
  return getRuleContext<DongLangParser::Array_typeContext>(i);
}


size_t DongLangParser::Type_typeContext::getRuleIndex() const {
  return DongLangParser::RuleType_type;
}

void DongLangParser::Type_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_type(this);
}

void DongLangParser::Type_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_type(this);
}


std::any DongLangParser::Type_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitType_type(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Type_typeContext* DongLangParser::type_type() {
  Type_typeContext *_localctx = _tracker.createInstance<Type_typeContext>(_ctx, getState());
  enterRule(_localctx, 66, DongLangParser::RuleType_type);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    primary_type();
    setState(375);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::POINT) {
      setState(372);
      match(DongLangParser::POINT);
      setState(377);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(381);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::T__8) {
      setState(378);
      array_type();
      setState(383);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_type_voidContext ------------------------------------------------------------------

DongLangParser::Type_type_voidContext::Type_type_voidContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::Type_typeContext* DongLangParser::Type_type_voidContext::type_type() {
  return getRuleContext<DongLangParser::Type_typeContext>(0);
}

tree::TerminalNode* DongLangParser::Type_type_voidContext::VOID() {
  return getToken(DongLangParser::VOID, 0);
}


size_t DongLangParser::Type_type_voidContext::getRuleIndex() const {
  return DongLangParser::RuleType_type_void;
}

void DongLangParser::Type_type_voidContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_type_void(this);
}

void DongLangParser::Type_type_voidContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_type_void(this);
}


std::any DongLangParser::Type_type_voidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitType_type_void(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Type_type_voidContext* DongLangParser::type_type_void() {
  Type_type_voidContext *_localctx = _tracker.createInstance<Type_type_voidContext>(_ctx, getState());
  enterRule(_localctx, 68, DongLangParser::RuleType_type_void);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__10:
      case DongLangParser::T__11:
      case DongLangParser::T__12:
      case DongLangParser::T__13:
      case DongLangParser::T__14: {
        enterOuterAlt(_localctx, 1);
        setState(384);
        type_type();
        break;
      }

      case DongLangParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(385);
        match(DongLangParser::VOID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_valueContext ------------------------------------------------------------------

DongLangParser::Var_valueContext::Var_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::ExpressionContext* DongLangParser::Var_valueContext::expression() {
  return getRuleContext<DongLangParser::ExpressionContext>(0);
}

DongLangParser::Var_arr_valueContext* DongLangParser::Var_valueContext::var_arr_value() {
  return getRuleContext<DongLangParser::Var_arr_valueContext>(0);
}


size_t DongLangParser::Var_valueContext::getRuleIndex() const {
  return DongLangParser::RuleVar_value;
}

void DongLangParser::Var_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_value(this);
}

void DongLangParser::Var_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_value(this);
}


std::any DongLangParser::Var_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitVar_value(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Var_valueContext* DongLangParser::var_value() {
  Var_valueContext *_localctx = _tracker.createInstance<Var_valueContext>(_ctx, getState());
  enterRule(_localctx, 70, DongLangParser::RuleVar_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(390);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__0:
      case DongLangParser::TRUE:
      case DongLangParser::FALSE:
      case DongLangParser::POINTADDR:
      case DongLangParser::COND_NOT:
      case DongLangParser::POINT:
      case DongLangParser::SUB:
      case DongLangParser::NOT:
      case DongLangParser::IDENTIFIER:
      case DongLangParser::NUMBER:
      case DongLangParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(388);
        expression(0);
        break;
      }

      case DongLangParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(389);
        var_arr_value();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_arr_valueContext ------------------------------------------------------------------

DongLangParser::Var_arr_valueContext::Var_arr_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DongLangParser::Var_arr_valueContext *> DongLangParser::Var_arr_valueContext::var_arr_value() {
  return getRuleContexts<DongLangParser::Var_arr_valueContext>();
}

DongLangParser::Var_arr_valueContext* DongLangParser::Var_arr_valueContext::var_arr_value(size_t i) {
  return getRuleContext<DongLangParser::Var_arr_valueContext>(i);
}

DongLangParser::Expr_listContext* DongLangParser::Var_arr_valueContext::expr_list() {
  return getRuleContext<DongLangParser::Expr_listContext>(0);
}


size_t DongLangParser::Var_arr_valueContext::getRuleIndex() const {
  return DongLangParser::RuleVar_arr_value;
}

void DongLangParser::Var_arr_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_arr_value(this);
}

void DongLangParser::Var_arr_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_arr_value(this);
}


std::any DongLangParser::Var_arr_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitVar_arr_value(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Var_arr_valueContext* DongLangParser::var_arr_value() {
  Var_arr_valueContext *_localctx = _tracker.createInstance<Var_arr_valueContext>(_ctx, getState());
  enterRule(_localctx, 72, DongLangParser::RuleVar_arr_value);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(407);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(392);
      match(DongLangParser::T__4);
      setState(393);
      var_arr_value();
      setState(398);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DongLangParser::T__6) {
        setState(394);
        match(DongLangParser::T__6);
        setState(395);
        var_arr_value();
        setState(400);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(401);
      match(DongLangParser::T__5);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(403);
      match(DongLangParser::T__4);
      setState(404);
      expr_list();
      setState(405);
      match(DongLangParser::T__5);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

DongLangParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::Id_primaryContext* DongLangParser::AssignContext::id_primary() {
  return getRuleContext<DongLangParser::Id_primaryContext>(0);
}

DongLangParser::ExpressionContext* DongLangParser::AssignContext::expression() {
  return getRuleContext<DongLangParser::ExpressionContext>(0);
}

tree::TerminalNode* DongLangParser::AssignContext::ADD() {
  return getToken(DongLangParser::ADD, 0);
}

tree::TerminalNode* DongLangParser::AssignContext::SUB() {
  return getToken(DongLangParser::SUB, 0);
}

tree::TerminalNode* DongLangParser::AssignContext::POINT() {
  return getToken(DongLangParser::POINT, 0);
}

tree::TerminalNode* DongLangParser::AssignContext::DIV() {
  return getToken(DongLangParser::DIV, 0);
}

tree::TerminalNode* DongLangParser::AssignContext::OR() {
  return getToken(DongLangParser::OR, 0);
}

tree::TerminalNode* DongLangParser::AssignContext::XOR() {
  return getToken(DongLangParser::XOR, 0);
}

tree::TerminalNode* DongLangParser::AssignContext::POINTADDR() {
  return getToken(DongLangParser::POINTADDR, 0);
}

tree::TerminalNode* DongLangParser::AssignContext::INCREMENT() {
  return getToken(DongLangParser::INCREMENT, 0);
}

tree::TerminalNode* DongLangParser::AssignContext::DECREMENT() {
  return getToken(DongLangParser::DECREMENT, 0);
}


size_t DongLangParser::AssignContext::getRuleIndex() const {
  return DongLangParser::RuleAssign;
}

void DongLangParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void DongLangParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}


std::any DongLangParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::AssignContext* DongLangParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 74, DongLangParser::RuleAssign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(420);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(409);
      id_primary();
      setState(415);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
      case 1: {
        setState(411);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 4059012530176) != 0)) {
          setState(410);
          antlrcpp::downCast<AssignContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 4059012530176) != 0))) {
            antlrcpp::downCast<AssignContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        setState(413);
        match(DongLangParser::T__15);
        setState(414);
        expression(0);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(417);
      id_primary();
      setState(418);
      _la = _input->LA(1);
      if (!(_la == DongLangParser::INCREMENT

      || _la == DongLangParser::DECREMENT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignsContext ------------------------------------------------------------------

DongLangParser::AssignsContext::AssignsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DongLangParser::AssignContext *> DongLangParser::AssignsContext::assign() {
  return getRuleContexts<DongLangParser::AssignContext>();
}

DongLangParser::AssignContext* DongLangParser::AssignsContext::assign(size_t i) {
  return getRuleContext<DongLangParser::AssignContext>(i);
}


size_t DongLangParser::AssignsContext::getRuleIndex() const {
  return DongLangParser::RuleAssigns;
}

void DongLangParser::AssignsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssigns(this);
}

void DongLangParser::AssignsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssigns(this);
}


std::any DongLangParser::AssignsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitAssigns(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::AssignsContext* DongLangParser::assigns() {
  AssignsContext *_localctx = _tracker.createInstance<AssignsContext>(_ctx, getState());
  enterRule(_localctx, 76, DongLangParser::RuleAssigns);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(422);
    assign();
    setState(427);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::T__6) {
      setState(423);
      match(DongLangParser::T__6);
      setState(424);
      assign();
      setState(429);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

DongLangParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DongLangParser::VarContext::IDENTIFIER() {
  return getToken(DongLangParser::IDENTIFIER, 0);
}

DongLangParser::Var_valueContext* DongLangParser::VarContext::var_value() {
  return getRuleContext<DongLangParser::Var_valueContext>(0);
}


size_t DongLangParser::VarContext::getRuleIndex() const {
  return DongLangParser::RuleVar;
}

void DongLangParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}

void DongLangParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}


std::any DongLangParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::VarContext* DongLangParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 78, DongLangParser::RuleVar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(430);
    match(DongLangParser::IDENTIFIER);
    setState(433);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::T__15) {
      setState(431);
      match(DongLangParser::T__15);
      setState(432);
      var_value();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarsContext ------------------------------------------------------------------

DongLangParser::VarsContext::VarsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DongLangParser::VarContext *> DongLangParser::VarsContext::var() {
  return getRuleContexts<DongLangParser::VarContext>();
}

DongLangParser::VarContext* DongLangParser::VarsContext::var(size_t i) {
  return getRuleContext<DongLangParser::VarContext>(i);
}


size_t DongLangParser::VarsContext::getRuleIndex() const {
  return DongLangParser::RuleVars;
}

void DongLangParser::VarsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVars(this);
}

void DongLangParser::VarsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVars(this);
}


std::any DongLangParser::VarsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitVars(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::VarsContext* DongLangParser::vars() {
  VarsContext *_localctx = _tracker.createInstance<VarsContext>(_ctx, getState());
  enterRule(_localctx, 80, DongLangParser::RuleVars);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(435);
    var();
    setState(440);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::T__6) {
      setState(436);
      match(DongLangParser::T__6);
      setState(437);
      var();
      setState(442);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declaresContext ------------------------------------------------------------------

DongLangParser::Var_declaresContext::Var_declaresContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::Type_typeContext* DongLangParser::Var_declaresContext::type_type() {
  return getRuleContext<DongLangParser::Type_typeContext>(0);
}

DongLangParser::VarsContext* DongLangParser::Var_declaresContext::vars() {
  return getRuleContext<DongLangParser::VarsContext>(0);
}


size_t DongLangParser::Var_declaresContext::getRuleIndex() const {
  return DongLangParser::RuleVar_declares;
}

void DongLangParser::Var_declaresContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declares(this);
}

void DongLangParser::Var_declaresContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declares(this);
}


std::any DongLangParser::Var_declaresContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitVar_declares(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Var_declaresContext* DongLangParser::var_declares() {
  Var_declaresContext *_localctx = _tracker.createInstance<Var_declaresContext>(_ctx, getState());
  enterRule(_localctx, 82, DongLangParser::RuleVar_declares);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(443);
    type_type();
    setState(444);
    vars();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool DongLangParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 9: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool DongLangParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void DongLangParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  donglangParserInitialize();
#else
  ::antlr4::internal::call_once(donglangParserOnceFlag, donglangParserInitialize);
#endif
}
