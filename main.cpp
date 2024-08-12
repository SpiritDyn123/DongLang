#include <iostream>
#include "font/ast/DongLangBaseAST.h"
#include "include/dl_flag.h"
#include "backend/GenBase.h"

using namespace antlr4;
using namespace std;


int main(int argc, char** argv) {
	//cmd flags
	initFlags(argc, argv);

	auto outGen = createGen(outType);
	if (!outGen->genWrap(createGen(inType))) {
		errs() << "gen failed";
		exit(1);
	}

	return 0;
}