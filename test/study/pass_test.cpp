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

template<typename T> class Name {
public:
	void print() {
		cout << __PRETTY_FUNCTION__ << endl;
	}
};
int main() {
	selfPass obj;
	cout << obj.name().str() << endl;
	Name<int>().print();
	cout << getTypeName<XXX>().str() << endl;
}