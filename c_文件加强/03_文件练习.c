#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include "config.h"


int main()
{
	int line = get_file_line("./config.txt");
	printf("文件的有效行数为：%d\n", line);


	system("pause");
	return EXIT_SUCCESS;
}