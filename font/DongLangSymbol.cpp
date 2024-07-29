#include "font/DongLangSymbol.h"
#include "font/ast/DongLangBaseAST.h"

string FuncDLSymbol::funcID(string baseId, vector<DongLangTypeInfo*> argTypes, bool isVarArg) {
	string id = baseId;
	static map<string, string> oprAlias = {
		{"int", "i"},
		{"byte", "bt"},
		{"float", "f"},
		{"bool", "b"},
		{"string", "s"},
	};
	if (baseId != "main" && baseId != "global_main_init") {
		if (argTypes.size() > 0) {
			for (auto& argType : argTypes) {
				DongLangTypeInfo tmpType(*argType);
				DongLangTypeInfo::arrToPtr(&tmpType);
				id += "_" + oprAlias[tmpType.primary_type];
				for (auto p : tmpType.pas) {
					if (p.pointOrArr) {
						id += "P";
					}
					else {
						id += "A"  + to_string(p.array_len);
					}
				}
			}
		}

		if (isVarArg) {
			id += "__VAR";
		}

	/*	id = regex_replace(id, regex("\\*"), "P");
		id = regex_replace(id, regex("\\["), "A");
		id = regex_replace(id, regex("\\]"), "A");*/
	}
	
	return id;
}
vector<VarDLSymbol*>  FuncDLSymbol::argSymbol() {
	vector<VarDLSymbol*> argSymbols = {};
	for (auto symbol : argSymbols) {
		argSymbols.push_back(symbol);
	}

	return  argSymbols;
}

VarDLSymbol* FuncDLSymbol::argSymbol(int index) {
	if (index < 0 || index >= argSymbols.size()) {
		return NULL;
	}

	return argSymbols[index];
}

vector<DongLangTypeInfo*> FuncDLSymbol::argType() {
	vector<DongLangTypeInfo*> argTypes = {};
	for (auto symbol : argSymbols) {
		argTypes.push_back(symbol->getVarType());
	}

	return  argTypes;
}

DongLangTypeInfo* FuncDLSymbol::argType(int index) {
	if (index < 0 || index >= argSymbols.size()) {
		return NULL;
	}

	return argSymbols[index]->getVarType();
}

string FuncDLSymbol::String() {
	string buf = "FUNC:";
	buf += getVarType()->String() + " " + DLSymbol::ID() + "(";
	int argCnt = argSymbols.size();
	for (int i = 0; i < argCnt;i++) {
		buf += argTypes[i]->String() + " " + argSymbols[i]->ID();
		if (argSymbols[i]->getDefaultValueID()) {
			buf += "(default_value)";
		}

		if (i < argCnt - 1) {
			buf += ",";
		}
	}

	if (isVarArg) {
		buf += ", ...";
	}
	buf += ")";

	return buf;
}
