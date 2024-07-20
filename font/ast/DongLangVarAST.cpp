#include "DongLangVarAST.h"
#include "DongLangPrimaryAST.h"

DongLangVarDeclareAST::DongLangVarDeclareAST(antlr4Ctx ctx,
	DongLangTypeInfo* spType,
	string id, 
	DongLangBaseAST* defaultValue,
	bool isGlobal,
	DongLangTypeInfo* typeInfo,
	bool isPrimary): DongLangBaseAST(typeInfo) {
	this->ctx = ctx;
	this->spType = spType;
	this->id = id;
	this->value = defaultValue;
	this->isGlobal = isGlobal;
	this->isPrimary = isPrimary;
}

Value* DongLangVarDeclareAST::genCode() {
	//DongLangArrayAST 带值初始化自己完成
	if (spType->isArray() && value != NULL) {
		return value->genCode();
	}

	//查找变量
	auto symbol = FindSymbol(ctx, id);
	auto llType = LlvmType(spType);

	auto idValue = isGlobal ? (Value*)lM.getOrInsertGlobal(id, llType) : (Value*)lB.CreateAlloca(llType, NULL, id);
	if (isGlobal) {
		auto gvar = (GlobalVariable*)idValue;
		gvar->setLinkage(GlobalValue::ExternalLinkage);
		gvar->setDSOLocal(true);
	}

	if (value) {
		if (isPrimary) {
			auto rValue = value->genCode();
			if (isGlobal) {
				auto gValue = ((GlobalVariable*)idValue);
				gValue->setInitializer((Constant*)rValue);
			}
			else {
				lB.CreateStore(rValue, idValue);
			}
		}
		else {
			auto* curBB = lB.GetInsertBlock();
			if (isGlobal) {
				auto& entryBB = lM.getFunction("global_main_init")->getEntryBlock();
				lB.SetInsertPoint(&entryBB);
			}
				
			value->setLeftValue(idValue);
			value->genCode();

			if (isGlobal) {
				lB.SetInsertPoint(curBB); //还原
			}

		}
	}
	else {
		if (isGlobal) { //全局分配一个默认值
			Value* zeroInit = Constant::getNullValue(llType);
			((GlobalVariable*)idValue)->setInitializer((Constant*)zeroInit);
		}
	}

	symbol->setVal(idValue);

	if (getFArg()) {
		idValue = lB.CreateLoad(llType, idValue);
		idValue = TransValue(spType, idValue);
	}

	return  idValue;
}

DongLangVarAST::DongLangVarAST(antlr4Ctx ctx,
	string id,
	DongLangBaseAST* defaultValue, 
	DongLangTypeInfo* typeInfo, 
	bool isPrimary) : DongLangBaseAST(typeInfo) {
	this->ctx = ctx;
	this->id = id;
	this->value = defaultValue;
	this->isPrimary = isPrimary;

}

Value* DongLangVarAST::genCode() {
	//查找变量
	auto symbol = FindSymbol(ctx, id);
	auto idValue = symbol->getVal();
	auto typeInfo = symbol->getVarType();
	auto llType = typeInfo->LlvmType(&lB);
	if (value != NULL) {
		if (isPrimary) {
			lB.CreateStore(value->genCode(), idValue);
		}
		else {
			value->setLeftValue(idValue);
			value->genCode();
		}
	}

	if (getFArg()) {
		idValue = lB.CreateLoad(llType, idValue);
		idValue = TransValue(typeInfo, idValue);
	}

	return  idValue;
}


DongLangAssignAST::DongLangAssignAST(DongLangBaseAST* idAst, 
	DongLangBaseAST* valueAst, 
	DongLangTypeInfo* typeInfo, 
	bool isPrimary) :
	DongLangBaseAST(typeInfo),
	idAst(idAst),
	valueAst(valueAst),
	isPrimary(isPrimary){
}

Value* DongLangAssignAST::genCode() {
	Value* idValue = idAst->genCode();
	if (valueAst) {
		if (isPrimary) {
			lB.CreateStore(valueAst->genCode(), idValue);
		}
		else {
			valueAst->setLeftValue(idValue);
			valueAst->genCode();
		}
	}
	
	if (getFArg()) {
		auto typeInfo = idAst->exprType();
		idValue = lB.CreateLoad(typeInfo->LlvmType(&lB), idValue);
		idValue = TransValue(typeInfo, idValue);
	}

	return  idValue;
}