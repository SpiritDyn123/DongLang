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
#include <map>
#include "font/DongLangScope.h"
#include "antlr4-runtime.h"

using namespace std;
using namespace llvm;


class DongLangBaseAST {
public:
	using antlr4Ctx = antlr4::ParserRuleContext*;

	DongLangBaseAST():typeInfo(NULL), leftValue(NULL),farg(false), parent(NULL) {}
	DongLangBaseAST(DongLangTypeInfo* typeInfo) :typeInfo(typeInfo), leftValue(NULL), farg(false), parent(NULL) {}

	void setLeftValue(Value* leftV) { leftValue = leftV;  }
	Value* getLeftValue() { return leftValue; }

	virtual void setFArg() { farg = true; }
	virtual bool getFArg() { return farg;  }

	virtual Value* genCode() { return NULL;  }

	void setParent(DongLangBaseAST* parent) { this->parent = parent;  }
	DongLangBaseAST* getParent() { return parent;  }

	virtual ~DongLangBaseAST() = default;

	DongLangTypeInfo* exprType() { return typeInfo; }
	Value* TransValue(DongLangTypeInfo* defaultTypeInfo, Value* curValue);
	//公共API
	static void InitLLVMAST();

	//Scope相关 (todo 以后改为stack mod)
	static void AddScope(antlr4Ctx, bool isRoot = false, string name= "");
	static DongLangScope* CurScope(antlr4Ctx);
	static DLSymbol* FindSymbol(antlr4Ctx, string);
	static DLSymbol* FindSymbol(antlr4Ctx, SYMBOL_ID id);
	static FuncDLSymbol* FindFuncSymbol(antlr4Ctx, string id, vector<DongLangTypeInfo*> argTypes = {}, bool isVarArg = false);
	static vector<FuncDLSymbol*>* FindFuncSymbolList(antlr4Ctx ctx, string baseId);
	static DongLangScope* RootScope() { return rootScope;  }

	//类型系统
	static llvm::Type* LlvmType(DongLangTypeInfo* spType);

public:
	static LLVMContext* llvmCtx;
	static Module* llvmModule;
	static IRBuilder<>* llvmBuilder;

private:
	static DongLangScope* rootScope;
	static map<antlr4Ctx, DongLangScope*> mScopes;
	DongLangTypeInfo* typeInfo;
	Value* leftValue;
	bool farg;
	DongLangBaseAST* parent;
};


template<typename T> class DongLangVectorAST : public DongLangBaseAST {
public:
	DongLangVectorAST(vector<T*> vars) : vars(vars) {}
	Value* genCode() override {
		Value* retValue = NULL;
		for (auto varAst : vars) {
			retValue = varAst->genCode();
		}
		return retValue;
	}

	virtual void setFArg() override {
		for (auto varAst : vars) {
			varAst->setFArg();
		}
	}

	virtual bool getFArg() override {
		bool fArg = false;
		for (auto varAst : vars) {
			fArg = varAst->getFArg();
		}
		return fArg;
	}

private:
	vector<T*> vars;
};

class ICanAddressAST {
public:
	virtual bool isAddressed() = 0;
};

#define lC (*DongLangBaseAST::llvmCtx)
#define lB (*DongLangBaseAST::llvmBuilder)
#define lM (*DongLangBaseAST::llvmModule)
