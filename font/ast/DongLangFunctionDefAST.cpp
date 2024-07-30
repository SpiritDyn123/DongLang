#include "DongLangFunctionDefAST.h"
#include "DongLangVarAST.h"

DongLangFunctionDefAST::DongLangFunctionDefAST(antlr4Ctx ctx, 
	string fnName, vector<ArgInfo> args, bool isVarArg, bool hasBody, vector<DongLangBaseAST*> body)
{
	this->ctx = ctx;
	this->fnName = fnName;
	this->isVarArg = isVarArg;
	this->args = args;
	this->body = body;
	this->hasBody = hasBody;
}

const string& DongLangFunctionDefAST::getName() {
	return fnName;
}

Value* DongLangFunctionDefAST::genCode() {
	//cout << "DongLangFunctionDefAST:" << fnName << endl;
	//func_type
	vector<DongLangTypeInfo*> argTypes;
	argTypes.clear();

	vector<Type*> fArgTypes;
	fArgTypes.clear();
	for (auto& argT : args) {
		auto argTypeInfo = argT.typeInfo;
		argTypes.push_back(argTypeInfo);

		auto fArgType = argTypeInfo->LlvmType(&lB);
		fArgTypes.push_back(fArgType);
	}

	auto curScope = CurScope(ctx);
	auto funcSymbol = curScope->FindFuncSymbol(fnName, argTypes, isVarArg);
	auto lRetType = funcSymbol->getVarType()->LlvmType(&lB);
	if (funcSymbol->getVarType()->isArray()) {
		lRetType = lRetType->getArrayElementType()->getPointerTo();
	}

	auto fnType = FunctionType::get(lRetType, fArgTypes, funcSymbol->varArg());
	auto fn = Function::Create(fnType, GlobalValue::ExternalLinkage, funcSymbol->ID(), &lM);

	if (hasBody) {
		string& fnName = funcSymbol->Name();
		auto entryBB = BasicBlock::Create(lC, "entry_" + fnName, fn);
		lB.SetInsertPoint(entryBB);

		//var name
		int indx = 0;
		for (auto& arg : fn->args()) {
			auto& argInfo = args[indx];
			//arg.setName(argInfo.name);

			Value* argValue = lB.CreateAlloca(arg.getType(), NULL, argInfo.name);
			lB.CreateStore(&arg, argValue);
			//save symbol
			auto symbol = FindSymbol(argInfo.ctx, argInfo.name);
			auto symbolTypeInfo = symbol->getVarType();
			if (symbolTypeInfo->isArray()) {

			}
			symbol->setVal(argValue);
			indx++;
		}

		if (fnName == "main") {
			lB.CreateCall(lM.getFunction("global_main_init"));
		}

		bool hasRet = false;
		for (auto expr : body) {
			auto sv = expr->genCode();
			if (auto smBB = dyn_cast<BasicBlock>(sv); smBB && smBB != entryBB) {
				//当前模块不存在preds,可能内存存在break continue 导致的不可达代码
				if (pred_begin(smBB) == pred_end(smBB)) {
					smBB->eraseFromParent();
					break;
				}
			}
			else if (dyn_cast<ReturnInst>(sv)) {
				hasRet = true;
			}
		}

		if (!hasRet) {
			if (lRetType->isVoidTy()) {
				lB.CreateRetVoid();
			}
			else {
				lB.CreateRet(Constant::getNullValue(lRetType));
			}
		}
	}

	return fn;
}