#include "DLGen.h"
#include "include/dl_flag.h"
#include "font/antlr4/gen/DongLangBaseListener.h"
#include "font/antlr4/gen/DongLangLexer.h"
#include "font/antlr4/gen/DongLangParser.h"
#include "antlr4-common.h"
#include "antlr4-runtime.h"
#include "font/ast/DongLangBaseAST.h"
#include "font/antlr4/DongLangLLVMListener.h"
#include "font/antlr4/DongLangLLVMVarListener.h"
#include "font/antlr4/DongLangLLVMExprTypeListener.h"

const string defaultLibContent = R"(
extern C func int printf(string fmt, ...);
extern C func byte* memcpy(byte *dst, byte*src, int len);
)";

bool DLGen::gen(GenBase* srcGen, bool final) {
	ifstream codeFile;
	codeFile.open(FLAGS_in);
	if (!codeFile.is_open()) {
		errs() << "read input file:" << FLAGS_in << " error";
		exit(1);
	}

	int defaultLine = 0;
	for (auto ch : defaultLibContent) {
		if (ch == '\n') {
			defaultLine++;
		}
	}

	stringstream rdBuf;
	rdBuf << defaultLibContent << endl;
	rdBuf << codeFile.rdbuf();
	string codeBuf(rdBuf.str());

	ANTLRInputStream st(codeBuf);
	DongLangLexer lexer(&st);
	CommonTokenStream tokens(&lexer);
	DongLangParser parser(&tokens);

	DongLangBaseAST::InitLLVMAST();

	//监听错误
	DongLangLLVMErrorListener errLis(defaultLine);
	parser.addErrorListener(&errLis);

	//实例化自己的listener
	DongLangParser::ProgContext* prog = parser.prog();

	//1:vars and scopes
	DongLangLLVMVarListener varLis;
	tree::ParseTreeWalker::DEFAULT.walk(&varLis, prog);

	//2:expression type analyse
	DongLangLLVMExprTypeListener etLis;
	tree::ParseTreeWalker::DEFAULT.walk(&etLis, prog);

	//3: lang
	DongLangLLVMListener lis(&etLis, defaultLine);
	tree::ParseTreeWalker::DEFAULT.walk(&lis, prog);

	lis.GetRootAST()->genCode();
	return true;
}
