#include <iostream>
#include "llvm/Pass.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include <string>
using namespace std;
using namespace llvm;


PassBuilder PB;
FunctionAnalysisManager FAM;
FunctionPassManager FPM;
LoopAnalysisManager LAM;
CGSCCAnalysisManager CGAM;
ModuleAnalysisManager MAM;
ModulePassManager MPM;

LLVMContext lC;
Module lM("spirit jit", lC);
IRBuilder<> lB(lC);

void testGenIR() {
	for (int i = 0; i < 5; i++) {
		auto fn = Function::Create(FunctionType::get(
			lB.getVoidTy(), {}), GlobalValue::ExternalLinkage, "test_fun_" + to_string(i+1), &lM);
		auto eBB = BasicBlock::Create(lC, "entry", fn);
		lB.SetInsertPoint(eBB);
		auto intType = lB.getInt32Ty();
		auto var_a = lB.CreateAlloca(intType, NULL, "a");
		auto var_b = lB.CreateAlloca(intType, NULL, "b");
		auto a = lB.CreateLoad(intType, var_a);
		auto b = lB.CreateLoad(intType, var_b);
		auto var_sum = lB.CreateAdd(a, b, "c");
	}

}

void print() {
	lM.print(errs(), NULL);
}

struct selfPass1 : public PassInfoMixin<selfPass1> {
	PreservedAnalyses run(Function& F, FunctionAnalysisManager& AM) {
		cout << "selfPass1::Function:" << F.getName().str() << endl;
		return PreservedAnalyses::all();
	}
};

struct selfPass2 : public PassInfoMixin<selfPass2> {
	PreservedAnalyses run(Function& F, FunctionAnalysisManager& AM) {
		cout << "selfPass2::Function:" << F.getName().str() << endl;
		return PreservedAnalyses::all();
	}
};

void midPass() {
	PB.registerLoopAnalyses(LAM);
	PB.registerCGSCCAnalyses(CGAM);
	PB.registerModuleAnalyses(MAM);
	PB.registerFunctionAnalyses(FAM);
	PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);

	//1¡¢f1:pass1,pass2-->f2:pass1,pass2....
	/*FPM.addPass(selfPass1());
	FPM.addPass(selfPass2());
	MPM.addPass(createModuleToFunctionPassAdaptor(std::move(FPM)));*/

	//1¡¢pass1:f1->f2..., pass2: f1->f2...
	MPM.addPass(createModuleToFunctionPassAdaptor(selfPass1()));
	MPM.addPass(createModuleToFunctionPassAdaptor(selfPass2()));
}

int main() {

	testGenIR();

	midPass();

	MPM.run(lM, MAM);
	print();
}