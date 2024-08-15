#include "DongLangCondAST.h"
#include "DongLangExpressionAST.h"
DongLangBreakAST::DongLangBreakAST(antlr4Ctx ctx, CodeLocData& locData): DongLangBaseAST(NULL, locData), ctx(ctx) {

}

Value* DongLangBreakAST::genCode() {
	return 	lB.CreateBr(CurScope(ctx)->getForInfo()->getLoopEndBB());
}

DongLangContinueAST::DongLangContinueAST(antlr4Ctx ctx, CodeLocData& locData): DongLangBaseAST(NULL, locData), ctx(ctx) {
	
}

Value* DongLangContinueAST::genCode() {
	return 	lB.CreateBr(CurScope(ctx)->getForInfo()->getLoopBeginBB());
}

DongLangIfExprAST::DongLangIfExprAST(CodeLocData& locData, vector<DongLangIfExprItem*>& ifItems):
	DongLangBaseAST(NULL, locData),
	ifItems(ifItems){
}

Value* DongLangIfExprAST::genCode() {
	auto curBB = lB.GetInsertBlock();
	BasicBlock* endBB = BasicBlock::Create(lC, "", curBB->getParent());
	BasicBlock* elseBB = NULL;
	map<DongLangIfExprItem*, BasicBlock*> mIfBBs;
	mIfBBs.clear();
	for (auto cAst : ifItems) {
		mIfBBs[cAst] = BasicBlock::Create(lC, "", curBB->getParent());
		if (!cAst->initAst && !cAst->condAst) { // else
			elseBB = mIfBBs[cAst];
		}
	}

	int index = 0;
	for (auto cAst : ifItems) {
		if (G_DEBUG) {
			auto debugScope1 = lDB.createLexicalBlock(
				lDI.curScope(),
				lDI.file,
				cAst->locData.line,
				cAst->locData.column);

			lDI.enterScope(debugScope1);
		}

		//˳�� cmp BBS ===> trueBB ==> trueStatements BBS ==> falseBB
		auto BB1 = lB.GetInsertBlock();
		Value* cmpValue = NULL;
		if (cAst->initAst) {
			if(!cAst->condAst) cAst->initAst->setFArg();
			cmpValue = cAst->initAst->genCodeWrap();
		}

		if (cAst->condAst) {
			cAst->condAst->setFArg();
			cmpValue = cAst->condAst->genCodeWrap();
		}

		bool bElse = !cAst->initAst && !cAst->condAst;
		if (G_DEBUG) {
			if (!bElse) {
				auto debugScope2 = lDB.createLexicalBlock(
					lDI.curScope(),
					lDI.file,
					cAst->locData.line,
					cAst->locData.column);
				lDI.enterScope(debugScope2);
			}
		}

		auto BB2 = lB.GetInsertBlock();
		BasicBlock* trueBB = mIfBBs[cAst];
		BasicBlock* nextIfBB = NULL;
		if (!bElse) {
			nextIfBB =  (index >= ifItems.size() - (elseBB ? 2 : 1)) ? (elseBB ? elseBB : endBB) : BasicBlock::Create(lC, "", BB2->getParent(), endBB);
			BranchInst::Create(trueBB, nextIfBB, cmpValue, BB2);
		}

		trueBB->moveAfter(BB2);

		lB.SetInsertPoint(trueBB);
		BasicBlock* bkOrCtBB = NULL;
		bool noPreds = false;
		for (auto smAst : cAst->statements) {
			auto sv = smAst->genCodeWrap();
			if (BranchInst* brSv = dyn_cast<BranchInst>(sv)) {
				if (brSv->getNumSuccessors() == 1) {
					bkOrCtBB = brSv->getSuccessor(0);
					break;
				}
			}else if (auto smBB = dyn_cast<BasicBlock>(sv); smBB && smBB != trueBB) {
				//��ǰģ�鲻����preds,�����ڴ����break continue ���µĲ��ɴ����
				if (pred_begin(smBB) == pred_end(smBB)) {
					lB.SetInsertPoint(smBB->getPrevNode());
					smBB->eraseFromParent();
					noPreds = true;
					break;
				}
			}
		}

		BB2 = lB.GetInsertBlock(); //��������ѡ����л�basicBlock

		//����ֱ����ת�����սڵ�
		if (!bkOrCtBB && !noPreds) {
			lB.CreateBr(endBB);
		}

		endBB->moveAfter(BB2);
		index++;

		if (nextIfBB && nextIfBB != endBB) {
			lB.SetInsertPoint(nextIfBB);
			nextIfBB->moveAfter(BB2);
		}

		if (G_DEBUG) {
			if (!bElse) {
				lDI.leaveScope();
			}
		}
	}

	if (G_DEBUG) {
		for (auto cAst : ifItems) {
			lDI.leaveScope();
		}
	}

	lB.SetInsertPoint(endBB);

	return endBB;
}


