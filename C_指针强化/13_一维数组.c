#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


void test01()
{
	int a[6] = { 1, 2, 3, 4, 5 };
	int* p = a;

	printf("sizeof=%d\n", sizeof(a));
	printf("&a=%d\n", &a);
	printf("&a+1=%d\n", &a+1);

	p = p + 3;
	printf("p[0]=%d\n", p[0]);
	printf("p[-1]=%d\n", p[-1]);
}

void print_arr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr=%d\n", arr[i]);
	}
}

void test02()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);

	print_arr(arr, len);
}

// 数组指针的定义
// 1.先定义数组的类型，再通过类型定义出数组指针
void test03()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	typedef int(ARR_TYPE)[5]; // 定义ARR_TYPE名称的数组

	ARR_TYPE* arrP = &arr;
	for (int i = 0; i < 5; i++)
	{
		printf("arr=%d", (*arrP)[i]);
	}

}
// 2.直接定义为指针
void test04()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	typedef int(*ARR_TYPE)[5]; // 定义ARR_TYPE名称的数组

	ARR_TYPE* arrP = &arr;
	for (int i = 0; i < 5; i++)
	{
		printf("arr=%d", *arrP[i]);
	}
}

// 3.直接定义
void test05()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int (*p)[5] = &arr;

	for (int i = 0; i < 5; i++)
	{
		printf("arr=%d\n", (*p)[i]);
	}
}


int main()
{
	test05();

	system("pause");
	return 0;
}