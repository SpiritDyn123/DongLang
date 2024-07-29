
// Generated from D:/vsprojects/DongLang/font/antlr4/DongLang.g4 by ANTLR 4.13.1


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
      "farg_default", "f_varargs", "farg_list", "ret_expression", "expression", 
      "cond_statement", "if_expression", "elif_expr", "else_expr", "elif", 
      "if_cond", "for_expression", "for_cond", "global_var_expression", 
      "var_expression", "paran_expr", "call_expr", "expr_list", "num_primary", 
      "str_primary", "bool_primary", "value_primary", "array_index", "id_primary_p_addrs", 
      "id_primary", "primary", "primary_type", "array_type", "type_type", 
      "type_type_void", "var_value", "var_arr_value", "assign", "assigns", 
      "var", "vars", "var_declares", "template", "class_def"
    },
    std::vector<std::string>{
      "", "'('", "')'", "'extern'", "'C'", "'{'", "'}'", "'='", "','", "'...'", 
      "'\\u003F'", "':'", "'['", "']'", "'int'", "'string'", "'float'", 
      "'bool'", "'byte'", "'class'", "'func'", "'return'", "'void'", "'true'", 
      "'false'", "'for'", "'break'", "'continue'", "'if'", "'else'", "'elif'", 
      "'&'", "'&&'", "'||'", "'!'", "", "'++'", "'--'", "';'", "'NIL'", 
      "'type'", "'+'", "'-'", "", "'/'", "'|'", "'^'", "'~'", "'=='", "'!='", 
      "'>'", "'<'", "'>='", "'<='", "", "", "", "", "", "", "", "", "", 
      "'NULL'"
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
  	4,1,64,497,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,1,0,1,0,1,0,1,0,5,0,95,8,0,10,0,12,0,98,9,0,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,108,8,1,1,2,3,2,111,8,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,3,2,121,8,2,1,3,1,3,1,3,1,4,1,4,5,4,128,8,4,10,4,
  	12,4,131,9,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,8,1,8,
  	1,8,1,8,5,8,149,8,8,10,8,12,8,152,9,8,1,8,1,8,5,8,156,8,8,10,8,12,8,159,
  	9,8,1,8,3,8,162,8,8,1,8,1,8,1,8,5,8,167,8,8,10,8,12,8,170,9,8,1,8,3,8,
  	173,8,8,3,8,175,8,8,1,9,1,9,3,9,179,8,9,1,10,1,10,1,10,1,10,1,10,1,10,
  	3,10,187,8,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,
  	213,8,10,10,10,12,10,216,9,10,1,11,1,11,1,11,3,11,221,8,11,1,12,1,12,
  	1,12,1,12,1,12,1,12,5,12,229,8,12,10,12,12,12,232,9,12,1,12,1,12,5,12,
  	236,8,12,10,12,12,12,239,9,12,1,12,3,12,242,8,12,1,13,1,13,1,13,1,13,
  	1,13,1,13,5,13,250,8,13,10,13,12,13,253,9,13,1,13,1,13,1,14,1,14,1,14,
  	5,14,260,8,14,10,14,12,14,263,9,14,1,14,1,14,1,15,1,15,1,15,3,15,270,
  	8,15,1,16,3,16,273,8,16,1,16,3,16,276,8,16,1,16,3,16,279,8,16,1,17,1,
  	17,1,17,1,17,1,17,1,17,5,17,287,8,17,10,17,12,17,290,9,17,1,17,1,17,1,
  	18,1,18,3,18,296,8,18,1,18,1,18,3,18,300,8,18,1,18,1,18,3,18,304,8,18,
  	3,18,306,8,18,1,19,1,19,1,19,1,19,1,19,3,19,313,8,19,3,19,315,8,19,1,
  	20,1,20,3,20,319,8,20,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,
  	23,1,23,1,23,1,23,5,23,334,8,23,10,23,12,23,337,9,23,3,23,339,8,23,1,
  	24,3,24,342,8,24,1,24,1,24,3,24,346,8,24,1,25,1,25,1,26,1,26,1,27,1,27,
  	1,27,3,27,355,8,27,1,28,1,28,1,28,1,28,1,29,3,29,362,8,29,1,29,1,29,3,
  	29,366,8,29,5,29,368,8,29,10,29,12,29,371,9,29,1,29,3,29,374,8,29,1,29,
  	3,29,377,8,29,1,29,5,29,380,8,29,10,29,12,29,383,9,29,3,29,385,8,29,1,
  	30,1,30,1,30,1,30,3,30,391,8,30,1,30,5,30,394,8,30,10,30,12,30,397,9,
  	30,1,31,1,31,3,31,401,8,31,1,32,1,32,1,33,1,33,3,33,407,8,33,1,33,1,33,
  	1,34,1,34,3,34,413,8,34,1,34,1,34,5,34,417,8,34,10,34,12,34,420,9,34,
  	1,35,1,35,3,35,424,8,35,1,36,1,36,3,36,428,8,36,1,37,1,37,1,37,1,37,5,
  	37,434,8,37,10,37,12,37,437,9,37,1,37,1,37,1,37,1,37,1,37,1,37,3,37,445,
  	8,37,1,38,1,38,3,38,449,8,38,1,38,1,38,3,38,453,8,38,1,38,1,38,1,38,3,
  	38,458,8,38,1,39,1,39,1,39,5,39,463,8,39,10,39,12,39,466,9,39,1,40,1,
  	40,1,40,3,40,471,8,40,1,41,1,41,1,41,5,41,476,8,41,10,41,12,41,479,9,
  	41,1,42,1,42,1,42,1,43,1,43,5,43,486,8,43,10,43,12,43,489,9,43,1,43,1,
  	43,1,44,1,44,1,44,1,44,1,44,0,1,20,45,0,2,4,6,8,10,12,14,16,18,20,22,
  	24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,
  	70,72,74,76,78,80,82,84,86,88,0,10,2,0,35,35,44,44,1,0,41,42,2,0,31,31,
  	45,46,1,0,48,53,1,0,26,27,1,0,23,24,2,0,31,31,35,35,1,0,14,18,4,0,31,
  	31,35,35,41,42,44,46,1,0,36,37,526,0,96,1,0,0,0,2,107,1,0,0,0,4,110,1,
  	0,0,0,6,122,1,0,0,0,8,125,1,0,0,0,10,134,1,0,0,0,12,137,1,0,0,0,14,141,
  	1,0,0,0,16,174,1,0,0,0,18,176,1,0,0,0,20,186,1,0,0,0,22,220,1,0,0,0,24,
  	222,1,0,0,0,26,243,1,0,0,0,28,256,1,0,0,0,30,269,1,0,0,0,32,272,1,0,0,
  	0,34,280,1,0,0,0,36,305,1,0,0,0,38,314,1,0,0,0,40,318,1,0,0,0,42,320,
  	1,0,0,0,44,324,1,0,0,0,46,338,1,0,0,0,48,345,1,0,0,0,50,347,1,0,0,0,52,
  	349,1,0,0,0,54,354,1,0,0,0,56,356,1,0,0,0,58,384,1,0,0,0,60,386,1,0,0,
  	0,62,400,1,0,0,0,64,402,1,0,0,0,66,404,1,0,0,0,68,412,1,0,0,0,70,423,
  	1,0,0,0,72,427,1,0,0,0,74,444,1,0,0,0,76,457,1,0,0,0,78,459,1,0,0,0,80,
  	467,1,0,0,0,82,472,1,0,0,0,84,480,1,0,0,0,86,483,1,0,0,0,88,492,1,0,0,
  	0,90,91,3,38,19,0,91,92,5,38,0,0,92,95,1,0,0,0,93,95,3,4,2,0,94,90,1,
  	0,0,0,94,93,1,0,0,0,95,98,1,0,0,0,96,94,1,0,0,0,96,97,1,0,0,0,97,1,1,
  	0,0,0,98,96,1,0,0,0,99,100,3,40,20,0,100,101,5,38,0,0,101,108,1,0,0,0,
  	102,103,3,18,9,0,103,104,5,38,0,0,104,108,1,0,0,0,105,108,3,24,12,0,106,
  	108,3,34,17,0,107,99,1,0,0,0,107,102,1,0,0,0,107,105,1,0,0,0,107,106,
  	1,0,0,0,108,3,1,0,0,0,109,111,3,6,3,0,110,109,1,0,0,0,110,111,1,0,0,0,
  	111,112,1,0,0,0,112,113,5,20,0,0,113,114,3,70,35,0,114,115,5,57,0,0,115,
  	116,5,1,0,0,116,117,3,16,8,0,117,120,5,2,0,0,118,121,3,8,4,0,119,121,
  	5,38,0,0,120,118,1,0,0,0,120,119,1,0,0,0,121,5,1,0,0,0,122,123,5,3,0,
  	0,123,124,5,4,0,0,124,7,1,0,0,0,125,129,5,5,0,0,126,128,3,2,1,0,127,126,
  	1,0,0,0,128,131,1,0,0,0,129,127,1,0,0,0,129,130,1,0,0,0,130,132,1,0,0,
  	0,131,129,1,0,0,0,132,133,5,6,0,0,133,9,1,0,0,0,134,135,3,68,34,0,135,
  	136,5,57,0,0,136,11,1,0,0,0,137,138,3,10,5,0,138,139,5,7,0,0,139,140,
  	3,20,10,0,140,13,1,0,0,0,141,142,5,8,0,0,142,143,5,9,0,0,143,15,1,0,0,
  	0,144,175,1,0,0,0,145,150,3,10,5,0,146,147,5,8,0,0,147,149,3,10,5,0,148,
  	146,1,0,0,0,149,152,1,0,0,0,150,148,1,0,0,0,150,151,1,0,0,0,151,157,1,
  	0,0,0,152,150,1,0,0,0,153,154,5,8,0,0,154,156,3,12,6,0,155,153,1,0,0,
  	0,156,159,1,0,0,0,157,155,1,0,0,0,157,158,1,0,0,0,158,161,1,0,0,0,159,
  	157,1,0,0,0,160,162,3,14,7,0,161,160,1,0,0,0,161,162,1,0,0,0,162,175,
  	1,0,0,0,163,168,3,12,6,0,164,165,5,8,0,0,165,167,3,12,6,0,166,164,1,0,
  	0,0,167,170,1,0,0,0,168,166,1,0,0,0,168,169,1,0,0,0,169,172,1,0,0,0,170,
  	168,1,0,0,0,171,173,3,14,7,0,172,171,1,0,0,0,172,173,1,0,0,0,173,175,
  	1,0,0,0,174,144,1,0,0,0,174,145,1,0,0,0,174,163,1,0,0,0,175,17,1,0,0,
  	0,176,178,5,21,0,0,177,179,3,20,10,0,178,177,1,0,0,0,178,179,1,0,0,0,
  	179,19,1,0,0,0,180,181,6,10,-1,0,181,182,5,34,0,0,182,187,3,20,10,10,
  	183,184,5,47,0,0,184,187,3,20,10,7,185,187,3,62,31,0,186,180,1,0,0,0,
  	186,183,1,0,0,0,186,185,1,0,0,0,187,214,1,0,0,0,188,189,10,9,0,0,189,
  	190,7,0,0,0,190,213,3,20,10,10,191,192,10,8,0,0,192,193,7,1,0,0,193,213,
  	3,20,10,9,194,195,10,6,0,0,195,196,7,2,0,0,196,213,3,20,10,7,197,198,
  	10,5,0,0,198,199,7,3,0,0,199,213,3,20,10,6,200,201,10,4,0,0,201,202,5,
  	32,0,0,202,213,3,20,10,5,203,204,10,3,0,0,204,205,5,33,0,0,205,213,3,
  	20,10,4,206,207,10,2,0,0,207,208,5,10,0,0,208,209,3,20,10,0,209,210,5,
  	11,0,0,210,211,3,20,10,3,211,213,1,0,0,0,212,188,1,0,0,0,212,191,1,0,
  	0,0,212,194,1,0,0,0,212,197,1,0,0,0,212,200,1,0,0,0,212,203,1,0,0,0,212,
  	206,1,0,0,0,213,216,1,0,0,0,214,212,1,0,0,0,214,215,1,0,0,0,215,21,1,
  	0,0,0,216,214,1,0,0,0,217,221,3,2,1,0,218,219,7,4,0,0,219,221,5,38,0,
  	0,220,217,1,0,0,0,220,218,1,0,0,0,221,23,1,0,0,0,222,223,5,28,0,0,223,
  	224,5,1,0,0,224,225,3,32,16,0,225,226,5,2,0,0,226,230,5,5,0,0,227,229,
  	3,22,11,0,228,227,1,0,0,0,229,232,1,0,0,0,230,228,1,0,0,0,230,231,1,0,
  	0,0,231,233,1,0,0,0,232,230,1,0,0,0,233,237,5,6,0,0,234,236,3,26,13,0,
  	235,234,1,0,0,0,236,239,1,0,0,0,237,235,1,0,0,0,237,238,1,0,0,0,238,241,
  	1,0,0,0,239,237,1,0,0,0,240,242,3,28,14,0,241,240,1,0,0,0,241,242,1,0,
  	0,0,242,25,1,0,0,0,243,244,3,30,15,0,244,245,5,1,0,0,245,246,3,32,16,
  	0,246,247,5,2,0,0,247,251,5,5,0,0,248,250,3,22,11,0,249,248,1,0,0,0,250,
  	253,1,0,0,0,251,249,1,0,0,0,251,252,1,0,0,0,252,254,1,0,0,0,253,251,1,
  	0,0,0,254,255,5,6,0,0,255,27,1,0,0,0,256,257,5,29,0,0,257,261,5,5,0,0,
  	258,260,3,22,11,0,259,258,1,0,0,0,260,263,1,0,0,0,261,259,1,0,0,0,261,
  	262,1,0,0,0,262,264,1,0,0,0,263,261,1,0,0,0,264,265,5,6,0,0,265,29,1,
  	0,0,0,266,270,5,30,0,0,267,268,5,29,0,0,268,270,5,28,0,0,269,266,1,0,
  	0,0,269,267,1,0,0,0,270,31,1,0,0,0,271,273,3,40,20,0,272,271,1,0,0,0,
  	272,273,1,0,0,0,273,275,1,0,0,0,274,276,5,38,0,0,275,274,1,0,0,0,275,
  	276,1,0,0,0,276,278,1,0,0,0,277,279,3,20,10,0,278,277,1,0,0,0,278,279,
  	1,0,0,0,279,33,1,0,0,0,280,281,5,25,0,0,281,282,5,1,0,0,282,283,3,36,
  	18,0,283,284,5,2,0,0,284,288,5,5,0,0,285,287,3,22,11,0,286,285,1,0,0,
  	0,287,290,1,0,0,0,288,286,1,0,0,0,288,289,1,0,0,0,289,291,1,0,0,0,290,
  	288,1,0,0,0,291,292,5,6,0,0,292,35,1,0,0,0,293,306,3,20,10,0,294,296,
  	3,40,20,0,295,294,1,0,0,0,295,296,1,0,0,0,296,297,1,0,0,0,297,299,5,38,
  	0,0,298,300,3,20,10,0,299,298,1,0,0,0,299,300,1,0,0,0,300,301,1,0,0,0,
  	301,303,5,38,0,0,302,304,3,78,39,0,303,302,1,0,0,0,303,304,1,0,0,0,304,
  	306,1,0,0,0,305,293,1,0,0,0,305,295,1,0,0,0,306,37,1,0,0,0,307,315,3,
  	84,42,0,308,309,5,40,0,0,309,312,5,57,0,0,310,313,3,68,34,0,311,313,3,
  	88,44,0,312,310,1,0,0,0,312,311,1,0,0,0,313,315,1,0,0,0,314,307,1,0,0,
  	0,314,308,1,0,0,0,315,39,1,0,0,0,316,319,3,78,39,0,317,319,3,84,42,0,
  	318,316,1,0,0,0,318,317,1,0,0,0,319,41,1,0,0,0,320,321,5,1,0,0,321,322,
  	3,20,10,0,322,323,5,2,0,0,323,43,1,0,0,0,324,325,5,57,0,0,325,326,5,1,
  	0,0,326,327,3,46,23,0,327,328,5,2,0,0,328,45,1,0,0,0,329,339,1,0,0,0,
  	330,335,3,20,10,0,331,332,5,8,0,0,332,334,3,20,10,0,333,331,1,0,0,0,334,
  	337,1,0,0,0,335,333,1,0,0,0,335,336,1,0,0,0,336,339,1,0,0,0,337,335,1,
  	0,0,0,338,329,1,0,0,0,338,330,1,0,0,0,339,47,1,0,0,0,340,342,5,42,0,0,
  	341,340,1,0,0,0,341,342,1,0,0,0,342,343,1,0,0,0,343,346,5,58,0,0,344,
  	346,5,39,0,0,345,341,1,0,0,0,345,344,1,0,0,0,346,49,1,0,0,0,347,348,5,
  	64,0,0,348,51,1,0,0,0,349,350,7,5,0,0,350,53,1,0,0,0,351,355,3,48,24,
  	0,352,355,3,52,26,0,353,355,3,50,25,0,354,351,1,0,0,0,354,352,1,0,0,0,
  	354,353,1,0,0,0,355,55,1,0,0,0,356,357,5,12,0,0,357,358,3,20,10,0,358,
  	359,5,13,0,0,359,57,1,0,0,0,360,362,7,6,0,0,361,360,1,0,0,0,361,362,1,
  	0,0,0,362,369,1,0,0,0,363,365,5,35,0,0,364,366,5,31,0,0,365,364,1,0,0,
  	0,365,366,1,0,0,0,366,368,1,0,0,0,367,363,1,0,0,0,368,371,1,0,0,0,369,
  	367,1,0,0,0,369,370,1,0,0,0,370,385,1,0,0,0,371,369,1,0,0,0,372,374,5,
  	35,0,0,373,372,1,0,0,0,373,374,1,0,0,0,374,381,1,0,0,0,375,377,5,31,0,
  	0,376,375,1,0,0,0,376,377,1,0,0,0,377,378,1,0,0,0,378,380,5,35,0,0,379,
  	376,1,0,0,0,380,383,1,0,0,0,381,379,1,0,0,0,381,382,1,0,0,0,382,385,1,
  	0,0,0,383,381,1,0,0,0,384,361,1,0,0,0,384,373,1,0,0,0,385,59,1,0,0,0,
  	386,390,3,58,29,0,387,391,5,57,0,0,388,391,3,44,22,0,389,391,3,42,21,
  	0,390,387,1,0,0,0,390,388,1,0,0,0,390,389,1,0,0,0,391,395,1,0,0,0,392,
  	394,3,56,28,0,393,392,1,0,0,0,394,397,1,0,0,0,395,393,1,0,0,0,395,396,
  	1,0,0,0,396,61,1,0,0,0,397,395,1,0,0,0,398,401,3,54,27,0,399,401,3,60,
  	30,0,400,398,1,0,0,0,400,399,1,0,0,0,401,63,1,0,0,0,402,403,7,7,0,0,403,
  	65,1,0,0,0,404,406,5,12,0,0,405,407,5,58,0,0,406,405,1,0,0,0,406,407,
  	1,0,0,0,407,408,1,0,0,0,408,409,5,13,0,0,409,67,1,0,0,0,410,413,3,64,
  	32,0,411,413,5,57,0,0,412,410,1,0,0,0,412,411,1,0,0,0,413,418,1,0,0,0,
  	414,417,5,35,0,0,415,417,3,66,33,0,416,414,1,0,0,0,416,415,1,0,0,0,417,
  	420,1,0,0,0,418,416,1,0,0,0,418,419,1,0,0,0,419,69,1,0,0,0,420,418,1,
  	0,0,0,421,424,3,68,34,0,422,424,5,22,0,0,423,421,1,0,0,0,423,422,1,0,
  	0,0,424,71,1,0,0,0,425,428,3,20,10,0,426,428,3,74,37,0,427,425,1,0,0,
  	0,427,426,1,0,0,0,428,73,1,0,0,0,429,430,5,5,0,0,430,435,3,74,37,0,431,
  	432,5,8,0,0,432,434,3,74,37,0,433,431,1,0,0,0,434,437,1,0,0,0,435,433,
  	1,0,0,0,435,436,1,0,0,0,436,438,1,0,0,0,437,435,1,0,0,0,438,439,5,6,0,
  	0,439,445,1,0,0,0,440,441,5,5,0,0,441,442,3,46,23,0,442,443,5,6,0,0,443,
  	445,1,0,0,0,444,429,1,0,0,0,444,440,1,0,0,0,445,75,1,0,0,0,446,452,3,
  	60,30,0,447,449,7,8,0,0,448,447,1,0,0,0,448,449,1,0,0,0,449,450,1,0,0,
  	0,450,451,5,7,0,0,451,453,3,20,10,0,452,448,1,0,0,0,452,453,1,0,0,0,453,
  	458,1,0,0,0,454,455,3,60,30,0,455,456,7,9,0,0,456,458,1,0,0,0,457,446,
  	1,0,0,0,457,454,1,0,0,0,458,77,1,0,0,0,459,464,3,76,38,0,460,461,5,8,
  	0,0,461,463,3,76,38,0,462,460,1,0,0,0,463,466,1,0,0,0,464,462,1,0,0,0,
  	464,465,1,0,0,0,465,79,1,0,0,0,466,464,1,0,0,0,467,470,5,57,0,0,468,469,
  	5,7,0,0,469,471,3,72,36,0,470,468,1,0,0,0,470,471,1,0,0,0,471,81,1,0,
  	0,0,472,477,3,80,40,0,473,474,5,8,0,0,474,476,3,80,40,0,475,473,1,0,0,
  	0,476,479,1,0,0,0,477,475,1,0,0,0,477,478,1,0,0,0,478,83,1,0,0,0,479,
  	477,1,0,0,0,480,481,3,68,34,0,481,482,3,82,41,0,482,85,1,0,0,0,483,487,
  	5,12,0,0,484,486,5,57,0,0,485,484,1,0,0,0,486,489,1,0,0,0,487,485,1,0,
  	0,0,487,488,1,0,0,0,488,490,1,0,0,0,489,487,1,0,0,0,490,491,5,13,0,0,
  	491,87,1,0,0,0,492,493,5,19,0,0,493,494,5,5,0,0,494,495,5,6,0,0,495,89,
  	1,0,0,0,64,94,96,107,110,120,129,150,157,161,168,172,174,178,186,212,
  	214,220,230,237,241,251,261,269,272,275,278,288,295,299,303,305,312,314,
  	318,335,338,341,345,354,361,365,369,373,376,381,384,390,395,400,406,412,
  	416,418,423,427,435,444,448,452,457,464,470,477,487
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
    setState(96);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144116287589040136) != 0)) {
      setState(94);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DongLangParser::T__13:
        case DongLangParser::T__14:
        case DongLangParser::T__15:
        case DongLangParser::T__16:
        case DongLangParser::T__17:
        case DongLangParser::TYPE:
        case DongLangParser::IDENTIFIER: {
          setState(90);
          global_var_expression();
          setState(91);
          match(DongLangParser::COND_SPE);
          break;
        }

        case DongLangParser::T__2:
        case DongLangParser::FUNC: {
          setState(93);
          function_def();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(98);
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
    setState(107);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__0:
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::T__15:
      case DongLangParser::T__16:
      case DongLangParser::T__17:
      case DongLangParser::POINTADDR:
      case DongLangParser::POINT:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(99);
        var_expression();
        setState(100);
        match(DongLangParser::COND_SPE);
        break;
      }

      case DongLangParser::RETURN: {
        enterOuterAlt(_localctx, 2);
        setState(102);
        ret_expression();
        setState(103);
        match(DongLangParser::COND_SPE);
        break;
      }

      case DongLangParser::IF: {
        enterOuterAlt(_localctx, 3);
        setState(105);
        if_expression();
        break;
      }

      case DongLangParser::FOR: {
        enterOuterAlt(_localctx, 4);
        setState(106);
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
    setState(110);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::T__2) {
      setState(109);
      externC();
    }
    setState(112);
    match(DongLangParser::FUNC);
    setState(113);
    type_type_void();
    setState(114);
    match(DongLangParser::IDENTIFIER);
    setState(115);
    match(DongLangParser::T__0);
    setState(116);
    farg_list();
    setState(117);
    match(DongLangParser::T__1);
    setState(120);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__4: {
        setState(118);
        function_body();
        break;
      }

      case DongLangParser::COND_SPE: {
        setState(119);
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
    setState(122);
    match(DongLangParser::T__2);
    setState(123);
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
    setState(125);
    match(DongLangParser::T__4);
    setState(129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115224887672834) != 0)) {
      setState(126);
      statement();
      setState(131);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(132);
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
    setState(134);
    type_type();
    setState(135);
    match(DongLangParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Farg_defaultContext ------------------------------------------------------------------

DongLangParser::Farg_defaultContext::Farg_defaultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DongLangParser::FargContext* DongLangParser::Farg_defaultContext::farg() {
  return getRuleContext<DongLangParser::FargContext>(0);
}

DongLangParser::ExpressionContext* DongLangParser::Farg_defaultContext::expression() {
  return getRuleContext<DongLangParser::ExpressionContext>(0);
}


size_t DongLangParser::Farg_defaultContext::getRuleIndex() const {
  return DongLangParser::RuleFarg_default;
}

void DongLangParser::Farg_defaultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFarg_default(this);
}

void DongLangParser::Farg_defaultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DongLangListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFarg_default(this);
}


