#pragma once
#include "llvm/Pass.h"
#include "Pass.h"

namespace llvm {
	class FunctionSymbolPass : public FunctionPass {
	public:
		static char ID;
		virtual void getAnalysisUsage(AnalysisUsage& Info) const override;

		virtual bool runOnFunction(Function& F) override;
	};

}

