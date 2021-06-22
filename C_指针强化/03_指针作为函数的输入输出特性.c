#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


Set_Value(char *p)
{
	strcpy(p, "hello world");
}

// 输入特性(栈区)
void test01()
{
	char buf[1024] = { 0 };

	Set_Value(buf);
	printf("buf=%s\n", buf);
}

set_value(char *p)
{
	memset(p, 0,  128);
	strcpy(p, "hello world");
}

// 堆区
void test02()
{
	char* p = malloc(sizeof(char) * 128);;

	memset(p, 0, 128);
	strcpy(p, "hello world");


	printf("p=%s\n", p);

	free(p);
	p = NULL;
}

void allocate_Space(char **p)
{
	char* tmp = malloc(sizeof(char) * 128);

	memset(tmp, 0, 128);
	strcpy(tmp, "hello world");

	*p = tmp;
}

// 输出
void test03()
{
	char* p = NULL;

	allocate_Space(&p);
	printf("%s\n", p);

	free(p);
	p = NULL;
}


int main()
{
	test03();

	system("pause");
	return 0;
}