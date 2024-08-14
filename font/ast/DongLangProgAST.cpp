#include "DongLangProgAST.h"
#include "DongLangFunctionDefAST.h"
#include "llvm/IR/Type.h"
#include "include/dl_flag.h"

DongLangProgAST::DongLangProgAST(vector<DongLangBaseAST*>& lineAsts) {
	this->lineAsts = lineAsts;

	//global_main_init
	/*auto rootScope = CurScope(NULL);
	auto mainRetType = new DongLangTypeInfo("void");
	vector<DongLangTypeInfo*> mainArgTs = {};
	vector<VarDLSymbol*> mainArgSs = {};
	auto gloablMainInitFuncSs = FuncDLSymbol::Create("global_main_init",
		mainRetType, mainArgSs, mainArgTs, NULL, true, false);
	rootScope->AddSymbol("global_main_init", func_global_main_init_id, gloablMainInitFuncSs);
	
	CodeLocData locData(0, 0, "");
	auto mainInitFn = new DongLangFunctionDefAST(gloablMainInitFuncSs, "global_main_init", {}, false, true, {}, locData);
	this->lineAsts.insert(this->lineAsts.begin(), mainInitFn);*/

	doSysExternFuncs();

	bool hasMain = false;
	for (auto line : lineAsts) {
		auto fn = dynamic_cast<DongLangFunctionDefAST*>(line);
		if (!fn) {
			continue;
		}

		if (fn->getName() == "main") {
			hasMain = true;
			break;
		}
	}

	if (!hasMain) {
		/*auto mainFuncSs = FuncDLSymbol::Create("main",
			mainRetType, mainArgSs, mainArgTs, NULL, true, false);
		rootScope->AddSymbol("main", func_main_id, mainFuncSs);
		this->lineAsts.insert(this->lineAsts.end(), new DongLangFunctionDefAST(mainFuncSs, "main", {}, false, true, {}, locData));*/
	}
}

void DongLangProgAST::doSysExternFuncs() {
}

Value* DongLangProgAST::genCode() {
	//初始化一个init函数

#if 1
	for (auto line : lineAsts) {
		Value* v = line->genCodeWrap();
	}

	auto globalMainInitFunc = GetGlobalMainInit(false);
	if (globalMainInitFunc) {
		auto& entryBB = globalMainInitFunc->getEntryBlock();
		lB.SetInsertPoint(&entryBB);
		lB.CreateRetVoid();
	}

	if (FLAGS_g) {
		lDB.finalize();
	}
#else 
	testStudy();
#endif
	return NULL;
}


#define CREAT_TEST_FUNC(fnName) vector<Type*> argTypes; \
	FunctionType* tfnType = FunctionType::get(lB.getVoidTy(), argTypes, false); \
	Function* tfn = Function::Create(tfnType, GlobalValue::ExternalLinkage, string(fnName), &lM); \
	BasicBlock* entryBB = BasicBlock::Create(lC, string(fnName) + "_entry:", tfn); \
	lB.SetInsertPoint(entryBB);


void DongLangProgAST::testStudy() {
	//创建main
	CREAT_TEST_FUNC("main");

	auto v1 = lB.CreateAlloca(lB.getInt32Ty());
	auto v2 = lB.CreateAlloca(lB.getInt8Ty()->getPointerTo());
	auto v3 = lB.CreateAlloca(ArrayType::get(lB.getInt32Ty(), 2));
	for (auto v : { v1,v2,v3 }) {
		cout << "type info:" << v->getType()->getTypeID() << "," << (PointerType*)(v->getType())->getTypeID()
	
			<< endl;
	}
	
	//testSysFunctions();

	//testGlobalVars();

	//testIfAndFor();

	//testArrayAndStruct();
	
	//jit engine
	
}

void DongLangProgAST::testSysFunctions() {
	CREAT_TEST_FUNC("testSysFunctions")

	//call sys printf
	llvm::FunctionType* func_type = llvm::FunctionType::get(
		llvm::Type::getInt32Ty(lM.getContext()),
		{ llvm::Type::getInt8PtrTy(lM.getContext()) },
		true);
	auto func = llvm::Function::Create(func_type, llvm::GlobalValue::ExternalLinkage, "printf", lM);
	lB.CreateCall(func, { lB.CreateGlobalString("hello world:%d\n"), lB.getInt32(22) });
}

