#pragma once

#include <iostream>
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include "DongLangBaseAST.h"
#include <vector>
using namespace std;

using namespace llvm;

class DongLangProgAST : public DongLangBaseAST {
public:
	DongLangProgAST(vector<DongLangBaseAST*>& lineAsts);
	virtual Value* genCode() override;
private:
	void doSysExternFuncs();
private:
	vector<DongLangBaseAST*> lineAsts;

private:
	void testStudy();
	void testSysFunctions();
	void testGlobalVars();
	void testArrayAndStruct(); //getelementptr
	void testIfAndFor();  //br
};

