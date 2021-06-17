#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MY_ADD(x, y) x + y

void test01()
{
	int a = 20;
	int b = 30;

	printf("a+b=%d\n", MY_ADD(a, b));
}


int main()
{

	test01();

	system("pause");
	return 0;
}