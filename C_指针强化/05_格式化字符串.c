#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


void test01()
{
	char buf[1024] = {0};
	memset(buf, 0, 1024);

	// 参数1 格式化后目标字符串
	// 参数2 格式化形式
	// 参数3.. 格式化中的参数
	sprintf(buf, "hello %s", "LiSi");
	printf("%s\n", buf);
}

void test02()
{
	char buf[1024] = { 0 };
	memset(buf, 0, 1024);

	// 参数1 格式化后目标字符串
	// 参数2 格式化形式
	// 参数3.. 格式化中的参数
	sprintf(buf, "hello %s", "LiSi");
	printf("%s\n", buf);
}


int main()
{
	test01();

	system("pause");
	return 0;
}