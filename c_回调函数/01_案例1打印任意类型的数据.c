#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


struct Person 
{
	char name[64];
	int age;
};

// 打印任意类型的数据
void my_print(void* data, void(* mp)(void *))
{
	mp(data);
}

void printInt(void* data)
{
	int* num = data;
	printf("%d\n", *num);
}

void printDouble(void* data)
{
	double* num = data;
	printf("%f\n", *num);
}

void printStruct(void* data)
{
	struct Person* num = data;
	printf("姓名:%s, 年龄:%d\n", num->name, num->age);
}

void test01()
{
	int a = 10;
	my_print(&a, printInt);

	double b = 3.14;
	my_print(&b, printDouble);

	struct Person student = { "aaa", 16 };
	my_print(&student, printStruct);
}


int main()
{
	test01();

	system("pause");
	return 0;
}