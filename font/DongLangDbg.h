#pragma once

#include <iostream>
#include "llvm/IR/Value.h"
#include <map>
#include <vector>
#include <string>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include <regex>
#include "include/dl_flag.h"
#include "llvm/IR/DIBuilder.h"

using namespace llvm;
using namespace std;

class DongLangBaseAST;

struct DongLangDebugInfo {
	DIBuilder* builder;
	DICompileUnit* cu;
	std::vector<DIScope*> scopes;

	void Init();
	DIBuilder* Builder() { return builder; }
	void enterScope(DIScope* scope);
	bool leaveScope();
	DIScope* curScope();
	void emitLocation(DongLangBaseAST* ast);
};
