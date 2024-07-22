#include "font/DongLangSymbol.h"
#include "font/ast/DongLangBaseAST.h"

string FuncSLSymbol::funcID(string baseId, vector<DongLangTypeInfo*> types, bool isVarArg) {
	string id = baseId;
	static map<string, string> oprAlias = {
		{"int", "i"},
		{"byte", "bt"},
		{"float", "f"},
		{"bool", "b"},
		{"string", "s"},
	};
	if (baseId != "main" && baseId != "global_main_init") {
		if (types.size() > 0) {
			for (auto& argType : types) {
				id += "_" + oprAlias[argType->primary_type];
				for (auto p : argType->pas) {
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