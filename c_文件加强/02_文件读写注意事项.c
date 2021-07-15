#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


void test01()
{
	FILE * file = fopen("./a.txt", "r");
	if (file == NULL)
	{
		ferror("error!");
	}

	char ch;

	while ((ch = fgetc(file)) != EOF)
	{
		printf("%c", ch);
	}

	fclose(file);
}


int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}