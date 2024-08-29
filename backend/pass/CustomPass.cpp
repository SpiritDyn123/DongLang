#include "CustomPass.h"
#include <iostream>
using namespace llvm;
using namespace std;

PassBuilder PB;
FunctionAnalysisManager FAM;
FunctionPassManager FPM;
LoopAnalysisManager LAM;
CGSCCAnalysisManager CGAM;
ModuleAnalysisManager MAM;
ModulePassManager MPM;

void InitCustomPass(legacy::PassManager* passMgr, legacy::FunctionPassManager*& funPassMgr, Module& lm) {
#if defined(CUSTOM_PASS_OPR) && CUSTOM_PASS_OPR != 0
#if CUSTOM_PASS_OPR == 1
	funPassMgr = new legacy::FunctionPassManager(&lm);
//add pass
#define CUSTOM_PASS(passClass) addLe##passClass##Pass(funPassMgr);
#include "backend/pass/PassConfig.def"
#elif CUSTOM_PASS_OPR == 2
	PB.registerLoopAnalyses(LAM);
	PB.registerCGSCCAnalyses(CGAM);
	PB.registerModuleAnalyses(MAM);
	PB.registerFunctionAnalyses(FAM);
	PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);
//add pass
#define CUSTOM_PASS(passClass) add##passClass##Pass(FPM);
#include "backend/pass/PassConfig.def"

	//function pass ===> module pass
	MPM.addPass(createModuleToFunctionPassAdaptor(std::move(FPM)));
#endif
#endif
}