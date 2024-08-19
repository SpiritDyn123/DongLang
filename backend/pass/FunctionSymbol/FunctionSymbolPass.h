#pragma once

#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"

using namespace std;
using namespace llvm;

namespace {
	void runCustom(Function& F);

	class LeFunctionSymbolPass :  public FunctionPass {
	public:
		LeFunctionSymbolPass();
		static char ID;

		virtual bool runOnFunction(Function& F) override;
	};

	class FunctionSymbolPass : public PassInfoMixin<FunctionSymbolPass> {
	public:
		PreservedAnalyses run(Function& F, FunctionAnalysisManager& AM);
	};
}

