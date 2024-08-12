
class A {
public:
	A() {}
	A(int a):a(a) {}
	void add(int b) {
		a += b;
	}

	virtual void ff() {}
private:
	int a;
	int b;
};

void fff(int a, A o1, A* po1) {
	o1.add(a);
	po1->add(a);
}

 int main() {
	 int a;
	 A o1;
	 A o2(1);

	 fff(a, o1, &o2);
	//fff(a, p, arr1);
}