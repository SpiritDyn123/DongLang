#pragma once

#include <gflags/gflags.h>

DECLARE_string(in);
DECLARE_string(out);
DECLARE_string(otype);

void initFlags(int argc, char** argv);