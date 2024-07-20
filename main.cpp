#include <iostream>
//#include "font/DongLangBaseAST.h"
using namespace std;

#include "font/antlr4/gen/DongLangBaseListener.h"
#include "font/antlr4/gen/DongLangLexer.h"
#include "font/antlr4/gen/DongLangParser.h"
#include "antlr4-common.h"
#include "antlr4-runtime.h"
#include "font/ast/DongLangBaseAST.h"
#include "font/antlr4/DongLangLLVMListener.h"
#include "font/antlr4/DongLangLLVMVarListener.h"
#include "font/antlr4/DongLangLLVMExprTypeListener.h"

using namespace antlr4;

const string defaultLibContent = R"(
extern C func int printf(string fmt, ...);
extern C func byte* memcpy(byte *dst, byte*src, int len);
)";
int main() {

	DongLangBaseAST::InitLLVMAST();

	/*ANTLRInputStream st(R"(
		
	)");*/


	ifstream codeFile;
	codeFile.open("./tmp.dl");
	if (!codeFile.is_open()) {
		cout << "open file err" << endl;
		return 0;
	}

	stringstream rdBuf;
	rdBuf << defaultLibContent << endl;
	rdBuf << codeFile.rdbuf();
	string codeBuf(rdBuf.str());

	ANTLRInputStream st(codeBuf);
	DongLangLexer lexer(&st);
	CommonTokenStream tokens(&lexer);
	DongLangParser parser(&tokens);

	//监听错误
	DongLangLLVMErrorListener errLis;
	parser.addErrorListener(&errLis);

	//实例化自己的listener
	DongLangParser::ProgContext *prog = parser.prog();

	//1:vars and scopes
	DongLangLLVMVarListener varLis;
	tree::ParseTreeWalker::DEFAULT.walk(&varLis, prog);

	//2:expression type analyse
	DongLangLLVMExprTypeListener etLis;
	tree::ParseTreeWalker::DEFAULT.walk(&etLis, prog);

	//3: lang
	DongLangLLVMListener lis(&etLis);
	tree::ParseTreeWalker::DEFAULT.walk(&lis, prog);

	lis.GetRootAST()->genCode();
	//DongLangBaseAST::llvmModule->dump();
	DongLangBaseAST::llvmModule->print(errs(), NULL);

	//cout << "hello clang remote linux\n";
	return 0;
}