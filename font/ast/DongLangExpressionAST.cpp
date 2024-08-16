#include "DongLangExpressionAST.h"


DongLangExpressionAST::MEXPRESSION_HANDLERS DongLangExpressionAST::mExpressionHandlers = {
	{"+", addExpr },
	{"-", subExpr },
	{"*", mulExpr },
	{"/", divExpr },
	{"&", andExpr },
	{"|", orExpr },
	{"^", xorExpr },
	{"~", notExpr },

	{"==", cmpExpr },
	{"!=", cmpExpr},
	{">", cmpExpr},
	{">=", cmpExpr},
	{"<", cmpExpr},
	{"<=", cmpExpr},

	{"!", ifNotExpr },
	{"&&", ifAndExpr},
	{"||", ifOrExpr},
	{"?:", ifThreeOrExpr},
};

#define CREATE_PHI(llType, NUM)  lB.CreatePHI(llType->isArrayTy() ? llType->getPointerTo() : llType, NUM);

DongLangExpressionAST::DongLangExpressionAST(CodeLocData& locData, std::string op, DongLangBaseAST* lhs,
	DongLangBaseAST* rhs, DongLangBaseAST* exths, DongLangTypeInfo* typeInfo, DongLangTypeInfo* defaultTypeInfo)
	: DongLangBaseAST(typeInfo, locData),
	defaultTypeInfo(defaultTypeInfo), 
	trueBB(NULL),
	falseBB(NULL),
	phi(NULL) {
	this->op = op;
	this->lhs = lhs;
	this->rhs = rhs;
	this->exths = exths;

	this->lhs->setParent(this);
	if (this->rhs) {
		this->rhs->setParent(this);
	}

	assetOpearation();
	
}

void DongLangExpressionAST::assetOpearation() {
	auto typeInfo = exprType();
	auto tS = typeInfo->String();
	auto lhsType = lhs->exprType();
	auto lhsTs = lhsType->String();
	if (op == "!") {
		if (lhsTs != "bool" &&
			lhsTs != "bit") {
			lC.emitError("expression assetOpearation:" + op + " error");
			return;
		}
	} 
	else if (op == "+" || op == "-" ) {
		//数字和指针才能加减
		if (lhsTs != "byte" &&
			lhsTs != "int" &&
			lhsTs != "float" && 
			(!lhsType->isPoint() || rhs->exprType()->String() != "int")) {
			lC.emitError("expression assetOpearation:" + lhsType->String() + op + rhs->exprType()->String() + " error");
			return;
		}
	}
	else if (op == "*" || op == "/") {
		if (lhsTs != "byte" &&
			lhsTs != "int" &&
			lhsTs != "float") {
			lC.emitError("expression assetOpearation:" + op + " error");
			return;
		}
	}
	else if (op == "==" || op == "!=") {
		if (lhsTs != "byte" &&
			lhsTs != "int" &&
			lhsTs != "float" &&
			lhsTs != "bool" &&
			(!lhsType->isPoint() || lhsTs != rhs->exprType()->String())) {
			lC.emitError("expression assetOpearation:" + op + " error");
			return;
		}
	}
	else if (op == "&" || op == "|" || op == "^" || op == "~") {
		if (lhsTs != "byte" &&
			lhsTs != "int" &&
			lhsTs != "bool") {
			lC.emitError("expression assetOpearation:" + op + " error");
			return;
		}
	}
	else if(op == ">" || op == "<" || op == "<=" || op == ">=") {
		if (lhsTs != "byte" &&
			lhsTs != "int" &&
			lhsTs != "float") {
			lC.emitError("expression assetOpearation:" + op + " error");
			return;
		}
	}
	else if (op == "&&" || op == "||" || "?:") {
		if (lhsTs != "bool" && lhsTs != "bit") {
			lC.emitError("expression assetOpearation:" + op + " error");
			return;
		}
	}
	else {
		lC.emitError("expression invalid operation:" + op);
		return;
	}
}


Value* DongLangExpressionAST::genCode() {
	//std::cout << "DongLangExpressionAST::genCode op:" << op << std::endl;
	Value* value = mExpressionHandlers[op](this);
	return TransValue(defaultTypeInfo, value);
}

