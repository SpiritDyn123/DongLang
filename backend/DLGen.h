#pragma once

#include "GenBase.h"

using namespace std;
using namespace llvm;

class DLGen : public GenBase {
public:
	virtual emGenType genType() override { return genType_dl; }
protected:
	virtual bool gen(GenBase* srcGen, bool final) override;

};