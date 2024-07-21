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



class DongLangExpressionAST : public DongLangBaseAST {
public:
	DongLangExpressionAST(std::string op, 
		DongLangBaseAST* lhs, 
		DongLangBaseAST* rhs, 
		DongLangBaseAST* exths,
		DongLangTypeInfo* typeInfo,
		DongLangTypeInfo* defaultTypeInfo);
	virtual Value* genCode() override;
	void assetOpearation();

	static DongLangExpressionAST* createCmpAst(string op, vector<DongLangBaseAST*> cAsts, DongLangTypeInfo* typeInfo, DongLangTypeInfo* defaultTypeInfo);

private:
	std::string op;
	DongLangBaseAST* lhs;
	DongLangBaseAST* rhs;
	DongLangBaseAST* exths;
	DongLangTypeInfo* defaultTypeInfo;

private:
	BasicBlock* retBB() { return op == "&&" ? falseBB : trueBB ; }
	BasicBlock* trueBB;
	BasicBlock* falseBB;
	PHINode* phi;
private:
	
	static Value* addExpr(DongLangExpressionAST* ast);
	static Value* subExpr(DongLangExpressionAST* ast);
	static Value* mulExpr(DongLangExpressionAST* ast);
	static Value* divExpr(DongLangExpressionAST* ast);
	static Value* notExpr(DongLangExpressionAST* ast);
	static Value* andExpr(DongLangExpressionAST* ast);
	static Value* orExpr(DongLangExpressionAST* ast);
	static Value* xorExpr(DongLangExpressionAST* ast);

	static Value* cmpExpr(DongLangExpressionAST* ast);


	static Value* ifNotExpr(DongLangExpressionAST* ast);
	static Value* ifAndExpr(DongLangExpressionAST*);
	static Value* ifOrExpr(DongLangExpressionAST*);
	static Value* ifThreeOrExpr(DongLangExpressionAST*);


	//using  EXPRESSION_HANDLER = void(DongLangExpressionAST*);
	typedef Value* (*EXPRESSION_HANDLER)(DongLangExpressionAST*);
	typedef map<string, EXPRESSION_HANDLER> MEXPRESSION_HANDLERS;
	static MEXPRESSION_HANDLERS mExpressionHandlers;
};
