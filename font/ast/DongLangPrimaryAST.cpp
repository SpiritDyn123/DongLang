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
	DongLangTypeInfo* defaultTypeInfo,
	DongLangTypeInfo* idTypeInfo) : DongLangBaseAST(typeInfo), 
	id(id),
	idAst(idAst), 
	ctx(ctx), arrAsts(arrAsts),
	defaultTypeInfo(defaultTypeInfo),
	idTypeInfo(idTypeInfo){ 
	if (!defaultTypeInfo) {
		defaultTypeInfo = typeInfo;
	}
}

Value* DongLangIdPrimaryAST::genCode() {
	Value* idValue = NULL;
	bool bSymbol = id != "";
	if (bSymbol) {
		auto symbol = FindSymbol(ctx, id);
		idValue = symbol->getVal(); //alloca ptr
	}
	else { //idAst
		idValue = idAst->genCode();
	}

	auto typeInfo = exprType();

	auto tmpTypeInfo = *idTypeInfo;

	//array opr
	for (auto arrIndexAst : arrAsts) {
		auto arrIndexV = arrIndexAst->genCode();
		auto arrLLType = tmpTypeInfo.LlvmType(&lB);
		if (arrLLType->isPointerTy()) {
			idValue = lB.CreateLoad(arrLLType, idValue);
			tmpTypeInfo.DelPointArrayItem(PointOrArray(false));
			arrLLType = tmpTypeInfo.LlvmType(&lB);
			idValue = lB.CreateInBoundsGEP(arrLLType, idValue, { arrIndexV });
		}
		else {
			idValue = lB.CreateInBoundsGEP(arrLLType, idValue, { lB.getInt32(0), arrIndexV });
			tmpTypeInfo.DelPointArrayItem(PointOrArray(false));
		}
	}

	bool bLeftValue = !getLeftValue();

	//point opr
	int pointCnt = defaultTypeInfo->pas.size() - tmpTypeInfo.pas.size();
	if (pointCnt != 0) {
		if (pointCnt > 0) { //ȡ��ַֻ��һ��
			if (!bSymbol) {
				idValue = lB.CreateLoad(tmpTypeInfo.LlvmType(&lB), idValue);
			}
		}
		else {
			if (bSymbol) {
				auto llType = tmpTypeInfo.LlvmType(&lB);
				if (tmpTypeInfo.isPoint()) {
					idValue = lB.CreateLoad(llType, idValue);
				}
				else {
					idValue = lB.CreateInBoundsGEP(llType, idValue, { lB.getInt32(0), lB.getInt32(0) });
				}
			}

			//�Ƿ�����ֵ
			if (bLeftValue && !getFArg()) {
				pointCnt++;
			}
			for (; pointCnt != 0; pointCnt++) {//*���
				if (tmpTypeInfo.isPoint()) {
					tmpTypeInfo.DelPointArrayItem(PointOrArray(true));
					auto llType = tmpTypeInfo.LlvmType(&lB);
					idValue = lB.CreateLoad(llType, idValue);
				}
				else {
					auto llType = tmpTypeInfo.LlvmType(&lB);
					idValue = lB.CreateInBoundsGEP(llType, idValue, { lB.getInt32(0), lB.getInt32(0)});
					tmpTypeInfo.DelPointArrayItem(PointOrArray(true));
				}
			}
		}
	}
	else {
		if (bSymbol && (!bLeftValue || getFArg())) {
			auto llType = tmpTypeInfo.LlvmType(&lB);
			if (!defaultTypeInfo->isArray()) {
				idValue = lB.CreateLoad(llType, idValue);
			}
		}
	}
	
	return TransValue(defaultTypeInfo, idValue);
}
