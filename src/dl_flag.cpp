#include "include/dl_flag.h"
#include <iostream>
using namespace std;

DEFINE_string(in, "tmp.dl", "input dl file");
DEFINE_string(out, "", "output file");
DEFINE_string(otype, "exe", "output dl file type: ll,asm,exe");
DEFINE_bool (fpic, false, "link fpic");
DEFINE_bool(fpie, true, "link fpie");



static bool validatorIn(const char* flag, const string& value) {
	if (value == "") {
		cout << "validator input file empty" << endl;
		return false;
	}

	return true;
}

static bool validatorOType(const char* flag, const string& value) {
	if (value != "ll" && value != "asm" && value != "exe") {
		cout << "validator otype:" << value << " invalid" << endl;
		return false;
	}

	return true;
}

DEFINE_validator(in, validatorIn);
DEFINE_validator(otype, validatorOType);

void initFlags(int argc, char** argv) {
	gflags::ParseCommandLineFlags(&argc, &argv, true);
	if (FLAGS_out == "") {
		int index = FLAGS_in.find_last_of('.');
		if (index >= 0) {
			FLAGS_out = FLAGS_in.substr(0, index);
		}

		if (FLAGS_otype == "ll") {
			FLAGS_out += ".ll";
		}
		else if (FLAGS_otype == "asm") {
			FLAGS_out += ".S";
		}
		else if (FLAGS_otype == "exe") {
			FLAGS_out = "dl.out";
		}
	}
}