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
#include <map>

using namespace llvm;
using namespace std;

class DongLangFunctionDefAST : public DongLangBaseAST {
public:
	struct ArgInfo {
		string name;
		antlr4Ctx ctx;
		ArgInfo(string name, antlr4Ctx ctx ): name(name), ctx(ctx){}
	};
public:
	DongLangFunctionDefAST(FuncDLSymbol* funcSymbol, string fnName, vector<ArgInfo> args, bool isVarArg,
		bool hasBody, vector<DongLangBaseAST*> body, CodeLocData& locData);
	virtual Value* genCode() override;

	const string& getName();
private:
	FuncDLSymbol* funcSymbol;
	string fnName;
	bool isVarArg;
	vector<ArgInfo> args;
	bool hasBody;
	vector<DongLangBaseAST*> body;
};

