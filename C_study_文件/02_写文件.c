#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char b[] = "hello";

	FILE* fp = fopen("./a.txt", "a+");
	if (NULL == fp)
	{
		perror("open:");
		return;
	}

	/*
	// 写入文件
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		fputc(b[i], fp);
	}
	*/

	// char c = fgetc(fp);
	// printf("%c\n", c);

	char buf[128] = "";
	int i = 0;
	// 当二进制文件中有-1时会直接中断，使用feof函数解决,feof读完输出为非0，0表示还没读完
	// while ((buf[i++] = fgetc(fp)) != -1)
	do
	{
		buf[i++] = fgetc(fp);
	} while (!feof(fp));

	printf("%s\n", buf);

	// fclose(fp); // 关闭文件

	system("pause");
	return 0;
}
