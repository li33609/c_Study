#define _CRT_SECURE_NO_WARNINGS£»
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CALC_NUM 10
#define FILE_NAME "calc.txt"


FILE* open_file(char *p)
{
	FILE* fp = fopen(FILE_NAME, p);
	if (NULL == fp)
	{
		perror("open:");
	}
	return fp;
}


void my_random()
{
	FILE *fp = open_file("w");

	int a;
	int b;
	char c;
	char add[4] = {'+', '-', '*', '/'};
	char cmd[128] = "";
	rand(time(NULL));
	
	for (int i = 0; i < CALC_NUM; i++)
	{
		a = rand() % 100 + 1;
		b = rand() % 100 + 1;
		c = rand() % 4;
		sprintf(cmd, "%d%c%d= \n", a, add[c], b);
		printf("%s", cmd);
		fputs(cmd, fp);
	}
	fclose(fp);
}


int main()
{
	
	my_random();

	system("pause");
	return 0;
}