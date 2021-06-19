#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void test01()
{
	int a = 10; // 栈低 高地址
	int b = 10;
	int c = 10;
	int d = 10; // 栈顶 低地址

	printf("%d\n", &a);
	printf("%d\n", &b);
	printf("%d\n", &c);
	printf("%d\n", &d);
}

// 内存的存储方式
void test02()
{
	int a = 0x11223344;
	char* p = &a;

	printf("%x\n", *p); // 44 低地址
	printf("%x\n", *(p + 1)); // 33 高地址
}


int main()
{

	test01();

	system("pause");
	return 0;
}