#pragma once

#include <gflags/gflags.h>
#include "backend/GenBase.h"

DECLARE_string(in);
DECLARE_string(out);
DECLARE_string(otype);
DECLARE_bool(fpic);
DECLARE_bool(fpie);

using GenType = GenBase::emGenType;

extern GenType inType;
extern GenType outType;

void initFlags(int argc, char** argv);