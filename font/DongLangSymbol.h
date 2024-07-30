#pragma once

#include <iostream>
#include "llvm/IR/Value.h"
#include <map>
#include <vector>
#include <string>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include <regex>

#include "DongLangType.h"
using namespace llvm;
using namespace std;

typedef int64_t SYMBOL_ID;

class DongLangScope;
class DLSymbol {
public:
	enum emSymbolType {
		symbolType_Var = 0,
		symbolType_Func = 1,
		symbolType_Type = 2,
		symbolType_Class = 3,
	};

	DLSymbol(string id, DongLangTypeInfo* varType, Value* v,
		DongLangScope* s = NULL,
		emSymbolType st = symbolType_Var) : id(id), varType(varType), value(v), scope(s), sType(st) {}
	virtual ~DLSymbol() {}
	virtual string& ID() { return id; }
	virtual string String() { return id; }
	Value* getVal() { return value; }
	void setVal(Value* v) { value = v; }
	DongLangScope* getScope() { return scope; }
	void setScope(DongLangScope* s) { scope = s; }
	emSymbolType type() const { return sType; };
	DongLangTypeInfo* getVarType() const { return varType;  }
	void arrToPtr();
private:
	string id;
	emSymbolType sType;
	DongLangScope* scope;
	DongLangTypeInfo* varType;
	Value* value;
};

class VarDLSymbol : public DLSymbol {
public:
	VarDLSymbol(string id, DongLangTypeInfo* vt,Value* v, SYMBOL_ID defaultValueID, DongLangScope* s = NULL) :
		DLSymbol(id, vt, v, s, symbolType_Var), defaultValueID(defaultValueID) { }

	virtual string String() override { return "VAR:" + ID(); }

	SYMBOL_ID getDefaultValueID() { return defaultValueID; }

	~VarDLSymbol() override {}

	static VarDLSymbol* Create( string id, DongLangTypeInfo* vt, Value* v, SYMBOL_ID defaultValueID = 0, DongLangScope* s = NULL) {
		return new VarDLSymbol(id, vt, v, defaultValueID, s);
	}

private :
	SYMBOL_ID defaultValueID;
};

class FuncDLSymbol : public DLSymbol {
public:
	FuncDLSymbol(string baseId, DongLangTypeInfo* retType, 
		vector<VarDLSymbol*>& argSymbols, 
		vector<DongLangTypeInfo*>& argTypes,
		Value* v, bool externC = false, bool isVarArg = false, DongLangScope* s = NULL) :
		DLSymbol(baseId, retType, v, s, symbolType_Func), argSymbols(argSymbols){
		this->externC = externC;
		this->isVarArg = isVarArg;
		this->id = externC ? baseId : funcID(baseId, argTypes , isVarArg);
	}

	string& Name() { return DLSymbol::ID(); }
	virtual string String() override;

	virtual string& ID() override { return id; }
	bool extC() const { return externC;  }
	bool varArg() const { return isVarArg;}

	vector<VarDLSymbol*>& argSymbol();
	VarDLSymbol* argSymbol(int index);
	vector<DongLangTypeInfo*> argType();
	DongLangTypeInfo* argType(int index);

	~FuncDLSymbol() override {}

	static FuncDLSymbol* Create(string baseId, DongLangTypeInfo* retType, vector<VarDLSymbol*>& argSymbols,
		vector<DongLangTypeInfo*>& argTypes,
		Value* v, bool externC = false, bool isVarArg = false, DongLangScope* s = NULL) {
		return new FuncDLSymbol(baseId, retType, argSymbols, argTypes, v, externC, isVarArg, s);
	}

	static string funcID(string baseId, vector<DongLangTypeInfo*> types, bool isVarArg = false);

private:
	vector<VarDLSymbol*> argSymbols;
	vector<DongLangTypeInfo*> argTypes;
	bool externC;
	bool isVarArg;
	string id;
};


class TypeDLSymbol : public DLSymbol {
public:
	TypeDLSymbol(string id, DongLangTypeInfo* vt, DongLangScope* s = NULL) :
		DLSymbol(id, vt, NULL, s, symbolType_Type) { }

	virtual string String() override { return "TYPE:" + ID(); }

	~TypeDLSymbol() override {}

	static TypeDLSymbol* Create(string id, DongLangTypeInfo* vt, DongLangScope* s = NULL) {
		return new TypeDLSymbol(id, vt, s);
	}

private:

};

class ClassDLSymbol : public DLSymbol {
public:
	ClassDLSymbol(string id, DongLangTypeInfo* vt, DongLangScope* s = NULL) :
		DLSymbol(id, vt, NULL, s, symbolType_Class) { }

	virtual string String() override { return "CLASS:" + ID(); }

	~ClassDLSymbol() override {}

	static ClassDLSymbol* Create(string id, DongLangTypeInfo* vt, DongLangScope* s = NULL) {
		return new ClassDLSymbol(id, vt, s);
	}

private:

};
