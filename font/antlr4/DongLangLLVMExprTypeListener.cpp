#include "DongLangLLVMExprTypeListener.h"
#include "DongLangLLVMVarListener.h"
#include "DongLangLLVMListener.h"
#include "font/ast/DongLangExprAST.h"
#include "font/ast/DongLangExprAST.h"
#include "font/ast/DongLangExpressionAST.h"
#include "font/ast/DongLangProgAST.h"
#include "font/ast/DongLangFunctionDefAST.h"
#include "font/ast/DongLangVarAST.h"
#include "font/ast/DongLangPrimaryAST.h"
#include <memory>


using namespace std;

#define COPY_SP_TYPE_INFO(ptr) new DongLangTypeInfo(*ptr)

//=========================DongLangLLVMExprTypeListener==============================
DongLangLLVMExprTypeListener::DongLangLLVMExprTypeListener() {
	mExprTypes.clear();
	mDefaultExprTypes.clear();
	mIdPrimaryTypes.clear();
	mVarArrValueTypes.clear();
	mAssignTypes.clear();
	mCallFuncSymbol.clear();
}


DongLangTypeInfo* DongLangLLVMExprTypeListener::ExprType(DongLangParser::ExpressionContext* ctx, bool hasDefault) {
	auto it = mExprTypes.find(ctx);
	if (it != mExprTypes.end()) {
		return it->second;
	}

	return hasDefault ? ExprDefaultType(ctx) : NULL;
}

DongLangTypeInfo* DongLangLLVMExprTypeListener::ExprDefaultType(DongLangParser::ExpressionContext* ctx) {
	auto it = mDefaultExprTypes.find(ctx);
	if (it != mDefaultExprTypes.end()) {
		return it->second;
	}

	return NULL;
}

DongLangTypeInfo* DongLangLLVMExprTypeListener::IdPrimaryType(DongLangParser::Id_primaryContext* ctx) {
	auto it = mIdPrimaryTypes.find(ctx);
	if (it != mIdPrimaryTypes.end()) {
		return it->second;
	}

	return NULL;
}

DongLangTypeInfo* DongLangLLVMExprTypeListener::VarArrValueType(DongLangParser::Var_arr_valueContext* ctx) {
	auto it = mVarArrValueTypes.find(ctx);
	if (it != mVarArrValueTypes.end()) {
		return it->second;
	}

	return NULL;
}

DongLangTypeInfo* DongLangLLVMExprTypeListener::AssignType(DongLangParser::AssignContext* ctx) {
	auto it = mAssignTypes.find(ctx);
	if (it != mAssignTypes.end()) {
		return it->second;
	}

	return NULL;
}

DongLangTypeInfo* DongLangLLVMExprTypeListener::VarExprTypes(DongLangParser::Var_expressionContext* ctx) {
	auto it = mVarExprTypes.find(ctx);
	if (it != mVarExprTypes.end()) {
		return it->second;
	}
	return NULL;
}

FuncSLSymbol* DongLangLLVMExprTypeListener::CallFuncSLSymbol(antlr4::ParserRuleContext* callCtx) {
	auto it = mCallFuncSymbol.find(callCtx);
	if (it != mCallFuncSymbol.end()) {
		return it->second;
	}

	return NULL;
}

void DongLangLLVMExprTypeListener::enterVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) {
	//cout << "enterVar_arr_value:" << ctx->getText() << endl;
	//var_arr_value->var_arr_value, var
	for (auto pCtx = ctx->parent; pCtx; pCtx = pCtx->parent) {
		//call 函数类型涉及重载需要特殊处理
		if (auto tCtx = dynamic_cast<DongLangParser::Var_arr_valueContext*>(pCtx)) {
			auto cTypeInfo = COPY_SP_TYPE_INFO(mVarArrValueTypes[tCtx]); //传递给child节点
			int lastIndex = (int)cTypeInfo->pas.size() - 1;
			if (lastIndex <= 0 || cTypeInfo->pas[lastIndex].pointOrArr) {
				DongLangBaseAST::llvmCtx->emitError("array value deepth: " + cTypeInfo->String() + " ,err:" + ctx->getText());
				return;
			}

			cTypeInfo->DelPointArrayItem(PointOrArray(false));
			mVarArrValueTypes[ctx] = cTypeInfo;
			break;
		}


		//var
		if (auto tCtx = dynamic_cast<DongLangParser::VarContext*>(pCtx)) {
			auto varSymbol = DongLangBaseAST::FindSymbol(tCtx, tCtx->IDENTIFIER()->getText());
			mVarArrValueTypes[ctx] = COPY_SP_TYPE_INFO(varSymbol->getVarType());
			break;
		}
	}

	//cout << "===typeInfo:" << mVarArrValueTypes[ctx]->String() << endl;
	if (ctx->expr_list()) {
		auto cTypeInfo = COPY_SP_TYPE_INFO(mVarArrValueTypes[ctx]); //传递给child节点
		int lastIndex = (int)cTypeInfo->pas.size() - 1;
		if (lastIndex < 0 || cTypeInfo->pas[lastIndex].pointOrArr) {
			DongLangBaseAST::llvmCtx->emitError("array value element expr: " + cTypeInfo->String() + " ,err:" + ctx->getText());
			return;
		}
		cTypeInfo->DelPointArrayItem(PointOrArray(false));
		for (auto expr : ctx->expr_list()->expression()) {
			mExprTypes[expr] = cTypeInfo; //最底层传递给expression
		}
	}
}

