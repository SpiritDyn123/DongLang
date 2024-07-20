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

using namespace llvm;


class DongLangCallExprAST : public DongLangBaseAST {
public:
	DongLangCallExprAST(FuncSLSymbol* funcSymbol, std::vector<DongLangBaseAST*>&, bool, 
		DongLangTypeInfo* typeInfo, DongLangTypeInfo* defaultTypeInfo);
	Value* genCode() override;
private:
	FuncSLSymbol* funcSymbol;
	std::vector<DongLangBaseAST*> args;
	bool isGlobal;
	DongLangTypeInfo* defaultTypeInfo;
};

class DongLangRetExprAST : public DongLangBaseAST {
public:
	DongLangRetExprAST(DongLangBaseAST* expr, DongLangTypeInfo* typeInfo = NULL):
		DongLangBaseAST(typeInfo), expr(expr) {}
	Value* genCode() override;
private:
	DongLangBaseAST* expr;
};
