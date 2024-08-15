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
	DongLangCallExprAST(CodeLocData& locData, FuncDLSymbol* , std::vector<DongLangBaseAST*>&, 
		std::vector<DongLangTypeInfo*>&, bool);
	Value* genCode() override;
private:
	FuncDLSymbol* funcSymbol;
	std::vector<DongLangBaseAST*> args;
	std::vector<DongLangTypeInfo*> argDefaultTypes;
	bool isGlobal;
};

class DongLangRetExprAST : public DongLangBaseAST {
public:
	DongLangRetExprAST(CodeLocData& locData, DongLangBaseAST* expr = NULL, 
		DongLangTypeInfo* typeInfo = NULL, DongLangTypeInfo* defaultTypeInfo = NULL):
		DongLangBaseAST(typeInfo, locData), expr(expr), defaultTypeInfo(defaultTypeInfo){}
	Value* genCode() override;
private:
	DongLangBaseAST* expr;
	DongLangTypeInfo* defaultTypeInfo;
};
