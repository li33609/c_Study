#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

#pragma pack (show) // 查看对齐模数的值为8 可以改成2的n次方

// 内存对齐
// 1.从0开始计算偏移量
// 2.该属性的大小与 对齐模数比 取最小值的 整数倍上
// 当所有属性计算完比后，整体二次偏移，将计算结果 扩充到 与对齐模数比 这个结构体中最大数据类型 的整数倍

typedef struct person
{
	int a; // 0~3
	char b; // 4~7
	double c; // 8~15
	float d; // 16`19 
}Teacher;


void test01()
{
	printf("结构体的大小为：%d\n", sizeof(Teacher));
}


int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}