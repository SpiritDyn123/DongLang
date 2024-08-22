#include "CustomPass.h"

using namespace llvm;
PassBuilder PB;
FunctionAnalysisManager FAM;
FunctionPassManager FPM;
LoopAnalysisManager LAM;
CGSCCAnalysisManager CGAM;
ModuleAnalysisManager MAM;

void InitCustomPass(legacy::PassManager* passMgr, legacy::FunctionPassManager*& funPassMgr, Module& lm) {
#ifdef CUSTOM_PASS_OPR
#if CUSTOM_PASS_OPR == 1
	funPassMgr = new legacy::FunctionPassManager(&lm);
#elif CUSTOM_PASS_OPR == 2
	PB.registerLoopAnalyses(LAM);
	PB.registerCGSCCAnalyses(CGAM);
	PB.registerModuleAnalyses(MAM);
	PB.registerFunctionAnalyses(FAM);
	PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);
#endif
	
	//add pass
	CUSTOM_ADD_PASS(FunctionSymbol);
#endif
}