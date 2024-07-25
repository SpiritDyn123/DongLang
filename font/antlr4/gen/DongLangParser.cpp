
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
      "var_declares", "template", "class_def"
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
  	4,1,64,473,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,1,0,1,0,1,0,1,0,5,0,93,8,0,10,0,12,0,96,9,0,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,3,1,106,8,1,1,2,3,2,109,8,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,3,2,119,8,2,1,3,1,3,1,3,1,4,1,4,5,4,126,8,4,10,4,12,4,129,9,
  	4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,7,5,7,143,8,7,10,7,12,
  	7,146,9,7,1,7,3,7,149,8,7,3,7,151,8,7,1,8,1,8,3,8,155,8,8,1,9,1,9,1,9,
  	1,9,1,9,1,9,3,9,163,8,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,189,8,9,10,9,12,
  	9,192,9,9,1,10,1,10,1,10,3,10,197,8,10,1,11,1,11,1,11,1,11,1,11,1,11,
  	5,11,205,8,11,10,11,12,11,208,9,11,1,11,1,11,5,11,212,8,11,10,11,12,11,
  	215,9,11,1,11,3,11,218,8,11,1,12,1,12,1,12,1,12,1,12,1,12,5,12,226,8,
  	12,10,12,12,12,229,9,12,1,12,1,12,1,13,1,13,1,13,5,13,236,8,13,10,13,
  	12,13,239,9,13,1,13,1,13,1,14,1,14,1,14,3,14,246,8,14,1,15,3,15,249,8,
  	15,1,15,3,15,252,8,15,1,15,3,15,255,8,15,1,16,1,16,1,16,1,16,1,16,1,16,
  	5,16,263,8,16,10,16,12,16,266,9,16,1,16,1,16,1,17,1,17,3,17,272,8,17,
  	1,17,1,17,3,17,276,8,17,1,17,1,17,3,17,280,8,17,3,17,282,8,17,1,18,1,
  	18,1,18,1,18,1,18,3,18,289,8,18,3,18,291,8,18,1,19,1,19,3,19,295,8,19,
  	1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,5,22,
  	310,8,22,10,22,12,22,313,9,22,3,22,315,8,22,1,23,3,23,318,8,23,1,23,1,
  	23,3,23,322,8,23,1,24,1,24,1,25,1,25,1,26,1,26,1,26,3,26,331,8,26,1,27,
  	1,27,1,27,1,27,1,28,3,28,338,8,28,1,28,1,28,3,28,342,8,28,5,28,344,8,
  	28,10,28,12,28,347,9,28,1,28,3,28,350,8,28,1,28,3,28,353,8,28,1,28,5,
  	28,356,8,28,10,28,12,28,359,9,28,3,28,361,8,28,1,29,1,29,1,29,1,29,3,
  	29,367,8,29,1,29,5,29,370,8,29,10,29,12,29,373,9,29,1,30,1,30,3,30,377,
  	8,30,1,31,1,31,1,32,1,32,3,32,383,8,32,1,32,1,32,1,33,1,33,3,33,389,8,
  	33,1,33,1,33,5,33,393,8,33,10,33,12,33,396,9,33,1,34,1,34,3,34,400,8,
  	34,1,35,1,35,3,35,404,8,35,1,36,1,36,1,36,1,36,5,36,410,8,36,10,36,12,
  	36,413,9,36,1,36,1,36,1,36,1,36,1,36,1,36,3,36,421,8,36,1,37,1,37,3,37,
  	425,8,37,1,37,1,37,3,37,429,8,37,1,37,1,37,1,37,3,37,434,8,37,1,38,1,
  	38,1,38,5,38,439,8,38,10,38,12,38,442,9,38,1,39,1,39,1,39,3,39,447,8,
  	39,1,40,1,40,1,40,5,40,452,8,40,10,40,12,40,455,9,40,1,41,1,41,1,41,1,
  	42,1,42,5,42,462,8,42,10,42,12,42,465,9,42,1,42,1,42,1,43,1,43,1,43,1,
  	43,1,43,0,1,18,44,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,
  	38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,
  	84,86,0,10,2,0,35,35,44,44,1,0,41,42,2,0,31,31,45,46,1,0,48,53,1,0,26,
  	27,1,0,23,24,2,0,31,31,35,35,1,0,13,17,4,0,31,31,35,35,41,42,44,46,1,
  	0,36,37,499,0,94,1,0,0,0,2,105,1,0,0,0,4,108,1,0,0,0,6,120,1,0,0,0,8,
  	123,1,0,0,0,10,132,1,0,0,0,12,135,1,0,0,0,14,150,1,0,0,0,16,152,1,0,0,
  	0,18,162,1,0,0,0,20,196,1,0,0,0,22,198,1,0,0,0,24,219,1,0,0,0,26,232,
  	1,0,0,0,28,245,1,0,0,0,30,248,1,0,0,0,32,256,1,0,0,0,34,281,1,0,0,0,36,
  	290,1,0,0,0,38,294,1,0,0,0,40,296,1,0,0,0,42,300,1,0,0,0,44,314,1,0,0,
  	0,46,321,1,0,0,0,48,323,1,0,0,0,50,325,1,0,0,0,52,330,1,0,0,0,54,332,
  	1,0,0,0,56,360,1,0,0,0,58,362,1,0,0,0,60,376,1,0,0,0,62,378,1,0,0,0,64,
  	380,1,0,0,0,66,388,1,0,0,0,68,399,1,0,0,0,70,403,1,0,0,0,72,420,1,0,0,
  	0,74,433,1,0,0,0,76,435,1,0,0,0,78,443,1,0,0,0,80,448,1,0,0,0,82,456,
  	1,0,0,0,84,459,1,0,0,0,86,468,1,0,0,0,88,89,3,36,18,0,89,90,5,38,0,0,
  	90,93,1,0,0,0,91,93,3,4,2,0,92,88,1,0,0,0,92,91,1,0,0,0,93,96,1,0,0,0,
  	94,92,1,0,0,0,94,95,1,0,0,0,95,1,1,0,0,0,96,94,1,0,0,0,97,98,3,38,19,
  	0,98,99,5,38,0,0,99,106,1,0,0,0,100,101,3,16,8,0,101,102,5,38,0,0,102,
  	106,1,0,0,0,103,106,3,22,11,0,104,106,3,32,16,0,105,97,1,0,0,0,105,100,
  	1,0,0,0,105,103,1,0,0,0,105,104,1,0,0,0,106,3,1,0,0,0,107,109,3,6,3,0,
  	108,107,1,0,0,0,108,109,1,0,0,0,109,110,1,0,0,0,110,111,5,20,0,0,111,
  	112,3,68,34,0,112,113,5,57,0,0,113,114,5,1,0,0,114,115,3,14,7,0,115,118,
  	5,2,0,0,116,119,3,8,4,0,117,119,5,38,0,0,118,116,1,0,0,0,118,117,1,0,
  	0,0,119,5,1,0,0,0,120,121,5,3,0,0,121,122,5,4,0,0,122,7,1,0,0,0,123,127,
  	5,5,0,0,124,126,3,2,1,0,125,124,1,0,0,0,126,129,1,0,0,0,127,125,1,0,0,
  	0,127,128,1,0,0,0,128,130,1,0,0,0,129,127,1,0,0,0,130,131,5,6,0,0,131,
  	9,1,0,0,0,132,133,3,66,33,0,133,134,5,57,0,0,134,11,1,0,0,0,135,136,5,
  	7,0,0,136,137,5,8,0,0,137,13,1,0,0,0,138,151,1,0,0,0,139,144,3,10,5,0,
  	140,141,5,7,0,0,141,143,3,10,5,0,142,140,1,0,0,0,143,146,1,0,0,0,144,
  	142,1,0,0,0,144,145,1,0,0,0,145,148,1,0,0,0,146,144,1,0,0,0,147,149,3,
  	12,6,0,148,147,1,0,0,0,148,149,1,0,0,0,149,151,1,0,0,0,150,138,1,0,0,
  	0,150,139,1,0,0,0,151,15,1,0,0,0,152,154,5,21,0,0,153,155,3,18,9,0,154,
  	153,1,0,0,0,154,155,1,0,0,0,155,17,1,0,0,0,156,157,6,9,-1,0,157,158,5,
  	34,0,0,158,163,3,18,9,10,159,160,5,47,0,0,160,163,3,18,9,7,161,163,3,
  	60,30,0,162,156,1,0,0,0,162,159,1,0,0,0,162,161,1,0,0,0,163,190,1,0,0,
  	0,164,165,10,9,0,0,165,166,7,0,0,0,166,189,3,18,9,10,167,168,10,8,0,0,
  	168,169,7,1,0,0,169,189,3,18,9,9,170,171,10,6,0,0,171,172,7,2,0,0,172,
  	189,3,18,9,7,173,174,10,5,0,0,174,175,7,3,0,0,175,189,3,18,9,6,176,177,
  	10,4,0,0,177,178,5,32,0,0,178,189,3,18,9,5,179,180,10,3,0,0,180,181,5,
  	33,0,0,181,189,3,18,9,4,182,183,10,2,0,0,183,184,5,9,0,0,184,185,3,18,
  	9,0,185,186,5,10,0,0,186,187,3,18,9,3,187,189,1,0,0,0,188,164,1,0,0,0,
  	188,167,1,0,0,0,188,170,1,0,0,0,188,173,1,0,0,0,188,176,1,0,0,0,188,179,
  	1,0,0,0,188,182,1,0,0,0,189,192,1,0,0,0,190,188,1,0,0,0,190,191,1,0,0,
  	0,191,19,1,0,0,0,192,190,1,0,0,0,193,197,3,2,1,0,194,195,7,4,0,0,195,
  	197,5,38,0,0,196,193,1,0,0,0,196,194,1,0,0,0,197,21,1,0,0,0,198,199,5,
  	28,0,0,199,200,5,1,0,0,200,201,3,30,15,0,201,202,5,2,0,0,202,206,5,5,
  	0,0,203,205,3,20,10,0,204,203,1,0,0,0,205,208,1,0,0,0,206,204,1,0,0,0,
  	206,207,1,0,0,0,207,209,1,0,0,0,208,206,1,0,0,0,209,213,5,6,0,0,210,212,
  	3,24,12,0,211,210,1,0,0,0,212,215,1,0,0,0,213,211,1,0,0,0,213,214,1,0,
  	0,0,214,217,1,0,0,0,215,213,1,0,0,0,216,218,3,26,13,0,217,216,1,0,0,0,
  	217,218,1,0,0,0,218,23,1,0,0,0,219,220,3,28,14,0,220,221,5,1,0,0,221,
  	222,3,30,15,0,222,223,5,2,0,0,223,227,5,5,0,0,224,226,3,20,10,0,225,224,
  	1,0,0,0,226,229,1,0,0,0,227,225,1,0,0,0,227,228,1,0,0,0,228,230,1,0,0,
  	0,229,227,1,0,0,0,230,231,5,6,0,0,231,25,1,0,0,0,232,233,5,29,0,0,233,
  	237,5,5,0,0,234,236,3,20,10,0,235,234,1,0,0,0,236,239,1,0,0,0,237,235,
  	1,0,0,0,237,238,1,0,0,0,238,240,1,0,0,0,239,237,1,0,0,0,240,241,5,6,0,
  	0,241,27,1,0,0,0,242,246,5,30,0,0,243,244,5,29,0,0,244,246,5,28,0,0,245,
  	242,1,0,0,0,245,243,1,0,0,0,246,29,1,0,0,0,247,249,3,38,19,0,248,247,
  	1,0,0,0,248,249,1,0,0,0,249,251,1,0,0,0,250,252,5,38,0,0,251,250,1,0,
  	0,0,251,252,1,0,0,0,252,254,1,0,0,0,253,255,3,18,9,0,254,253,1,0,0,0,
  	254,255,1,0,0,0,255,31,1,0,0,0,256,257,5,25,0,0,257,258,5,1,0,0,258,259,
  	3,34,17,0,259,260,5,2,0,0,260,264,5,5,0,0,261,263,3,20,10,0,262,261,1,
  	0,0,0,263,266,1,0,0,0,264,262,1,0,0,0,264,265,1,0,0,0,265,267,1,0,0,0,
  	266,264,1,0,0,0,267,268,5,6,0,0,268,33,1,0,0,0,269,282,3,18,9,0,270,272,
  	3,38,19,0,271,270,1,0,0,0,271,272,1,0,0,0,272,273,1,0,0,0,273,275,5,38,
  	0,0,274,276,3,18,9,0,275,274,1,0,0,0,275,276,1,0,0,0,276,277,1,0,0,0,
  	277,279,5,38,0,0,278,280,3,76,38,0,279,278,1,0,0,0,279,280,1,0,0,0,280,
  	282,1,0,0,0,281,269,1,0,0,0,281,271,1,0,0,0,282,35,1,0,0,0,283,291,3,
  	82,41,0,284,285,5,40,0,0,285,288,5,57,0,0,286,289,3,66,33,0,287,289,3,
  	86,43,0,288,286,1,0,0,0,288,287,1,0,0,0,289,291,1,0,0,0,290,283,1,0,0,
  	0,290,284,1,0,0,0,291,37,1,0,0,0,292,295,3,76,38,0,293,295,3,82,41,0,
  	294,292,1,0,0,0,294,293,1,0,0,0,295,39,1,0,0,0,296,297,5,1,0,0,297,298,
  	3,18,9,0,298,299,5,2,0,0,299,41,1,0,0,0,300,301,5,57,0,0,301,302,5,1,
  	0,0,302,303,3,44,22,0,303,304,5,2,0,0,304,43,1,0,0,0,305,315,1,0,0,0,
  	306,311,3,18,9,0,307,308,5,7,0,0,308,310,3,18,9,0,309,307,1,0,0,0,310,
  	313,1,0,0,0,311,309,1,0,0,0,311,312,1,0,0,0,312,315,1,0,0,0,313,311,1,
  	0,0,0,314,305,1,0,0,0,314,306,1,0,0,0,315,45,1,0,0,0,316,318,5,42,0,0,
  	317,316,1,0,0,0,317,318,1,0,0,0,318,319,1,0,0,0,319,322,5,58,0,0,320,
  	322,5,39,0,0,321,317,1,0,0,0,321,320,1,0,0,0,322,47,1,0,0,0,323,324,5,
  	64,0,0,324,49,1,0,0,0,325,326,7,5,0,0,326,51,1,0,0,0,327,331,3,46,23,
  	0,328,331,3,50,25,0,329,331,3,48,24,0,330,327,1,0,0,0,330,328,1,0,0,0,
  	330,329,1,0,0,0,331,53,1,0,0,0,332,333,5,11,0,0,333,334,3,18,9,0,334,
  	335,5,12,0,0,335,55,1,0,0,0,336,338,7,6,0,0,337,336,1,0,0,0,337,338,1,
  	0,0,0,338,345,1,0,0,0,339,341,5,35,0,0,340,342,5,31,0,0,341,340,1,0,0,
  	0,341,342,1,0,0,0,342,344,1,0,0,0,343,339,1,0,0,0,344,347,1,0,0,0,345,
  	343,1,0,0,0,345,346,1,0,0,0,346,361,1,0,0,0,347,345,1,0,0,0,348,350,5,
  	35,0,0,349,348,1,0,0,0,349,350,1,0,0,0,350,357,1,0,0,0,351,353,5,31,0,
  	0,352,351,1,0,0,0,352,353,1,0,0,0,353,354,1,0,0,0,354,356,5,35,0,0,355,
  	352,1,0,0,0,356,359,1,0,0,0,357,355,1,0,0,0,357,358,1,0,0,0,358,361,1,
  	0,0,0,359,357,1,0,0,0,360,337,1,0,0,0,360,349,1,0,0,0,361,57,1,0,0,0,
  	362,366,3,56,28,0,363,367,5,57,0,0,364,367,3,42,21,0,365,367,3,40,20,
  	0,366,363,1,0,0,0,366,364,1,0,0,0,366,365,1,0,0,0,367,371,1,0,0,0,368,
  	370,3,54,27,0,369,368,1,0,0,0,370,373,1,0,0,0,371,369,1,0,0,0,371,372,
  	1,0,0,0,372,59,1,0,0,0,373,371,1,0,0,0,374,377,3,52,26,0,375,377,3,58,
  	29,0,376,374,1,0,0,0,376,375,1,0,0,0,377,61,1,0,0,0,378,379,7,7,0,0,379,
  	63,1,0,0,0,380,382,5,11,0,0,381,383,5,58,0,0,382,381,1,0,0,0,382,383,
  	1,0,0,0,383,384,1,0,0,0,384,385,5,12,0,0,385,65,1,0,0,0,386,389,3,62,
  	31,0,387,389,5,57,0,0,388,386,1,0,0,0,388,387,1,0,0,0,389,394,1,0,0,0,
  	390,393,5,35,0,0,391,393,3,64,32,0,392,390,1,0,0,0,392,391,1,0,0,0,393,
  	396,1,0,0,0,394,392,1,0,0,0,394,395,1,0,0,0,395,67,1,0,0,0,396,394,1,
  	0,0,0,397,400,3,66,33,0,398,400,5,22,0,0,399,397,1,0,0,0,399,398,1,0,
  	0,0,400,69,1,0,0,0,401,404,3,18,9,0,402,404,3,72,36,0,403,401,1,0,0,0,
  	403,402,1,0,0,0,404,71,1,0,0,0,405,406,5,5,0,0,406,411,3,72,36,0,407,
  	408,5,7,0,0,408,410,3,72,36,0,409,407,1,0,0,0,410,413,1,0,0,0,411,409,
  	1,0,0,0,411,412,1,0,0,0,412,414,1,0,0,0,413,411,1,0,0,0,414,415,5,6,0,
  	0,415,421,1,0,0,0,416,417,5,5,0,0,417,418,3,44,22,0,418,419,5,6,0,0,419,
  	421,1,0,0,0,420,405,1,0,0,0,420,416,1,0,0,0,421,73,1,0,0,0,422,428,3,
  	58,29,0,423,425,7,8,0,0,424,423,1,0,0,0,424,425,1,0,0,0,425,426,1,0,0,
  	0,426,427,5,18,0,0,427,429,3,18,9,0,428,424,1,0,0,0,428,429,1,0,0,0,429,
  	434,1,0,0,0,430,431,3,58,29,0,431,432,7,9,0,0,432,434,1,0,0,0,433,422,
  	1,0,0,0,433,430,1,0,0,0,434,75,1,0,0,0,435,440,3,74,37,0,436,437,5,7,
  	0,0,437,439,3,74,37,0,438,436,1,0,0,0,439,442,1,0,0,0,440,438,1,0,0,0,
  	440,441,1,0,0,0,441,77,1,0,0,0,442,440,1,0,0,0,443,446,5,57,0,0,444,445,
  	5,18,0,0,445,447,3,70,35,0,446,444,1,0,0,0,446,447,1,0,0,0,447,79,1,0,
  	0,0,448,453,3,78,39,0,449,450,5,7,0,0,450,452,3,78,39,0,451,449,1,0,0,
  	0,452,455,1,0,0,0,453,451,1,0,0,0,453,454,1,0,0,0,454,81,1,0,0,0,455,
  	453,1,0,0,0,456,457,3,66,33,0,457,458,3,80,40,0,458,83,1,0,0,0,459,463,
  	5,11,0,0,460,462,5,57,0,0,461,460,1,0,0,0,462,465,1,0,0,0,463,461,1,0,
  	0,0,463,464,1,0,0,0,464,466,1,0,0,0,465,463,1,0,0,0,466,467,5,12,0,0,
  	467,85,1,0,0,0,468,469,5,19,0,0,469,470,5,5,0,0,470,471,5,6,0,0,471,87,
  	1,0,0,0,61,92,94,105,108,118,127,144,148,150,154,162,188,190,196,206,
  	213,217,227,237,245,248,251,254,264,271,275,279,281,288,290,294,311,314,
  	317,321,330,337,341,345,349,352,357,360,366,371,376,382,388,392,394,399,
  	403,411,420,424,428,433,440,446,453,463
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
    setState(94);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144116287588786184) != 0)) {
      setState(92);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DongLangParser::T__12:
        case DongLangParser::T__13:
        case DongLangParser::T__14:
        case DongLangParser::T__15:
        case DongLangParser::T__16:
        case DongLangParser::TYPE:
        case DongLangParser::IDENTIFIER: {
          setState(88);
          global_var_expression();
          setState(89);
          match(DongLangParser::COND_SPE);
          break;
        }

        case DongLangParser::T__2:
        case DongLangParser::FUNC: {
          setState(91);
          function_def();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(96);
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

DongLangParser::Var_expressionContext* DongLangParser::StatementContext::var_expression() {
  return getRuleContext<DongLangParser::Var_expressionContext>(0);
}

tree::TerminalNode* DongLangParser::StatementContext::COND_SPE() {
  return getToken(DongLangParser::COND_SPE, 0);
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
    setState(105);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__0:
      case DongLangParser::T__12:
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::T__15:
      case DongLangParser::T__16:
      case DongLangParser::POINTADDR:
      case DongLangParser::POINT:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(97);
        var_expression();
        setState(98);
        match(DongLangParser::COND_SPE);
        break;
      }

      case DongLangParser::RETURN: {
        enterOuterAlt(_localctx, 2);
        setState(100);
        ret_expression();
        setState(101);
        match(DongLangParser::COND_SPE);
        break;
      }

      case DongLangParser::IF: {
        enterOuterAlt(_localctx, 3);
        setState(103);
        if_expression();
        break;
      }

      case DongLangParser::FOR: {
        enterOuterAlt(_localctx, 4);
        setState(104);
        for_expression();
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
    setState(108);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::T__2) {
      setState(107);
      externC();
    }
    setState(110);
    match(DongLangParser::FUNC);
    setState(111);
    type_type_void();
    setState(112);
    match(DongLangParser::IDENTIFIER);
    setState(113);
    match(DongLangParser::T__0);
    setState(114);
    farg_list();
    setState(115);
    match(DongLangParser::T__1);
    setState(118);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__4: {
        setState(116);
        function_body();
        break;
      }

      case DongLangParser::COND_SPE: {
        setState(117);
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
    setState(120);
    match(DongLangParser::T__2);
    setState(121);
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
    setState(123);
    match(DongLangParser::T__4);
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115224887418882) != 0)) {
      setState(124);
      statement();
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(130);
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
    setState(132);
    type_type();
    setState(133);
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
    setState(135);
    match(DongLangParser::T__6);
    setState(136);
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
    setState(150);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__1: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case DongLangParser::T__12:
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::T__15:
      case DongLangParser::T__16:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(139);
        farg();
        setState(144);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(140);
            match(DongLangParser::T__6);
            setState(141);
            farg(); 
          }
          setState(146);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
        }
        setState(148);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DongLangParser::T__6) {
          setState(147);
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
    setState(152);
    match(DongLangParser::RETURN);
    setState(154);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 1)) & -9007126385239523327) != 0)) {
      setState(153);
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
    setState(162);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::COND_NOT: {
        setState(157);
        match(DongLangParser::COND_NOT);
        setState(158);
        expression(10);
        break;
      }

      case DongLangParser::NOT: {
        setState(159);
        match(DongLangParser::NOT);
        setState(160);
        expression(7);
        break;
      }

      case DongLangParser::T__0:
      case DongLangParser::TRUE:
      case DongLangParser::FALSE:
      case DongLangParser::POINTADDR:
      case DongLangParser::POINT:
      case DongLangParser::NIL:
      case DongLangParser::SUB:
      case DongLangParser::IDENTIFIER:
      case DongLangParser::NUMBER:
      case DongLangParser::STRING_LITERAL: {
        setState(161);
        primary();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(190);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(188);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(164);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(165);
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
          setState(166);
          expression(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(167);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(168);
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
          setState(169);
          expression(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(170);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(171);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 105555263750144) != 0))) {
            antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(172);
          expression(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(173);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(174);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 17732923532771328) != 0))) {
            antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(175);
          expression(6);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(176);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(177);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = match(DongLangParser::COND_AND);
          setState(178);
          expression(5);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(179);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(180);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = match(DongLangParser::COND_OR);
          setState(181);
          expression(4);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(182);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(183);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->threeOpr = match(DongLangParser::T__8);
          setState(184);
          expression(0);
          setState(185);
          match(DongLangParser::T__9);
          setState(186);
          expression(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(192);
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
    setState(196);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__0:
      case DongLangParser::T__12:
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::T__15:
      case DongLangParser::T__16:
      case DongLangParser::RETURN:
      case DongLangParser::FOR:
      case DongLangParser::IF:
      case DongLangParser::POINTADDR:
      case DongLangParser::POINT:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(193);
        statement();
        break;
      }

      case DongLangParser::BREAK:
      case DongLangParser::CONTINUE: {
        enterOuterAlt(_localctx, 2);
        setState(194);
        _la = _input->LA(1);
        if (!(_la == DongLangParser::BREAK

        || _la == DongLangParser::CONTINUE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(195);
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
    setState(198);
    match(DongLangParser::IF);
    setState(199);
    match(DongLangParser::T__0);
    setState(200);
    if_cond();
    setState(201);
    match(DongLangParser::T__1);
    setState(202);
    match(DongLangParser::T__4);
    setState(206);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115225088745474) != 0)) {
      setState(203);
      cond_statement();
      setState(208);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(209);
    match(DongLangParser::T__5);
    setState(213);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(210);
        elif_expr(); 
      }
      setState(215);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
    setState(217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::ELSE) {
      setState(216);
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
    setState(219);
    elif();
    setState(220);
    match(DongLangParser::T__0);
    setState(221);
    if_cond();
    setState(222);
    match(DongLangParser::T__1);
    setState(223);
    match(DongLangParser::T__4);
    setState(227);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115225088745474) != 0)) {
      setState(224);
      cond_statement();
      setState(229);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(230);
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
    setState(232);
    match(DongLangParser::ELSE);
    setState(233);
    match(DongLangParser::T__4);
    setState(237);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115225088745474) != 0)) {
      setState(234);
      cond_statement();
      setState(239);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(240);
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
    setState(245);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::ELIF: {
        enterOuterAlt(_localctx, 1);
        setState(242);
        match(DongLangParser::ELIF);
        break;
      }

      case DongLangParser::ELSE: {
        enterOuterAlt(_localctx, 2);
        setState(243);
        match(DongLangParser::ELSE);
        setState(244);
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
    setState(248);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(247);
      var_expression();
      break;
    }

    default:
      break;
    }
    setState(251);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::COND_SPE) {
      setState(250);
      match(DongLangParser::COND_SPE);
    }
    setState(254);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 1)) & -9007126385239523327) != 0)) {
      setState(253);
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
    setState(256);
    match(DongLangParser::FOR);
    setState(257);
    match(DongLangParser::T__0);
    setState(258);
    for_cond();
    setState(259);
    match(DongLangParser::T__1);
    setState(260);
    match(DongLangParser::T__4);
    setState(264);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115225088745474) != 0)) {
      setState(261);
      cond_statement();
      setState(266);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(267);
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
    setState(281);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(269);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(271);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 144115224583331842) != 0)) {
        setState(270);
        var_expression();
      }
      setState(273);
      match(DongLangParser::COND_SPE);
      setState(275);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 1) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 1)) & -9007126385239523327) != 0)) {
        setState(274);
        expression(0);
      }
      setState(277);
      match(DongLangParser::COND_SPE);
      setState(279);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 144115224583077890) != 0)) {
        setState(278);
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

tree::TerminalNode* DongLangParser::Global_var_expressionContext::TYPE() {
  return getToken(DongLangParser::TYPE, 0);
}

tree::TerminalNode* DongLangParser::Global_var_expressionContext::IDENTIFIER() {
  return getToken(DongLangParser::IDENTIFIER, 0);
}

DongLangParser::Type_typeContext* DongLangParser::Global_var_expressionContext::type_type() {
  return getRuleContext<DongLangParser::Type_typeContext>(0);
}

DongLangParser::Class_defContext* DongLangParser::Global_var_expressionContext::class_def() {
  return getRuleContext<DongLangParser::Class_defContext>(0);
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
    setState(290);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__12:
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::T__15:
      case DongLangParser::T__16:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(283);
        var_declares();
        break;
      }

      case DongLangParser::TYPE: {
        enterOuterAlt(_localctx, 2);
        setState(284);
        match(DongLangParser::TYPE);
        setState(285);
        match(DongLangParser::IDENTIFIER);
        setState(288);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case DongLangParser::T__12:
          case DongLangParser::T__13:
          case DongLangParser::T__14:
          case DongLangParser::T__15:
          case DongLangParser::T__16:
          case DongLangParser::IDENTIFIER: {
            setState(286);
            type_type();
            break;
          }

          case DongLangParser::T__18: {
            setState(287);
            class_def();
            break;
          }

        default:
          throw NoViableAltException(this);
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

//----------------- Var_expressionContext ------------------------------------------------------------------

DongLangParser::Var_expressionContext::Var_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
    setState(294);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(292);
      assigns();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(293);
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
    setState(296);
    match(DongLangParser::T__0);
    setState(297);
    expression(0);
    setState(298);
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
    setState(300);
    match(DongLangParser::IDENTIFIER);
    setState(301);
    match(DongLangParser::T__0);
    setState(302);
    expr_list();
    setState(303);
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
    setState(314);
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
      case DongLangParser::NIL:
      case DongLangParser::SUB:
      case DongLangParser::NOT:
      case DongLangParser::IDENTIFIER:
      case DongLangParser::NUMBER:
      case DongLangParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(306);
        expression(0);
        setState(311);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == DongLangParser::T__6) {
          setState(307);
          match(DongLangParser::T__6);
          setState(308);
          expression(0);
          setState(313);
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

tree::TerminalNode* DongLangParser::Num_primaryContext::NIL() {
  return getToken(DongLangParser::NIL, 0);
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
    setState(321);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::SUB:
      case DongLangParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(317);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DongLangParser::SUB) {
          setState(316);
          match(DongLangParser::SUB);
        }
        setState(319);
        match(DongLangParser::NUMBER);
        break;
      }

      case DongLangParser::NIL: {
        enterOuterAlt(_localctx, 2);
        setState(320);
        match(DongLangParser::NIL);
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
    setState(323);
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
    setState(325);
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
    setState(330);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::NIL:
      case DongLangParser::SUB:
      case DongLangParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(327);
        num_primary();
        break;
      }

      case DongLangParser::TRUE:
      case DongLangParser::FALSE: {
        enterOuterAlt(_localctx, 2);
        setState(328);
        bool_primary();
        break;
      }

      case DongLangParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(329);
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
    setState(332);
    match(DongLangParser::T__10);

    setState(333);
    expression(0);
    setState(334);
    match(DongLangParser::T__11);
   
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
    setState(360);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(337);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
      case 1: {
        setState(336);
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
      setState(345);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DongLangParser::POINT) {
        setState(339);
        match(DongLangParser::POINT);
        setState(341);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DongLangParser::POINTADDR) {
          setState(340);
          match(DongLangParser::POINTADDR);
        }
        setState(347);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(349);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
      case 1: {
        setState(348);
        match(DongLangParser::POINT);
        break;
      }

      default:
        break;
      }
      setState(357);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DongLangParser::POINTADDR

      || _la == DongLangParser::POINT) {
        setState(352);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DongLangParser::POINTADDR) {
          setState(351);
          match(DongLangParser::POINTADDR);
        }
        setState(354);
        match(DongLangParser::POINT);
        setState(359);
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
    setState(362);
    id_primary_p_addrs();
    setState(366);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      setState(363);
      match(DongLangParser::IDENTIFIER);
      break;
    }

    case 2: {
      setState(364);
      call_expr();
      break;
    }

    case 3: {
      setState(365);
      paran_expr();
      break;
    }

    default:
      break;
    }
    setState(371);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(368);
        array_index(); 
      }
      setState(373);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
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
    setState(376);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::TRUE:
      case DongLangParser::FALSE:
      case DongLangParser::NIL:
      case DongLangParser::SUB:
      case DongLangParser::NUMBER:
      case DongLangParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(374);
        value_primary();
        break;
      }

      case DongLangParser::T__0:
      case DongLangParser::POINTADDR:
      case DongLangParser::POINT:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(375);
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
    setState(378);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 253952) != 0))) {
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
    setState(380);
    match(DongLangParser::T__10);
    setState(382);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::NUMBER) {
      setState(381);
      match(DongLangParser::NUMBER);
    }
    setState(384);
    match(DongLangParser::T__11);
   
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

