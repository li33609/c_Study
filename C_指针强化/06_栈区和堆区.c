#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


// calloc ��������ռ䣬������ֵ��λ0
void test01()
{
	// malloc���������0
	// int* p = malloc(sizeof(int) * 5);

	// calloc(����, ����)
	int* p = calloc(5, sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

// realloc ���·����ڴ棬׷�Ӵ�С
void test02()
{
	int* p = malloc(sizeof(int) * 5);

	for (int i = 0; i < 5; i++)
	{
		p[i] = i + 1;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
	printf("%d\n", p);

	// realloc(ԭ�ռ���׵�ַ�� ���·����ڴ�Ĵ�С)
	p = realloc(p, sizeof(int) * 10);
	printf("%d\n", p);
}


int main()
{
	test02();

	system("pause");
	return 0;
}