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

using namespace llvm;
using namespace std;
/**
var_value:
    | expression
    | var_arr_value
    | '&'IDENTIFIER
    ;

var_arr_value:  '{' expr_list '}' //array
    ;

var:
    IDENTIFIER ('=' var_value)?
    ;
vars:
    var (',' var)*
    ;
var_declares:
   type_type vars
   ;

 */

class DongLangFunctionDefAST;

class DongLangVarDeclareAST : public DongLangBaseAST {
public:
    friend class DongLangFunctionDefAST;
    DongLangVarDeclareAST(antlr4Ctx ctx, CodeLocData& locData, DongLangTypeInfo* spType, string id, DongLangBaseAST* defaultValue=NULL,
        bool isGlobal = false, DongLangTypeInfo* typeInfo = NULL, bool isPrimary = false);
	Value* genCode() override;
private:
    antlr4Ctx ctx;
    DongLangTypeInfo* spType;
    string id; 
    DongLangBaseAST* value;
    bool isGlobal;
    bool isPrimary;
};

class DongLangVarAST : public DongLangBaseAST {
public:
    DongLangVarAST(antlr4Ctx ctx, CodeLocData& locData, string id, DongLangBaseAST* defaultValue = NULL, DongLangTypeInfo* typeInfo = NULL, bool isPrimary = false);
     Value* genCode() override;
private:
    antlr4Ctx ctx;
    string id;
    DongLangBaseAST* value;
    bool isPrimary;
};

using DongLangVarsAST = DongLangVectorAST<DongLangBaseAST>;

class DongLangAssignAST : public DongLangBaseAST {
public:
    DongLangAssignAST(DongLangBaseAST* idAst, CodeLocData& locData, DongLangBaseAST* valueAst, DongLangTypeInfo* typeInfo = NULL, bool isPrimary =false);
    Value* genCode() override;
private:
    DongLangBaseAST* idAst;
    DongLangBaseAST* valueAst;
    bool isPrimary;
};

