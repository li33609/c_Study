#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


typedef struct person
{
	char a;
	int b;
}Teacher;

typedef struct person02
{
	char a;
	int b;
	Teacher c;
}Teacher02;

void test01()
{
	Teacher t1;
	Teacher* p1 = &t1;

	printf("结构体偏移量%d。\n", (int)&(p1->b) - (int)p1);
	printf("结构体偏移量%d。\n", offsetof(Teacher, b));
}

void test02()
{
	Teacher t1 = {'a', 1000};
	Teacher* p1 = &t1;

	printf("b的值为%d。\n", *(int *)((char *)p1 + offsetof(Teacher, b)));
	printf("b的值为%d。\n", *(int*)((int *)p1 + 1));
}

void test03()
{
	Teacher02 t1 = { 'a', 1000, 'b', 2000 };
	Teacher* p1 = &t1;

	printf("结构体c中b的值为%d。\n", *(int *)((char *)p1+offsetof(Teacher02, c)+offsetof(Teacher, b)));
	
}


int main()
{
	test03();

	system("pause");
	return EXIT_SUCCESS;
}