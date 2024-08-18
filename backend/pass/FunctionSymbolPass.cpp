#include "FunctionSymbolPass.h"
#include <iostream>
#include <sstream>
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalIFunc.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Casting.h"
#include <map>
#include <vector>

using namespace std;

namespace llvm {

static RegisterPass<FunctionSymbolPass> reg("fun_symbol", "fun_symbol", false, false);

char FunctionSymbolPass::ID = 0;

void FunctionSymbolPass::getAnalysisUsage(AnalysisUsage& Info) const {

}

bool FunctionSymbolPass::runOnFunction(Function& F) {
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

	return true;
}



}