Value* DongLangExpressionAST::addExpr(DongLangExpressionAST* ast) {
	auto lhsTypeInfo = ast->lhs->exprType();
	string lhsTS = lhsTypeInfo->String();

	ast->lhs->setFArg();
	ast->rhs->setFArg();
	Value* lValue = ast->lhs->genCodeWrap();
	Value* rValue = ast->rhs->genCodeWrap();
	Value* retValue = NULL;
	if (lhsTS == "int") {
		retValue = lB.CreateAdd(lValue, rValue);
	}
	else if (lhsTS == "float") {
		retValue = lB.CreateFAdd(lValue, rValue);
	}
	else if (lhsTS == "byte") {
		retValue = lB.CreateAdd(lValue, rValue);
	}
	else if (lhsTypeInfo->isPoint()) {
		DongLangTypeInfo ptrTypeInfo = *(ast->lhs->exprType());
		ptrTypeInfo.DelPointArrayItem(PointOrArray(true));
		retValue = lB.CreateGEP(ptrTypeInfo.LlvmType(&lB), lValue, {rValue});
	}

	return retValue;
}

Value* DongLangExpressionAST::subExpr(DongLangExpressionAST* ast) {
	auto lhsTypeInfo = ast->lhs->exprType();
	string lhsTS = lhsTypeInfo->String();

	ast->lhs->setFArg();
	ast->rhs->setFArg();
	Value* lValue = ast->lhs->genCodeWrap();
	Value* rValue = ast->rhs->genCodeWrap();
	Value* retValue = NULL;
	if (lhsTS == "int") {
		retValue = lB.CreateSub(lValue, rValue);
	}
	else if (lhsTS == "float") {
		retValue = lB.CreateFSub(lValue, rValue);
	}
	else if (lhsTS == "byte") {
		retValue = lB.CreateSub(lValue, rValue);
	}
	else if (lhsTypeInfo->isPoint()) {
		DongLangTypeInfo ptrTypeInfo = *(ast->lhs->exprType());
		ptrTypeInfo.DelPointArrayItem(PointOrArray(true));

		rValue = lB.CreateSub(lB.getInt64(0), rValue);
		retValue = lB.CreateGEP(ptrTypeInfo.LlvmType(&lB), lValue, {rValue});
	}

	return retValue;
}

Value* DongLangExpressionAST::mulExpr(DongLangExpressionAST* ast) {
	auto lhsTypeInfo = ast->lhs->exprType();
	string lhsTS = lhsTypeInfo->String();

	ast->lhs->setFArg();
	ast->rhs->setFArg();
	Value* lValue = ast->lhs->genCodeWrap();
	Value* rValue = ast->rhs->genCodeWrap();
	Value* retValue = NULL;
	if (lhsTS == "int") {
		retValue = lB.CreateMul(lValue, rValue);
	}
	else if (lhsTS == "float") {
		retValue = lB.CreateFMul(lValue, rValue);
	}
	else if (lhsTS == "byte") {
		lValue = lB.CreateCast(Instruction::CastOps::SExt, lValue, lB.getInt64Ty());
		rValue = lB.CreateCast(Instruction::CastOps::SExt, rValue, lB.getInt64Ty());
		retValue = lB.CreateMul(lValue, rValue);
	}
	

	return retValue;
}

Value* DongLangExpressionAST::divExpr(DongLangExpressionAST* ast) {
	auto lhsTypeInfo = ast->lhs->exprType();
	string lhsTS = lhsTypeInfo->String();

	ast->lhs->setFArg();
	ast->rhs->setFArg();
	Value* lValue = ast->lhs->genCodeWrap();
	Value* rValue = ast->rhs->genCodeWrap();
	Value* retValue = NULL;
	if (lhsTS == "int") {
		retValue = lB.CreateSDiv(lValue, rValue);
	}
	else if (lhsTS == "float") {
		retValue = lB.CreateFDiv(lValue, rValue);
	}
	else if (lhsTS == "byte") {
		lValue = lB.CreateCast(Instruction::CastOps::SExt, lValue, lB.getInt64Ty());
		rValue = lB.CreateCast(Instruction::CastOps::SExt, rValue, lB.getInt64Ty());
		retValue = lB.CreateSDiv(lValue, rValue);
	}

	return retValue;
}

Value* DongLangExpressionAST::notExpr(DongLangExpressionAST* ast) {
	ast->lhs->setFArg();
	return lB.CreateNot(ast->lhs->genCodeWrap());
}

