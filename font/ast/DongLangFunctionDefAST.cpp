#include "DongLangFunctionDefAST.h"
#include "DongLangVarAST.h"

DongLangFunctionDefAST::DongLangFunctionDefAST(FuncDLSymbol* funcSymbol,
	string fnName, vector<ArgInfo> args, bool isVarArg, bool hasBody, vector<DongLangBaseAST*> body)
{
	this->funcSymbol = funcSymbol;
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
	for(auto argSs: funcSymbol->argSymbol()) {
		auto argTypeInfo = argSs->getVarType();
		argTypes.push_back(argTypeInfo);

		auto fArgType = argTypeInfo->LlvmType(&lB);
		fArgTypes.push_back(fArgType);
	}

	auto lRetType = funcSymbol->getVarType()->LlvmType(&lB);
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
				//��ǰģ�鲻����preds,�����ڴ����break continue ���µĲ��ɴ����
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

		BasicBlock* endBB = NULL;
		for (BasicBlock& bb : *fn) {
			endBB = &bb;
		}

		if (endBB->size() > 1) {
			auto newBB = BasicBlock::Create(lC, "", fn);
			newBB->moveAfter(endBB);
			for (auto it = endBB->begin(); it != endBB->end(); ++it) {
				if (auto retInst = dyn_cast<ReturnInst>(it)) {
					//BranchInst::Create(newBB, retInst);
					//endBB->erase(it, endBB->end());
					break;
				}
			}

			endBB = newBB;
			//ReturnInst::Create(, endBB);
		}

		for (BasicBlock& bb : *fn) {
			if (&bb == endBB) {
				break;
			}

			BasicBlock::iterator it;
			for (it = bb.begin(); it != bb.end();++it) {
				if (auto retInst = dyn_cast<ReturnInst>(it)) {
					//BranchInst::Create(endBB, retInst);
					//bb.erase(it, bb.end());
					break;
				}
			}
		}
	}

	return fn;
}