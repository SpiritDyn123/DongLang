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
class SLSymbol {
public:
	enum emSymbolType {
		symbolType_Var = 0,
		symbolType_Func = 1,
	};

	SLSymbol(string id, DongLangTypeInfo* varType, Value* v,
		DongLangScope* s = NULL,
		emSymbolType st = symbolType_Var) : id(id), varType(varType), value(v), scope(s), sType(st) {}
	virtual ~SLSymbol() {}
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

class VarSLSymbol : public SLSymbol {
public:
	VarSLSymbol(string id, DongLangTypeInfo* vt,Value* v, DongLangScope* s = NULL) :
		SLSymbol(id, vt, v, s, symbolType_Var) { }
	~VarSLSymbol() override {}

	
	static VarSLSymbol* Create( string id, DongLangTypeInfo* vt, Value* v, DongLangScope* s = NULL) {
		return new VarSLSymbol(id, vt, v, s);
	}

private :
	 
};

class FuncSLSymbol : public SLSymbol {
public:
	FuncSLSymbol(string baseId, vector<DongLangTypeInfo*> types, Value* v, 
		bool externC = false, bool isVarArg = false, DongLangScope* s = NULL) :
		SLSymbol(baseId, types[0], v, s, symbolType_Func) {
		types.erase(types.begin());
		this->types = types;
		this->externC = externC;
		this->isVarArg = isVarArg;
		this->id = externC ? baseId : funcID(baseId, types, isVarArg);
	}

	string& Name() { return SLSymbol::ID(); }

	virtual string& ID() override { return id; }
	bool extC() const { return externC;  }
	bool varArg() const { return isVarArg;}
	vector<DongLangTypeInfo*>& argType() { return types; }
	DongLangTypeInfo* argType(int index) { return types[index]; }

	~FuncSLSymbol() override {}

	static FuncSLSymbol* Create(string baseId, vector<DongLangTypeInfo*> types, Value* v, bool externC = false, bool isVarArg = false, DongLangScope* s = NULL) {
		return new FuncSLSymbol(baseId, types, v, externC, isVarArg, s);
	}

	static string funcID(string baseId, vector<DongLangTypeInfo*> types, bool isVarArg = false);

private:
	vector<DongLangTypeInfo*> types; //types[0] == returntype
	bool externC;
	bool isVarArg;
	string id;
};