std::any DongLangParser::Farg_defaultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DongLangVisitor*>(visitor))
    return parserVisitor->visitFarg_default(this);
  else
    return visitor->visitChildren(this);
}

DongLangParser::Farg_defaultContext* DongLangParser::farg_default() {
  Farg_defaultContext *_localctx = _tracker.createInstance<Farg_defaultContext>(_ctx, getState());
  enterRule(_localctx, 12, DongLangParser::RuleFarg_default);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    farg();
    setState(138);
    match(DongLangParser::T__6);
    setState(139);
    expression(0);
   
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
  enterRule(_localctx, 14, DongLangParser::RuleF_varargs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(DongLangParser::T__7);
    setState(142);
    match(DongLangParser::T__8);
   
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

std::vector<DongLangParser::Farg_defaultContext *> DongLangParser::Farg_listContext::farg_default() {
  return getRuleContexts<DongLangParser::Farg_defaultContext>();
}

DongLangParser::Farg_defaultContext* DongLangParser::Farg_listContext::farg_default(size_t i) {
  return getRuleContext<DongLangParser::Farg_defaultContext>(i);
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
  enterRule(_localctx, 16, DongLangParser::RuleFarg_list);
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
    setState(174);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);

      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(145);
      farg();
      setState(150);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(146);
          match(DongLangParser::T__7);
          setState(147);
          farg(); 
        }
        setState(152);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      }
      setState(157);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(153);
          match(DongLangParser::T__7);
          setState(154);
          farg_default(); 
        }
        setState(159);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      }
      setState(161);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DongLangParser::T__7) {
        setState(160);
        f_varargs();
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(163);
      farg_default();
      setState(168);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(164);
          match(DongLangParser::T__7);
          setState(165);
          farg_default(); 
        }
        setState(170);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(172);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DongLangParser::T__7) {
        setState(171);
        f_varargs();
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
  enterRule(_localctx, 18, DongLangParser::RuleRet_expression);
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
    setState(176);
    match(DongLangParser::RETURN);
    setState(178);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 1)) & -9007126385239523327) != 0)) {
      setState(177);
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
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, DongLangParser::RuleExpression, precedence);

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
    setState(186);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::COND_NOT: {
        setState(181);
        match(DongLangParser::COND_NOT);
        setState(182);
        expression(10);
        break;
      }

      case DongLangParser::NOT: {
        setState(183);
        match(DongLangParser::NOT);
        setState(184);
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
        setState(185);
        primary();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(214);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(212);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(188);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(189);
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
          setState(190);
          expression(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(191);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(192);
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
          setState(193);
          expression(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(194);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(195);
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
          setState(196);
          expression(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(197);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(198);
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
          setState(199);
          expression(6);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(200);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(201);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = match(DongLangParser::COND_AND);
          setState(202);
          expression(5);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(203);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(204);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->opr = match(DongLangParser::COND_OR);
          setState(205);
          expression(4);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(206);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(207);
          antlrcpp::downCast<ExpressionContext *>(_localctx)->threeOpr = match(DongLangParser::T__9);
          setState(208);
          expression(0);
          setState(209);
          match(DongLangParser::T__10);
          setState(210);
          expression(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(216);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
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
  enterRule(_localctx, 22, DongLangParser::RuleCond_statement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(220);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__0:
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::T__15:
      case DongLangParser::T__16:
      case DongLangParser::T__17:
      case DongLangParser::RETURN:
      case DongLangParser::FOR:
      case DongLangParser::IF:
      case DongLangParser::POINTADDR:
      case DongLangParser::POINT:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(217);
        statement();
        break;
      }

      case DongLangParser::BREAK:
      case DongLangParser::CONTINUE: {
        enterOuterAlt(_localctx, 2);
        setState(218);
        _la = _input->LA(1);
        if (!(_la == DongLangParser::BREAK

        || _la == DongLangParser::CONTINUE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(219);
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
  enterRule(_localctx, 24, DongLangParser::RuleIf_expression);
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
    setState(222);
    match(DongLangParser::IF);
    setState(223);
    match(DongLangParser::T__0);
    setState(224);
    if_cond();
    setState(225);
    match(DongLangParser::T__1);
    setState(226);
    match(DongLangParser::T__4);
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115225088999426) != 0)) {
      setState(227);
      cond_statement();
      setState(232);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(233);
    match(DongLangParser::T__5);
    setState(237);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(234);
        elif_expr(); 
      }
      setState(239);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
    setState(241);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::ELSE) {
      setState(240);
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
  enterRule(_localctx, 26, DongLangParser::RuleElif_expr);
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
    setState(243);
    elif();
    setState(244);
    match(DongLangParser::T__0);
    setState(245);
    if_cond();
    setState(246);
    match(DongLangParser::T__1);
    setState(247);
    match(DongLangParser::T__4);
    setState(251);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115225088999426) != 0)) {
      setState(248);
      cond_statement();
      setState(253);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(254);
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
  enterRule(_localctx, 28, DongLangParser::RuleElse_expr);
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
    match(DongLangParser::ELSE);
    setState(257);
    match(DongLangParser::T__4);
    setState(261);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115225088999426) != 0)) {
      setState(258);
      cond_statement();
      setState(263);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(264);
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
  enterRule(_localctx, 30, DongLangParser::RuleElif);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(269);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::ELIF: {
        enterOuterAlt(_localctx, 1);
        setState(266);
        match(DongLangParser::ELIF);
        break;
      }

      case DongLangParser::ELSE: {
        enterOuterAlt(_localctx, 2);
        setState(267);
        match(DongLangParser::ELSE);
        setState(268);
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
  enterRule(_localctx, 32, DongLangParser::RuleIf_cond);
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
    setState(272);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(271);
      var_expression();
      break;
    }

    default:
      break;
    }
    setState(275);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::COND_SPE) {
      setState(274);
      match(DongLangParser::COND_SPE);
    }
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 1)) & -9007126385239523327) != 0)) {
      setState(277);
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
  enterRule(_localctx, 34, DongLangParser::RuleFor_expression);
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
    setState(280);
    match(DongLangParser::FOR);
    setState(281);
    match(DongLangParser::T__0);
    setState(282);
    for_cond();
    setState(283);
    match(DongLangParser::T__1);
    setState(284);
    match(DongLangParser::T__4);
    setState(288);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115225088999426) != 0)) {
      setState(285);
      cond_statement();
      setState(290);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(291);
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
  enterRule(_localctx, 36, DongLangParser::RuleFor_cond);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(293);
      expression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(295);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 144115224583585794) != 0)) {
        setState(294);
        var_expression();
      }
      setState(297);
      match(DongLangParser::COND_SPE);
      setState(299);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 1) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 1)) & -9007126385239523327) != 0)) {
        setState(298);
        expression(0);
      }
      setState(301);
      match(DongLangParser::COND_SPE);
      setState(303);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 144115224583077890) != 0)) {
        setState(302);
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
  enterRule(_localctx, 38, DongLangParser::RuleGlobal_var_expression);

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
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::T__15:
      case DongLangParser::T__16:
      case DongLangParser::T__17:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(307);
        var_declares();
        break;
      }

      case DongLangParser::TYPE: {
        enterOuterAlt(_localctx, 2);
        setState(308);
        match(DongLangParser::TYPE);
        setState(309);
        match(DongLangParser::IDENTIFIER);
        setState(312);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case DongLangParser::T__13:
          case DongLangParser::T__14:
          case DongLangParser::T__15:
          case DongLangParser::T__16:
          case DongLangParser::T__17:
          case DongLangParser::IDENTIFIER: {
            setState(310);
            type_type();
            break;
          }

          case DongLangParser::T__18: {
            setState(311);
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
  enterRule(_localctx, 40, DongLangParser::RuleVar_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(318);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(316);
      assigns();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(317);
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
  enterRule(_localctx, 42, DongLangParser::RuleParan_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(320);
    match(DongLangParser::T__0);
    setState(321);
    expression(0);
    setState(322);
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
  enterRule(_localctx, 44, DongLangParser::RuleCall_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    match(DongLangParser::IDENTIFIER);
    setState(325);
    match(DongLangParser::T__0);
    setState(326);
    expr_list();
    setState(327);
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
  enterRule(_localctx, 46, DongLangParser::RuleExpr_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(338);
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
        setState(330);
        expression(0);
        setState(335);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == DongLangParser::T__7) {
          setState(331);
          match(DongLangParser::T__7);
          setState(332);
          expression(0);
          setState(337);
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
  enterRule(_localctx, 48, DongLangParser::RuleNum_primary);
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
    switch (_input->LA(1)) {
      case DongLangParser::SUB:
      case DongLangParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(341);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DongLangParser::SUB) {
          setState(340);
          match(DongLangParser::SUB);
        }
        setState(343);
        match(DongLangParser::NUMBER);
        break;
      }

      case DongLangParser::NIL: {
        enterOuterAlt(_localctx, 2);
        setState(344);
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
  enterRule(_localctx, 50, DongLangParser::RuleStr_primary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
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
  enterRule(_localctx, 52, DongLangParser::RuleBool_primary);
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
    setState(349);
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
  enterRule(_localctx, 54, DongLangParser::RuleValue_primary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(354);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::NIL:
      case DongLangParser::SUB:
      case DongLangParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(351);
        num_primary();
        break;
      }

      case DongLangParser::TRUE:
      case DongLangParser::FALSE: {
        enterOuterAlt(_localctx, 2);
        setState(352);
        bool_primary();
        break;
      }

      case DongLangParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(353);
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
  enterRule(_localctx, 56, DongLangParser::RuleArray_index);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    match(DongLangParser::T__11);

    setState(357);
    expression(0);
    setState(358);
    match(DongLangParser::T__12);
   
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
  enterRule(_localctx, 58, DongLangParser::RuleId_primary_p_addrs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(384);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(361);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
      case 1: {
        setState(360);
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
      setState(369);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DongLangParser::POINT) {
        setState(363);
        match(DongLangParser::POINT);
        setState(365);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DongLangParser::POINTADDR) {
          setState(364);
          match(DongLangParser::POINTADDR);
        }
        setState(371);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(373);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
      case 1: {
        setState(372);
        match(DongLangParser::POINT);
        break;
      }

      default:
        break;
      }
      setState(381);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DongLangParser::POINTADDR

      || _la == DongLangParser::POINT) {
        setState(376);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == DongLangParser::POINTADDR) {
          setState(375);
          match(DongLangParser::POINTADDR);
        }
        setState(378);
        match(DongLangParser::POINT);
        setState(383);
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
  enterRule(_localctx, 60, DongLangParser::RuleId_primary);

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
    setState(386);
    id_primary_p_addrs();
    setState(390);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(387);
      match(DongLangParser::IDENTIFIER);
      break;
    }

    case 2: {
      setState(388);
      call_expr();
      break;
    }

    case 3: {
      setState(389);
      paran_expr();
      break;
    }

    default:
      break;
    }
    setState(395);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(392);
        array_index(); 
      }
      setState(397);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx);
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
  enterRule(_localctx, 62, DongLangParser::RulePrimary);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(400);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::TRUE:
      case DongLangParser::FALSE:
      case DongLangParser::NIL:
      case DongLangParser::SUB:
      case DongLangParser::NUMBER:
      case DongLangParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(398);
        value_primary();
        break;
      }

      case DongLangParser::T__0:
      case DongLangParser::POINTADDR:
      case DongLangParser::POINT:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(399);
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
  enterRule(_localctx, 64, DongLangParser::RulePrimary_type);
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
    setState(402);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 507904) != 0))) {
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
  enterRule(_localctx, 66, DongLangParser::RuleArray_type);
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
    setState(404);
    match(DongLangParser::T__11);
    setState(406);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::NUMBER) {
      setState(405);
      match(DongLangParser::NUMBER);
    }
    setState(408);
    match(DongLangParser::T__12);
   
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
  enterRule(_localctx, 68, DongLangParser::RuleType_type);
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
    setState(412);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::T__15:
      case DongLangParser::T__16:
      case DongLangParser::T__17: {
        setState(410);
        primary_type();
        break;
      }

      case DongLangParser::IDENTIFIER: {
        setState(411);
        match(DongLangParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(418);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::T__11

    || _la == DongLangParser::POINT) {
      setState(416);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DongLangParser::POINT: {
          setState(414);
          match(DongLangParser::POINT);
          break;
        }

        case DongLangParser::T__11: {
          setState(415);
          array_type();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(420);
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
  enterRule(_localctx, 70, DongLangParser::RuleType_type_void);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(423);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DongLangParser::T__13:
      case DongLangParser::T__14:
      case DongLangParser::T__15:
      case DongLangParser::T__16:
      case DongLangParser::T__17:
      case DongLangParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(421);
        type_type();
        break;
      }

      case DongLangParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(422);
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
  enterRule(_localctx, 72, DongLangParser::RuleVar_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(427);
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
        setState(425);
        expression(0);
        break;
      }

      case DongLangParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(426);
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
  enterRule(_localctx, 74, DongLangParser::RuleVar_arr_value);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(444);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(429);
      match(DongLangParser::T__4);
      setState(430);
      var_arr_value();
      setState(435);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DongLangParser::T__7) {
        setState(431);
        match(DongLangParser::T__7);
        setState(432);
        var_arr_value();
        setState(437);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(438);
      match(DongLangParser::T__5);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(440);
      match(DongLangParser::T__4);
      setState(441);
      expr_list();
      setState(442);
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
  enterRule(_localctx, 76, DongLangParser::RuleAssign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(457);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(446);
      id_primary();
      setState(452);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
      case 1: {
        setState(448);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 129778879299584) != 0)) {
          setState(447);
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
        setState(450);
        match(DongLangParser::T__6);
        setState(451);
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
      setState(454);
      id_primary();
      setState(455);
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
  enterRule(_localctx, 78, DongLangParser::RuleAssigns);
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
    assign();
    setState(464);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::T__7) {
      setState(460);
      match(DongLangParser::T__7);
      setState(461);
      assign();
      setState(466);
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
  enterRule(_localctx, 80, DongLangParser::RuleVar);
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
    setState(467);
    match(DongLangParser::IDENTIFIER);
    setState(470);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DongLangParser::T__6) {
      setState(468);
      match(DongLangParser::T__6);
      setState(469);
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
  enterRule(_localctx, 82, DongLangParser::RuleVars);
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
    setState(472);
    var();
    setState(477);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::T__7) {
      setState(473);
      match(DongLangParser::T__7);
      setState(474);
      var();
      setState(479);
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
  enterRule(_localctx, 84, DongLangParser::RuleVar_declares);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(480);
    type_type();
    setState(481);
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
  enterRule(_localctx, 86, DongLangParser::RuleTemplate);
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
    setState(483);
    match(DongLangParser::T__11);
    setState(487);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DongLangParser::IDENTIFIER) {
      setState(484);
      match(DongLangParser::IDENTIFIER);
      setState(489);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(490);
    match(DongLangParser::T__12);
   
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
  enterRule(_localctx, 88, DongLangParser::RuleClass_def);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(492);
    match(DongLangParser::T__18);
    setState(493);
    match(DongLangParser::T__4);
    setState(494);
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
    case 10: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

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
