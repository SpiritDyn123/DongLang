#include "font/DongLangType.h"
#include "font/ast/DongLangBaseAST.h"

 DongLangTypeInfo* DongLangTypeInfo::IntType = new DongLangTypeInfo("int");
 DongLangTypeInfo* DongLangTypeInfo::ConstIntType = new DongLangTypeInfo("int", {}, true);
 DongLangTypeInfo* DongLangTypeInfo::ByteType = new DongLangTypeInfo("byte");
 DongLangTypeInfo* DongLangTypeInfo::BoolType = new DongLangTypeInfo("bool");
 DongLangTypeInfo* DongLangTypeInfo::FloatType = new DongLangTypeInfo("float");
 DongLangTypeInfo* DongLangTypeInfo::ConstFloatType = new DongLangTypeInfo("float", {}, true);
 DongLangTypeInfo* DongLangTypeInfo::BitType = new DongLangTypeInfo("bit");
 DongLangTypeInfo* DongLangTypeInfo::StringType = new DongLangTypeInfo("string");

string DongLangTypeInfo::String() {
	string dd = primary_type;
	for (auto i = pas.begin(); i != pas.end(); ++i) {
		if (i->pointOrArr) {
			dd += "*";
		}
		else {
			dd += "[";
			dd += to_string(i->array_len);
			dd += "]";
		}
	}

	return dd;
}

Type* DongLangTypeInfo::LlvmType(IRBuilder<>* llvmBuilder) {
	auto& lBd = *llvmBuilder;
	auto& lCt = lBd.getContext();

	llvm::Type* lType = NULL;
	size = 0;
	if (primary_type == "int") {
		lType = lBd.getInt64Ty();
		size = 8;
	}
	else if (primary_type == "string") {
		lType = lBd.getInt8PtrTy();
		size = 8;
	}
	else if (primary_type == "float") {
		lType = lBd.getDoubleTy();
		size = 8;
	}

	else if (primary_type == "bool") {
		lType = lBd.getInt8Ty();
		size = 1;
	}
	else if (primary_type == "void") {
		lType = lBd.getVoidTy();
		size = 0;
	}
	else if (primary_type == "byte") {
		lType = lBd.getInt8Ty();
		size = 1;
	}
	else if (primary_type == "bit") {
		lType = lBd.getInt1Ty();
		size = 1;
	}
	else {
		//throw "invalid type:" + sType;
		lCt.emitError("invalid type:" + String());
		return NULL;
	}

	for (auto it = pas.begin(); it != pas.end(); ++it) {
		if (it->pointOrArr) {
			lType = lType->getPointerTo();
			size = 8;
		}
		else {
			lType = ArrayType::get(lType, it->array_len);
			size = size * it->array_len;
		}
	}

	// cout << "llvm_type(" << String() << "):" << lType->getTypeID() << endl;
	return lType;
}

bool DongLangTypeInfo::needInitial() {
	if (pas.size() == 0) {
		return false;
	}

	auto& pa = pas[pas.size() - 1];
	return !pa.pointOrArr && pa.array_len < 0;;
}


void DongLangTypeInfo::AddPointArrayItem(PointOrArray pa) {
	pas.push_back(pa);
	//pas.insert(pas.begin(), pa);
}

bool DongLangTypeInfo::DelPointArrayItem(PointOrArray pa) {
	if (pas.size() > 0) {
		pas.pop_back();
		return true;
	}

	return false;
}

PointOrArray* DongLangTypeInfo::getArrayPA(uint offset) {
	for (int i = pas.size() - 1; i >= 0; i--, offset--) {
		PointOrArray& pa = pas[i];
		if (pa.pointOrArr) {
			break;
		}

		if (offset == 0) {
			return &pa;
		}
	}

	return  NULL;
}


