#include "DongLangLLVMBaseListener.h"
#include "include/dl_flag.h"
#include <fstream>  
#include <sstream>
#include <string>  
#include "include/default_lib.h"
using namespace std;

string DongLangLLVMBaseListener::getLineTxt(antlr4::ParserRuleContext* ctx, int line, int defaultLine) {
	string lineStr = "";
	istream *input;
	if (line <= 0) {
		line += defaultLine + 1;
		static stringstream defaultLibCtx(defaultLibContent);
		input = &defaultLibCtx;
	}
	else {
		static ifstream file(FLAGS_in, ios::in);
		if (!file.is_open()) {
			return "";
		}

		input = &file;
	}

	//ÉèÖÃÆô¶¯ÐÐ
	input->seekg(0, ios_base::beg);
	for (; line > 0 && getline(*input, lineStr); line--) {
	}
	
	return lineStr;
}