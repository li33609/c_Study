#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Person
{
	char name;
	int age;
	char name2;
	int num;
}PERSON;


// 变量修改方式
void test01()
{
	PERSON pr = { "a", 14,"b", 15 };
	pr.num = 100;
	char* p = &pr;

	printf("num=%d\n", *(int *)(p + 12));
	printf("num=%d\n", *(int *)((int *)p + 3));

}
// 1.直接修改
// 2.间接修改
void test02()
{
	int a = 10;
	int* p = &a;

	*p = 100;
	printf("a = %d\n", p);
}


int main()
{
	test01();

	system("pause");
	return 0;
}