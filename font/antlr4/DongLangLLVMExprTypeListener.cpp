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
DongLangLLVMExprTypeListener::DongLangLLVMExprTypeListener(int defaultLine):
	DongLangLLVMBaseListener(defaultLine) {
	mExprTypes.clear();
	mDefaultExprTypes.clear();
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

FuncDLSymbol* DongLangLLVMExprTypeListener::CallFuncDLSymbol(antlr4::ParserRuleContext* callCtx) {
	auto it = mCallFuncSymbol.find(callCtx);
	if (it != mCallFuncSymbol.end()) {
		return it->second;
	}

	return NULL;
}

string DongLangLLVMExprTypeListener::getExprOpr(DongLangParser::ExpressionContext* exprCtx) {
	string opr = "=";
	antlr4::ParserRuleContext* lastCtx = exprCtx;
	bool isArr = mDefaultExprTypes[exprCtx]->isArray();
	if (!isArr) {
		return opr;
	}

	for (auto pCtx = exprCtx->parent; pCtx; lastCtx = (antlr4::ParserRuleContext*)pCtx, pCtx = pCtx->parent) {
		if (dynamic_cast<DongLangParser::Paran_exprContext*>(pCtx) || // paran
			dynamic_cast<DongLangParser::PrimaryContext*>(pCtx) ||
			dynamic_cast<DongLangParser::Expr_listContext*>(pCtx) ||
			dynamic_cast<DongLangParser::AssignContext*>(pCtx) ||
			dynamic_cast<DongLangParser::AssignsContext*>(pCtx) ||
			dynamic_cast<DongLangParser::Var_expressionContext*>(pCtx)) { // call
			continue;
		}
		
		if (auto pExprCtx = dynamic_cast<DongLangParser::ExpressionContext*>(pCtx)) {
			if (pExprCtx->opr) {
				opr = (pExprCtx->COND_AND() || pExprCtx->COND_OR()) ? opr : pExprCtx->opr->getText();
			}
			else if (pExprCtx->threeOpr ) {
				if (lastCtx != pExprCtx->expression(0)) {
					opr = "three_op";
				}
			}
			else if(pExprCtx->COND_NOT()) {

			}
			else {
				cout << exprCtx->getText() << "," << pCtx->getText() << endl;
				continue;
			}
		}
		else if (auto pIdPrimayCtx = dynamic_cast<DongLangParser::Id_primaryContext*>(pCtx)) {
			auto ptrAddrCtx = pIdPrimayCtx->id_primary_p_addrs();
			if (ptrAddrCtx->POINT().size() == 0 && ptrAddrCtx->POINTADDR().size() == 0 && pIdPrimayCtx->array_index().size() == 0) {
				continue;
			}
			opr = "ptr_arr";
		}
		else if (dynamic_cast<DongLangParser::Ret_expressionContext*>(pCtx)) {
			opr = "ret";
		}
		else if (dynamic_cast<DongLangParser::Call_exprContext*>(pCtx)) {
			opr = "call";
		} 
		else if (dynamic_cast<DongLangParser::If_condContext*>(pCtx) ||
			dynamic_cast<DongLangParser::For_condContext*>(pCtx)) {
			opr = "cond";
		}
		break;
	}
	
	
	return opr;
}

#define CHECK_ARR_LEN(ctx, varTypeInfo) auto arrPa = varTypeInfo->getArrayPA(); \
	int initialSize = ctx->var_arr_value().size() > 0 ? \
	ctx->var_arr_value().size() : ctx->expr_list()->expression().size(); \
	if (arrPa->array_len > 0 && initialSize > arrPa->array_len) { \
		lC.emitError("array value size: " + to_string(arrPa->array_len) + " ,err:" + ctx->getText());\
		return; \
	} \
	if (arrPa->array_len < 0) arrPa->array_len = initialSize;


void DongLangLLVMExprTypeListener::enterVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) {
	//cout << "enterVar_arr_value:" << ctx->getText() << endl;
	//var_arr_value->var_arr_value, var
	for (auto pCtx = ctx->parent; pCtx; pCtx = pCtx->parent) {
		//var
		if (auto tCtx = dynamic_cast<DongLangParser::VarContext*>(pCtx)) {
			auto varSymbol = DongLangBaseAST::FindSymbol(tCtx, tCtx->IDENTIFIER()->getText());

			//修正一下长度
			auto varTypeInfo = varSymbol->getVarType();

			CHECK_ARR_LEN(ctx, varTypeInfo);

			mVarArrValueTypes[ctx] = COPY_SP_TYPE_INFO(varTypeInfo);
			break;
		}

		if (auto tCtx = dynamic_cast<DongLangParser::Var_arr_valueContext*>(pCtx)) {
			auto cTypeInfo = COPY_SP_TYPE_INFO(mVarArrValueTypes[tCtx]); //传递给child节点
			if (!cTypeInfo->isArray()) {
				lC.emitError("array value deepth: " + cTypeInfo->String() + " ,err:" + ctx->getText());
				return;
			}

			cTypeInfo->DelPointArrayItem(PointOrArray(false));

			CHECK_ARR_LEN(ctx, cTypeInfo);

			mVarArrValueTypes[ctx] = cTypeInfo;
			break;
		}
	}

	if (ctx->expr_list()) {
		auto cTypeInfo = COPY_SP_TYPE_INFO(mVarArrValueTypes[ctx]); //传递给child节点
		if (!cTypeInfo->DelPointArrayItem(PointOrArray(false)) || cTypeInfo->isArray()) {
			lC.emitError("array value element expr: " + cTypeInfo->String() + " ,err:" + ctx->getText());
			return;
		}

		for (auto expr : ctx->expr_list()->expression()) {
			mExprTypes[expr] = cTypeInfo; //最底层传递给expression
		}
	}
}

