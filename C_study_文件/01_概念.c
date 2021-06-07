#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{

	// 只读 r 不存在，不创建
	// 只写情空文件 w 不存在，创建文件
	// 可读可写 r+
	// 可读可写清空文件 w+
	// 追加 a 不存在，创建文件
	// b 二进制文件
	FILE *fp = fopen("./a.txt", "r"); // 打开当前文件，成功返回结构体，失败返回NULL

	if (NULL == fp)
	{
		perror("open:");
		return;
	}
	fclose(fp); // 关闭文件

	system("pause");
	return 0;
}