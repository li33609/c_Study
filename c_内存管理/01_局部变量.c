#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int a = 0;

	if (1)
	{
		int b = 1;
		printf("%d\n", a);
	}
	// printf("%d\n", a); erro b在大括号内使用

	system("pause");
	return 0;
}