void DongLangLLVMExprTypeListener::exitVar_arr_value(DongLangParser::Var_arr_valueContext* ctx) {

#if 0 //length 不修正了

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
#endif
}

void DongLangLLVMExprTypeListener::enterExpression(DongLangParser::ExpressionContext* ctx) {
	//统计类型，自上而下
	for (auto pCtx = ctx->parent; pCtx; pCtx = pCtx->parent) {
		//call 函数类型涉及重载需要特殊处理
		if (auto tCtx = dynamic_cast<DongLangParser::Call_exprContext*>(pCtx)) {
			break;
		}

		//数组在var_arr_value rule里处理了
		if (auto tCtx = dynamic_cast<DongLangParser::Var_arr_valueContext*>(pCtx)) {
			break;
		}

		if (auto tCtx = dynamic_cast<DongLangParser::Id_primaryContext*>(pCtx)) {
			if (tCtx->id_primary_p_addrs()->POINT().size() == 0 &&
				tCtx->id_primary_p_addrs()->POINTADDR().size() == 0 &&
				tCtx->array_index().size() == 0) {
				continue;
			}

			//type = defaulttype;
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
				if (tCtx->expression().size() == 0) { // expression --> paran_expr -> id_primary -> expression
					mExprTypes[ctx] = typeInfo; //传递给child节点
				}
				if (tCtx->expression().size() == 1 && !tCtx->COND_NOT()) {
					mExprTypes[ctx] = typeInfo; //传递给child节点
				}
			}

			if (tCtx->COND_NOT() || tCtx->COND_AND() || tCtx->COND_OR()) {
				mExprTypes[ctx] = DongLangTypeInfo::BitType; //传递给child节点
			}

			//三元
			if (tCtx->threeOpr) {
				if (ctx == tCtx->expression(0)) {
					mExprTypes[ctx] = DongLangTypeInfo::BitType;
				}
				else {
					//if(typeInfo) mExprTypes[ctx] = typeInfo; //exitExpression时候自动赋值
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
					mExprTypes[ctx] = funcVar->getVarType();
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
				lC.emitError("undefined var:" + tCtx->IDENTIFIER()->getText());
				return;
			}

			mExprTypes[ctx] = var->getVarType();
			break;
		}

		//farg_default: fun(int a = expr)
		if (auto tCtx = dynamic_cast<DongLangParser::Farg_defaultContext*>(pCtx)) {
			auto var = DongLangBaseAST::FindSymbol(tCtx, tCtx->farg()->IDENTIFIER()->getText());
			if (!var) {
				lC.emitError("undefined var:" + tCtx->farg()->IDENTIFIER()->getText());
				return;
			}

			mExprTypes[ctx] = var->getVarType();
			break;
		}

		//assign *arr[5] (+-*/)?= xxx
		if (auto tCtx = dynamic_cast<DongLangParser::AssignContext*>(pCtx)) {
			// assign value: expression
			if (!tCtx->opr) {
				mExprTypes[ctx] = mAssignTypes[tCtx];
			}
			break;
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
	if (ctx->primary()) { // primary
	}
	else if (ctx->expression().size() == 1) {
		auto cTypeInfo = mDefaultExprTypes[ctx->expression(0)];
		if (ctx->COND_NOT()) {
			mDefaultExprTypes[ctx] = DongLangTypeInfo::BitType;
		}
		else {
			mDefaultExprTypes[ctx] = cTypeInfo;
		}
	}
	else {
		auto exprLCtx = ctx->expression(0);
		auto exprRCtx = ctx->expression(1);

		string expOpr;
		if (ctx->threeOpr) {
			exprLCtx = ctx->expression(1);
			exprRCtx = ctx->expression(2);
			expOpr = "three_op";
		}
		else {
			 expOpr = ctx->opr->getText();
		}
		auto typeL = mDefaultExprTypes[exprLCtx];
		auto typeR = mDefaultExprTypes[exprRCtx];

		DongLangTypeInfo* transTypeInfo = NULL;
		if (ctx->COND_AND() || ctx->COND_OR()) {
			transTypeInfo = DongLangTypeInfo::BitType;
		}
		else {
			transTypeInfo = DongLangTypeInfo::typeCheckTrans(typeL, typeR, expOpr, true, ctx->parent->getText());
			if (!transTypeInfo) {
				return;
			}

			if (typeL->String() != typeR->String()) {
				auto cmpIndex = (typeL->String() == transTypeInfo->String() ? 1 : 0) + (ctx->threeOpr ? 1 : 0);
				auto cmpExprCtx = ctx->expression(cmpIndex);

				if (transTypeInfo->isPoint() || transTypeInfo->isArray()) { //指针 == !=
					if (ctx->CMP_EQ() || ctx->CMP_NE() || ctx->threeOpr) {
						if (cmpExprCtx->primary() && cmpExprCtx->primary()->value_primary() && (cmpExprCtx->getText() != "0" && cmpExprCtx->getText() != "NIL")) {
							lC.emitError(ctx->getText() + +" opr='" + expOpr + "' point must use int NIL(0) value");
							return;
						}
					}
				}

				if(!transTypeInfo->isPoint() || (!ctx->ADD() && !ctx->SUB())) mExprTypes[cmpExprCtx] = transTypeInfo; //修正默认运算类型
			}

			if (ctx->CMP_EQ() || ctx->CMP_NE() || ctx->CMP_GT() || ctx->CMP_GE() || ctx->CMP_LT() || ctx->CMP_LE()) {
				//auto exprTypeInfo = ExprType(ctx);
				transTypeInfo = DongLangTypeInfo::BitType;
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
				lC.emitError(ctx->getText() + " byte operation type err:" + sti);
			}
		}
	}

	//检查类型冲突
	auto typeInfo = ExprType(ctx);
	auto defaultTypeInfo = ExprDefaultType(ctx);
	
	if (!typeInfo) {
		mExprTypes[ctx] = defaultTypeInfo;
		typeInfo = mExprTypes[ctx];
	}

	string opr = getExprOpr(ctx);

	/*cout << ctx->getText() << ",typeInfo:" << (typeInfo ? typeInfo->String() : "null") <<
		",defaultTypeInfo:" <<  (defaultTypeInfo ? defaultTypeInfo->String() : "null") <<
		endl;*/

	if (DongLangTypeInfo::typeCheckTrans(typeInfo, defaultTypeInfo, opr, true, ctx->getText())) {
		if (typeInfo->isPoint() && defaultTypeInfo->String() == "int" && (ctx->getText() != "0" && ctx->getText() != "NIL")) {
			lC.emitError(ctx->parent->getText() + " opr='" + opr  + "' point must use int NIL(0) value:" + ctx->getText());
		}
	}
}

void DongLangLLVMExprTypeListener::enterAssign(DongLangParser::AssignContext* ctx) {

}

void DongLangLLVMExprTypeListener::exitAssign(DongLangParser::AssignContext* ctx) {
	//++,--
	if (ctx->INCREMENT() || ctx->DECREMENT()) {
		DongLangTypeInfo::typeCheckTrans(mAssignTypes[ctx], DongLangTypeInfo::IntType, ctx->INCREMENT() ? "+" : "-", true, ctx->getText());
		return;
	}

	//没有赋值或者没有运算符
	if (!ctx->expression() || !ctx->opr) {
		return;
	}

	// id_primary (运算类opr)= expression
	auto typeL = mAssignTypes[ctx];
	auto exprCtx = ctx->expression();
	auto typeR = mDefaultExprTypes[exprCtx];

	//类型检查
	string expOpr = ctx->opr->getText();
	DongLangTypeInfo* transTypeInfo = DongLangTypeInfo::typeCheckTrans(typeL, typeR, expOpr, true, ctx->getText());
	if (!transTypeInfo) {
		return;
	}

	//位运算解析
	if (ctx->POINTADDR() || ctx->OR() || ctx->XOR()) {
		for (auto ti : { typeL, typeR }) {
			if (!ti) {
				continue;
			}

			auto sti = ti->String();
			if (sti != "int" && sti != "byte" && sti != "bool") {
				lC.emitError(ctx->getText() + " byte operation type err:" + sti);
			}
		}
	}

	if (typeR->String() != transTypeInfo->String() && !(ctx->ADD() || ctx->SUB()) && !transTypeInfo->isPoint()) {
		mExprTypes[exprCtx] = transTypeInfo;
	}

}


void DongLangLLVMExprTypeListener::enterVar_expression(DongLangParser::Var_expressionContext* ctx) {
	auto typeInfo = DongLangTypeInfo::BitType;
	if (dynamic_cast<DongLangParser::If_condContext*>(ctx->parent)) {
		mVarExprTypes[ctx] = typeInfo;
	}
}

void DongLangLLVMExprTypeListener::exitVar_expression(DongLangParser::Var_expressionContext* ctx) {
	//var_expression 没有类型信息(不在 if里)
	DongLangTypeInfo* typeInfo = mVarExprTypes[ctx];
	//获取默认类型
	DongLangTypeInfo* defaultTypeInfo = NULL;
	if (auto varsDecCtx = ctx->var_declares()) {
		defaultTypeInfo = DongLangBaseAST::FindSymbol(varsDecCtx, varsDecCtx->vars()->var(0)->IDENTIFIER()->getText())->getVarType();
	}
	else {
		auto assignsCtx = ctx->assigns();
		defaultTypeInfo = AssignType(assignsCtx->assign(0));
	}

	if (!typeInfo) {
		mVarExprTypes[ctx] = defaultTypeInfo;
		return;
	}

	if (DongLangTypeInfo::typeCheckTrans(typeInfo, defaultTypeInfo, "=", true, ctx->getText())) {
		if (typeInfo->isPoint() && defaultTypeInfo->String() == "int" && ctx->getText() != "0") {
			lC.emitError(ctx->parent->getText() + "var_expression type err");
		}
	}
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
			lC.emitError(ctx->getText() + " undefined var:" + id);
			return;
		}
		
		idTypeInfo = symbol->getVarType();
	}
	else if(ctx->call_expr()){//call_expr
		auto pCtx = dynamic_cast<DongLangParser::Id_primaryContext*>(ctx->parent);
		idTypeInfo = mCallFuncSymbol[ctx->call_expr()]->getVarType();
	}
	else  { //paran_expr
		idTypeInfo = mDefaultExprTypes[ctx->paran_expr()->expression()];
	}

	idTypeInfo = COPY_SP_TYPE_INFO(idTypeInfo);

	for (auto child : ctx->children) {
		if (auto arrIndexCtx = dynamic_cast<DongLangParser::Array_indexContext*>(child)) {
			if (!idTypeInfo->DelPointArrayItem(PointOrArray(false))) {
				lC.emitError("primary:" + ctx->getText() + " type:" + idTypeInfo->String() + "opr error");
				return;
			}
		}
	}

	//right -> left: &*&*(IDENTIFIER|call_expr|paran_expr)
	auto oprPtrCCtx = ctx->id_primary_p_addrs()->children;
	for(int i = oprPtrCCtx.size() - 1; i >= 0;i--) {
		auto child = oprPtrCCtx[i];
		auto pointS = child->getText();
		if (pointS == "*") {
			if (!idTypeInfo->DelPointArrayItem(PointOrArray(true))) {
				lC.emitError("primary:" + ctx->getText() + " type:" + idTypeInfo->String() + " opr error");
				return;
			}
		}
		else { // '&'
			/*if (idTypeInfo->isArray()) {
				lC.emitError("primary:" + ctx->getText() + " array cannot opr point");
				return;
			}*/

			//必须针对identifier
			if (i == oprPtrCCtx.size() - 1) { //最后一个才判断
				bool canAddress = ctx->array_index().size();
				if (!canAddress) {
					if (ctx->IDENTIFIER()) {
						canAddress = true;
					}
					else if (ctx->call_expr()) {
						auto ptrCCtx = ctx->id_primary_p_addrs();
						if (ctx->array_index().size()) {
							canAddress = true;
						}
					}
					else if (ctx->paran_expr()) { //paran
						for (auto cCtx = ctx;; canAddress = false) {
							auto exprCtx = cCtx->paran_expr()->expression();
							if (!exprCtx->primary() || !exprCtx->primary()->id_primary()) {
								break;
							}

							cCtx = exprCtx->primary()->id_primary();
							auto ptrCCtx = cCtx->id_primary_p_addrs();
							canAddress = ptrCCtx->POINT().size() >= ptrCCtx->POINTADDR().size(); // count(*) > count(&)
							if (!canAddress) {
								break;
							}

							canAddress = cCtx->array_index().size();
							if (canAddress) {
								break;
							}

							if (cCtx->IDENTIFIER()) {
								canAddress = true;
								break;
							}

							if (ctx->call_expr()) {
								break;
							}
						}
					}
				}

				if (!canAddress) {
					lC.emitError("primary:" + ctx->getText() + " can not address &");
					return;
				}
			}

			idTypeInfo->AddPointArrayItem(PointOrArray(true));
		}
	}

	if (auto assignCtx = dynamic_cast<DongLangParser::AssignContext*>(ctx->parent)) {//->assign
		//TODO assign 左值：检查是否可以寻址
		if (assignCtx->expression() || assignCtx->INCREMENT() || assignCtx->DECREMENT()) {
			DongLangTypeInfo* srcTypeInfo = NULL;
			for (auto cCtx = ctx;;) {
				if (cCtx->IDENTIFIER()) {
					srcTypeInfo = DongLangBaseAST::FindSymbol(cCtx, cCtx->IDENTIFIER()->getText())->getVarType();
					break;
				}
				else if (cCtx->call_expr()) {
					srcTypeInfo = mCallFuncSymbol[cCtx->call_expr()]->getVarType();
					break;
				}

				auto exprCtx = cCtx->paran_expr()->expression();
				if (exprCtx->expression().size()) {
					srcTypeInfo = mDefaultExprTypes[exprCtx];
					if (srcTypeInfo->isPoint() && (exprCtx->ADD() || exprCtx->SUB())) {
						exprCtx = exprCtx->expression(0);
					}
					else {
						srcTypeInfo = NULL;
						break;
					}
				}

				auto primaryCtx = exprCtx->primary();
				if (primaryCtx->value_primary()) {
					break;
				}

				cCtx = primaryCtx->id_primary();
			}

			if (!srcTypeInfo || srcTypeInfo->pas.size() < idTypeInfo->pas.size()) {
				lC.emitError("primary:" + ctx->getText() + " can not as left value");
				return;
			}
		}
	
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
	DongLangTypeInfo* primaryTypeInfo = NULL;
	if (ctx->num_primary()) {
		primaryTypeInfo = DongLangTypeInfo::ConstIntType;
		if (ctx->num_primary()->getText().find(".") != string::npos) {
			primaryTypeInfo = DongLangTypeInfo::ConstFloatType;
		}
	}

	if (ctx->bool_primary()) {
		primaryTypeInfo = DongLangTypeInfo::BoolType;
	}

	if (ctx->str_primary()) {
		primaryTypeInfo = DongLangTypeInfo::StringType;
	}

	mDefaultExprTypes[exprCtx] = primaryTypeInfo;
}

void DongLangLLVMExprTypeListener::enterParan_expr(DongLangParser::Paran_exprContext* ctx) {}
void DongLangLLVMExprTypeListener::exitParan_expr(DongLangParser::Paran_exprContext* ctx) {}

void DongLangLLVMExprTypeListener::enterCall_expr(DongLangParser::Call_exprContext* ctx) {}
void DongLangLLVMExprTypeListener::exitCall_expr(DongLangParser::Call_exprContext* ctx) {
	//做参数映射
	string fnName(ctx->IDENTIFIER()->getText());
	auto funcList = DongLangBaseAST::FindFuncSymbolList(ctx, fnName);
	if (funcList == NULL || funcList->size() == 0) {
		lC.emitError("call undefined function:" + fnName);
		return;
	}

	vector<DongLangParser::ExpressionContext*> exprCtxList;
	exprCtxList.clear();
	if (ctx->expr_list()) {
		exprCtxList = ctx->expr_list()->expression();
	}

	int inputArgCount = exprCtxList.size();

	map<FuncDLSymbol*, int> dstFuncs;
	dstFuncs.clear();
	int maxEValue = 0;
	const static int mStandEV = 100; //默认一个函数的参数不会超过这么多
	string errArgDesc = "";
	int lastMaxMatchValue = -1;
	for (auto func : *funcList) {
		//argCount
		auto argTypes = func->argType();
		int argCount = argTypes.size();
		if (inputArgCount > argCount && !func->varArg()) { //参数不足
			continue;
		}

		//检查参数
		int ti = 0;
		int matchEValue = 0;
		for (;ti < argCount && ti < inputArgCount; ti++) {
			auto argT = argTypes[ti];
			auto inputT = mDefaultExprTypes[(exprCtxList[ti])];
			auto inputTStr = inputT->String();
			auto argTStr = argT->String();
			if (inputTStr != argTStr) {
				if (DongLangTypeInfo::typeCheckTrans(argT, inputT, "call")) {
					matchEValue += (mStandEV-ti-1); //按照位置修正-1
				}
				else {
					if (lastMaxMatchValue < matchEValue) {
						lastMaxMatchValue = matchEValue;
						errArgDesc = exprCtxList[ti]->getText();
					}
					matchEValue = -1; //参数对不上直接清零
					break;
				}
			}
			else {
				matchEValue += mStandEV;
			}
		}

		if (matchEValue < 0) {
			continue;
		}
		
		if (inputArgCount < argCount) {//default arg
			if (!func->argSymbol(ti)->getDefaultValueID()) {
				continue;
			}
		}
		else {//var arg
			if (func->varArg()) {
				for (; ti < inputArgCount; ti++) {
					matchEValue += (mStandEV - ti - 2); //按照位置修正-2
				}
			}
		}

		if (maxEValue < matchEValue) {
			maxEValue = matchEValue;
		}
		dstFuncs[func] = matchEValue;
	}

	//1、参数不对函数
	if (dstFuncs.size() == 0) {
		lC.emitError("call arg error function:" + fnName + ",arg:" + errArgDesc);
		return;
	}

	//2、函数有歧义
	FuncDLSymbol* callFunc = NULL;
	for (auto it = dstFuncs.begin(); it != dstFuncs.end();++it) {
		if (maxEValue == it->second) {
			if (callFunc) {
				lC.emitError("call ambiguity function:" + fnName);
				return;
			}

			callFunc = it->first;
		}
	}

	int ti = 0;
	for (auto argT : callFunc->argType()) {
		if (ti >= inputArgCount) {
			break;
		}

		mExprTypes[exprCtxList[ti++]] = argT;//exitExpression检查会报错
	}

	//varArg 就直接default
	for (; ti < inputArgCount; ti++) {
		auto exprCtx = exprCtxList[ti];
		mExprTypes[exprCtx] = mDefaultExprTypes[exprCtx]; 
	}

	mCallFuncSymbol[ctx] = callFunc;

}

void DongLangLLVMExprTypeListener::enterArray_type(DongLangParser::Array_typeContext* ctx) {
}

void DongLangLLVMExprTypeListener::exitRet_expression(DongLangParser::Ret_expressionContext* ctx) {
	if (ctx->expression()) {
		return;
	}

	//void空返回校验
	
	//找到归属的function
	for (auto ptCtx = ctx->parent; ptCtx != NULL; ptCtx = ptCtx->parent) {
		if (auto funcCtx = dynamic_cast<DongLangParser::Function_defContext*>(ptCtx)) {
			auto funcVar = (FuncDLSymbol *)DongLangBaseAST::FindSymbol(funcCtx, SYMBOL_ID(funcCtx));
			auto typeInfo = funcVar->getVarType();
			if (typeInfo->String() != "void") {
				lC.emitError("function's return type is not void:" + funcVar->Name());
				return;
			}

			break;
		}
	}
}