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

	vector<PointOrArray> tmpArrPas;
	tmpArrPas.clear();
	for (auto it = pas.begin(); it != pas.end(); ++it) {
		if (it->pointOrArr) {
			if (tmpArrPas.size()) {
				for (auto arrpa : tmpArrPas) {
					lType = ArrayType::get(lType, arrpa.array_len);
					size = size * arrpa.array_len;
				}
				tmpArrPas.clear();
			}

			lType = lType->getPointerTo();
			size = 8;
		}
		else {
			tmpArrPas.insert(tmpArrPas.begin(), *it);	
		}
	}

	for (auto arrpa : tmpArrPas) {
		lType = ArrayType::get(lType, arrpa.array_len);
		size = size * arrpa.array_len;
	}

	// cout << "llvm_type(" << String() << "):" << lType->getTypeID() << endl;
	return lType;
}

bool DongLangTypeInfo::needInitial() {
	if (!isArray()) {
		return false;
	}

	for (int i = pas.size() - 1; i >= 0; i--) {
		if (pas[i].pointOrArr) {
			return pas[i+1].array_len < 0;
		}
	}

	return pas[0].array_len < 0;;
}


void DongLangTypeInfo::AddPointArrayItem(PointOrArray pa) {
	pas.insert(pas.begin(), pa);
}

bool DongLangTypeInfo::DelPointArrayItem(PointOrArray pa) {
	for (int i = pas.size() - 1; i >= 0; i--) {
		PointOrArray& pa = pas[i];
		if (pa.pointOrArr || i == 0) {
			pas.erase(pas.begin() + i);
			return true;
		}
		else {
			if (pas[i - 1].pointOrArr) {
				pas.erase(pas.begin() + i);
				return true;
			}
		}
	}

	return false;
}

PointOrArray* DongLangTypeInfo::getArrayPA(uint offset) {
	if (!isArray()) {
		return NULL;
	}

	vector<PointOrArray*> tmpArrPas;
	tmpArrPas.clear();
	for (int i = pas.size() - 1; i >= 0; i--) {
		PointOrArray& pa = pas[i];
		if (pa.pointOrArr) {
			break;
		}

		tmpArrPas.insert(tmpArrPas.begin(), & pa);
	}

	for (auto it = tmpArrPas.begin(); it != tmpArrPas.end(); ++it, --offset) {
		if (offset== 0) {
			return *it;
		}
	}

	return  NULL;
}

bool DongLangTypeInfo::checkArrayOpr(string& opr) {
	return opr == "call"		||
		   opr == "ret"			||
		   opr == "three_op"	||
		   opr == "ptr_arr"	||
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
				tmpT2.pas[tmpT2.pas.size() - 1].pointOrArr = true;
				if (t1S == tmpT2.String()) {
					return transT;
				}
			}
		}
		else if (t1->isArray()) {
			if (checkArrayOpr(opr)) {
				if (t2->isPoint()) { // 数组和指针
					auto tmpT1 = *t1; // copy to use
					tmpT1.pas[tmpT1.pas.size() - 1].pointOrArr = true;
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