Value* DongLangExpressionAST::andExpr(DongLangExpressionAST* ast) {
	auto lhsTypeInfo = ast->lhs->exprType();
	string lhsTS = lhsTypeInfo->String();

	ast->lhs->setFArg();
	ast->rhs->setFArg();
	Value* lValue = ast->lhs->genCodeWrap();
	Value* rValue = ast->rhs->genCodeWrap();
	return lB.CreateAnd(lValue, rValue);
}

Value* DongLangExpressionAST::orExpr(DongLangExpressionAST* ast) {
	auto lhsTypeInfo = ast->lhs->exprType();
	string lhsTS = lhsTypeInfo->String();

	ast->lhs->setFArg();
	ast->rhs->setFArg();
	Value* lValue = ast->lhs->genCodeWrap();
	Value* rValue = ast->rhs->genCodeWrap();
	return lB.CreateOr(lValue, rValue);
}

Value* DongLangExpressionAST::xorExpr(DongLangExpressionAST* ast) {
	auto lhsTypeInfo = ast->lhs->exprType();
	string lhsTS = lhsTypeInfo->String();

	ast->lhs->setFArg();
	ast->rhs->setFArg();
	Value* lValue = ast->lhs->genCodeWrap();
	Value* rValue = ast->rhs->genCodeWrap();
	return lB.CreateXor(lValue, rValue);
}

Value* DongLangExpressionAST::cmpExpr(DongLangExpressionAST* ast) {
	auto lhsTypeInfo = ast->lhs->exprType();
	string lhsTS = lhsTypeInfo->String();

	ast->lhs->setFArg();
	ast->rhs->setFArg();
	Value* lValue = ast->lhs->genCodeWrap();
	Value* rValue = ast->rhs->genCodeWrap();
	Value* retValue = NULL;

	string op = ast->op;
	CmpInst::Predicate cmpP;
	if (op == "==") {
		cmpP = lhsTS == "float" ? CmpInst::Predicate::FCMP_OEQ : CmpInst::Predicate::ICMP_EQ;
	} else if (op == "!=") {
		cmpP = lhsTS == "float" ? CmpInst::Predicate::FCMP_ONE : CmpInst::Predicate::ICMP_NE;
	} else if (op == ">") {
		cmpP = lhsTS == "float" ? CmpInst::Predicate::FCMP_OGT : CmpInst::Predicate::ICMP_SGT;
	} else if (op == ">=") {
		cmpP = lhsTS == "float" ? CmpInst::Predicate::FCMP_OGE : CmpInst::Predicate::ICMP_SGE;
	} else if (op == "<") {
		cmpP = lhsTS == "float" ? CmpInst::Predicate::FCMP_OLT : CmpInst::Predicate::ICMP_SLT;
	}
	else if (op == "<=") {
		cmpP = lhsTS == "float" ? CmpInst::Predicate::FCMP_OLE : CmpInst::Predicate::ICMP_SLE;
	}

	if (lhsTS == "byte") {
		lValue = lB.CreateCast(Instruction::CastOps::SExt, lValue, lB.getInt64Ty());
		rValue = lB.CreateCast(Instruction::CastOps::SExt, rValue, lB.getInt64Ty());
	}

	if (lhsTS == "float") {
		retValue = lB.CreateFCmp(cmpP, lValue, rValue);
	}
	else {
		retValue = lB.CreateICmp(cmpP, lValue, rValue);
	}

	//i1 => i8(bool)
	//retValue = lB.CreateCast(Instruction::CastOps::ZExt, retValue, lB.getInt8Ty());
	
	return retValue;
}

Value* DongLangExpressionAST::ifNotExpr(DongLangExpressionAST* ast) {
	ast->lhs->setFArg();
	return lB.CreateNot(ast->lhs->genCodeWrap());
}

#define CUR_BB lB.GetInsertBlock()