void DongLangLLVMExprTypeListener::exitVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) {
	vector< DongLangParser::Var_arr_valueContext*> arrCtxs;
	arrCtxs.clear();
	if (ctx->expr_list()) {
		arrCtxs.push_back(ctx);
	}
	else {
		arrCtxs = ctx->var_arr_value();
	}
	
	int maxArrLen = 0;
	//修正或者填充数组长度
	for (auto arrCtx : arrCtxs) {
		int arrayLen = 0;
		if (arrCtx->expr_list()) {
			arrayLen = arrCtx->expr_list()->expression().size();
		}
		else {
			arrayLen = arrCtx->var_arr_value().size();
		}

		if (maxArrLen < arrayLen) {
			maxArrLen = arrayLen;
		}
	}

	for (auto arrCtx : arrCtxs) {
		auto typeInfo = mVarArrValueTypes[arrCtx];
		auto paInfo = typeInfo->getArrayPA();
		if ( maxArrLen > paInfo->array_len) {
			paInfo->array_len = maxArrLen;
		}

		if (auto pCtx = dynamic_cast<DongLangParser::Var_arr_valueContext*>(arrCtx->parent)) {
			auto pTypeInfo = mVarArrValueTypes[pCtx];
			auto pPaInfo = pTypeInfo->getArrayPA(1);
			if (maxArrLen > pPaInfo->array_len) {
				pPaInfo->array_len = maxArrLen;
			}
		}
	}

	//重写定义的id typeInfo
	auto& arrCtx = arrCtxs[0];
	auto typeInfo = mVarArrValueTypes[ctx];
	if (ctx->var_arr_value().size()) {
		int arrayLen = ctx->var_arr_value().size();
		auto typeInfo = mVarArrValueTypes[ctx];
		auto paInfo = typeInfo->getArrayPA();
		if (arrayLen > paInfo->array_len) {
			paInfo->array_len = arrayLen;
		}
	}

	if (auto tCtx = dynamic_cast<DongLangParser::Var_arr_valueContext*>(ctx->parent)) {
		return;
	}
	
	auto pCtx = ctx->parent->parent;
	//var
	if (auto tCtx = dynamic_cast<DongLangParser::VarContext*>(pCtx)) {
		auto varSymbol = DongLangBaseAST::FindSymbol(tCtx, tCtx->IDENTIFIER()->getText());
		*varSymbol->getVarType() = *typeInfo;

	}
}


