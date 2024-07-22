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

string DongLangTypeInfo::String(bool hasArrayLen) {
	string dd = primary_type;
	for (auto i = pas.begin(); i != pas.end(); ++i) {
		if (i->pointOrArr) {
			dd += "*";
		}
		else {
			dd += "[";
			//if (hasArrayLen){
				//if (i->array_len > 0) {
					dd += to_string(i->array_len);
				//}
			//}
			
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

	for (auto i = pas.begin(); i != pas.end(); ++i) {
		if (i->pointOrArr) {
			lType = lType->getPointerTo();
		}
		else {
			break;
		}
	}

	for (auto i = pas.rbegin(); i != pas.rend(); ++i) {
		if (i->pointOrArr) {
			break;
		}
		else {
			lType = ArrayType::get(lType, i->array_len);
			size = size * i->array_len;
		}
	}

	// cout << "llvm_type(" << String() << "):" << lType->getTypeID() << endl;
	return lType;
}


void DongLangTypeInfo::AddPointArrayItem(PointOrArray pa) {
	if (pa.pointOrArr) {
		pas.insert(pas.begin(), pa);
	}
	else {
		pas.push_back(pa);
	}
}

bool DongLangTypeInfo::DelPointArrayItem(PointOrArray pa) {
	if (pa.pointOrArr) { //point倒序
		for (auto it = pas.rbegin(); it != pas.rend(); ++it) {
			if (it->pointOrArr) {
				pas.erase(pas.begin() + pas.size() - 1 - distance(pas.rbegin(), it));
				return true;
			}
		}
	}
	else {
		for (auto it = pas.begin(); it != pas.end(); ++it) {
			if (!it->pointOrArr) {
				pas.erase(it);
				return true;
			}
		}
	}

	return false;
}
PointOrArray* DongLangTypeInfo::getArrayPA(uint offset) {
	for (auto it = pas.begin(); it != pas.end(); ++it, --offset) {
		if (!it->pointOrArr && offset== 0) {
			return &(*it);
		}
	}

	return  NULL;
}


DongLangTypeInfo* DongLangTypeInfo::typeCheckTrans(DongLangTypeInfo* t1, DongLangTypeInfo* t2, string opr, bool errReport, string reportStr) {
	if (!t1 || !t2) {
		return NULL;
	}

	auto transT = t1;
	auto t1S = t1->String(false);
	auto t2S = t2->String(false);
	if (t1S == t2S) {
		if (opr != "=" || !t1->isArray() && !t2->isArray()) {
			return transT;
		}
	}
	else {
		/* 赋值情况下可以给bool */
		if (t1S == "bool" || t1S == "bit") {
			if (opr == "=" && !t2->isArray()) {
				return transT;
			}
		}
		else if (t1->isPoint()) {
			if (t2S == "int" && (
				t2->constant && (opr == "=" || opr == "==" || opr == "!=") ||
				opr == "+" ||
				opr == "-")) {
				return transT;
			}
		} if (t2->isPoint()) {
			if (t1S == "int" && (
				t1->constant && (opr == "==" || opr == "!="))) {
				transT = t2;
				return transT;
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
		DongLangBaseAST::llvmCtx->emitError(reportStr + " opr=" + opr + " type trans error:" + 
			t2S + "(constant:" + (t2->constant ? "true" : "false") + ")=>" + t1S);
	}

	return NULL;
}

