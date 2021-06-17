#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// void使用
// 1.无类型,不可以通过void创建变量
// 2.用途：限定函数返回值，限定函数参数
// 3.void * ，万能指针
int func()
{
	return 10;
}

void test01()
{
	printf("%d\n", func());
}

void test02()
{
	void* p = NULL;

	int* pInt = NULL;
	char* pChar = NULL;

	pInt = (int *)pChar; // error报错，不同类型不能赋值,需要进行类型转换

	pChar = p; // 不用进行强转
}


int main()
{
	test01();

	system("pause");
	return 0;
}