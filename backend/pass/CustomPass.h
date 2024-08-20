#pragma once

#include "llvm/Pass.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"

using namespace llvm;
extern PassBuilder PB;
extern FunctionAnalysisManager FAM;
extern FunctionPassManager FPM;
extern LoopAnalysisManager LAM;
extern CGSCCAnalysisManager CGAM;
extern ModuleAnalysisManager MAM;

void InitCustomPass(legacy::PassManager* passMgr, 
	legacy::FunctionPassManager*& funPassMgr, Module& lm);

#ifdef CUSTOM_PASS_OPR
#if CUSTOM_PASS_OPR == 1
#define CUSTOM_PASS(passPlugin)  llvm::Pass* createLe##passPlugin##Pass();
#include "backend/pass/PassConfig.def"
#elif CUSTOM_PASS_OPR == 2
#define CUSTOM_PASS(passPlugin)  llvm::PassPluginLibraryInfo get##passPlugin##PluginInfo();
#include "backend/pass/PassConfig.def"
#endif
#endif


