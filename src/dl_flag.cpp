#include "include/dl_flag.h"
#include <iostream>
#include <map>

using namespace std;

DEFINE_string(in, 
#ifdef IN_DEV
	"tmp.dl", 
#else
	"",
#endif
	"input dl file");
DEFINE_string(out,
	"",
	"output file");
DEFINE_string(otype, "exe", "output dl file type: ll,asm,obj,exe; gen library use system tools: ar,cmake...");
DEFINE_bool (fpic, false, "link fpic");
DEFINE_bool(fpie, true, "link fpie");
DEFINE_bool(g, false, "compiler gdb");

GenType inType = GenType::genType_invalid;
GenType outType = GenType::genType_invalid;

struct genTypeInfo {
	GenType		gt;
	uint8_t		opr;
	genTypeInfo(GenType gt, uint8_t opr) :gt(gt),
		opr(opr) {}
};

const uint8_t genTypeInfoOpr_input = 1;
const uint8_t genTypeInfoOpr_output = 1 << 1;
const uint8_t genTypeInfoOpr_io = genTypeInfoOpr_input | genTypeInfoOpr_output;

using MGenType = map<string, genTypeInfo>;
using MGenTypeIter = MGenType::iterator;

MGenType mGenTypes = MGenType{
	{ "dl",		{ GenType::genType_dl,  genTypeInfoOpr_input}},
	{ "ll",		{ GenType::genType_ll,  genTypeInfoOpr_io}},
	{ "asm",	{ GenType::genType_asm, genTypeInfoOpr_output}},
	{ "s",		{ GenType::genType_asm, genTypeInfoOpr_input}},
	{ "obj",	{ GenType::genType_obj, genTypeInfoOpr_output}},
	{ "o",		{ GenType::genType_obj, genTypeInfoOpr_input}},
	{ "exe",	{ GenType::genType_exe, genTypeInfoOpr_output}},
};

static bool validatorIn(const char* flag, const string& value) {
	int index = value.find_last_of('.');
	if (index < 0) {
		errs() << "validator input file name error\n";
		return false;
	}

	string suffix = value.substr(index+1);
	MGenTypeIter iter = mGenTypes.find(suffix);
	if (iter == mGenTypes.end() || !(iter->second.opr & genTypeInfoOpr_input)) {
		errs() << "validator input file formt error\n";
		return false;
	}
	
	inType = iter->second.gt;
	return true;
}

static bool validatorOType(const char* flag, const string& value) {
	MGenTypeIter iter = mGenTypes.find(value);
	if (iter == mGenTypes.end() || !(iter->second.opr & genTypeInfoOpr_output)) {
		errs() << "validator otype:" << value << " invalid\n";
		return false;
	}

	outType = iter->second.gt;
	return true;
}

DEFINE_validator(in, validatorIn);
DEFINE_validator(otype, validatorOType);

void initFlags(int argc, char** argv) {
	gflags::ParseCommandLineFlags(&argc, &argv, true);
	if (inType >= outType) {
		errs() << "input file:" << FLAGS_in << " already is " << FLAGS_out << " file!!!\n";
		exit(1);
	}

	if (FLAGS_out == "") {

	}
}