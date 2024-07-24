#include "font/ast/DongLangBaseAST.h"


LLVMContext* DongLangBaseAST::llvmCtx = NULL;
Module* DongLangBaseAST::llvmModule = NULL;
IRBuilder<>* DongLangBaseAST::llvmBuilder = NULL;
map<DongLangBaseAST::antlr4Ctx, DongLangScope*> DongLangBaseAST::mScopes;
DongLangScope* DongLangBaseAST::rootScope = NULL;

Value* DongLangBaseAST::TransValue(DongLangTypeInfo* defaultTypeInfo, Value* curValue) {
	if (!typeInfo) {
		return curValue;
	}

	string t1S = typeInfo->String();
	string t2S = defaultTypeInfo->String();

	//int <==> float trans
	auto llType = typeInfo->LlvmType(&lB);
	if (t1S != t2S) {
		if (typeInfo->isPrimary()) {
			Instruction::CastOps castT;
			if (t1S == "bool" || t1S == "bit") {
				if (t2S != "bit") {
					if (defaultTypeInfo->isArray()) { //数组比较特殊
						curValue = lB.CreateGEP(defaultTypeInfo->LlvmType(&lB), curValue, { lB.getInt32(0), lB.getInt32(0) });
					}
					
					Value* zeroValue = Constant::getNullValue(curValue->getType());
					if (t2S == "float") {
						curValue = lB.CreateFCmpUNE(curValue, zeroValue);
					}
					else {
						curValue = lB.CreateICmpNE(curValue, zeroValue);
					}
				}

				if (t1S == "bool") {
					castT = Instruction::ZExt;
				}
			}
			else {
				if (t1S == "int") {
					if (t2S == "float") {
						castT = Instruction::FPToSI;
					}
					else {
						castT = Instruction::SExt;
					}
				}
				else if (t1S == "float") {
					castT = Instruction::SIToFP;
				}
				else if (t1S == "byte") {
					if (t2S == "int") {
						castT = Instruction::Trunc;
					}
					else {
						castT = Instruction::FPToSI;
					}
				}
			}

			if (!llType->isIntegerTy(1)) {
				curValue = lB.CreateCast(castT, curValue, llType);
			}
		}
		else if (typeInfo->isPoint()) {
			if (defaultTypeInfo->isArray()) {
				curValue = lB.CreateInBoundsGEP(defaultTypeInfo->LlvmType(&lB), curValue, {lB.getInt32(0), lB.getInt32(0)});
			}
		}
	}
	
	if (leftValue) {
		lB.CreateStore(curValue, leftValue);
		curValue = leftValue;
	}

	return curValue;
}

 void DongLangBaseAST::InitLLVMAST() {
	llvmCtx = new LLVMContext();
	llvmModule = new Module("spirit lang jit", *llvmCtx);
	llvmBuilder = new IRBuilder<>(*llvmCtx);
	mScopes.clear();
}

 void DongLangBaseAST::AddScope(antlr4Ctx ctx, bool isRoot, string name) {
	 auto scope = mScopes.find(ctx);
	 if (scope != mScopes.end()) {
		 return;
	 }

	 auto parent = CurScope(ctx);
	 if (name == "") {
		 name = std::to_string((long long)ctx);
	 }

	 if (parent) {
		 name = parent->getName() + "." + name;
	 }

	 mScopes[ctx] = new DongLangScope(parent, name);
	 if (isRoot) {
		 rootScope = mScopes[ctx];
	 }
}

DongLangScope* DongLangBaseAST::CurScope(antlr4Ctx ctx) {
	if (ctx == NULL) {
		return rootScope;
	}

	for (auto pCtx = ctx; pCtx != NULL; pCtx = (antlr4Ctx)pCtx->parent) {
		auto pScp = mScopes.find(pCtx);
		if (pScp != mScopes.end()) {
			return pScp->second;
		}
	}

	return NULL;
}

 SLSymbol* DongLangBaseAST::FindSymbol(antlr4Ctx ctx, string id) {
	 auto scope = CurScope(ctx);
	 if (scope == NULL) {
		 return NULL;
	 }

	 return scope->FindSymbol(id);
}

 SLSymbol* DongLangBaseAST::FindSymbol(antlr4Ctx ctx, SYMBOL_ID id) {
	 auto scope = CurScope(ctx);
	 if (scope == NULL) {
		 return NULL;
	 }

	 return scope->FindSymbol(id);
 }

 FuncSLSymbol* DongLangBaseAST::FindFuncSymbol(antlr4Ctx ctx, string id, vector<DongLangTypeInfo*> argTypes, bool isVarArg) {
	 auto scope = CurScope(ctx);
	 if (scope == NULL) {
		 return NULL;
	 }

	 return scope->FindFuncSymbol(id, argTypes, isVarArg);
 }

 vector<FuncSLSymbol*>* DongLangBaseAST::FindFuncSymbolList(antlr4Ctx ctx, string baseId) {
	 auto scope = CurScope(ctx);
	 if (scope == NULL) {
		 return NULL;
	 }

	 return scope->FindFuncSymbolList(baseId);
 }

 llvm::Type* DongLangBaseAST::LlvmType(DongLangTypeInfo* spType) {
	 return spType->LlvmType(llvmBuilder);
 }