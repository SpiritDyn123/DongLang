#include "FunctionSymbolPass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalIFunc.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Casting.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include "llvm/IR/Attributes.h"
using namespace std;
using namespace llvm;

namespace {
	
	bool runCustom(Function& F) {
		if (F.isDeclaration() || F.isIntrinsic()) {
			return false;
		}

		stringstream ss;
		ss << "Function: " << string(F.getName()) << "(";

		int argIndex = 0;
		for (auto& arg : F.args()) {
			ss << string(arg.getName());
			if (argIndex < F.arg_size() - 1) {
				ss << ",";
			}
			argIndex++;
		}

		ss << ")";

		map<BasicBlock*, int> mBBSymbols = {};
		for (auto& bb : F) {
			mBBSymbols[&bb] = 0;
			for (auto& inst : bb) {
				if (dyn_cast<AllocaInst>(&inst)) {
					mBBSymbols[&bb]++;
				}
			}
		}

		ss << "\n\tBlockNums:" << mBBSymbols.size();
		for (auto it = mBBSymbols.begin(); it != mBBSymbols.end(); ++it) {
			ss << "\n\t\t" << it->first->getName().str() << " symbols:" << it->second;
		}

		ss << "\n\n";
		cout << ss.str();
		return true;
	}

	char LeFunctionSymbolPass::ID = 0;

	LeFunctionSymbolPass::LeFunctionSymbolPass() : FunctionPass(ID) {
	}

	bool LeFunctionSymbolPass::runOnFunction(Function& F) {
		runCustom(F);
		return true;
	}

	PreservedAnalyses FunctionSymbolPass::run(Function& F, FunctionAnalysisManager& AM) {
		if (runCustom(F)) {
			/*F.addFnAttr(Attribute::NoInline);
			return PreservedAnalyses::none();*/
		}

		return PreservedAnalyses::all();
	}
}

#if defined(CUSTOM_PASS_OPR)
#if CUSTOM_PASS_OPR == 1
void addLeFunctionSymbolPass(legacy::FunctionPassManager*& funPassMgr) {
	funPassMgr->add(new LeFunctionSymbolPass());
}
#elif CUSTOM_PASS_OPR == 2
void addFunctionSymbolPass(FunctionPassManager& FPM) {
	FPM.addPass(FunctionSymbolPass());
}
#endif
#endif

#ifdef OPT_LEGACY_PASS
static RegisterPass<LeFunctionSymbolPass> X("funsymbol", "function symbol",
	false /* Only looks at CFG */,
	false /* Analysis Pass */);
#endif

#ifdef OPT_LOAD_PLUGIN
llvm::PassPluginLibraryInfo getFunctionSymbolPluginInfo() {
	return { LLVM_PLUGIN_API_VERSION, "functionSymbol", LLVM_VERSION_STRING,
			[](PassBuilder& PB) {
				PB.registerVectorizerStartEPCallback(
					[](llvm::FunctionPassManager& PM, OptimizationLevel Level) {
					PM.addPass(FunctionSymbolPass());
					});
				PB.registerPipelineParsingCallback(
					[](StringRef Name, llvm::FunctionPassManager& PM,
						ArrayRef<llvm::PassBuilder::PipelineElement>) {
					if (Name == "funsymbol") {
						PM.addPass(FunctionSymbolPass());
						return true;
					}
					return false;
					});
			/*PB.registerPipelineStartEPCallback(
				[](ModulePassManager& MPM, OptimizationLevel Level) {
					FunctionPassManager FPM;
					FPM.addPass(FunctionSymbolPass());
					MPM.addPass(createModuleToFunctionPassAdaptor(std::move(FPM)));
				});*/
			} };
}

//dynamic load must has this api from PassPlugin::Load(const std::string &Filename)
extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() { 
	return getFunctionSymbolPluginInfo();
}
#endif