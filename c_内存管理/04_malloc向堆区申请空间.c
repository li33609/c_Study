#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// malloc返回的(void *)类型需要进行类型转化
int main()
{
	int *p = (int *)malloc(sizeof(int) * 10);
	memset(p, 0, sizeof(int) * 10);
	free(p); // 释放内存 malloc申请的空间不能释放两次

	// *p = 1000;

	for (int i = 0; i < 100; i++)
	{
		printf("%d ", *(p + i));
	}
	
	system("pause");
	return 0;
}