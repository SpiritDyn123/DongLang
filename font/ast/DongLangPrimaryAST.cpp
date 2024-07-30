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

Value* DongLangIdPrimaryAST::genCode() {
	Value* idValue = NULL;
	bool bSymbol = id != "";
	DongLangTypeInfo* idTypeInfo = NULL;
	if (bSymbol) {
		auto symbol = FindSymbol(ctx, id);
		idValue = symbol->getVal(); //alloca ptr
		idTypeInfo = symbol->getVarType();
	}
	else { //idAst
		idAst->setFArg();
		idValue = idAst->genCode();
		idTypeInfo = idAst->exprType();
	}

	auto tmpTypeInfo = *idTypeInfo;


	bool needInitialLoad = dyn_cast<AllocaInst>(idValue) 
		|| dyn_cast<Constant>(idValue);

	//array opr
	int arrOprCnt = arrAsts.size();
	if (arrOprCnt) {
		if (needInitialLoad && !tmpTypeInfo.isArray()) {
			idValue = lB.CreateLoad(tmpTypeInfo.LlvmType(&lB), idValue);
		}

	
		int arrIndex = 0;
		for (auto arrIndexAst : arrAsts) {
			auto arrIndexV = arrIndexAst->genCode();
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
	if (ptrOprCnt) {
		if (ptrOprCnt > 0) { //取地址只能一次
			//idValue = lB.CreateLoad(tmpTypeInfo.LlvmType(&lB), idValue);
		}
		else {
			if (!arrOprCnt && !needInitialLoad && !tmpTypeInfo.isArray()) {
				tmpTypeInfo.DelPointArrayItem(PointOrArray(true));
				ptrOprCnt++;
			}

			for (; ptrOprCnt != 0; ptrOprCnt++) {//*多次
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
	}

	//是否是左值 或函参
	bool bLeftValue = !getLeftValue();
	if ((!bLeftValue || getFArg()) && ptrOprCnt <= 0) {
		auto llType = tmpTypeInfo.LlvmType(&lB);
		if (tmpTypeInfo.isArray()) { //array作为左值，右值必然只能是指针
			//idValue = lB.CreateGEP(llType, idValue, { lB.getInt32(0), lB.getInt32(0) });
		} else {
			idValue = lB.CreateLoad(llType, idValue);

		}
	}
	
	return TransValue(defaultTypeInfo, idValue);
}