DongLangForExprAST::DongLangForExprAST(CodeLocData& locData, DongLangBaseAST* initAst,
	DongLangBaseAST* condAst,
	DongLangBaseAST* iterAst,
	vector<DongLangBaseAST*> statements):
	DongLangBaseAST(NULL, locData),
	initAst(initAst),
	condAst(condAst),
	iterAst(iterAst),
	statements(statements),
	condBB(NULL),
	iterBB(NULL),
	endBB(NULL){
}

Value* DongLangForExprAST::genCode() {
	if (G_DEBUG) {
		auto debugScope = lDB.createLexicalBlock(
			lDI.curScope(),
			lDI.file,
			getLocLine(),
			getLocColumn());

		lDI.enterScope(debugScope);
	}

	if (initAst) {
		initAst->genCodeWrap();
	}

	auto mainBB = lB.GetInsertBlock();
	endBB = BasicBlock::Create(lC, "", mainBB->getParent());
	condBB = BasicBlock::Create(lC, "", mainBB->getParent());
	condBB->moveAfter(mainBB);

	if (iterAst) {
		iterBB = BasicBlock::Create(lC, "", mainBB->getParent(), endBB);

		//main->iter
		lB.SetInsertPoint(iterBB);
		iterAst->genCodeWrap();
		lB.CreateBr(condBB);
	}

	//main->cond
	lB.SetInsertPoint(mainBB);
	lB.CreateBr(condBB);

	lB.SetInsertPoint(condBB);
	

	if (condAst) {
		condAst->setFArg();
		auto cmpValue = condAst->genCodeWrap();
		auto trueBB = BasicBlock::Create(lC, "", mainBB->getParent());

		trueBB->moveAfter(lB.GetInsertBlock());
		BranchInst::Create(trueBB, endBB, cmpValue, condBB);

		lB.SetInsertPoint(trueBB);
	}
	
	auto BB1 = lB.GetInsertBlock();
	BasicBlock* bkOrCtBB = NULL;
	BasicBlock* smBB = NULL;
	bool noPreds = false;

	for (auto smAst : statements) {
		auto sv = smAst->genCodeWrap();

		//continue or break?
		if (BranchInst* brSv = dyn_cast<BranchInst>(sv)) {
			if (brSv->getNumSuccessors() == 1) {
				bkOrCtBB = brSv->getSuccessor(0);
				break;
			}
		}
		else if (smBB = dyn_cast<BasicBlock>(sv); smBB && smBB != BB1) {
			//��ǰģ�鲻����preds,�����ڴ����break continue ���µĲ��ɴ����
			if (pred_begin(smBB) == pred_end(smBB)) {
				lB.SetInsertPoint(smBB->getPrevNode());
				smBB->eraseFromParent();
				noPreds = true;
				break;
			}
		}
	}

	auto BB2 = lB.GetInsertBlock();
	endBB->moveAfter(BB2);
	
	if (iterBB) {
		iterBB->moveBefore(endBB);

		//no break or continue �Զ���ת
		if (!bkOrCtBB && !noPreds) {
			lB.CreateBr(iterBB);
		}
	}
	else {
		if (!bkOrCtBB && !noPreds) {
			lB.CreateBr(condBB);
		}
	}

	//TODO ����Ƿ�����ѭ�� �������벻������
	
	//�ص�����BB
	lB.SetInsertPoint(endBB);

	if (G_DEBUG) {
		lDI.leaveScope();
	}

	return endBB;
}