void DongLangLLVMExprTypeListener::enterExpression(DongLangParser::ExpressionContext* ctx) {
	//统计类型，自上而下
	for (auto pCtx = ctx->parent; pCtx; pCtx = pCtx->parent) {
		if (dynamic_cast<DongLangParser::StatementContext*>(pCtx)) {
			break;
		}

		//call 函数类型涉及重载需要特殊处理
		if (auto tCtx = dynamic_cast<DongLangParser::Call_exprContext*>(pCtx)) {
			break;
		}

		//数组在var_arr_value rule里处理了
		if (auto tCtx = dynamic_cast<DongLangParser::Var_arr_valueContext*>(pCtx)) {
			break;
		}

		if (auto tCtx = dynamic_cast<DongLangParser::ExpressionContext*>(pCtx)) {
			auto typeInfo = ExprType(tCtx);
			/*
				cout << "enterExpression ExpressionContext:" << ctx->getText() << "__" << ctx
				<< ",parent:" << tCtx->getText() << "__" << tCtx << "_" << tCtx->expression().size()
				<< ",parent_typeInfo:"<< (typeInfo ? typeInfo->String() : "NULL")
				<< endl;
				*/
			if (typeInfo) { //某些路径的expression需要特殊处理 1、callfun(expr) 2、assign=expr
				if (tCtx->expression().size() <= 1) {
					mExprTypes[ctx] = typeInfo; //传递给child节点
				}
				else if (tCtx->COND_AND() || tCtx->COND_OR()) {
					mExprTypes[ctx] = typeInfo; //传递给child节点
				}
			}
			break;
		}

		//return expr;
		if (auto tCtx = dynamic_cast<DongLangParser::Ret_expressionContext*>(pCtx)) {
			//找到归属的function
			for (auto ptCtx = tCtx->parent; ptCtx != NULL; ptCtx = ptCtx->parent) {
				if (auto funcCtx = dynamic_cast<DongLangParser::Function_defContext*>(ptCtx)) {
					auto funcVar = DongLangBaseAST::FindSymbol(funcCtx, SYMBOL_ID(funcCtx));
					mExprTypes[ctx] = COPY_SP_TYPE_INFO(funcVar->getVarType());
					break;
				}
			}

			break;
		}

		//arr[expr]
		if (auto tCtx = dynamic_cast<DongLangParser::Array_indexContext*>(pCtx)) {
			mExprTypes[ctx] = DongLangTypeInfo::IntType;
			break;
		}

		//var=expr;
		if (auto tCtx = dynamic_cast<DongLangParser::VarContext*>(pCtx)) {
			auto var = DongLangBaseAST::FindSymbol(tCtx, tCtx->IDENTIFIER()->getText());
			if (!var) {
				DongLangBaseAST::llvmCtx->emitError("undefined var:" + tCtx->IDENTIFIER()->getText());
				return;
			}

			mExprTypes[ctx] = COPY_SP_TYPE_INFO(var->getVarType());
			break;
		}

		//int var=expr;
		if (auto tCtx = dynamic_cast<DongLangParser::Var_declaresContext*>(pCtx)) {

			auto var = DongLangBaseAST::FindSymbol(tCtx, tCtx->vars()->var(0)->getText());
			if (!var) {
				DongLangBaseAST::llvmCtx->emitError("undefined var:" + tCtx->vars()->var(0)->getText());
				return;
			}

			break;
		}

		//assign *arr[5] (+-*/)?= xxx
		if (auto tCtx = dynamic_cast<DongLangParser::AssignContext*>(pCtx)) {
			if (tCtx->expression() == pCtx) {
				break;
			}

			//tCtx->id_primary()里也包含expression
		}

		// if cond
		if (auto tCtx = dynamic_cast<DongLangParser::If_condContext*>(pCtx)) {
			mExprTypes[ctx] = DongLangTypeInfo::BitType;
			break;
		}

		//for cond
		if (auto tCtx = dynamic_cast<DongLangParser::For_condContext*>(pCtx)) {
			mExprTypes[ctx] = DongLangTypeInfo::BitType;
			break;
		}
	}
}


