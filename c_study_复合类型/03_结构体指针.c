#define _CRT_SECURE_NO_WARNINGS£»
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct stu
{
	int id;
	int age;
	char name[128];
} ;

int main01()
{
	/*
	struct stu a;

	// struct stu* p; // pÊÇÒ°Ö¸Õë,error
	struct stu* p = &a;
	*/

	struct stu* p = malloc(sizeof(struct stu));
	
	p->id = 100;
	p->age = 20;
	strcpy(p->name, "lisi");

	printf("%d %d %s\n", p->id, p->age, p->name);

	system("pause");
	return 0;
}