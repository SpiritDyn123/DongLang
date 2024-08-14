#include "DongLangPrimaryAST.h"
#include "llvm/IR/Constants.h"
#include "DongLangExprAST.h"

DongLangNumPrimaryAST::DongLangNumPrimaryAST(std::string value, DongLangTypeInfo* typeInfo): DongLangBaseAST(typeInfo),
	value(value){
}

Value* DongLangNumPrimaryAST::genCode() {
	auto typeInfo = exprType();
	if (typeInfo == NULL) {
		return NULL;
	}

	Value* idValue;
	if (typeInfo->isPoint()) {
		idValue = Constant::getNullValue(typeInfo->LlvmType(&lB));
	}
	else if (typeInfo->primary_type == "int") {
		idValue =  llvmBuilder->getInt64(stoll(value));
	}
	else if (typeInfo->primary_type == "float") {
		idValue = ConstantFP::get(*DongLangBaseAST::llvmCtx, APFloat(stod(value)));
	}
	else if (typeInfo->primary_type == "byte") {
		idValue = llvmBuilder->getInt8(stoll(value));
	} else if (typeInfo->primary_type == "bool") { //bool
		idValue = llvmBuilder->getInt8(value != "0" ? 1 : 0);
	}

	return idValue;
}

DongLangStrPrimaryAST::DongLangStrPrimaryAST(std::string s, DongLangTypeInfo* typeInfo) : DongLangBaseAST(typeInfo) {
	value = s.substr(1, s.length() - 2);

	value = regex_replace(value, regex("\\\\r\\\\n"), "\n");
	value = regex_replace(value, regex("\\\\n"), "\n");
	value = regex_replace(value, regex("\\\\t"), "\t");
}

Value* DongLangStrPrimaryAST::genCode() {
	auto typeInfo = exprType();
	if (typeInfo == NULL) {
		return NULL;
	}

	Value* idValue;
	if (typeInfo->primary_type == "string") {
		idValue = llvmBuilder->CreateGlobalString(value);
	} else { //bool
		idValue = llvmBuilder->getInt8(1);
	}

	return idValue;
}

DongLangBoolPrimaryAST::DongLangBoolPrimaryAST(std::string s, DongLangTypeInfo* typeInfo) : DongLangBaseAST(typeInfo) {
	value = s == "true" ? true : false;
}

Value* DongLangBoolPrimaryAST::genCode() {
	auto idValue = llvmBuilder->getInt8(value ? 1 : 0);
	return idValue;
}

DongLangIdPrimaryAST::DongLangIdPrimaryAST(antlr4Ctx ctx, std::string id, 
	DongLangBaseAST* idAst, 
	vector<DongLangBaseAST*>& arrAsts, 
	DongLangTypeInfo* typeInfo, 
	DongLangTypeInfo* defaultTypeInfo) : DongLangBaseAST(typeInfo), 
	id(id),
	idAst(idAst), 
	ctx(ctx), arrAsts(arrAsts),
	defaultTypeInfo(defaultTypeInfo) { 
	if (!defaultTypeInfo) {
		defaultTypeInfo = typeInfo;
	}
}

bool DongLangIdPrimaryAST::isAddressed() {
	DongLangTypeInfo* idTypeInfo = NULL;
	if (id != "") {
		auto symbol = FindSymbol(ctx, id);
		idTypeInfo = symbol->getVarType();
	}
	else { //idAst
		idTypeInfo = idAst->exprType();
	}

	return defaultTypeInfo->pas.size() - idTypeInfo->pas.size() + arrAsts.size() > 0;
}