Value* DongLangExpressionAST::ifAndExpr(DongLangExpressionAST* ast) {
	auto curBB = lB.GetInsertBlock();

	ast->lhs->setFArg();
	Value* lValue = ast->lhs->genCodeWrap();
	auto cCurBB = CUR_BB;
	if (cCurBB == curBB) { //说明lhs不是expression嵌套
		ast->trueBB = BasicBlock::Create(lC, "", curBB->getParent());
		ast->falseBB = BasicBlock::Create(lC, "", curBB->getParent());

		ast->phi = CREATE_PHI(lValue->getType(), 2);

		ast->phi->addIncoming(lValue, cCurBB);
		//BranchInst::Create(ast->trueBB, ast->falseBB, lValue, cCurBB);
		lB.CreateCondBr(lValue, ast->trueBB, ast->falseBB);
	}
	else {
		BasicBlock* cFirstBB = cCurBB->getPrevNode();
		ast->trueBB = BasicBlock::Create(lC, "", cFirstBB->getParent());
		ast->trueBB->moveAfter(cFirstBB);
		ast->falseBB = cCurBB;

		//查找子endBB里的phinode
		Instruction* lastInst;
		for (Instruction& inst : *cCurBB) {
			lastInst = &inst;
			if (PHINode* phi = dyn_cast<PHINode>(&inst)) {
				ast->phi = phi;
				break;
			}
		}

		//获取start启动block
		BasicBlock* startBB;
		for (auto pi = pred_begin(cFirstBB), pe = pred_end(cFirstBB); pi != pe; ++pi) {
			startBB = dyn_cast<BasicBlock>(*pi);
		}

		Value* cmpValue;
		int instLen = startBB->size();
		for (Instruction& inst : *startBB) {
			lastInst = &inst;
			instLen--;
			if (instLen == 1) { //倒数第二条指令是赋值
				cmpValue = &inst;
			}
		}

		//判断子expr && 或者 ||
		BranchInst* brInst = dyn_cast<BranchInst>(lastInst);
		if(brInst->getSuccessor(0) != cFirstBB) { // == "||"
			lastInst->eraseFromParent();
			ast->phi->removeIncomingValue(startBB);
			//BranchInst::Create(ast->trueBB, cFirstBB, cmpValue, startBB);

			lB.SetInsertPoint(startBB);
			lB.CreateCondBr(cmpValue, ast->trueBB, cFirstBB);
			lB.SetInsertPoint(cCurBB);
		}

		//修改子trueBB的br
		instLen = cFirstBB->size();
		for (Instruction& inst : *cFirstBB) {
			lastInst = &inst;
			instLen--;
			if (instLen == 1) { //倒数第二条指令是赋值
				cmpValue = &inst;
			}
		}
		lastInst->eraseFromParent();

		//BranchInst::Create(ast->trueBB, ast->falseBB, cmpValue, cFirstBB);
		lB.SetInsertPoint(cFirstBB);
		lB.CreateCondBr(cmpValue, ast->trueBB, ast->falseBB);
		lB.SetInsertPoint(cCurBB);
	}

	lB.SetInsertPoint(ast->trueBB);
	ast->rhs->setFArg();
	Value* rValue = ast->rhs->genCodeWrap();
	cCurBB = CUR_BB;
	ast->phi->addIncoming(rValue, cCurBB);

	if (ast->trueBB != cCurBB) { //expression嵌套
		ast->falseBB->moveAfter(cCurBB);
	}

	lB.CreateBr(ast->falseBB);

	lB.SetInsertPoint(ast->falseBB);
	ast->phi->removeFromParent();
	ast->phi->insertInto(ast->falseBB, ast->falseBB->end());

	return ast->phi;
}

