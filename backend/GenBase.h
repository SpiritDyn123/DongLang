#pragma once

#include <iostream>
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Target/TargetMachine.h"
#include <map>
#include "font/DongLangScope.h"
#include "antlr4-runtime.h"
#include "include/dl_version.h"
using namespace std;
using namespace llvm;


class GenBase {
public:
	enum emGenType {
		genType_invalid = 0,
		genType_dl = 1,
		genType_ll = 2,
		genType_asm = 3,
		genType_obj = 4,
		genType_exe = 5,
	};
public:
	GenBase();
	virtual ~GenBase() = default;
	
	virtual emGenType genType() { return genType_invalid; }

	bool genWrap(GenBase*);
	TargetMachine* getTargetMachine();
	string getOutFileName();
protected:
	virtual bool gen(GenBase* srcGen, bool final) { return false; }

};

GenBase* createGen(GenBase::emGenType gt);

class DLGen : public GenBase {
public:
	virtual emGenType genType() override  { return genType_dl; }
protected:
	virtual bool gen(GenBase* srcGen, bool final) override;

};

class LLGen : public GenBase {
public:
	virtual emGenType genType() override { return genType_ll; }
protected:
	virtual bool gen(GenBase* srcGen, bool final) override;
};

class AsmGen : public GenBase {
public:
	virtual emGenType genType() override { return genType_asm; }
protected:
	virtual bool gen(GenBase* srcGen, bool final) override;
};

class ObjGen : public GenBase {
public:
	virtual emGenType genType() override { return genType_obj; }
protected:
	virtual bool gen(GenBase *srcGen, bool final) override;
};

class ExeGen : public GenBase {
public:
	virtual emGenType genType() override { return genType_exe; }
protected:
	virtual bool gen(GenBase* srcGen, bool final) override;

};