void DongLangLLVMExprTypeListener::exitExpression(DongLangParser::ExpressionContext* ctx) {
	/**
	  * 自下而上的修正类型
	  * paren_expr, expr opr expr
	  */

	if (dynamic_cast<DongLangParser::AssignContext*>(ctx->parent)) { //assign exit
		return;
	}

	if (ctx->expression().size() <= 1) {
		if (ctx->COND_NOT()) {
			mDefaultExprTypes[ctx] = DongLangTypeInfo::BoolType;
		}
		else if (ctx->NOT()) {
			mDefaultExprTypes[ctx] = COPY_SP_TYPE_INFO(mDefaultExprTypes[ctx->expression(0)]);
		}
	}
	else {
		auto typeL = mDefaultExprTypes[ctx->expression(0)];
		auto typeR = mDefaultExprTypes[ctx->expression(1)];
		string expOpr = ctx->opr->getText();

		DongLangTypeInfo* transTypeInfo = NULL;
		if (ctx->COND_AND() || ctx->COND_OR()) {
			auto exprTypeInfo = ExprType(ctx);
			if (exprTypeInfo) { // if or for
				transTypeInfo = COPY_SP_TYPE_INFO(exprTypeInfo);
			}
			else {
				transTypeInfo = DongLangTypeInfo::BoolType;
			}
		}
		else {
			transTypeInfo = SLSymbol::typeCheckTrans(typeL, typeR, expOpr, true, ctx->getText());
			if (!transTypeInfo) {
				return;
			}

			transTypeInfo = COPY_SP_TYPE_INFO(transTypeInfo);
			if (typeL->String() != typeR->String()) {
				auto cmpIndex = typeL->String() == transTypeInfo->String() ? 1 : 0;
				auto cmpExprCtx = ctx->expression(cmpIndex);
				if (transTypeInfo->isPoint()) { //指针
					if (ctx->CMP_EQ() || ctx->CMP_NE()) { // == !=
						if (cmpExprCtx->getText() != "0") {
							lC.emitError(ctx->getText() + " point must use int NULL(0) value");
						}
						else {
							mExprTypes[cmpExprCtx] = COPY_SP_TYPE_INFO(transTypeInfo);
						}
					}
				}
				else {
					mExprTypes[cmpExprCtx] = COPY_SP_TYPE_INFO(transTypeInfo);
				}
			}

			if (ctx->CMP_EQ() || ctx->CMP_NE() || ctx->CMP_GT() || ctx->CMP_GE() || ctx->CMP_LT() || ctx->CMP_LE()) {
				delete transTypeInfo;
				auto exprTypeInfo = ExprType(ctx);
				if (exprTypeInfo->String() == "bit") { // if or for
					transTypeInfo = DongLangTypeInfo::BoolType;
				}
				else {
					transTypeInfo = DongLangTypeInfo::BitType;
				}
			}
		}

		mDefaultExprTypes[ctx] = transTypeInfo;

		/*cout << "exitexpression:" << ctx->getText() << ",defaulTypeInfo:" << mDefaultExprTypes[ctx]->String()
			<< ",typeInfo:" << (mExprTypes[ctx] ? mExprTypes[ctx]->String() : "NULL")
			<< endl;*/
	}

	//位运算解析
	if (ctx->POINTADDR() || ctx->OR() || ctx->XOR() || ctx->NOT()) {
		auto typeL = mDefaultExprTypes[ctx->expression(0)];
		DongLangTypeInfo* typeR = ctx->expression().size() > 1 ? mDefaultExprTypes[ctx->expression(1)] : NULL;
		for (auto ti : { typeL, typeR }) {
			if (!ti) {
				continue;
			}

			auto sti = ti->String();
			if (sti != "int" && sti != "byte" && sti != "bool") {
				lC.emitError(ctx->getText() + " byte param type err:" + sti);
			}
		}
	}

	//检查类型冲突
	auto typeInfo = ExprType(ctx);
	auto defaultTypeInfo = ExprDefaultType(ctx);
	/*cout << ctx->getText() << ",typeInfo:" << (typeInfo ? typeInfo->String() : "null") << 
		",defaultTypeInfo:" <<  (defaultTypeInfo ? defaultTypeInfo->String() : "null") << 
		endl;*/
	if (!typeInfo) {
		mExprTypes[ctx] = COPY_SP_TYPE_INFO(defaultTypeInfo);
		typeInfo = mExprTypes[ctx];
	}

	if (SLSymbol::typeCheckTrans(typeInfo, defaultTypeInfo, "=", true, ctx->getText())) {
		if (typeInfo->isPoint() && defaultTypeInfo->String() == "int" && ctx->getText() != "0") {
			lC.emitError(ctx->parent->getText() + " point must use int NULL(0) value");
		}
	}
}

void DongLangLLVMExprTypeListener::enterAssign(DongLangParser::AssignContext* ctx) {
	//统计类型，自上而下
	for (auto pCtx = ctx->parent; pCtx; pCtx = pCtx->parent) {
		if (dynamic_cast<DongLangParser::StatementContext*>(pCtx)) {
			break;
		}

		if (dynamic_cast<DongLangParser::If_condContext*>(pCtx)) {
			mAssignTypes[ctx] = DongLangTypeInfo::BitType;
			break;
		}

		if (dynamic_cast<DongLangParser::For_condContext*>(pCtx)) {
			mAssignTypes[ctx] = DongLangTypeInfo::BitType;
			break;
		}
	}
}

