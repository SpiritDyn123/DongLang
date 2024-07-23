#include "DongLangExprAST.h"


DongLangCallExprAST::DongLangCallExprAST(FuncSLSymbol* funcSymbol,
	std::vector<DongLangBaseAST*>& args, bool isGlobal, DongLangTypeInfo* typeInfo, DongLangTypeInfo* defaultTypeInfo) :
	DongLangBaseAST(typeInfo),
	funcSymbol(funcSymbol),
	isGlobal(isGlobal),
	defaultTypeInfo(defaultTypeInfo) {
	//copy
	this->args.insert(this->args.begin(), args.begin(), args.end());

}

Value* DongLangCallExprAST::genCode() {
	auto fn = lM.getFunction(funcSymbol->ID());
	std::vector<Value*> fArgs(args.size());
	for (auto i = 0; i < args.size(); i++) {
		args[i]->setFArg();
		auto value = args[i]->genCode();
		auto argType = args[i]->exprType();
		if (argType->isArray() && value->getType()->isArrayTy()) {
			value = lB.CreateGEP(argType->LlvmType(&lB), value, {lB.getInt32(0), lB.getInt32(0)});
		}

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

	return callValue;

}

Value* DongLangRetExprAST::genCode() {
	if (!expr) {
		return lB.CreateRetVoid();
	}

	expr->setFArg();
	Value *retValue = expr->genCode();

	return llvmBuilder->CreateRet(retValue);
}

