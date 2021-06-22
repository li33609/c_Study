#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


// calloc 堆区申请空间，把其中值置位0
void test01()
{
	// malloc不会进行清0
	// int* p = malloc(sizeof(int) * 5);

	// calloc(个数, 类型)
	int* p = calloc(5, sizeof(int));

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

// realloc 重新分配内存，追加大小
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

	// realloc(原空间的首地址， 重新分配内存的大小)
	p = realloc(p, sizeof(int) * 10);
	printf("%d\n", p);
}


int main()
{
	test02();

	system("pause");
	return 0;
}