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
		auto idValue = value->genCodeWrap();
		if (idValue && getFArg()) {
			idValue = TransValue(spType, idValue);
		}
		return idValue;
	}

	//查找变量
	auto symbol = FindSymbol(ctx, id);
	auto llType = LlvmType(spType);

	auto idValue = isGlobal ? (Value*)lM.getOrInsertGlobal(id, llType) : (Value*)lB.CreateAlloca(llType, NULL, id);
	if (isGlobal) {
		auto gvar = (GlobalVariable*)idValue;
		//gvar->setLinkage(GlobalValue::ExternalLinkage);
		gvar->setDSOLocal(true);
	}

	if (!value || !isPrimary) {
		Value* zeroInit = Constant::getNullValue(llType);
		if (isGlobal) { //全局分配一个默认值
			((GlobalVariable*)idValue)->setInitializer((Constant*)zeroInit);
		}
		else if(!value){
			lB.CreateStore(zeroInit, idValue); //默认值
		}
	}

	if (value) {
		if (isPrimary) {
			auto rValue = value->genCodeWrap();
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

				auto& entryBB = GetGlobalMainInit()->getEntryBlock();
				lB.SetInsertPoint(&entryBB);
			}
				
			value->setLeftValue(idValue);
			value->genCodeWrap();

			if (isGlobal) {
				lB.SetInsertPoint(curBB); //还原
			}

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
			lB.CreateStore(value->genCodeWrap(), idValue);
		}
		else {
			value->setLeftValue(idValue);
			value->genCodeWrap();
		}
	}

	if (getFArg()) {
		//数组不能赋值
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
	Value* idValue = idAst->genCodeWrap();
	if (valueAst) {
		if (isPrimary) {
			lB.CreateStore(valueAst->genCodeWrap(), idValue);
		}
		else {
			valueAst->setLeftValue(idValue);
			valueAst->genCodeWrap();
		}
	}
	
	if (getFArg()) {
		DongLangTypeInfo idTypeInfo = *(idAst->exprType());
		if (!idTypeInfo.isArray()) {
			idValue = lB.CreateLoad(idTypeInfo.LlvmType(&lB), idValue);
		}

		idValue = TransValue(&idTypeInfo, idValue);
	}

	return  idValue;
}