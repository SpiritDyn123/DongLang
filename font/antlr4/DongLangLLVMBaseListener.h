#pragma once

#include "font/antlr4/gen/DongLangBaseListener.h"
#include "font/ast/DongLangBaseAST.h"
using namespace antlr4;

#define GET_LOC_DATA(ctx) \
	auto sToken = ctx->getStart();\
	int curLine = sToken->getLine() - defaultLine - 1; \
	string codeLineTxt = getLineTxt(ctx, curLine, defaultLine); \
	if(curLine <= 0) curLine += defaultLine + 1; \
	CodeLocData locData(curLine,\
		sToken->getCharPositionInLine(),\
		codeLineTxt);\

class DongLangLLVMBaseListener {
public:
	DongLangLLVMBaseListener(int defaultLine): defaultLine(defaultLine) {}

public:
	static string getLineTxt(antlr4::ParserRuleContext* ctx, int line, int defaultLine);
public:
	int defaultLine;
};
