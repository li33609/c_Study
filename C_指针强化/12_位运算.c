#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


// 按位取反
void test01()
{
	int num = 2;

	printf("~num=%d\n", ~num);
}


int main()
{
	test01();

	system("pause");
	return 0;
}