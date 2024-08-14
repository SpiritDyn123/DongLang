### һ�����
-------------
#### ʹ��**Antlr4**(Ҳ����ʹ��flex&bison)��**LLVM16**������һ���򵥵��� **C++** ���ԣ�Դ��ɹ��ο�ѧϰ��
  - [Antlr4](https://github.com/antlr/antlr4.git)
  - [LLVM](https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/index.html)
  - [gflag](https://github.com/gflags/gflags.git)
  - flex&bison
  - Visual Studio 2022�������漴�ɣ�
  - wsl2 ubuntu
  - cmake

### ����Դ�밲װ
---------------
#### 1. github[����Դ��](https://github.com/SpiritDyn123/DongLang.git)
#### 2. ��װCMakeLists.txt����ȱ�ٵĿ���а�װ
#### 3. �����������Է���
- **wsl** ��Ҫ��visualstudio �в鿴����linuxԶ�̶˿ڣ�ʹ��vs��Զ�̵��Կ���
    - ����wsl2 ����ubuntu20ϵͳ
	- ����ubuntu������sshd�Ķ˿�Ϊ2232 ������sshd
	- ���ִ�и�Ŀ¼�µ�WslSSH.bat������ӳ��wsl��ssh�˿ڵ�127.0.0.1����

-  **linux** ��ֱ��cmake��gdb���Լ���
    - cmake .
	- make
	- ./DongLangִ��

- ****����ʹ��vsԶ�̿�����Ч�ʸߣ����������ʹ��cmake��vsԶ�̵��Ժ�����������****

### �����﷨ѧϰ
--------------------
#### ʾ������
- [type](./test/type_test.dl)

    ![type](./test/type.png)
- [function](./test/function_test.dl)

    ![function](./test/function.png)
- [if_for](./test/cond_if_for_test.dl)

    ![cond_if_for](./test/cond_if_for.png)


#### 1.�������� int float byte bool string
```
int a, b = 1; // int ���� ����bĬ��ֵ1
byte ba = 1;
float fa = 1.2;
bool  gg = (true|false); 
string str = "hello world"; // ��c char *
	
```
#### 1.ָ�������
```
int * p1, p2; //һ��ָ�� p1 p2,ע�����ﲻͬ��c��p2�����ͣ�
int **pp1,pp2;

//����:������������ʾ��ά���飬��c�෴
int[] arr = {1,2};					//c: int arr[]
int[3][2] arr2;						 //c: int arr2[][3]
int [2][] arr3 = {{1,2},{2,2}};		 //c: int arr3[][2]

//����ָ��
int*[3] arrp;		 //c: int* arrp[3]
int[3]* parr;		 //c: int (*parr)[3]

```
#### 2.�������߼�����
```
//��������
a = 1+b;
a = a-b;
a = a/b;
a = c/d;
a = a ^ b;
a = a &b;
a = a | b;
a += b;
a -= 2;
a *= 3;
a /= e;
 .
 .
 .

 //�߼�����

 a || b
 a && b
!a
a > b
a < b
a >= b
a <= b
a == b
a != b

```

#### 3.if else
```
// else if �� elif������
if(int a = 1;a > 1) {

}
else if(a || b) {

} else if( a > b || a && b) {

} elif(int c = 1) {

} else {

}


```
#### 4.for
```
1. for(true) {
		if(xxx) {
			break;
		}
		continue;
	}

2. for(;;) <==> for(true)

3. for(int i= 0, j =1;i >= 1 && j < 1;i++, j--) {

}
```

#### 5.function
```
1. �������巽ʽ
func int fff(int a, int b) {
	return a+b;
}

2.Ĭ��ֵ������
func int f1(int a) {
}

func int f1(int a, int b) {
}

func int f1(float a = 5.1) {
}

3.����������ʱ��֧��
func int f1(int a, ...) {
}
```
#### 6.TODO templateģ��

#### 7.TODO class��

### �ġ�����
---------------------
1. �ļ����ͣ�
- dl�����ļ���׺
- ll��׺��
- s����׺��asm)
-  o object�ļ���׺��
- ��ִ�к�׺�Լ�ָ��Ĭ�ϣ�dl.out)

2.����ll�ļ�
```
./DongLang -in xxx.dl -otype ll
```
3.����asm�ļ�
```
./DongLang -in xxx.dl -otype asm
./DongLang -in xxx.ll -otype asm
```
4.����object�ļ�
```
./DongLang -in xxx.dl -otype obj
./DongLang -in xxx.ll -otype obj
./DongLang -in xxx.s -otype obj
```
5.���ɿ�ִ���ļ�
```
./DongLang -in xxx.dl -otype exe
./DongLang -in xxx.ll -otype exe
./DongLang -in xxx.s -otype exe
./DongLang -in xxx.o -otype exe
-otype Ĭ�Ͼ���exe ���Բ�д
```
6��TODO֧�־�̬��