#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


// 按位取反
void test01()
{
	int num = 2;

	printf("~num=%d\n", ~num);
}

// 按位与
void test02()
{
	// 判断奇偶性
	int num = 124;

	if ((num & 1) == 0)
	{
		printf("偶数！\n");
	}
	else
	{
		printf("奇数！\n");
	}
}

//按位或
void test03()
{
	int num1 = 3;
	int num2 = 5;

	printf("num1 | num2 = %d\n", num1 | num2);
}

// 按位异或
void test04()
{
	// 数字交换
	int a = 8;
	int b = 9;

	// 方法 1
	/*a = a ^ b;
	b = a ^ b;
	a = a ^ b;*/

	// 方法 2
	a = a + b;
	b = a - b;
	a = a - b;

	printf("a=%d,b=%d\n", a, b);
}

// 左移,<<,左移几位,原数乘以2的几次方
// 右移相反,>>
void test05()
{
	int a = 8;
	
	printf("a=%d\n", a <<= 3);
}


int main()
{
	test05();

	system("pause");
	return 0;
}
