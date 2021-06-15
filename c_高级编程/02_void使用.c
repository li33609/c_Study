#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// void使用
// 1.无类型,不可以通过void创建变量
// 2.用途：限定函数返回值，限定函数参数

void func()
{
	return 10;
}

void test01()
{
	printf("%d\n", func());
}

int main()
{
	test01();

	system("pause");
	return 0;
}