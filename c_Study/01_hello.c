#include<stdio.h>
#include<stdlib.h>

// 定义宏变量
#define PI 3.14

int main01()
{
	int a;
	int b;
	int c;

	// 汇编
	_asm
	{
		mov a, 3
		mov b, 4
		mov eax, a
		add eax, b
		mov c, eax
	}

	printf("%d\n", c);


	printf("hellow world %lf\n", PI);
	system("pause");

	return 0;
}

int main02()
{
	int a = 4;
	int b = 3;
	int c;

	c = a + b;

	printf("%d\n", c);

	system("pause");

	return 0;
}

int My_max(int a, int b)
{
	return a > b ? a : b;
}