Value* DongLangExpressionAST::ifOrExpr(DongLangExpressionAST* ast) {
	auto curBB = lB.GetInsertBlock();

	ast->lhs->setFArg();
	Value* lValue = ast->lhs->genCodeWrap();
	auto cCurBB = CUR_BB;
	if (cCurBB == curBB) { //说明lhs不是expression嵌套
		ast->trueBB = BasicBlock::Create(lC, "", curBB->getParent());
		ast->falseBB = BasicBlock::Create(lC, "", curBB->getParent());
		ast->trueBB->moveAfter(ast->falseBB);

		ast->phi = CREATE_PHI(lValue->getType(), 0); 

		ast->phi->addIncoming(lValue, cCurBB);
		//BranchInst::Create(ast->trueBB, ast->falseBB, lValue, cCurBB);
		lB.CreateCondBr(lValue, ast->trueBB, ast->falseBB);
	}
	else {
		BasicBlock* cFirstBB = cCurBB->getPrevNode(); // 子block1
		ast->falseBB = BasicBlock::Create(lC, "", cFirstBB->getParent()); //curBlock1
		ast->falseBB->moveAfter(cFirstBB);
		ast->trueBB = cCurBB; //子block2(endBB)

		//查找子endBB里的phinode
		Instruction* lastInst;
		for (Instruction& inst : *cCurBB) {
			lastInst = &inst;
			if (PHINode* phi = dyn_cast<PHINode>(&inst)) {
				ast->phi = phi;
				break;
			}
		}

		//获取start启动block
		BasicBlock* startBB;
		for (auto pi = pred_begin(cFirstBB), pe = pred_end(cFirstBB); pi != pe; ++pi) {
			startBB = dyn_cast<BasicBlock>(*pi);
		}

		Value* cmpValue;
		int instLen = startBB->size();
		for (Instruction& inst : *startBB) {
			lastInst = &inst;
			instLen--;
			if (instLen == 1) { //倒数第二条指令是赋值
				cmpValue = &inst;
			}
		}

		//判断子expr && 或者 ||
		BranchInst* brInst = dyn_cast<BranchInst>(lastInst);
		if (brInst->getSuccessor(1) != cFirstBB) { // == "&&"
			lastInst->eraseFromParent();
			ast->phi->removeIncomingValue(startBB);
			//BranchInst::Create(cFirstBB, ast->falseBB, cmpValue, startBB);

			lB.SetInsertPoint(startBB);
			lB.CreateCondBr(cmpValue, ast->trueBB, cFirstBB);
			lB.SetInsertPoint(cCurBB);
		}

		//修改子trueBB的br
		instLen = cFirstBB->size();
		for (Instruction& inst : *cFirstBB) {
			lastInst = &inst;
			instLen--;
			if (instLen == 1) { //倒数第二条指令是赋值
				cmpValue = &inst;
			}
		}
		lastInst->eraseFromParent();

		//BranchInst::Create(ast->trueBB, ast->falseBB, cmpValue, cFirstBB);
		lB.SetInsertPoint(cFirstBB);
		lB.CreateCondBr(cmpValue, ast->trueBB, ast->falseBB);
		lB.SetInsertPoint(cCurBB);
	}

	lB.SetInsertPoint(ast->falseBB);
	ast->rhs->setFArg();
	Value* rValue = ast->rhs->genCodeWrap();
	cCurBB = CUR_BB;
	ast->phi->addIncoming(rValue, cCurBB);

	if (ast->falseBB != cCurBB) { //expression嵌套
		ast->trueBB->moveAfter(cCurBB);
	}

	lB.CreateBr(ast->trueBB);

	lB.SetInsertPoint(ast->trueBB);
	ast->phi->removeFromParent();
	ast->phi->insertInto(ast->trueBB, ast->trueBB->end());

	return ast->phi;
}


Value* DongLangExpressionAST::ifThreeOrExpr(DongLangExpressionAST* ast) {
	auto condAst = ast->lhs;
	auto lhsAst = ast->rhs;
	auto rhsAst = ast->exths;

	auto curBB = CUR_BB;

	ast->trueBB = BasicBlock::Create(lC, "", curBB->getParent());
	ast->falseBB = BasicBlock::Create(lC, "", curBB->getParent());
	auto endBB = BasicBlock::Create(lC, "", curBB->getParent());

	ast->phi = CREATE_PHI(LlvmType(lhsAst->exprType()), 2);

	condAst->setFArg();
	Value* cmpValue = condAst->genCodeWrap();

	curBB = CUR_BB;
	//BranchInst::Create(ast->trueBB, ast->falseBB, cmpValue, CUR_BB);
	lB.CreateCondBr(cmpValue, ast->trueBB, ast->falseBB);

	ast->trueBB->moveAfter(curBB);
	lB.SetInsertPoint(ast->trueBB);
	lhsAst->setFArg();
	ast->phi->addIncoming(lhsAst->genCodeWrap(), ast->trueBB);
	lB.CreateBr(endBB);

	curBB = CUR_BB;
	ast->falseBB->moveAfter(curBB);
	lB.SetInsertPoint(ast->falseBB);
	rhsAst->setFArg();
	ast->phi->addIncoming(rhsAst->genCodeWrap(), ast->falseBB);
	lB.CreateBr(endBB);

	curBB = CUR_BB;
	endBB->moveAfter(curBB);
	lB.SetInsertPoint(endBB);
	ast->phi->removeFromParent();
	ast->phi->insertInto(endBB, endBB->end());

	return ast->phi;
}