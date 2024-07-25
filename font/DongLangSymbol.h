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
	Value* getVal() { return value; }
	void setVal(Value* v) { value = v; }
	DongLangScope* getScope() { return scope; }
	void setScope(DongLangScope* s) { scope = s; }
	emSymbolType type() const { return sType; };
	DongLangTypeInfo* getVarType() const { return varType;  }
private:
	string id;
	emSymbolType sType;
	DongLangScope* scope;
	DongLangTypeInfo* varType;
	Value* value;
};

class VarDLSymbol : public DLSymbol {
public:
	VarDLSymbol(string id, DongLangTypeInfo* vt,Value* v, DongLangScope* s = NULL) :
		DLSymbol(id, vt, v, s, symbolType_Var) { }
	~VarDLSymbol() override {}

	
	static VarDLSymbol* Create( string id, DongLangTypeInfo* vt, Value* v, DongLangScope* s = NULL) {
		return new VarDLSymbol(id, vt, v, s);
	}

private :
	 
};

class FuncDLSymbol : public DLSymbol {
public:
	FuncDLSymbol(string baseId, vector<DongLangTypeInfo*> types, Value* v, 
		bool externC = false, bool isVarArg = false, DongLangScope* s = NULL) :
		DLSymbol(baseId, types[0], v, s, symbolType_Func) {
		types.erase(types.begin());
		this->types = types;
		this->externC = externC;
		this->isVarArg = isVarArg;
		this->id = externC ? baseId : funcID(baseId, types, isVarArg);
	}

	string& Name() { return DLSymbol::ID(); }

	virtual string& ID() override { return id; }
	bool extC() const { return externC;  }
	bool varArg() const { return isVarArg;}
	vector<DongLangTypeInfo*>& argType() { return types; }
	DongLangTypeInfo* argType(int index) { return types[index]; }

	~FuncDLSymbol() override {}

	static FuncDLSymbol* Create(string baseId, vector<DongLangTypeInfo*> types, Value* v, bool externC = false, bool isVarArg = false, DongLangScope* s = NULL) {
		return new FuncDLSymbol(baseId, types, v, externC, isVarArg, s);
	}

	static string funcID(string baseId, vector<DongLangTypeInfo*> types, bool isVarArg = false);

private:
	vector<DongLangTypeInfo*> types; //types[0] == returntype
	bool externC;
	bool isVarArg;
	string id;
};


class TypeDLSymbol : public DLSymbol {
public:
	TypeDLSymbol(string id, DongLangTypeInfo* vt, DongLangScope* s = NULL) :
		DLSymbol(id, vt, NULL, s, symbolType_Type) { }
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
	~ClassDLSymbol() override {}

	static ClassDLSymbol* Create(string id, DongLangTypeInfo* vt, DongLangScope* s = NULL) {
		return new ClassDLSymbol(id, vt, s);
	}

private:

};
