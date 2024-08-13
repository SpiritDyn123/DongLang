int gbInit();

int g_a = 1;
int g_b = gbInit();
int g_arr[] = { 1,2,3 };
int gbInit() {
	return 2;
}

void fff(int a, int* pa) {
	*pa = a + *pa;
}

 int main() {
	 int a = 1;
	 int* p = &a;
	 fff(a, p);
	//fff(a, p, arr1);
}