#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void test01()
{
	int a = 10; // ջ�� �ߵ�ַ
	int b = 10;
	int c = 10;
	int d = 10; // ջ�� �͵�ַ

	printf("%d\n", &a);
	printf("%d\n", &b);
	printf("%d\n", &c);
	printf("%d\n", &d);
}

// �ڴ�Ĵ洢��ʽ
void test02()
{
	int a = 0x11223344;
	char* p = &a;

	printf("%x\n", *p); // 44 �͵�ַ
	printf("%x\n", *(p + 1)); // 33 �ߵ�ַ
}


int main()
{

	test01();

	system("pause");
	return 0;
}