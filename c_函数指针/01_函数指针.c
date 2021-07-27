#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


void func(int a, char b)
{
	printf("hello world!\n");
}

void func1()
{
	printf("hello world1!\n");
}

void func2()
{
	printf("hello world2!\n");
}

void func3()
{
	printf("hello world3!\n");
}

void test01()
{
	// 先定义函数类型，在通过类型定义指针变量
	typedef void(FUNC_TYPE)(int, char); // 定义出一个函数类型，返回值是void，形参是(int, char)

	FUNC_TYPE* pFunc = func;

	pFunc(10, "a");
}

void test02()
{
	// 先定义函数指针的类型，通过类型定义函数指针变量
	typedef void(*FUNC_TYPE)(int, char);

	FUNC_TYPE pFunc = func;
	pFunc(10, "a");
}

void test03()
{
	// 直接定义函数变量
	void(*p)(int, char) = func;
	p(30, "A");
}

// 函数指针数组
void test04()
{
	void(*func_array[3])();

	func_array[0] = func1;
	func_array[1] = func2;
	func_array[2] = func3;

	for (int i = 0; i < 3; i++)
	{
		func_array[i]();
	}
}

int main()
{
	test04();

	system("pause");
	return 0;
}