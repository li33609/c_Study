#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


typedef struct Student
{
	char name[64];
	int age;
}STUDENT01;

void test01()
{
	STUDENT01 person1 = { "张三", 18 };
	STUDENT01 person2 = { "李四", 20 };

	printf("姓名:%s, 年龄:%d\n", person1.name, person1.age);
	printf("姓名:%s, 年龄:%d\n", person2.name, person2.age);
}

typedef struct Person
{
	char *name;
	int age;
}STUDENT02;

void test02()
{
	STUDENT02 p1;
	p1.name = malloc(sizeof(char) * 64);
	strcpy(p1.name, "Tom");
	p1.age = 16;

	STUDENT02 p2;
	p2.name = malloc(sizeof(char) * 64);
	strcpy(p2.name, "Jerry");
	p2.age = 20;

	// p1 = p2;

	// 手动赋值
	if (p1.name != NULL)
	{
		free(p1.name);
		p1.name = NULL;
	}
	p1.name = malloc(strlen(p2.name) + 1);
	strcpy(p1.name, p2.name);
	p1.age = p2.age;

	printf("姓名:%s, 年龄:%d\n", p1.name, p1.age);
	printf("姓名:%s, 年龄:%d\n", p2.name, p2.age);

	if (p1.name != NULL)
	{
		free(p1.name);
		p1.name = NULL;
	}
	if (p2.name != NULL)
	{
		free(p2.name);
		p2.name = NULL;
	}
}


int main()
{
	test02();

	system("pause");
	return 0;
}