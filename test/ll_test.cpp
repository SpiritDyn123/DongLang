 void fff(int a, int* p, int arr1[], int arr2[][4] = 0) {
	//a = *p;
	//a = *arr1;
	a = **arr2;

}

 int getV() {}
 int* getPtr1() {}
 int** getPtr2() {}

 int main() {
	int a;
	int* p;
	int** pp;

	int arr1[3];
	int arr2[3][4];

	a = **arr2;//
	fff(a, p, arr1);
}