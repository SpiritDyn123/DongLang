#include <iostream>
#include "llvm/Pass.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
using namespace std;
using namespace llvm;

class selfPass : public PassInfoMixin<selfPass> {

};

class XXX {

};
int main() {
	selfPass obj;
	cout << obj.name().str() << endl;
	cout << getTypeName<XXX>().str() << endl;
}