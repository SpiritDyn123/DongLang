 void fff(int a, int* p, int arr1[], int arr2[][4] = 0) {
	//a = *p;
	//a = *arr1;
	 if (arr2 == 0) {
		 return;
	 }
	 else {
		 a += 2;
	 }

	 a += 1;

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
	int* parr2[5];


	a = **parr2;
	a = parr2[1][2];
	a = *parr2[1];
	a = (*parr2)[1];
	*parr2[1] = a;
	(*parr2)[1] = a;


	//fff(a, p, arr1);
}