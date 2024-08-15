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

class DongLangForExprAST;

class DongLangBreakAST : public DongLangBaseAST{
public:
	DongLangBreakAST(antlr4Ctx ctx, CodeLocData& locData);
	Value* genCode() override;
private:
	antlr4Ctx ctx;
};

class DongLangContinueAST : public DongLangBaseAST {
public:
	DongLangContinueAST(antlr4Ctx ctx, CodeLocData& locData);
	Value* genCode() override;

private:
	antlr4Ctx ctx;
};


class DongLangIfExprAST : public DongLangBaseAST {
public:
	struct DongLangIfExprItem {
		DongLangIfExprItem(CodeLocData& locData, DongLangBaseAST* initAst, DongLangBaseAST* condAst, vector<DongLangBaseAST*>& statements) :
			locData(locData),
			initAst(initAst),
			condAst(condAst),
			statements(statements) {}
		CodeLocData locData;
		DongLangBaseAST* initAst;
		DongLangBaseAST* condAst;
		vector<DongLangBaseAST*> statements;
	};

public:
	DongLangIfExprAST(CodeLocData& locData, vector<DongLangIfExprItem*>& ifItems);
	Value* genCode() override;
private:
	vector<DongLangIfExprItem*> ifItems;
};


class DongLangForExprAST : public DongLangBaseAST, public DongLangScopeForInfo {

public:
	DongLangForExprAST(CodeLocData& locData, DongLangBaseAST* initAst,
	DongLangBaseAST* condAst,
	DongLangBaseAST* iterAst,
	vector<DongLangBaseAST*> statements);

	Value* genCode() override;

	virtual BasicBlock* getLoopBeginBB() override { return iterBB ? iterBB : condBB;  }
	virtual BasicBlock* getLoopEndBB() override { return endBB;  }

private:
	DongLangBaseAST* initAst;
	DongLangBaseAST* condAst;
	DongLangBaseAST* iterAst;
	vector<DongLangBaseAST*> statements;

	BasicBlock* condBB;
	BasicBlock* iterBB;
	BasicBlock* endBB;
};
