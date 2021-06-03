#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void fun()
{
	static int num = 1; // main 函数运行之前就开辟了空间,只要程序不终结，一直执行

	num += 1;

	printf("%d\n", num);
}

int main()
{
	int a = 0;

	if (1)
	{
		int b = 1;
		printf("%d\n", a);
	}
	// printf("%d\n", a); erro b在大括号内使用
	fun();
	fun();

	system("pause");
	return 0;
}