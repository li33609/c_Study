#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int* func()
{
	int a = 10;

	return &a;
}


void test01()
{
	int *p = func(); // Ұָ��, ֮ǰ��ָ���Ѿ����ͷ�

	printf("%d\n", *p);
	printf("%d\n", *p);
}

char* func01()
{
	char buf[] = "hello world";

	return buf;
}

void test02()
{
	char* p = func01(); // Ұָ��, ֮ǰ��ָ���Ѿ����ͷ�

	printf("buf=%s\n", p);
}


int main()
{
	test02();

	system("pause");
	return 0;
}