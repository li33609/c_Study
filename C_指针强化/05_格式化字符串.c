#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


void test01()
{
	char buf[1024] = {0};
	memset(buf, 0, 1024);

	// ����1 ��ʽ����Ŀ���ַ���
	// ����2 ��ʽ����ʽ
	// ����3.. ��ʽ���еĲ���
	sprintf(buf, "hello %s", "LiSi");
	printf("%s\n", buf);
}

void test02()
{
	char buf[1024] = { 0 };
	memset(buf, 0, 1024);

	// ����1 ��ʽ����Ŀ���ַ���
	// ����2 ��ʽ����ʽ
	// ����3.. ��ʽ���еĲ���
	sprintf(buf, "hello %s", "LiSi");
	printf("%s\n", buf);
}


int main()
{
	test01();

	system("pause");
	return 0;
}