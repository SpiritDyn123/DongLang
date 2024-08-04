 void fff(int a, int* p, int arr1[], int arr2[][4] = 0) {
	//a = *p;
	//a = *arr1;
	a = **arr2;

}

 int getV() {}
 int* getPtr1() {}
 int** getPtr2() {}

 typedef int(*PARR)[5];
 int main() {
	int a;
	int* p;
	int** pp;

	int arr1[3];
	int arr2[3][4];
	PARR parr;

	//a = *pp[1];
	//a = *arr2[1];
	//a = **parr;
	//a = parr[1][2];

	//a = (*pp)[1];
	//a = (*arr2)[1];

	**pp = a;
	pp[1][2] = a;
	//fff(a, p, arr1);
}