tree::TerminalNode* DongLangParser::Type_typeContext::IDENTIFIER() {
  return getToken(DongLangParser::IDENTIFIER, 0);
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
    setState(388);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__12:
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::T__15:
      case DongLangParser::T__16: {
        setState(386);
        primary_type();
        break;
      }

      case DongLangParser::IDENTIFIER: {
        setState(387);
        match(DongLangParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(394);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::T__10

    || _la == DongLangParser::POINT) {
      setState(392);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DongLangParser::POINT: {
          setState(390);
          match(DongLangParser::POINT);
          break;
        }

        case DongLangParser::T__10: {
          setState(391);
          array_type();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(396);
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
    setState(399);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__12:
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::T__15:
      case DongLangParser::T__16:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(397);
        type_type();
        break;
      }

      case DongLangParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(398);
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
    setState(403);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__0:
      case DongLangParser::TRUE:
      case DongLangParser::FALSE:
      case DongLangParser::POINTADDR:
      case DongLangParser::COND_NOT:
      case DongLangParser::POINT:
      case DongLangParser::NIL:
      case DongLangParser::SUB:
      case DongLangParser::NOT:
      case DongLangParser::IDENTIFIER:
      case DongLangParser::NUMBER:
      case DongLangParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(401);
        expression(0);
        break;
      }

      case DongLangParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(402);
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
    setState(420);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(405);
      match(DongLangParser::T__4);
      setState(406);
      var_arr_value();
      setState(411);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DongLangParser::T__6) {
        setState(407);
        match(DongLangParser::T__6);
        setState(408);
        var_arr_value();
        setState(413);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(414);
      match(DongLangParser::T__5);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(416);
      match(DongLangParser::T__4);
      setState(417);
      expr_list();
      setState(418);
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
    setState(433);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(422);
      id_primary();
      setState(428);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx)) {
      case 1: {
        setState(424);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 129778879299584) != 0)) {
          setState(423);
          antlrcpp::downCast<AssignContext *>(_localctx)->opr = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 129778879299584) != 0))) {
            antlrcpp::downCast<AssignContext *>(_localctx)->opr = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        setState(426);
        match(DongLangParser::T__17);
        setState(427);
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
      setState(430);
      id_primary();
      setState(431);
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
    setState(435);
    assign();
    setState(440);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::T__6) {
      setState(436);
      match(DongLangParser::T__6);
      setState(437);
      assign();
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
    setState(443);
    match(DongLangParser::IDENTIFIER);
    setState(446);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::T__17) {
      setState(444);
      match(DongLangParser::T__17);
      setState(445);
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
    setState(448);
    var();
    setState(453);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::T__6) {
      setState(449);
      match(DongLangParser::T__6);
      setState(450);
      var();
      setState(455);
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
    setState(456);
    type_type();
    setState(457);
    vars();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TemplateContext ------------------------------------------------------------------

DongLangParser::TemplateContext::TemplateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DongLangParser::TemplateContext::IDENTIFIER() {
  return getTokens(DongLangParser::IDENTIFIER);
}

tree::TerminalNode* DongLangParser::TemplateContext::IDENTIFIER(size_t i) {
  return getToken(DongLangParser::IDENTIFIER, i);
}


size_t DongLangParser::TemplateContext::getRuleIndex() const {
  return DongLangParser::RuleTemplate;
}

void DongLangParser::TemplateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTemplate(this);
}

