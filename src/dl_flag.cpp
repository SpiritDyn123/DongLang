#include "include/dl_flag.h"
#include <iostream>
using namespace std;

DEFINE_string(in, "tmp.dl", "input dl file");
DEFINE_string(out, "", "output dl file");
DEFINE_string(otype, "ll", "output dl file type: ll,exe");

static bool validatorOType(const char* flag, const string& value) {
	if (value != "ll" && value != "exe") {
		cout << "validator otype:" << value << " invalid" << endl;
		return false;
	}

	return true;
}

DEFINE_validator(otype, validatorOType);

void initFlags(int argc, char** argv) {
	gflags::ParseCommandLineFlags(&argc, &argv, true);
}