#pragma once

#include <iostream>
#include "llvm/IR/Value.h"
#include <map>
#include <vector>
#include <string>
#include "DongLangSymbol.h"

using namespace llvm;
using namespace std;

typedef int64_t SYMBOL_ID;

const SYMBOL_ID func_main_id = -1;
const SYMBOL_ID func_global_main_init_id = -1;

class DongLangScopeForInfo {
public:
	virtual BasicBlock* getLoopBeginBB() = 0;
	virtual BasicBlock* getLoopEndBB() = 0;
};

class DongLangScope {
public:
	DongLangScope(DongLangScope* parent, string name);
	const string& getName() { return name;  }
	bool checkVar(string id, SLSymbol* symbol);
	bool AddSymbol(string id, SYMBOL_ID sId, SLSymbol* value);
	SLSymbol* FindSymbol(string id);
	SLSymbol* FindSymbol(SYMBOL_ID id);
	void AddForInfo(DongLangScopeForInfo*);
	DongLangScopeForInfo* getForInfo();

	FuncSLSymbol* FindFuncSymbol(string id, vector<DongLangTypeInfo*> argTypes = {}, bool isVarArg = false);
	vector<FuncSLSymbol*>* FindFuncSymbolList(string baseId);

	//symblMap type
	using SymbolType = SLSymbol::emSymbolType;
	typedef map<string, SLSymbol*> MTypeSymbols;
	using MSymbols = map<SymbolType, MTypeSymbols>;
	using FuncList = vector<FuncSLSymbol*>;

	
private:
	DongLangScope* parent;
	string name;
	MSymbols mSymbols;
	map<string, FuncList> mFuncList;
	map<SYMBOL_ID, SLSymbol*> mAllSymbols;
	DongLangScopeForInfo* forInfo;
};


