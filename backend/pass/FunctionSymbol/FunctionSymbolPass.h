#pragma once
#include "../Pass.h"

using namespace std;
using namespace llvm;

namespace {
	class FunctionSymbolPass : public PassInfoMixin<FunctionSymbolPass>, public FunctionPass {
	public:
		FunctionSymbolPass();
		static char ID;

		void runCustom(Function& F);
		virtual bool runOnFunction(Function& F) override;
		PreservedAnalyses run(Function& F, FunctionAnalysisManager& AM);
	};
}
