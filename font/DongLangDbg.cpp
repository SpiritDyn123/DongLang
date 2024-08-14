#include "font/DongLangDbg.h"
#include "font/ast/DongLangBaseAST.h"

void DongLangDebugInfo::Init() {
	builder = new DIBuilder(lM);

	cu = builder->createCompileUnit(dwarf::DW_LANG_C,
		builder->createFile(FLAGS_in, "."),
		"DongLang Debuger", 0, "", 0);
	scopes = {};
}


void DongLangDebugInfo::enterScope(DIScope* scope) {
	scopes.push_back(scope);
}

bool DongLangDebugInfo::leaveScope() {
	if (scopes.empty()) {
		return false;
	}

	scopes.pop_back();
	return true;
}

DIScope* DongLangDebugInfo::curScope() {
	if (scopes.empty()) {
		return cu;
	}

	return scopes.back();
}

void DongLangDebugInfo::emitLocation(DongLangBaseAST* ast) {
	if (!ast)
		return lB.SetCurrentDebugLocation(DebugLoc());
	DIScope* scope = curScope();

	auto& locData = ast->LocData();
	lB.SetCurrentDebugLocation(DILocation::get(
		scope->getContext(), locData.line, locData.column, scope));
}