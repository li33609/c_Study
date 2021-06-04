#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 结构体数组
struct stu
{
	int id;
	int age;
	char name[128];
};

// 结构体套结构体
struct nuc
{
	// int id;
	// int age;
	int sex;
	struct stu s;
	// char name[128];
};


int main01()
{
	// 结构体数组定义
	struct stu num[5] = { {1, 20, "lisi"}, {2, 20, "zhangsan"}, {3, 20, "wangwu"}, 
						  {4, 20, "lisi"}, {5, 25, "lisi"} };
	
	for (int i = 0; i < sizeof(num) / sizeof(num[0]); i++)
	{
		printf("%d %d %s\n", num[i].id, num[i].age, num[i].name);
	}

	system("pause");
	return 0;
}

int main()
{
	struct nuc nuc;

	nuc.s.id = 1;
	nuc.s.age = 22;
	nuc.sex = 1;
	strcpy(nuc.s.name, "lisi");

	printf("%d %d %d %s\n", nuc.s.id, nuc.s.age, nuc.sex, nuc.s.name);

	system("pause");
	return 0;
}