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
#include "llvm/TargetParser/Host.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"

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
	DongLangParser::ProgContext* prog = parser.prog();

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

			cout << "gen " << FLAGS_out << endl;
		}
	}
	else if (FLAGS_otype == "asm" || FLAGS_otype == "exe") {
		if (FLAGS_out == "") {
			cout << "exe file name empty" << endl;
			return 0;
		}

		string errStr = "";
		auto defaultTargetTrip = sys::getDefaultTargetTriple();
		const  llvm::Target* target = TargetRegistry::lookupTarget(defaultTargetTrip, errStr);
		if (!target) {
			cout << "get target:" << defaultTargetTrip << ",err:" << errStr << endl;
			return 0;
		}

		auto CPU = "generic";
		auto Features = "";

		TargetOptions opt;
		auto RM = FLAGS_fpie ? Reloc::DynamicNoPIC : FLAGS_fpic ? Reloc::PIC_ : optional<Reloc::Model>();
		auto machine = target->createTargetMachine(defaultTargetTrip, CPU, Features, opt, RM);
		lM.setDataLayout(machine->createDataLayout());
		lM.setTargetTriple(defaultTargetTrip);

		std::error_code EC;
		raw_fd_ostream out(FLAGS_out, EC);
		if (EC) {
			cout << FLAGS_out << " out file open err:" << EC.message() << endl;
			return 0;
		}

		auto fileType = FLAGS_otype == "asm" ? CGFT_AssemblyFile : CGFT_ObjectFile;
		legacy::PassManager pass;
		if (machine->addPassesToEmitFile(pass, out, NULL, fileType)) {
			cout << "addPassesToEmitFile err:" << endl;
			return 0;
		}
		
		pass.run(lM);
		out.flush();

		cout << "gen " << FLAGS_out << endl;
	}
	
	return 0;
}