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
using namespace std;

/*
value_primary:
	num_primary
	| bool_primary
	| str_primary
	;
*/

class DongLangNumPrimaryAST : public DongLangBaseAST {
public:
	DongLangNumPrimaryAST(std::string, DongLangTypeInfo* typeInfo = NULL) ;
	virtual Value* genCode() override;
private:
	string value;
};

class DongLangStrPrimaryAST : public DongLangBaseAST {
public:
	DongLangStrPrimaryAST(std::string, DongLangTypeInfo* typeInfo = NULL);
	virtual Value* genCode() override;
private:
	std::string value;
};

class DongLangBoolPrimaryAST : public DongLangBaseAST {
public:
	DongLangBoolPrimaryAST(std::string, DongLangTypeInfo* typeInfo = NULL);
	virtual Value* genCode() override;
private:
	bool value;
};

class DongLangIdPrimaryAST : public DongLangBaseAST {
public:
	DongLangIdPrimaryAST(antlr4Ctx, std::string, DongLangBaseAST* idAst, vector<DongLangBaseAST*>& arrAsts,
		DongLangTypeInfo* typeInfo, 
		DongLangTypeInfo* defaultTypeInfo);
	virtual Value* genCode() override;
private:
	antlr4Ctx ctx;
	string id;
	DongLangBaseAST* idAst;
	vector<DongLangBaseAST*> arrAsts;
	DongLangTypeInfo* defaultTypeInfo;
};


