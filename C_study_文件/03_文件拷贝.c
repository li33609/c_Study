#define _CRT_SECURE_NO_WARNINGS£»
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char ch = 0;

	FILE* src = fopen("./a.txt", "r+");

	if (NULL == src)
	{
		perror("open:");
		return;
	}

	FILE* dst = fopen("./b.txt", "w+");

	if (NULL == dst)
	{
		perror("open:");
		return;
	}

	while (1)
	{
		 ch = fgetc(src);
		 int a = feof(src);
		 if (a != 0)
		 {
			 break;
		 }
		 else
		 {
			 fputc(ch, dst);
		 }
	}
	
	fclose(src);
	fclose(dst);

	system("pause");
	return 0;
}