Value* DongLangIdPrimaryAST::genCode() {
#if !defined(VERSION) || VERSION == 1000000
	Value* idValue = NULL;
	bool bSymbol = id != "";
	DongLangTypeInfo* idTypeInfo = NULL;
	if (bSymbol) {
		auto symbol = FindSymbol(ctx, id);
		idValue = symbol->getVal(); //alloca ptr
		idTypeInfo = symbol->getVarType();
	}
	else { //idAst
		idValue = idAst->genCodeWrap();
		idTypeInfo = idAst->exprType();
	}

	auto tmpTypeInfo = *idTypeInfo;

	bool needInitialLoad = dyn_cast<AllocaInst>(idValue) 
		|| dyn_cast<Constant>(idValue);

	bool isAd = false;
	if (idAst) {
		auto adAst = dynamic_cast<ICanAddressAST*>(idAst);
			isAd = adAst && adAst->isAddressed();
	}

	//array opr
	int arrOprCnt = arrAsts.size();
	if (arrOprCnt) {
		if (needInitialLoad && !tmpTypeInfo.isArray() && !isAd) {
			idValue = lB.CreateLoad(tmpTypeInfo.LlvmType(&lB), idValue);
		}

		int arrIndex = 0;
		for (auto arrIndexAst : arrAsts) {
			arrIndexAst->setFArg();
			auto arrIndexV = arrIndexAst->genCodeWrap();
			auto arrLLType = tmpTypeInfo.LlvmType(&lB);
			if (arrLLType->isPointerTy()) {
				tmpTypeInfo.DelPointArrayItem(PointOrArray(false));
				arrLLType = tmpTypeInfo.LlvmType(&lB);
				idValue = lB.CreateInBoundsGEP(arrLLType, idValue, { arrIndexV });
				if (arrIndex < arrOprCnt - 1 && arrLLType->isPointerTy()) { // 最后一次不用load
					idValue = lB.CreateLoad(arrLLType, idValue);
				}
			}
			else {
				idValue = lB.CreateInBoundsGEP(arrLLType, idValue, { lB.getInt32(0), arrIndexV });
				tmpTypeInfo.DelPointArrayItem(PointOrArray(false));
			}

			arrIndex++;
		}
	}
	
	//ptr opr
	int ptrOprCnt = defaultTypeInfo->pas.size() - tmpTypeInfo.pas.size();
	if (ptrOprCnt < 0) {
		int oprIndex = ptrOprCnt;
		if (!tmpTypeInfo.isArray()&& (!arrOprCnt && !needInitialLoad || isAd)) {
			tmpTypeInfo.DelPointArrayItem(PointOrArray(true));
			oprIndex++;
		}

		for (; oprIndex != 0; oprIndex++) {//*多次
			auto llType = tmpTypeInfo.LlvmType(&lB);
			if (tmpTypeInfo.isArray()) {
				idValue = lB.CreateInBoundsGEP(llType, idValue, { lB.getInt32(0), lB.getInt32(0) });
			}
			else {
				idValue = lB.CreateLoad(llType, idValue);
			}

			tmpTypeInfo.DelPointArrayItem(PointOrArray(true));
		}
	}
	else if (ptrOprCnt > 0 ) { //取地址只能一次
		//idValue = lB.CreateLoad(tmpTypeInfo.LlvmType(&lB), idValue);
	}

	//是否是左值 或函参
	bool bLeftValue = !getLeftValue();
	if ((!bLeftValue || getFArg()) && ptrOprCnt <= 0) {
		auto llType = tmpTypeInfo.LlvmType(&lB);
		if (!tmpTypeInfo.isArray()) { //array作为左值，右值必然只能是指针
			idValue = lB.CreateLoad(llType, idValue);
		}
	}
	
#elif VERSION >= 1000001
	Value* idValue = NULL;
	bool bSymbol = id != "";
	bool bLeftValue = !getLeftValue();
	bool bFArg = getFArg();
	DongLangTypeInfo tmpTypeInfo;

	bool needLeftOpr = bLeftValue && !bFArg;
	if (bSymbol) {
		auto symbol = FindSymbol(ctx, id);
		idValue = symbol->getVal(); //alloca ptr
		tmpTypeInfo = *(symbol->getVarType());

		int oprCnt = defaultTypeInfo->pas.size() - tmpTypeInfo.pas.size();
		if (needLeftOpr) {
			oprCnt++;
		}

		auto llType = tmpTypeInfo.LlvmType(&lB);
		if (!llType->isArrayTy() && oprCnt <= 0) {
			idValue = lB.CreateLoad(llType, idValue);
		}
	}
	else { //idAst
		idAst->setFArg();
		idValue = idAst->genCodeWrap();
		tmpTypeInfo = *(idAst->exprType());
	}

	int ptrOprCnt = defaultTypeInfo->pas.size() - tmpTypeInfo.pas.size();
	int arrOprCnt = arrAsts.size();
	if (arrOprCnt) {
		for (auto arrIndexAst : arrAsts) {
			arrIndexAst->setFArg();
			auto arrIndexV = arrIndexAst->genCodeWrap();
			auto arrLLType = tmpTypeInfo.LlvmType(&lB);
			if (arrLLType->isArrayTy()) {
				idValue = lB.CreateInBoundsGEP(arrLLType, idValue, { lB.getInt32(0), arrIndexV });
				tmpTypeInfo.DelPointArrayItem(PointOrArray(false));
			} else {
				tmpTypeInfo.DelPointArrayItem(PointOrArray(false));
				arrLLType = tmpTypeInfo.LlvmType(&lB);
				idValue = lB.CreateInBoundsGEP(arrLLType, idValue, { arrIndexV });
			}

			arrLLType = tmpTypeInfo.LlvmType(&lB);
			if (!arrLLType->isArrayTy() && (!needLeftOpr || ptrOprCnt != -1)) {
				idValue = lB.CreateLoad(arrLLType, idValue);
			}

			ptrOprCnt++;
		}
	}

	if (ptrOprCnt < 0) {
		for (; ptrOprCnt != 0; ptrOprCnt++) {//*多次
			auto ptrLLType = tmpTypeInfo.LlvmType(&lB);
			if (ptrLLType->isArrayTy()) {
				idValue = lB.CreateInBoundsGEP(ptrLLType, idValue, { lB.getInt32(0), lB.getInt32(0) });
			}

			tmpTypeInfo.DelPointArrayItem(PointOrArray(false));

			ptrLLType = tmpTypeInfo.LlvmType(&lB);
			if (!ptrLLType->isArrayTy() && (!needLeftOpr || ptrOprCnt != -1)) {
				idValue = lB.CreateLoad(ptrLLType, idValue);
			}
		}
	}

#endif

	return TransValue(defaultTypeInfo, idValue);
}
