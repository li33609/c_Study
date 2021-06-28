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
	// ��ջ��
	STUDENT num1 = {"����", 18, 1};
	STUDENT* num2 = malloc(sizeof(STUDENT));

	// �ڶ��Ϸ���
	strcpy(num2->name, "����");
	num2->age = 18;
	num2->id = 2;

	free(num2);
}

void print_struct(STUDENT* p, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("���֣�%s, ���䣺%d, ID��%d\n", p[i].name, p[i].age, p[i].id);
	}
}

// �ṹ���������
void test02()
{
	// ��ջ��
	STUDENT p[] = {
		{"����", 16, 1},
		{"����", 17, 2},
		{"����", 18, 3}
	};
	int len = sizeof(p) / sizeof(p[0]);

	print_struct(p, len);
}

void test03()
{
	// �ڶ���
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