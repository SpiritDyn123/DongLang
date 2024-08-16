#pragma once
#include "llvm/Pass.h"
#include "Pass.h"

namespace llvm {
	class FunctionSymbolPass : public FunctionPass {
		virtual void getAnalysisUsage(AnalysisUsage& Info) const override;

		virtual bool runOnFunction(Function& F) override;
	};

	static RegisterPass<FunctionPass> reg("fun_symbol", "fun_symbol", false, false);
}
