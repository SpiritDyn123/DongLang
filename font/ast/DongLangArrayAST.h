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
var_arr_value:
	'{' var_arr_value (',' var_arr_value)* '}'
	| '{' expr_list '}' //array
	;
*/


class DongLangArrayAST : public DongLangBaseAST {
public:
	DongLangArrayAST(DLSymbol*idSymbol, bool isPrimary, vector<DongLangBaseAST*>& arrAsts, 
		DongLangTypeInfo* spType, DongLangTypeInfo* typeInfo) : DongLangBaseAST(typeInfo), spType(spType), idSymbol(idSymbol),
		isPrimary(isPrimary), arrAsts(arrAsts) {}
	bool primary() { return isPrimary;  }
	virtual Value* genCode() override;
	Constant* genConstantValue();

private:
	void genUnPrimaryArrayItem(bool isGlobal, DongLangBaseAST* ast, Value* arrValue, vector<int> indexs);

private:
	DLSymbol* idSymbol;
	bool isPrimary;
	DongLangTypeInfo* spType;
	vector<DongLangBaseAST*> arrAsts;
};
