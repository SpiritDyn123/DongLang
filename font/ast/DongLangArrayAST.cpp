#include "DongLangArrayAST.h"
#include "llvm/IR/Constants.h"

Constant* DongLangArrayAST::genConstantValue() {
	auto typeInfo = spType;
	auto arrT = LlvmType(typeInfo);

	vector<Constant*> arrItemValues;
	for (auto cAst : arrAsts) {
		arrItemValues.push_back((Constant*)cAst->genCode());
	}

	auto eleTypeInfo = DongLangTypeInfo(*typeInfo);
	eleTypeInfo.DelPointArrayItem(PointOrArray(false));
	auto eleType = eleTypeInfo.LlvmType(&lB);
	for (int i = arrItemValues.size(); i < typeInfo->getArrayPA()->array_len; i++) {
		arrItemValues.push_back(Constant::getNullValue(eleType));
	}

	return ConstantArray::get((ArrayType*)arrT, arrItemValues);
}

void DongLangArrayAST::genUnPrimaryArrayItem(bool isGlobal, DongLangBaseAST* ast, Value* arrValue, vector<int> indexs) {
	DongLangArrayAST* arrAst = dynamic_cast<DongLangArrayAST*>(ast);
	if (arrAst) {
		int i = 0;
		for (auto cAst : arrAst->arrAsts) {
			vector<int> cIndexs = indexs;
			cIndexs.push_back(i);
			genUnPrimaryArrayItem(isGlobal, cAst, arrValue, cIndexs);
			i++;
		}
	}
	else {
		vector<Value*> indxValues;
		indxValues.clear();
		indxValues.push_back(lB.getInt64(0));
		for (auto index : indexs) {
			indxValues.push_back(lB.getInt64(index));
		}

		Value* idValue = ast->genCode();
		auto* curBB = lB.GetInsertBlock();
		if (isGlobal) {
			auto& entryBB = lM.getFunction("global_main_init")->getEntryBlock();
			lB.SetInsertPoint(&entryBB);
		}

		auto typeInfo = spType;
		auto arrT = LlvmType(typeInfo);
		Value* indexValuePtr = lB.CreateInBoundsGEP(arrT, arrValue, indxValues);
		lB.CreateStore(idValue, indexValuePtr);

		if (isGlobal) {
			lB.SetInsertPoint(curBB); //还原
		}
	
	}
}

Value* DongLangArrayAST::genCode() {
	auto typeInfo = spType;
	auto arrT = LlvmType(typeInfo);

	if (!idSymbol) {
		if (isPrimary) {
			return genConstantValue();
		}

		return NULL;
	}

	string id = idSymbol->ID();
	bool isGlobal = idSymbol->getScope() == RootScope();
	
	auto arrValue = isGlobal ? (Value*)lM.getOrInsertGlobal(id, arrT) : (Value*)lB.CreateAlloca(arrT, NULL, id);
	if (isGlobal) {
		auto gvar = (GlobalVariable*)arrValue;
		gvar->setLinkage(GlobalValue::ExternalLinkage);
		gvar->setDSOLocal(true);
	}

	arrValue->setName(id);

	if (isPrimary) {
		auto arrV = genConstantValue();
		if (isGlobal) {
			auto gvar = (GlobalVariable*)arrValue;
			gvar->setInitializer(arrV);
		}
		else {
			//创建全局变量然后调用内置memcpy复制
			string globalID = idSymbol->getScope()->getName() + "." + id;
			auto gArrValue = lM.getOrInsertGlobal(globalID, arrT);
			((GlobalVariable*)gArrValue)->setInitializer(arrV);
			
			//auto memcpyFunc = Intrinsic::getDeclaration(&lM, Intrinsic::memcpy, FunctionType::get(
			//	lB.getInt8PtrTy(), // 返回类型为 void  
			//	{ 
			//		lB.getInt8PtrTy(), // 第一个参数为 i8*  
			//		lB.getInt8PtrTy(), // 第二个参数为 i8*  
			//		lB.getInt64Ty(),
			//		lB.getInt1Ty(),
			//	}, // 第三个参数为 i64  
			//	false // 不是 vararg  
			//));
			/*
			cout << "memcpy:" << memcpyFunc << endl;
			lB.CreateCall(memcpyFunc, {
				lB.CreateBitCast(arrValue, lB.getInt8PtrTy()), 
				lB.CreateBitCast(gArrValue, lB.getInt8PtrTy()),
				lB.getInt64(typeInfo->size)});*/

			Function* memcpyFunc = lM.getFunction("memcpy");
			lB.CreateCall(memcpyFunc, {
				lB.CreateBitCast(arrValue, lB.getInt8PtrTy()),
				lB.CreateBitCast(gArrValue, lB.getInt8PtrTy()),
				lB.getInt64(typeInfo->size) });
		}
	}
	else {
		if (isGlobal) {
			auto gvar = (GlobalVariable*)arrValue;
			gvar->setInitializer(Constant::getNullValue(arrT));
		}

		genUnPrimaryArrayItem(isGlobal, this, arrValue, {});
	}

	idSymbol->setVal(arrValue);
	return arrValue;
}
