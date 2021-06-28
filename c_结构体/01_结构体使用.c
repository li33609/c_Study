#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


typedef struct Student
{
	char name[64];
	int age;
	int id;
}STUDENT;

void test01()
{
	// 在栈上
	STUDENT num1 = {"张三", 18, 1};
	STUDENT* num2 = malloc(sizeof(STUDENT));

	// 在堆上分配
	strcpy(num2->name, "李四");
	num2->age = 18;
	num2->id = 2;

	free(num2);
}

void print_struct(STUDENT* p, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("名字：%s, 年龄：%d, ID：%d\n", p[i].name, p[i].age, p[i].id);
	}
}

// 结构体变量数组
void test02()
{
	// 在栈上
	STUDENT p[] = {
		{"张三", 16, 1},
		{"李四", 17, 2},
		{"王五", 18, 3}
	};
	int len = sizeof(p) / sizeof(p[0]);

	print_struct(p, len);
}

void test03()
{
	// 在堆区
	STUDENT* p = malloc(sizeof(STUDENT) * 3);

	for (int i = 0; i < 3; i++)
	{
		sprintf(p[i].name, "name_%d", i+1);
		p[i].age = i + 18;
		p[i].id = i + 1;
	}

	print_struct(p, 3);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}


int main()
{
	test03();

	system("pause");
	return 0;
}