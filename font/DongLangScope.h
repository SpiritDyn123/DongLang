#pragma once

#include <iostream>
#include "llvm/IR/Value.h"
#include <map>
#include <vector>
#include <string>
#include "DongLangSymbol.h"

using namespace llvm;
using namespace std;


const SYMBOL_ID func_main_id = -1;
const SYMBOL_ID func_global_main_init_id = -2;

class DongLangScopeForInfo {
public:
	virtual BasicBlock* getLoopBeginBB() = 0;
	virtual BasicBlock* getLoopEndBB() = 0;
};

class DongLangScope {
public:
	DongLangScope(DongLangScope* parent, string name);
	const string& getName() { return name;  }
	bool checkVar(string id, DLSymbol* symbol);
	bool AddSymbol(string id, SYMBOL_ID sId, DLSymbol* value);
	DLSymbol* FindSymbol(string id);
	DLSymbol* FindSymbol(SYMBOL_ID id);
	void AddForInfo(DongLangScopeForInfo*);
	DongLangScopeForInfo* getForInfo();

	FuncDLSymbol* FindFuncSymbol(string id, vector<DongLangTypeInfo*> argTypes = {}, bool isVarArg = false);
	vector<FuncDLSymbol*>* FindFuncSymbolList(string baseId);

	//symblMap type
	using SymbolType = DLSymbol::emSymbolType;
	typedef map<string, DLSymbol*> MTypeSymbols;
	using MSymbols = map<SymbolType, MTypeSymbols>;
	using FuncList = vector<FuncDLSymbol*>;

	
private:
	DongLangScope* parent;
	string name;
	MSymbols mSymbols;
	map<string, FuncList> mFuncList;
	map<SYMBOL_ID, DLSymbol*> mAllSymbols;
	DongLangScopeForInfo* forInfo;
};