void DongLangParser::TemplateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTemplate(this);
}


std::any DongLangParser::TemplateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitTemplate(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::TemplateContext* DongLangParser::template_() {
  TemplateContext *_localctx = _tracker.createInstance<TemplateContext>(_ctx, getState());
  enterRule(_localctx, 84, DongLangParser::RuleTemplate);
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
    setState(459);
    match(DongLangParser::T__10);
    setState(463);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::IDENTIFIER) {
      setState(460);
      match(DongLangParser::IDENTIFIER);
      setState(465);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(466);
    match(DongLangParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Class_defContext ------------------------------------------------------------------

DongLangParser::Class_defContext::Class_defContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DongLangParser::Class_defContext::getRuleIndex() const {
  return DongLangParser::RuleClass_def;
}

void DongLangParser::Class_defContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClass_def(this);
}

void DongLangParser::Class_defContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClass_def(this);
}


std::any DongLangParser::Class_defContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitClass_def(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Class_defContext* DongLangParser::class_def() {
  Class_defContext *_localctx = _tracker.createInstance<Class_defContext>(_ctx, getState());
  enterRule(_localctx, 86, DongLangParser::RuleClass_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(468);
    match(DongLangParser::T__18);
    setState(469);
    match(DongLangParser::T__4);
    setState(470);
    match(DongLangParser::T__5);
   
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
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);
    case 5: return precpred(_ctx, 3);
    case 6: return precpred(_ctx, 2);

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
