#include "CustomPass.h"

using namespace llvm;

void InitCustomPass(legacy::PassManagerBase*& passMgr, Module& lm) {
#ifdef CUSTOM_PASS_OPR
#if CUSTOM_PASS_OPR == 1
	passMgr = new legacy::FunctionPassManager(&lm);
	passMgr->add(createLeFunctionSymbolPass());
#elif CUSTOM_PASS_OPR == 2
	PassBuilder PB;
#else
	passMgr = new legacy::PassManager();
#endif
#else
	passMgr = new legacy::PassManager();
#endif
}