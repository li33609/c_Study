#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 宏函数,在预编译阶段做了宏替换
// 将频繁短小的函数， 封装为宏函数，避免了出栈入栈的时间
// 优点：以空间换时间(执行效率高)
#define MY_ADD(x, y) ((x) + (y))

void test01()
{
	int a = 20;
	int b = 30;

	printf("a+b=%d\n", MY_ADD(a, b) * 6);
}


int main()
{

	test01();

	system("pause");
	return 0;
}