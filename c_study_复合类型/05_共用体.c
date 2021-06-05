#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 共用体
union mi
{
	char a;
	short b;
	int c;
};


int main01()
{
	union mi tmp;

	tmp.a = 0x01;
	tmp.c = 0x01020304;
	tmp.b = 0x0a0b;

	printf("%x\n", tmp.b);
	printf("%x\n", tmp.a);
	printf("%x\n", tmp.c);
	printf("%d\n", sizeof(tmp));

	system("pause");
	return 0;
}


union abc
{
	char buf[2];
	short b;
};


// 验证大小端
int main()
{
	union abc tmp;

	tmp.b = 0x0102;
	if (tmp.buf[0] == 0x01)
	{
		printf("大端\n");
	}
	else
	{
		printf("小端\n");
	}

	system("pause");
	return 0;
}

