#include "DongLangExprAST.h"


DongLangCallExprAST::DongLangCallExprAST(FuncDLSymbol* funcSymbol,
	std::vector<DongLangBaseAST*>& args,
	std::vector<DongLangTypeInfo*>& argDefaultTypes,
	bool isGlobal) : DongLangBaseAST(funcSymbol->getVarType()),
	funcSymbol(funcSymbol),
	args(args),
	argDefaultTypes(argDefaultTypes),
	isGlobal(isGlobal) {
}

Value* DongLangCallExprAST::genCode() {
	auto fn = lM.getFunction(funcSymbol->ID());
	std::vector<Value*> fArgs(args.size());
	for (auto i = 0; i < args.size(); i++) {
		args[i]->setFArg();
		auto value = args[i]->genCode();

		//auto argType = args[i]->exprType();
		//if (argType->isArray() && argDefaultTypes[i]->isArray()) {// value->getType()->isArrayTy()
		//	value = lB.CreateGEP(argDefaultTypes[i]->LlvmType(&lB), value, {lB.getInt32(0), lB.getInt32(0)});
		//}

		fArgs[i] = value;
	}

	auto* curBB = lB.GetInsertBlock();
	Value* callValue = NULL;
	if ( isGlobal) {
		auto& entryBB = lM.getFunction("global_main_init")->getEntryBlock();
		lB.SetInsertPoint(&entryBB);
		callValue = lB.CreateCall(fn, fArgs);
		lB.SetInsertPoint(curBB); //»¹Ô­
	} else {
		callValue = lB.CreateCall(fn, fArgs);
	}

	return TransValue(funcSymbol->getVarType(), callValue);

}

Value* DongLangRetExprAST::genCode() {
	if (!expr) {
		return lB.CreateRetVoid();
	}

	expr->setFArg();
	Value *retValue = expr->genCode();
	auto retTypeInfo = expr->exprType();
	//if (retTypeInfo->isArray() && defaultTypeInfo->isArray()) { //&& retValue->getType()->isArrayTy()
	//	retValue = lB.CreateGEP(defaultTypeInfo->LlvmType(&lB), retValue, { lB.getInt32(0), lB.getInt32(0) });
	//}

	return llvmBuilder->CreateRet(retValue);
}

