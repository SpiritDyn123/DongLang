#pragma once

#include <iostream>
#include "llvm/IR/Value.h"
#include <map>
#include <vector>
#include <string>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include <regex>
using namespace llvm;
using namespace std;


struct PointOrArray {
	bool pointOrArr;
	int array_len;
	PointOrArray(bool pointOrArr, int array_len = 0) : pointOrArr(pointOrArr), array_len(array_len) {}
};
struct DongLangTypeInfo {
	string primary_type;
	vector< PointOrArray> pas; //****[][][][][]
	bool constant;
	bool arrPtr;
	int size;
	DongLangTypeInfo(string primary_type, vector< PointOrArray> pas = {}, bool constant = false, bool arrPtr = false) :
		primary_type(primary_type),
		pas(pas), constant(constant), arrPtr(arrPtr), size(0){}
	string String();

	Type* LlvmType(IRBuilder<>* llvmBuilder);
	bool isPrimary() { return pas.size() == 0;}
	bool isArray() { return pas.size() > 0 && !pas[pas.size() - 1].pointOrArr; }
	bool isPoint() { return pas.size() > 0 && pas[pas.size() - 1].pointOrArr; }
	void AddPointArrayItem(PointOrArray pa);
	bool DelPointArrayItem(PointOrArray pa);
	PointOrArray* getArrayPA(uint offset = 0);

	static DongLangTypeInfo* typeCheckTrans(DongLangTypeInfo* t1, DongLangTypeInfo* t2, string opr = "", bool errReport = false, string reportStr = "");
	static DongLangTypeInfo* IntType;
	static DongLangTypeInfo* ConstIntType;
	static DongLangTypeInfo* ByteType;
	static DongLangTypeInfo* BoolType;
	static DongLangTypeInfo* FloatType;
	static DongLangTypeInfo* ConstFloatType;
	static DongLangTypeInfo* BitType;
	static DongLangTypeInfo* StringType;
};


