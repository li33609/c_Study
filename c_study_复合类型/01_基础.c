#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 定义一个结构体数据类型
// 关键字 struct 代表这个是个结构体类型
// struct 为关键字,stu为名字,{}中为结构体成员,可以为任意类型
// 定义结构体类型需要;
// 结构体没空间，不可以给结构体赋值
struct stu
{
	int id;
	int age;
	char name[128];
} a, b; // 定义类型时，同时定义了两个结构体变量

struct stu c; // 定义时另一种方式

int main()
{
	// struct stu d = {1, 20, "lishijie"}; // 初始化值
	// struct stu d = { .age =  "lishijie" }; // 部分原素初始化值，其它元素为0
	// 访问结构体成员变量时，使用.域进行操作
	struct stu d;

	/*
	d.id = 1;
	d.age = 20;
	strcpy(d.name, "xiaoli");
	printf("%d %d %s\n", d.id, d.age, d.name);
	*/

	// 使用指向进行操作->
	(&d)->id = 2;
	(&d)->age = 20;
	strcpy((&d)->name , "zhangsan");
	printf("%d %d %s\n", (&d)->id, (&d)->age, (&d)->name);

	system("pause");
	return 0;
}