void DongLangProgAST::testGlobalVars() {
	CREAT_TEST_FUNC("testGlobalVars")

	std::string gvName = "gvar1";
	auto vvvv = (Value*)lM.getOrInsertGlobal(gvName, Type::getDoubleTy(*llvmCtx));
	GlobalVariable* gv = lM.getNamedGlobal(gvName);
	gv->setLinkage(GlobalValue::CommonLinkage);
	gv->setAlignment(MaybeAlign(8));

	gv->setInitializer(lB.getInt32(111));// (Constant*)lB.CreateCall(gfun1, {}));

	//extern
	lM.getOrInsertGlobal("gExtV1", Type::getInt32Ty(lC));

	//全局常量字符串
	gvName = "gCStr";
	auto gStr = ConstantDataArray::getString(lC, "hello llvm");
	lM.getOrInsertGlobal(gvName, gStr->getType());
	gv = lM.getNamedGlobal(gvName);
	gv->setConstant(true);
	gv->setInitializer(gStr);

	//全局数组 str,int
	gvName = "gStr";
	lM.getOrInsertGlobal(gvName, ArrayType::get(Type::getInt8Ty(lC), 20));
	gv = lM.getNamedGlobal(gvName);
	gv->setInitializer(gStr);

	gvName = "gIntArrVar";
	lM.getOrInsertGlobal(gvName, ArrayType::get(Type::getInt32Ty(lC), 3));
	gv = lM.getNamedGlobal(gvName);

	vector<Constant*> intVArr;
	intVArr.clear();
	intVArr.push_back(ConstantInt::get(Type::getInt32Ty(lC), 1));
	intVArr.push_back(ConstantInt::get(Type::getInt32Ty(lC), 2));
	intVArr.push_back(ConstantInt::get(Type::getInt32Ty(lC), 3));
	Constant* intArr = ConstantArray::get((ArrayType*)gv->getType(), intVArr);
	gv->setConstant(true);
	gv->setInitializer(intArr);
}

void DongLangProgAST::testArrayAndStruct() {
	CREAT_TEST_FUNC("testArrayAndStruct");

	//array
	Type* arrT = ArrayType::get(lB.getInt32Ty(), 5);

	auto  arrV = lB.CreateAlloca(arrT);
	lB.CreateConstGEP2_32(arrT, arrV, 0, 1);

	lB.CreateConstGEP2_32(arrV->getAllocatedType(), arrV, 0, 3);
}

void DongLangProgAST::testIfAndFor() {
	CREAT_TEST_FUNC("testIfAndFor");

	auto& fn = tfn;
	auto& block = entryBB;

	//if else
	auto ifBB = BasicBlock::Create(lC, "if", fn);
	BranchInst::Create(ifBB, block); //br label if; 无条件跳转

	auto ifThenBB = BasicBlock::Create(lC, "if.then", fn);
	auto ifElseBB = BasicBlock::Create(lC, "if.else", fn);
	auto ifEndBB = BasicBlock::Create(lC, "if.end", fn);

	auto cmp = new ICmpInst(*ifBB, ICmpInst::Predicate::ICMP_SGT, lB.getInt32(12), lB.getInt32(22), "gt");
	BranchInst::Create(ifThenBB, ifElseBB, cmp, ifBB);

	for (auto i = 0; i < 3; i++) {
		auto vv = lB.CreateAlloca(Type::getInt32Ty(lC), NULL, "if.then.v" + to_string(i));
		vv->removeFromParent(); //必须先删除
		vv->insertInto(ifThenBB, ifThenBB->end());

		auto svv = lB.CreateStore(vv, lB.getInt32(333));
		svv->removeFromParent(); //必须先删除
		svv->insertInto(ifThenBB, ifThenBB->end());
	}

	BranchInst::Create(ifEndBB, ifThenBB);

	BranchInst::Create(ifEndBB, ifElseBB);

	auto forBB = BasicBlock::Create(lC, "forbegin", fn);
	auto forLoopBB = BasicBlock::Create(lC, "forloop", fn);

	auto forEndBB = BasicBlock::Create(lC, "forend", fn);
	lB.CreateBr(forBB);
	lB.CreateBr(forLoopBB);

	//for
	lB.SetInsertPoint(forLoopBB);
	auto phi = lB.CreatePHI(Type::getInt32Ty(lC), 2, "i");
	phi->addIncoming(lB.getInt32(0), forBB);

	auto printFunc = lM.getOrInsertFunction("printf", FunctionType::get(Type::getVoidTy(lC), { Type::getInt8PtrTy(lC) }, true));
	lB.CreateCall(printFunc, { lB.CreateGlobalString("hello world") });
	auto newI = lB.CreateAdd(phi, lB.getInt32(32), "i");
	auto forICmp = new ICmpInst(*forLoopBB, CmpInst::Predicate::ICMP_ULT, newI, lB.getInt32(10), "fcmp");
	lB.CreateCondBr(forICmp, forLoopBB, forEndBB);
	phi->addIncoming(newI, forLoopBB);
	lB.SetInsertPoint(forEndBB);
	lB.CreateRetVoid();
}