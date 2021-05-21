#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int main()
{
	int num;
	// signed有符号数（正数和负数）
	signed char abc_123;
	// extern表示编辑器有变量（声明）没有定义
	// 声明变量没有空间
	extern short b;
	// const 修饰的变量不能更改
	const int a;


	num = 100;

	printf("num=%d\n", MAX);

	system("pause");

	return 0;
}