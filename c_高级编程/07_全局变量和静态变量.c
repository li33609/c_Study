#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 静态变量
// 提前分配内存
// 作用于程序结束
// 默认属于内部链接属性，在当前文件夹使用
static int a = 10;

// 全局变量 
// 外部链接属性,作用于所有文件，使用时要提前声明
extern int b = 20;

// const修饰的常量,放在常量区，受到常量区保护
// 不能直接修改
const int c = 30;

void func()
{
	// const修饰的局部常量可以被修改，因为放在栈区
	// 伪常量
	const int d = 100;
	int* p = &d;
	*p = 10;

	printf("d = %d\n", d);
}

// 字符串常量共享, 字符串常量不可修改
void my_str()
{
	char* p1 = "hello world";
	char* p2 = "hello world";
	char* p3 = "hello world";
	char* p4 = "hello world";

	printf("%d\n", p1);
	printf("%d\n", p2);
	printf("%d\n", p3);
	printf("%d\n", p4);
}


int main()
{
	my_str();

	system("pause");
	return 0;
}