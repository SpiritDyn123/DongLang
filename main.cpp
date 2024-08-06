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
#include "include/dl_flag.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/TargetParser/TargetParser.h"  
#include "llvm/Support/TargetSelect.h"  
#include "llvm/Support/raw_ostream.h"  
#include "llvm/IR/LegacyPassManager.h"  
#include "llvm/IRReader/IRReader.h"  
#include "llvm/Bitcode/BitcodeReader.h"  
#include "llvm/IR/LegacyPassManager.h" 
#include "llvm/MC/TargetRegistry.h"

using namespace antlr4;

const string defaultLibContent = R"(
extern C func int printf(string fmt, ...);
extern C func byte* memcpy(byte *dst, byte*src, int len);
)";


int main(int argc, char** argv) {
	//cmd flags
	initFlags(argc, argv);

	DongLangBaseAST::InitLLVMAST();

	/*ANTLRInputStream st(R"(
		
	)");*/


	ifstream codeFile;
	codeFile.open(FLAGS_in);
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

	if (FLAGS_otype == "ll") {
		if (FLAGS_out == "") {
			//DongLangBaseAST::llvmModule->dump();
			lM.print(llvm::errs(), NULL);
		}
		else {
			std::error_code EC;
			raw_fd_ostream out(FLAGS_out, EC);
			lM.print(out, NULL);
		}
	}
	else if (FLAGS_otype == "exe") {
		/*string errStr = "";
		auto archName = "x86_64-pc-linux-gnu";
		const  llvm::Target* target = TargetRegistry::lookupTarget(archName, errStr);
		if (!target) {
			cout << "get target:" << archName << ",err:" << errStr << endl;
			return 0;
		}*/
		
	}
	

	return 0;
}