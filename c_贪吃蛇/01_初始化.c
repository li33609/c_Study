#define _CRT_SECURE_NO_WARNINGS£»
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

#define HIGH 20
#define WEIGHT 40

struct 
{

};

void ui_init()
{
	for (int i = 0; i < HIGH; i++)
	{
		for (int j = 0; j < WEIGHT; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	ui_init();

	system("pause");
	return 0;
}