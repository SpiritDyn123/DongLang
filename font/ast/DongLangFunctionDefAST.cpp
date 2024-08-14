#include "DongLangFunctionDefAST.h"
#include "DongLangVarAST.h"

DongLangFunctionDefAST::DongLangFunctionDefAST(FuncDLSymbol* funcSymbol,
	string fnName, vector<ArgInfo> args, bool isVarArg, bool hasBody, vector<DongLangBaseAST*> body, 
	CodeLocData& locData) : DongLangBaseAST(NULL, locData)
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
	/*cout << "DongLangFunctionDefAST:" << fnName 
		<<  ",line:" << LocData().line 
		<<  ",column:" << LocData().column
		<< ",code:" << LocData().code
		<< endl;*/
	
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

		int scopeLine = getLocLine();
		DISubprogram* debugSp = NULL;
		DIFile* dUnit = NULL;
		if (G_DEBUG) {
			dUnit = lDB.createFile(lDI.cu->getFilename(),
				lDI.cu->getDirectory());
			SmallVector<Metadata*, 8> argMetas;
			argMetas.push_back(funcSymbol->getVarType()->getDebugType()); // return meta type
			for (auto argSs : funcSymbol->argSymbol()) { // args meta type
				auto argTypeInfo = argSs->getVarType();
				argMetas.push_back(argTypeInfo->getDebugType());
			}

			 debugSp = lDB.createFunction(
				dUnit, fnName, StringRef(), dUnit, scopeLine,
				lDB.createSubroutineType(lDB.getOrCreateTypeArray(argMetas)),
				scopeLine,
				DINode::FlagPrototyped, 
				DISubprogram::SPFlagDefinition);
			fn->setSubprogram(debugSp);
			lDI.enterScope(debugSp);

			// break not stay in function def line
			lDI.emitLocation(NULL);
		}

		//var name
		int indx = 0;
		Instruction* lastArgInst = NULL;
		for (auto& arg : fn->args()) {
			auto& argInfo = args[indx];
			//arg.setName(argInfo.name);

			Value* argValue = lB.CreateAlloca(arg.getType(), NULL, argInfo.name);
			lastArgInst = lB.CreateStore(&arg, argValue);
			//save symbol
			auto symbol = FindSymbol(argInfo.ctx, argInfo.name);
			auto symbolTypeInfo = symbol->getVarType();
			if (symbolTypeInfo->isArray()) {

			}
			symbol->setVal(argValue);
			indx++;

			if (G_DEBUG) {
				DILocalVariable* debugValue = lDB.createParameterVariable(
					debugSp, argInfo.name, indx, dUnit, scopeLine, symbolTypeInfo->getDebugType(),
					true);
				lDB.insertDeclare(argValue, debugValue, lDB.createExpression(),
					DILocation::get(debugSp->getContext(), scopeLine, 0, debugSp),
					lB.GetInsertBlock());
			}

		}

		/*if (fnName == "main") {
			lB.CreateCall(lM.getFunction("global_main_init"));
		}*/

		for (auto expr : body) {
			auto sv = expr->genCodeWrap();
			if (auto smBB = dyn_cast<BasicBlock>(sv); smBB && smBB != entryBB) {
				//当前模块不存在preds,可能内存存在break continue 导致的不可达代码
				if (pred_begin(smBB) == pred_end(smBB)) {
					smBB->eraseFromParent();
					break;
				}
			}
		}

#if 1
		/*
		 * return修正，后续TODO成Pass
		 */
		BasicBlock* endBB = lB.GetInsertBlock();
		ReturnInst* retInst = NULL;
		for (auto it = endBB->begin(); it != endBB->end(); ++it) {
			if (retInst = dyn_cast<ReturnInst>(it); retInst) {
				break;
			}
		}

		//1、retvalue填充
		Value* allocRetValue = NULL;
		if (entryBB != endBB && !lRetType->isVoidTy()) {
			allocRetValue = lB.CreateAlloca(lRetType);
			if (lastArgInst) {
				((AllocaInst*)allocRetValue)->moveAfter(lastArgInst);
			}
			else if (entryBB->size()) {
				((AllocaInst*)allocRetValue)->moveAfter(dyn_cast<Instruction>(entryBB->begin()));
			}

			if (retInst) {
				lB.CreateStore(retInst->getReturnValue(), allocRetValue);
				retInst->eraseFromParent();
			}


			//2、新增endBB
			if (endBB->size() > 1 && !dyn_cast<ReturnInst>(endBB->begin())) {
				auto newBB = BasicBlock::Create(lC, "", fn);
				newBB->moveAfter(endBB);
				endBB = newBB;
			}
			
			lB.SetInsertPoint(endBB);
			retInst = lB.CreateRet(lB.CreateLoad(lRetType, allocRetValue));
		}
		else {
			if (!retInst) {
				lRetType->isVoidTy() ? lB.CreateRetVoid() : lB.CreateRet(Constant::getNullValue(lRetType));
			}
		}
		
		//3、优化branchinst、returninst
		for (BasicBlock& bb : *fn) {
			for (auto it = bb.begin(); it != bb.end(); ++it) {
				if (auto brInst = dyn_cast<BranchInst>(it)) {
					break;

				} else if (auto retInst = dyn_cast<ReturnInst>(it)) {
					if (&bb != endBB) {
						lB.SetInsertPoint(&bb);
						if (allocRetValue != NULL) {
							auto inst = lB.CreateStore(retInst->getReturnValue(), allocRetValue);
							inst->moveBefore(retInst);
						}

						BranchInst::Create(endBB, retInst);
					}

					break;
				}
			}

			Instruction* brInst = NULL;
			for (auto it = bb.begin(); it != bb.end(); ++it) {
				if (dyn_cast<BranchInst>(it) || dyn_cast<ReturnInst>(it)) {
					if (++it != bb.end()) {
						bb.erase(it, bb.end());
					}
					brInst = NULL;
					break;
				}

				brInst = dyn_cast<Instruction>(it);
			}

			if (brInst) {
				BranchInst::Create(endBB, &bb);
			}
		}
#endif

		if (G_DEBUG) {
			lDI.leaveScope();
		}
	}

	return fn;
}