DIType* DongLangTypeInfo::getDebugType() {
	DIType* diType = NULL;
	int size = 0;
	unsigned encoding = 0;
	if (primary_type == "int") {
		size = 64;
		encoding = dwarf::DW_ATE_signed;
	}
	else if (primary_type == "string") {
		diType = lDB.createStringType(primary_type, 8);
	}
	else if (primary_type == "float") {
		size = 64;
		encoding = dwarf::DW_ATE_float;
	}
	else if (primary_type == "bool") {
		size = 8;
		encoding = dwarf::DW_ATE_boolean;
	}
	else if (primary_type == "void") {
		return NULL;
	}
	else if (primary_type == "byte") {
		size = 8;
		encoding = dwarf::DW_ATE_signed_char;
	}
	else if (primary_type == "bit") {
		size = 1;
		encoding = dwarf::DW_ATE_signed;
	}
	else {
		return NULL;
	}

	if (!diType) {
		diType = lDB.createBasicType(primary_type, size, encoding);
	}

	for (auto it = pas.begin(); it != pas.end(); ++it) {
		if (it->pointOrArr) {
			diType = lDB.createPointerType(diType, 64);
		}
		else {
			diType = lDB.createArrayType(it->array_len, 0, diType);
		}
	}

	return diType;
}

bool DongLangTypeInfo::arrToPtr(DongLangTypeInfo* typeInfo) {
	if (typeInfo->isArray()) {
		typeInfo->pas[typeInfo->pas.size() - 1].pointOrArr = true;
		return true;
	}

	return false;
}

bool DongLangTypeInfo::checkArrayOpr(string& opr) {
	return opr == "call"		||
		   opr == "ret"			||
		   opr == "three_op"	||
		   opr == "ptr_arr"		||
		   opr == "cond";
}

DongLangTypeInfo* DongLangTypeInfo::typeCheckTrans(DongLangTypeInfo* t1, DongLangTypeInfo* t2, string opr, bool errReport, string reportStr) {
	if (!t1 || !t2) {
		return NULL;
	}

	auto transT = t1;
	auto t1S = t1->String();
	auto t2S = t2->String();
	if (t1S == t2S) {
		if (t1->isArray()) {
			if (checkArrayOpr(opr)) {
				return transT;
			}
		}
		else {
			return transT;
		}
	}
	else {
		/* 赋值情况下可以给bool */
		if (t1S == "bool" || t1S == "bit") {
			if (opr == "=") {
				return transT;
			}
		}
		else if (t1->isPoint() ) {
			if (t2S == "int" && (
				t2->constant && (opr == "=" || opr == "==" || opr == "!=") ||
				opr == "+" ||
				opr == "-")) {
				return transT;
			}
			else if (t2->isArray()) { // 指针和数组
				auto tmpT2 = *t2; // copy to use
				arrToPtr(&tmpT2);
				if (t1S == tmpT2.String()) {
					return transT;
				}
			}
		}
		else if (t1->isArray()) {
			if (checkArrayOpr(opr)) {
				if (t2->isPoint()) { // 数组和指针
					auto tmpT1 = *t1; // copy to use
					arrToPtr(&tmpT1);
					if (t2S == tmpT1.String()) {
						return t2;
					}
				}
				else if (t2->isArray()) { // 数组和数组
					auto tmpT1 = *t1; // copy to use
					auto tmpT2 = *t2; // copy to use
					tmpT1.DelPointArrayItem(PointOrArray(false));
					tmpT2.DelPointArrayItem(PointOrArray(false));
					if (tmpT1.String() == tmpT2.String()) {
						return transT;
					}
				}
			}
		}
		else {
			/* byte float 和int 可以相互转换 */
			int checkCnt = 2;
			static vector<string> canTransValue = { "bit", "byte", "int", "float" };
			int maxIndex = -1;
			for (auto tS : map<string, DongLangTypeInfo*>{ {t1S,t1}, {t2S,t2 } }) {
				int i = 0;
				for (auto canS : canTransValue) {
					if (tS.first == canS) {
						if (maxIndex < i) {
							transT = tS.second;
							maxIndex = i;
						}
						checkCnt--;
						break;
					}
					i++;
				}
			}

			if (checkCnt == 0) {
				return transT;
			}
		}
	}

	if (errReport) {
		DongLangBaseAST::llvmCtx->emitError(reportStr + " opr='" + opr + "' type trans error:" + 
			t2S + "(constant:" + (t2->constant ? "true" : "false") + ")=>" + t1S);
	}

	return NULL;
}

