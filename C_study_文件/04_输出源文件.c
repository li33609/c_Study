#define _CRT_SECURE_NO_WARNINGS£»
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char ch = 0;

	FILE *fp = fopen("./03_ÎÄ¼þ¿½±´.c", "r");

	if (NULL == fp)
	{
		perror("open:");
	}

	while (1)
	{
		ch = fgetc(fp);
		if (feof(fp))
		{
			break;
		}
		fputc(ch, stdout);
	}
	
	fclose(fp);
	
	system("pause");
	return 0;
}