void DongLangLLVMExprTypeListener::exitAssign(DongLangParser::AssignContext* ctx) {
	if (!ctx->expression()) {
		if (ctx->INCREMENT() || ctx->DECREMENT()) {
			SLSymbol::typeCheckTrans(mAssignTypes[ctx], DongLangTypeInfo::IntType, ctx->INCREMENT() ? "+" : "-", true, ctx->getText());
		}

		return;
	}

	auto typeL = mAssignTypes[ctx];
	auto exprCtx = ctx->expression();
	auto typeR = mDefaultExprTypes[exprCtx];

	if (!ctx->opr) {
		mExprTypes[exprCtx] = COPY_SP_TYPE_INFO(typeL);
	}
	else { //带运算符
		//类型检查
		string expOpr = ctx->opr->getText();
		DongLangTypeInfo* transTypeInfo = SLSymbol::typeCheckTrans(typeL, typeR, expOpr, true, ctx->getText());
		if (!transTypeInfo) {
			return;
		}


		if (!transTypeInfo->isPoint() && typeR->String() != transTypeInfo->String()) { //指针
			mExprTypes[exprCtx] = COPY_SP_TYPE_INFO(transTypeInfo);
		}
	}

	//位运算解析
	if (ctx->POINTADDR() || ctx->OR() || ctx->XOR()) {
		for (auto ti : { typeL, typeR }) {
			if (!ti) {
				continue;
			}

			auto sti = ti->String();
			if (sti != "int" && sti != "byte" && sti != "bool") {
				lC.emitError(ctx->getText() + " byte param type err:" + sti);
			}
		}
	}
	

	//检查类型冲突
	auto typeInfo = mExprTypes[exprCtx];
	auto defaultTypeInfo = typeR;

	if (!typeInfo) {
		mExprTypes[exprCtx] = COPY_SP_TYPE_INFO(defaultTypeInfo);
		typeInfo = mExprTypes[exprCtx];
	}

	if (SLSymbol::typeCheckTrans(typeInfo, defaultTypeInfo, "=", true, ctx->getText())) {
		if (typeInfo->isPoint() && defaultTypeInfo->String() == "int" && ctx->getText() != "0") {
			lC.emitError(ctx->parent->getText() + " point must use int NULL(0) value");
		}
	}
}

void DongLangLLVMExprTypeListener::exitVar_expression(DongLangParser::Var_expressionContext* ctx) {
	//获取默认类型
	DongLangTypeInfo* defaultTypeInfo = NULL;
	if (auto varsCtx = ctx->vars()) {
		defaultTypeInfo = DongLangBaseAST::FindSymbol(varsCtx, varsCtx->var(0)->IDENTIFIER()->getText())->getVarType();
	}
	else if(auto varsDecCtx = ctx->var_declares())  {
		defaultTypeInfo = DongLangBaseAST::FindSymbol(varsDecCtx, varsDecCtx->vars()->var(0)->IDENTIFIER()->getText())->getVarType();
	}
	else {
		auto assignsCtx = ctx->assigns();
		defaultTypeInfo = AssignType(assignsCtx->assign(0));
	}

	//检查在if for里
	auto pCtx = ctx->parent;
	if (auto forCondCtx = dynamic_cast<DongLangParser::For_condContext*>(pCtx)) {
		if (forCondCtx->expression()) {
			return;
		}
	} else if (auto ifCondCtx = dynamic_cast<DongLangParser::If_condContext*>(pCtx)) {
		if (ifCondCtx->expression()) {
			return;
		}

		//检查一下如果是数组，必须包含expression
		if (defaultTypeInfo->isArray()) {
			lC.emitError("if cond var array must has cond expression:" + ctx->getText());
			return;
		}
	}
	else {
		return;
	}

	DongLangTypeInfo* typeInfo = DongLangTypeInfo::BitType;
	if (SLSymbol::typeCheckTrans(typeInfo, defaultTypeInfo, "=", true, ctx->getText())) {
		if (typeInfo->isPoint() && defaultTypeInfo->String() == "int" && ctx->getText() != "0") {
			lC.emitError(pCtx->getText() + "var expression type err");
		}
	}

	mVarExprTypes[ctx] = typeInfo;
}



void DongLangLLVMExprTypeListener::enterPrimary(DongLangParser::PrimaryContext* ctx) {}
void DongLangLLVMExprTypeListener::exitPrimary(DongLangParser::PrimaryContext* ctx) {
	
}

