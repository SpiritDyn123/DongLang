#include "CustomPass.h"

using namespace llvm;
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
	#define CUSTOM_PASS(passClass) addLe##passClass##Pass(funPassMgr);
#elif CUSTOM_PASS_OPR == 2
	PB.registerLoopAnalyses(LAM);
	PB.registerCGSCCAnalyses(CGAM);
	PB.registerModuleAnalyses(MAM);
	PB.registerFunctionAnalyses(FAM);
	PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);
	MPM = PB.buildPerModuleDefaultPipeline(OptimizationLevel::O2);
	#define CUSTOM_PASS(passClass) add##passClass##Pass(FPM);
#endif
	//add pass
	#include "backend/pass/PassConfig.def"
#endif
}