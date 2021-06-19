#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


//解引用
void test01() {

	//定义指针
	int* p = NULL;
	//指针指向谁，就把谁的地址赋给指针
	int a = 10;
	p = &a;
	*p = 20;//*在左边当左值，必须确保内存可写
	//*号放右面，从内存中读值
	int b = *p;
	

	printf("a:%d\n", a);
	printf("*p:%d\n", *p);
	printf("b:%d\n", b);
}

// 指针步长
void test02()
{
	char* p = NULL;

	printf("%d\n", p);
	printf("%d\n", p + 1);

	double* p1 = NULL;

	printf("%d\n", p1);
	printf("%d\n", p1 + 1);
}

// 解应用, 步长应用
void test03()
{
	char buf[1024] = { 0 };
	int a = 1000;

	memcpy(buf, &a, sizeof(int));
	char* p = buf;

	printf("%d\n", *(int *)p);
}

typedef struct Person
{
	char a;
	int b;
	char buf[64];
	int d;
}PERSON;


void test04()
{
	PERSON student = {'a', 10, "hello world", 1000};
	char* p = &student;
	
	printf("d的偏移量为：%d\n", offsetof(PERSON, d));

	printf("d的值为：%d\n", *(int *)(p + offsetof(PERSON, d)));
}


int main()
{
	test04();

	system("pause");
	return 0;
}