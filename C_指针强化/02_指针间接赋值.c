#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


void test01()
{
	// 通过指针直接修改
	int a = 10;
	int* p = NULL;

	p = &a;
	*p = 20;
	printf("a=%d\n", a);
}

Change_Value(int *p)
{
	*p = 1000;
}

void test02()
{
	// 函数体间接修改
	int a = 10;

	Change_Value(&a);
	printf("a=%d\n", a);
}


int main()
{
	test02();

	system("pause");
	return 0;
}