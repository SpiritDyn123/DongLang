#include "font/ast/DongLangBaseAST.h"
#include "llvm/Support/TargetSelect.h"  
#include "llvm/Target/TargetMachine.h" 
#include "llvm/TargetParser/Host.h"
#include "backend/GenBase.h"

LLVMContext* DongLangBaseAST::llvmCtx = NULL;
Module* DongLangBaseAST::llvmModule = NULL;
IRBuilder<>* DongLangBaseAST::llvmBuilder = NULL;
DongLangDebugInfo DongLangBaseAST::dbgInfo;

map<DongLangBaseAST::antlr4Ctx, DongLangScope*> DongLangBaseAST::mScopes;
DongLangScope* DongLangBaseAST::rootScope = NULL;

Value* DongLangBaseAST::genCodeWrap() {
	if(G_DEBUG) lDI.emitLocation(this);
	return this->genCode();
}

Value* DongLangBaseAST::TransValue(DongLangTypeInfo* defaultTypeInfo, Value* curValue) {
	if (!typeInfo) {
		return curValue;
	}

	string t1S = typeInfo->String();
	string t2S = defaultTypeInfo->String();

	//int <==> float trans
	auto llType = typeInfo->LlvmType(&lB);
	if (t1S != t2S) {
		if (typeInfo->isPrimary()) {
			Instruction::CastOps castT;
			if (t1S == "bool" || t1S == "bit") {
				if (t2S != "bit") {
					//if (defaultTypeInfo->isArray()) { //数组比较特殊
					//	curValue = lB.CreateGEP(defaultTypeInfo->LlvmType(&lB), curValue, { lB.getInt32(0), lB.getInt32(0) });
					//}
					
					Value* zeroValue = Constant::getNullValue(curValue->getType());
					if (t2S == "float") {
						curValue = lB.CreateFCmpUNE(curValue, zeroValue);
					}
					else if (defaultTypeInfo->isArray()) {
						curValue = lB.getInt1(1);
					}
					else {
						curValue = lB.CreateICmpNE(curValue, zeroValue);
					}
				}

				if (t1S == "bool") {
					castT = Instruction::ZExt;
				}
			}
			else {
				if (t1S == "int") {
					if (t2S == "float") {
						castT = Instruction::FPToSI;
					}
					else {
						castT = Instruction::SExt;
					}
				}
				else if (t1S == "float") {
					castT = Instruction::SIToFP;
				}
				else if (t1S == "byte") {
					if (t2S == "int") {
						castT = Instruction::Trunc;
					}
					else {
						castT = Instruction::FPToSI;
					}
				}
			}

			if (!llType->isIntegerTy(1)) {
				curValue = lB.CreateCast(castT, curValue, llType);
			}
		}
		else if (typeInfo->isPoint()) {
			if (defaultTypeInfo->isArray()) {
				curValue = lB.CreateInBoundsGEP(defaultTypeInfo->LlvmType(&lB), curValue, {lB.getInt32(0), lB.getInt32(0)});
			}
		}
	}
	
	if (leftValue) {
		lB.CreateStore(curValue, leftValue);
		curValue = leftValue;
	}

	return curValue;
}

 void DongLangBaseAST::InitLLVMAST() {
	llvmCtx = new LLVMContext();
	llvmModule = new Module("spirit lang jit", *llvmCtx);
	llvmBuilder = new IRBuilder<>(*llvmCtx);

	auto defaultTargetTrip = sys::getDefaultTargetTriple();
	llvmModule->setTargetTriple(defaultTargetTrip);
	llvmModule->setDataLayout(GenBase::getTargetMachine(lM, lC)->createDataLayout());

	//开启debug
	if (G_DEBUG) {
		dbgInfo.Init();
	}

	mScopes.clear();
}

 DongLangScope* DongLangBaseAST::AddScope(antlr4Ctx ctx, bool isRoot, string name, DongLangScope* parent) {
	 auto it = mScopes.find(ctx);
	 if (it != mScopes.end()) {
		 return it->second;
	 }

	 if (!parent) {
		 parent = CurScope(ctx);
	 }
	 
	 if (name == "") {
		 name = std::to_string((long long)ctx);
	 }

	 if (parent) {
		 name = parent->getName() + "." + name;
	 }

	 mScopes[ctx] = new DongLangScope(parent, name);
	 if (isRoot) {
		 rootScope = mScopes[ctx];
	 }
	 return mScopes[ctx];
}

