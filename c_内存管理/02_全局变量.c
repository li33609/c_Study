#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int num11; // 全局变量无法释放, 作用于整个工程
static int num22;// 静态全局变量不能声明，也不能在其他文件使用


void fun1()
{
	num11 = 11;
}


int main()
{
	printf("%d\n", num11);
	fun1();
	printf("%d\n", num11);
	
	system("pause");
	return 0;
}