void DongLangLLVMExprTypeListener::enterId_primary(DongLangParser::Id_primaryContext* ctx) {}
void DongLangLLVMExprTypeListener::exitId_primary(DongLangParser::Id_primaryContext* ctx) {
	DongLangTypeInfo* idTypeInfo = NULL;
	//var ID
	string id = "";
	if (ctx->IDENTIFIER()) {
		id = ctx->IDENTIFIER()->getText();
		auto symbol = DongLangBaseAST::FindSymbol(ctx, id);
		if (!symbol) {
			DongLangBaseAST::llvmCtx->emitError("undefined var:" + id);
			return;
		}
		
		mIdPrimaryTypes[ctx] = COPY_SP_TYPE_INFO(symbol->getVarType());
	}

	idTypeInfo = mIdPrimaryTypes[ctx];

	//cout << "id_primary:" << ctx->getText() << ",call:" << ctx->call_expr() << endl;
	idTypeInfo = COPY_SP_TYPE_INFO(idTypeInfo);


	for (auto child : ctx->children) {
		if (auto arrIndexCtx = dynamic_cast<DongLangParser::Array_indexContext*>(child)) {
			if (!idTypeInfo->DelPointArrayItem(PointOrArray(false))) {
				DongLangBaseAST::llvmCtx->emitError("primary:" + ctx->getText() + " type opr error");
				return;
			}
		}
	}

	for(auto child : ctx->id_primary_p_addrs()->children) {
		auto pointS = child->getText();
		if (pointS == "*") {
			if (!idTypeInfo->DelPointArrayItem(PointOrArray(true))) {
				DongLangBaseAST::llvmCtx->emitError("primary:" + ctx->getText() + " type opr error");
				return;
			}
		}
		else {
			if (idTypeInfo->isArray()) {
				DongLangBaseAST::llvmCtx->emitError("primary:" + ctx->getText() + " array cannot opr point");
				return;
			}
			idTypeInfo->AddPointArrayItem(PointOrArray(true));
		}
	}

	if (auto assignCtx = dynamic_cast<DongLangParser::AssignContext*>(ctx->parent)) {//->assign
		mAssignTypes[assignCtx] = idTypeInfo;
	}
	else { //primary->expression
		auto exprCtx = (DongLangParser::ExpressionContext*)ctx->parent->parent;
		mDefaultExprTypes[exprCtx] = idTypeInfo;
	}
}

void DongLangLLVMExprTypeListener::enterValue_primary(DongLangParser::Value_primaryContext* ctx) { }

void DongLangLLVMExprTypeListener::exitValue_primary(DongLangParser::Value_primaryContext* ctx) {
	auto pCtx = ctx->parent->parent; //->priamry->expression
	auto exprCtx = (DongLangParser::ExpressionContext*)pCtx;
	string primaryType;
	if (ctx->num_primary()) {
		primaryType = "int";
		if (ctx->num_primary()->getText().find(".") != string::npos) {
			primaryType = "float";
		}
	}

	if (ctx->bool_primary()) {
		primaryType = "bool";
	}

	if (ctx->str_primary()) {
		primaryType = "string";
	}

	mDefaultExprTypes[exprCtx] = new DongLangTypeInfo(primaryType, {}, true);
}

void DongLangLLVMExprTypeListener::enterParan_expr(DongLangParser::Paran_exprContext* ctx) {}
void DongLangLLVMExprTypeListener::exitParan_expr(DongLangParser::Paran_exprContext* ctx) {
	auto paranTypeInfo = mDefaultExprTypes[ctx->expression()];
	auto pCtx = dynamic_cast<DongLangParser::Id_primaryContext*>(ctx->parent);
	mIdPrimaryTypes[pCtx] = paranTypeInfo;
}

