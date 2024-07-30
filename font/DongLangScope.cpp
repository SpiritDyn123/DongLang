#include "font/DongLangScope.h"

auto STVar = DLSymbol::symbolType_Var;
DongLangScope::DongLangScope(DongLangScope* parent, string name) {
	this->parent = parent;
	this->name = name;
	mSymbols.clear();
	mAllSymbols.clear();
	mFuncList.clear();

	mSymbols[STVar] = MTypeSymbols();
	mSymbols[STVar].clear();
}

bool DongLangScope::checkVar(string id, DLSymbol* symbol) {
	auto& mVarSymbols = mSymbols[STVar];
	if (mVarSymbols.find(id) != mVarSymbols.end()) {
		return true;
	}

	return false;
}

bool DongLangScope::AddSymbol(string baseId, SYMBOL_ID sId, DLSymbol* symbol) {
	//cannot hase var name;
	if (checkVar(baseId, symbol)) {
		return false;
	}

	auto st = symbol->type();
	if (mSymbols.find(st) == mSymbols.end()) {
		mSymbols[st] = MTypeSymbols();
		mSymbols[st].clear();
	}
	
	auto& mTypeSymbols = mSymbols[st];
	if (st != STVar && mTypeSymbols.find(symbol->ID()) != mTypeSymbols.end()) {
		return false;
	}

	//cout << this << " add symbol:" << symbol->ID() <<endl;
	if (symbol->type() == DLSymbol::symbolType_Func) {
		if (mFuncList.find(baseId) == mFuncList.end()) {
			mFuncList[baseId] = FuncList();
			mFuncList[baseId].clear();
		}

		FuncDLSymbol* funcS = (FuncDLSymbol*)symbol;
		//注意externC
		if (!funcS->extC()) {
			for (auto func : mFuncList.find(baseId)->second) {
				if (!func->extC()) {
					continue;
				}

				//externC函数和正常函数 参数冲突
				string fId = FuncDLSymbol::funcID(func->Name(), func->argType(), func->varArg());
				if (fId == symbol->ID()) {
					return false;
				}
			}
		}
		
		mFuncList[baseId].push_back(funcS);
	}

	mTypeSymbols[symbol->ID()] = symbol;
	mAllSymbols[sId] = symbol;
	if (symbol->getScope() == NULL) {
		symbol->setScope(this);
	}

	return true;
}

DLSymbol* DongLangScope::FindSymbol(string id) {
	//cout << this << " find symbol:" << id << endl;
	for (auto its = mSymbols.begin(); its != mSymbols.end(); ++its) {
		auto it = its->second.find(id);
		if (it != its->second.end()) {
			return it->second;
		}
	}

	if (parent == NULL) {
		return NULL;
	}

	return parent->FindSymbol(id);
}

DLSymbol* DongLangScope::FindSymbol(SYMBOL_ID id) {
	auto it = mAllSymbols.find(id);
	if (it != mAllSymbols.end()) {
		return it->second;
	}

	if (parent == NULL) {
		return NULL;
	}

	return parent->FindSymbol(id);
}

FuncDLSymbol* DongLangScope::FindFuncSymbol(string id, 
	vector<DongLangTypeInfo*> argTypes, bool isVarArg) {
	string fId = FuncDLSymbol::funcID(id, argTypes, isVarArg);

	auto funcType = DLSymbol::symbolType_Func;
	if (mSymbols.find(funcType) == mSymbols.end()) {
		if (parent == NULL) {
			return NULL;
		}
		return parent->FindFuncSymbol(id, argTypes, isVarArg);
	}

	auto& mFuncSymbols = mSymbols[funcType];

	//externC模式查找
	auto it = mFuncSymbols.find(id);
	if (it != mFuncSymbols.end()) {
		auto funcS = (FuncDLSymbol*)it->second;
		if (fId == FuncDLSymbol::funcID(funcS->Name(), funcS->argType(), funcS->varArg())) {
			return  funcS;
		}
	}

	//正常模式查找
	it = mFuncSymbols.find(fId);
	if (it != mFuncSymbols.end()) {
		return (FuncDLSymbol*)it->second;
	}

	if (parent == NULL) {
		return NULL;
	}

	return parent->FindFuncSymbol(id, argTypes, isVarArg);
}

vector<FuncDLSymbol*>* DongLangScope::FindFuncSymbolList(string baseId) {
	auto funcList = mFuncList.find(baseId);
	if (funcList != mFuncList.end()) {
		return &(funcList->second);
	}

	if (parent == NULL) {
		return NULL;
	}

	return parent->FindFuncSymbolList(baseId);
}
void DongLangScope::AddForInfo(DongLangScopeForInfo* forInfo) {
	this->forInfo = forInfo;
}

DongLangScopeForInfo* DongLangScope::getForInfo() {
	return forInfo;
}
