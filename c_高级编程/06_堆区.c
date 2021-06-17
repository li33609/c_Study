#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int * func01()
{
	int *p = malloc(sizeof(int) * 5);

	if (p == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < 5; i++)
	{
		p[i] = 10 + i;
	}

	return p;
}

void test01()
{
	int* p = func01();

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");

	free(p);
	p = NULL;
}


void* func02(char **pp)
{
	char* tmp = NULL;
	tmp = malloc(100);
	memset(tmp, 0, 100);
	strcpy(tmp, "hello world");

	*pp = tmp;
}

void test02()
{
	char* p = NULL;
	func02(&p); // 同级指针分配失败， 利用高级指针进行分配

	printf("p = %s\n", p);

	free(p);
}


int main()
{
	test02();

	system("pause");
	return 0;
}