void DongLangLLVMExprTypeListener::enterCall_expr(DongLangParser::Call_exprContext* ctx) {}
void DongLangLLVMExprTypeListener::exitCall_expr(DongLangParser::Call_exprContext* ctx) {
	//做参数映射
	string fnName(ctx->IDENTIFIER()->getText());
	auto funcList = DongLangBaseAST::FindFuncSymbolList(ctx, fnName);
	if (funcList == NULL || funcList->size() == 0) {
		DongLangBaseAST::llvmCtx->emitError("call undefined function:" + fnName);
		return;
	}

	vector<DongLangParser::ExpressionContext*> exprCtxList;
	exprCtxList.clear();
	if (ctx->expr_list()) {
		exprCtxList = ctx->expr_list()->expression();
	}

	int argCount = exprCtxList.size();

	//int float可以转换
	map<FuncSLSymbol*, int> dstFuncs;
	dstFuncs.clear();
	int maxEValue = 0;
	const static int mStandEV = 100; //默认一个函数的参数不会超过这么多
	for (auto func : *funcList) {
		//argCount
		auto argTypes = func->argType();
		if (argCount < argTypes.size()) {
			continue;
		}

		if (!func->varArg()) {
			if (argCount != argTypes.size()) {
				continue;
			}
		}

		//检查参数
		auto ti = 0;
		int matchEValue = 0;
		for (auto argT : argTypes) {
			auto expectT = mDefaultExprTypes[(exprCtxList[ti])];
			auto expectTStr = expectT->String(false);
			auto argTStr = argT->String(false);
			if (expectTStr != argTStr) {
				if (SLSymbol::typeCheckTrans(argT, expectT, "=")) {
					matchEValue += (mStandEV-ti-1); //按照位置修正-1
				}
				else {
					matchEValue = -1; //参数对不上直接清零
					break;
				}
			}
			else {
				matchEValue += mStandEV;
			}

			ti++;
		}

		if (matchEValue < 0) {
			continue;
		}

		//var arg
		if (func->varArg()) {
			for (; ti < argCount; ti++) {
				matchEValue += (mStandEV-ti-2); //按照位置修正-2
			}	
		}

		if (maxEValue < matchEValue) {
			maxEValue = matchEValue;
		}
		dstFuncs[func] = matchEValue;
	}

	//1、参数不对函数
	if (dstFuncs.size() == 0) {
		DongLangBaseAST::llvmCtx->emitError("call param error function:" + fnName);
		return;
	}

	//2、函数有歧义
	FuncSLSymbol* callFunc = NULL;
	for (auto it = dstFuncs.begin(); it != dstFuncs.end();++it) {
		if (maxEValue == it->second) {
			if (callFunc) {
				DongLangBaseAST::llvmCtx->emitError("call ambiguity function:" + fnName);
				return;
			}

			callFunc = it->first;
		}
	}

	int ti = 0;
	for (auto argT : callFunc->argType()) {
		mExprTypes[exprCtxList[ti++]] = COPY_SP_TYPE_INFO(argT);
	}

	//varArg 就直接default?
	for (; ti < argCount; ti++) {
		auto exprCtx = exprCtxList[ti];
		mExprTypes[exprCtx] = COPY_SP_TYPE_INFO(mDefaultExprTypes[exprCtx]);
	}

	mCallFuncSymbol[ctx] = callFunc;

	//call_expr
	auto pCtx = dynamic_cast<DongLangParser::Id_primaryContext*>(ctx->parent);
	mIdPrimaryTypes[pCtx] = COPY_SP_TYPE_INFO(callFunc->getVarType());

}

void DongLangLLVMExprTypeListener::enterArray_type(DongLangParser::Array_typeContext* ctx) {
	for (auto pCtx = ctx->parent; pCtx; pCtx = pCtx->parent) {
		if (dynamic_cast<DongLangParser::Type_type_voidContext*>(pCtx) ||
			dynamic_cast<DongLangParser::FargContext*>(pCtx)) {
			int arrLen = 0;
			if (!ctx->NUMBER() || (arrLen = stoi(ctx->NUMBER()->getText())) <= 0) {
				DongLangBaseAST::llvmCtx->emitError("function's return or arg  array must has correct length:" + ctx->getText());
				return;
			}

			break;
		}
	}
}

void DongLangLLVMExprTypeListener::exitRet_expression(DongLangParser::Ret_expressionContext* ctx) {
	if (ctx->expression()) {
		return;
	}

	//void空返回校验
	
	//找到归属的function
	for (auto ptCtx = ctx->parent; ptCtx != NULL; ptCtx = ptCtx->parent) {
		if (auto funcCtx = dynamic_cast<DongLangParser::Function_defContext*>(ptCtx)) {
			auto funcVar = (FuncSLSymbol *)DongLangBaseAST::FindSymbol(funcCtx, SYMBOL_ID(funcCtx));
			auto typeInfo = funcVar->getVarType();
			if (typeInfo->String() != "void") {
				DongLangBaseAST::llvmCtx->emitError("function's return type is not void:" + funcVar->Name());
				return;
			}

			break;
		}
	}
}