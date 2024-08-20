#include "GenBase.h" 

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
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Object/ObjectFile.h>
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Object/ObjectFile.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ErrorOr.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include <memory>
#include <system_error>
#include "DLGen.h"
#include "font/ast/DongLangBaseAST.h"
#ifdef CUSTOM_PASS_OPR
#include "backend/pass/CustomPass.h"
#endif

using namespace antlr4;

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
	default:
		return NULL;
	}
}

legacy::PassManagerBase* GenBase::passMgr = NULL;

GenBase::GenBase() {

}


TargetMachine* GenBase::getTargetMachine(llvm::Module& lModule, llvm::LLVMContext& lCtx) {
 
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
		break;
	case GenBase::genType_ll:
		outFile += ".ll";
		break;
	case GenBase::genType_asm:
		outFile += ".s";
		break;
	case GenBase::genType_obj:
		outFile += ".o";
		break;
	case GenBase::genType_exe:
		outFile = FLAGS_out != "" ? FLAGS_out : outFile + ".out";
		break;
	default:
		break;
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

	llvm::InitializeAllTargetInfos();
	llvm::InitializeAllTargets();
	llvm::InitializeAllTargetMCs();
	llvm::InitializeAllAsmParsers();
	llvm::InitializeAllAsmPrinters();

	GenBase* sGen = NULL;
	for (auto curGen : genQueue) {
		if (!curGen->gen(sGen, curGen == this)) {
			return false;
		}
		sGen = curGen;
	}

	for (int i = 1; i < genQueue.size() - 1; i++) {
		//删除中间文件
		string tmpFile = genQueue[i]->getOutFileName().c_str();
		remove(tmpFile.c_str());
	}

	cout << "gen file:" << this->getOutFileName() << " success\n";

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
		DongLangBaseAST::llvmCtx = new llvm::LLVMContext();
		auto module = parseIRFile(FLAGS_in, EC, lC);
		if (!module) {
			errs() << "LLGen parseIRFile err:" << EC.getMessage();
			return false;
		}

		//lM重新赋值

		DongLangBaseAST::llvmModule = module.release();

	
	}
	
	//pass
	InitCustomPass(passMgr, lM);
	
	return true;
}

bool AsmGen::gen(GenBase* srcGen, bool final) {
	string outFile = getOutFileName();
	if (srcGen) {
		auto targetMachine = getTargetMachine(lM, lC);
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
		if (targetMachine->addPassesToEmitFile(*passMgr, out, NULL, fileType)) {
			errs() << "AsmGen " << "addPassesToEmitFile err error:" << EC.message();
			return false;
		}

#if defined(CUSTOM_PASS_OPR) && CUSTOM_PASS_OPR == 1  //function pass
		auto funPassMgr = (legacy::FunctionPassManager*)passMgr;
		for (auto& fun : lM) {
			if (fun.isDeclaration() || fun.isIntrinsic()) continue;
			funPassMgr->run(fun);
		}
#elif !defined(CUSTOM_PASS_OPR) || CUSTOM_PASS_OPR == 0
		((legacy::PassManager*)passMgr)->run(lM);
#elif defined(CUSTOM_PASS_OPR) && CUSTOM_PASS_OPR == 2

#endif
		out.flush();
	}

	return true;
}

bool ObjGen::gen(GenBase* srcGen, bool final) {
	string outFile = getOutFileName();
	if (srcGen) {
		if (srcGen->genType() == genType_asm) {
			string cmd = "clang++ -c ";
			cmd += FLAGS_in + " -o " + outFile;
			return system(cmd.c_str()) == 0;
		}
		else {
			auto targetMachine = getTargetMachine(lM, lC);
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
			if (targetMachine->addPassesToEmitFile(*passMgr, out, NULL, fileType)) {
				errs() << "ObjGen " << "addPassesToEmitFile err error:" << EC.message();
				return false;
			}

#if defined(CUSTOM_PASS_OPR) && CUSTOM_PASS_OPR == 1  //function pass
			auto funPassMgr = (legacy::FunctionPassManager*)passMgr;
			for (auto& fun : lM) {
				if (fun.isDeclaration() || fun.isIntrinsic()) continue;
				funPassMgr->run(fun);
			}
#elif !defined(CUSTOM_PASS_OPR) || CUSTOM_PASS_OPR == 0
			((legacy::PassManager*)passMgr)->run(lM);
#elif defined(CUSTOM_PASS_OPR) && CUSTOM_PASS_OPR == 2

#endif
			out.flush();
		}
	}

	/*
		DongLangBaseAST::InitLLVMAST();

		llvm::SMDiagnostic EC;
		llvm::LLVMContext lc;
		auto module = parseIRFile("tmp.ll", EC, lc);
		if (!module) {
			errs() << "LLGen parseIRFile err:" << EC.getMessage();
			return 0;
		}


		string errStr = "";
		auto defaultTargetTrip = sys::getDefaultTargetTriple();
		const  llvm::Target* target = TargetRegistry::lookupTarget(defaultTargetTrip, errStr);
		if (!target) {
			errs() << "get target:" << defaultTargetTrip << ",err:" << errStr;
			return 0;
		}

		auto CPU = "generic";
		auto Features = "";

		TargetOptions opt;
		auto RM = FLAGS_fpie ? Reloc::DynamicNoPIC : FLAGS_fpic ? Reloc::PIC_ : optional<Reloc::Model>();
		auto targetMachine = target->createTargetMachine(defaultTargetTrip, CPU, Features, opt, RM);
		module->setDataLayout(targetMachine->createDataLayout());
		module->setTargetTriple(defaultTargetTrip);

		std::error_code eEC;
		raw_fd_ostream out("tmp.s", eEC);
		if (eEC) {
			errs() << "AsmGen " << FLAGS_out << " out file open err:" << eEC.message();
			return 0;
		}

		auto fileType = CGFT_AssemblyFile;
		legacy::PassManager pass;
		if (targetMachine->addPassesToEmitFile(pass, out, NULL, fileType)) {
			errs() << "AsmGen " << "addPassesToEmitFile err error:" << eEC.message();
			return 0;
		}

		pass.run(*module);
		out.flush();

		return 0;
	*/
	return true;
}

bool ExeGen::gen(GenBase* srcGen, bool final) {
	string cmd = "clang++ ";
	cmd += srcGen->getOutFileName() + " -o " + getOutFileName();
	return 	system(cmd.c_str()) == 0;
}