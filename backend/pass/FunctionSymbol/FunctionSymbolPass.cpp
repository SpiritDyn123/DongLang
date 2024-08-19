#include "FunctionSymbolPass.h"
#include <iostream>
#include <sstream>
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalIFunc.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Casting.h"
#include <map>
#include <vector>
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"


using namespace std;

namespace {
	FunctionSymbolPass::FunctionSymbolPass(): FunctionPass(ID) {

	}

	void FunctionSymbolPass::runCustom(Function& F) {
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
			ss << "\n\t\t" << string(it->first->getName()) << " symbols:" << it->second;
		}

		ss << "\n\n";

	}

	bool FunctionSymbolPass::runOnFunction(Function& F) {
		runCustom(F); 
		return true;
	}

	PreservedAnalyses FunctionSymbolPass::run(Function& F, FunctionAnalysisManager& AM) {
		runCustom(F);
		return PreservedAnalyses::all();
	}

	char FunctionSymbolPass::ID = 0;


	static RegisterPass<FunctionSymbolPass> X("funsymbol", "function symbol",
		false /* Only looks at CFG */,
		false /* Analysis Pass */);

	/* New PM Registration */
	llvm::PassPluginLibraryInfo getFunctionSymbolPluginInfo() {
		return { LLVM_PLUGIN_API_VERSION, "funsymbol", LLVM_VERSION_STRING,
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
				} };
	}

	extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
		return getFunctionSymbolPluginInfo();
	}

}