DongLangScope* DongLangBaseAST::CurScope(antlr4Ctx ctx) {
	if (ctx == NULL) {
		return rootScope;
	}

	for (auto pCtx = ctx; pCtx != NULL; pCtx = (antlr4Ctx)pCtx->parent) {
		auto pScp = mScopes.find(pCtx);
		if (pScp != mScopes.end()) {
			return pScp->second;
		}
	}

	return NULL;
}

 DLSymbol* DongLangBaseAST::FindSymbol(antlr4Ctx ctx, string id) {
	 auto scope = CurScope(ctx);
	 if (scope == NULL) {
		 return NULL;
	 }

	 return scope->FindSymbol(id);
}

 DLSymbol* DongLangBaseAST::FindSymbol(antlr4Ctx ctx, SYMBOL_ID id) {
	 auto scope = CurScope(ctx);
	 if (scope == NULL) {
		 return NULL;
	 }

	 return scope->FindSymbol(id);
 }

 FuncDLSymbol* DongLangBaseAST::FindFuncSymbol(antlr4Ctx ctx, string id, vector<DongLangTypeInfo*> argTypes, bool isVarArg) {
	 auto scope = CurScope(ctx);
	 if (scope == NULL) {
		 return NULL;
	 }

	 return scope->FindFuncSymbol(id, argTypes, isVarArg);
 }

 vector<FuncDLSymbol*>* DongLangBaseAST::FindFuncSymbolList(antlr4Ctx ctx, string baseId) {
	 auto scope = CurScope(ctx);
	 if (scope == NULL) {
		 return NULL;
	 }

	 return scope->FindFuncSymbolList(baseId);
 }

 llvm::Type* DongLangBaseAST::LlvmType(DongLangTypeInfo* spType) {
	 return spType->LlvmType(llvmBuilder);
 }

 llvm::Function* DongLangBaseAST::GetGlobalMainInit(bool create) {
	 string fnName = "global_main_init";
	 Function* fn = lM.getFunction(fnName);
	 if (fn || !create) {
		 return fn;
	 }

	 // 创建一个全局构造函数  
	 llvm::FunctionType* fnType = llvm::FunctionType::get(llvm::Type::getVoidTy(lC), false);
	 fn = llvm::Function::Create(fnType,
		 llvm::Function::InternalLinkage, fnName, lM);
	 auto entryBB = BasicBlock::Create(lC, "entry_" + fnName, fn); // entry bb

	 // 定义结构体类型来存储函数指针和优先级  
	 std::vector<llvm::Type*> fields;
	 fields.push_back(llvm::Type::getInt32Ty(lC)); // 优先级  
	 fields.push_back(llvm::PointerType::getUnqual(fnType));       // 函数指针  
	 llvm::StructType* ctorEntryType = llvm::StructType::create(lC, fields, "global_ctor_ele_type");

	 // 创建一个全局数组来存储构造函数条目  
	 llvm::ArrayType* arrayType = llvm::ArrayType::get(ctorEntryType, 1); // 假设只有一个构造函数  
	 std::vector<llvm::Constant*> arrayElements = {};
	 arrayElements.push_back(llvm::ConstantStruct::get(
		 ctorEntryType,
		 {
			 llvm::ConstantInt::get(llvm::Type::getInt32Ty(lC), 65535), // 优先级  
			 llvm::ConstantExpr::getBitCast(fn, llvm::PointerType::getUnqual(fnType)) // 函数指针  
		 }
	 ));
	 llvm::Constant* initializer = llvm::ConstantArray::get(arrayType, arrayElements);

	 // 创建全局变量（注意：这里我们没有直接指定段名，这通常是通过链接器脚本或后端特性来处理的）  
	 llvm::GlobalVariable* globalCtors = new llvm::GlobalVariable(
		 lM,
		 arrayType,
		 false, // isConstant  
		 llvm::GlobalValue::AppendingLinkage,
		 initializer,
		 "llvm.global_ctors" 
	 );

	 return fn;
 }