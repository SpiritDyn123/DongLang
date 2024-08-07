#include "GenBase.h" 
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


GenBase* createGen(GenBase::emGenType gt) {
	switch (gt) {
	case GenBase::genType_dl:
		return new DLGen();
	case GenBase::genType_ll:
		return new LLGen();
	case GenBase::genType_asm:
		return new AsmGen();
	case GenBase::genType_obj:
		return new ObjGen();
	case GenBase::genType_exe:
		return new ExeGen();
	}

	return NULL;
}

GenBase::GenBase() {

}

TargetMachine* GenBase::getTargetMachine() {
	string errStr = "";
	auto defaultTargetTrip = sys::getDefaultTargetTriple();
	const  llvm::Target* target = TargetRegistry::lookupTarget(defaultTargetTrip, errStr);
	if (!target) {
		errs() << "get target:" << defaultTargetTrip << ",err:" << errStr;
		return NULL;
	}

	auto CPU = "generic";
	auto Features = "";

	TargetOptions opt;
	auto RM = FLAGS_fpie ? Reloc::DynamicNoPIC : FLAGS_fpic ? Reloc::PIC_ : optional<Reloc::Model>();
	auto machine = target->createTargetMachine(defaultTargetTrip, CPU, Features, opt, RM);
	lM.setDataLayout(machine->createDataLayout());
	lM.setTargetTriple(defaultTargetTrip);

	return machine;
}

string GenBase::getOutFileName() {
	string outFile = FLAGS_in;
	int sIndex = outFile.find_last_of('.');
	if (sIndex >= 0) {
		outFile = outFile.substr(0, sIndex);
	}
	
	switch (genType()) {
	case GenBase::genType_dl:
		outFile += ".dl";
	case GenBase::genType_ll:
		outFile += ".ll";
	case GenBase::genType_asm:
		outFile += ".s";
	case GenBase::genType_obj:
		outFile += ".o";
	case GenBase::genType_exe:
		outFile = FLAGS_out != "" ? FLAGS_out : outFile;
	}

	return outFile;
}

bool GenBase::genWrap(GenBase* srcGen) {
	auto srcGT = srcGen->genType();
	auto dstGT = genType();
	if (srcGT >= dstGT) {
		return false;
	}

	vector<GenBase*> genQueue = { srcGen };
	if (srcGT == genType_dl) {
		if (dstGT >= genType_asm) {
			genQueue.push_back(createGen(genType_ll));
		}

		if (dstGT >= genType_exe) {
			genQueue.push_back(createGen(genType_obj));
		}
	}
	else if (srcGT == genType_ll || srcGT == genType_asm) {
		if (dstGT >= genType_exe) {
			genQueue.push_back(createGen(genType_obj));
		}
	}

	genQueue.push_back(this);
	GenBase* srcGen = NULL;
	for (auto curGen : genQueue) {
		if (!curGen->gen(srcGen, curGen == this)) {
			return false;
		}
		srcGen = curGen;
	}

	return true;
}

bool DLGen::gen(GenBase* srcGen, bool final) {
	ifstream codeFile;
	codeFile.open(FLAGS_in);
	if (!codeFile.is_open()) {
		errs() << "read input file:" << FLAGS_in << " error";
		exit(1);
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
	return true;
}

bool LLGen::gen(GenBase* srcGen, bool final) {
	string outFile = getOutFileName();
	if (final) {
		std::error_code EC;
		raw_fd_ostream out(outFile, EC);
		lM.print(out, NULL);
		if (EC) {
			errs() << "LLGen err:" << EC.message();
			return false;
		}

		return true;
	}
	
	//转换成Module
	if (!srcGen) {
		llvm::SMDiagnostic EC;
		auto module = parseIRFile(FLAGS_in, EC, lC);
		if (!module) {
			errs() << "LLGen parseIRFile err:" << EC;
			return false;
		}

		//lM重新赋值
		delete DongLangBaseAST::llvmModule;
		DongLangBaseAST::llvmModule = module.get();
	}
	
	return true;
}

bool AsmGen::gen(GenBase* srcGen, bool final) {
	string outFile = getOutFileName();
	if (srcGen) {
		auto targetMachine = getTargetMachine();
		if (!targetMachine) {
			return false;
		}

		std::error_code EC;
		raw_fd_ostream out(outFile, EC);
		if (EC) {
			errs() << "AsmGen " << FLAGS_out << " out file open err:" << EC.message();
			return false;
		}

		auto fileType = CGFT_AssemblyFile ;
		legacy::PassManager pass;
		if (targetMachine->addPassesToEmitFile(pass, out, NULL, fileType)) {
			errs() << "AsmGen " << "addPassesToEmitFile err error:" << EC.message();
			return false;
		}

		pass.run(lM);
		out.flush();
	}

	return true;
}

bool ObjGen::gen(GenBase* srcGen, bool final) {
	string outFile = getOutFileName();
	if (srcGen) {
		if (srcGen->genType() == genType_asm) {

		}
		else {
			auto targetMachine = getTargetMachine();
			if (!targetMachine) {
				return false;
			}

			std::error_code EC;
			raw_fd_ostream out(outFile, EC);
			if (EC) {
				errs() << "ObjGen " << FLAGS_out << " out file open err:" << EC.message();
				return false;
			}

			auto fileType = CGFT_ObjectFile;
			legacy::PassManager pass;
			if (targetMachine->addPassesToEmitFile(pass, out, NULL, fileType)) {
				errs() << "ObjGen " << "addPassesToEmitFile err error:" << EC.message();
				return false;
			}

			pass.run(lM);
			out.flush();
		}
		return true;
	}
}

bool ExeGen::gen(GenBase* srcGen, bool final) {

}