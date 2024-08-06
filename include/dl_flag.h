#pragma once

#include <gflags/gflags.h>

DECLARE_string(in);
DECLARE_string(out);
DECLARE_string(otype);
DECLARE_bool(fpic);
DECLARE_bool(fpie);

void initFlags(int argc, char** argv);