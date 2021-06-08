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
		// printf("%s", cmd);
		fputs(cmd, fp);
	}
	fclose(fp);
}

void read_data()
{
	FILE* fp = open_file("r");

	int i = 0;
	int a = 0;
	int b = 0;
	int num = 0;
	char buf[128] = "";
	char* p = NULL;
	char c = 0;
	char result[128][128] = {0};

	while (1)
	{
		p = fgets(buf, sizeof(buf), fp);
		if (p == NULL)
		{
			break;
		}
		sscanf(buf, "%d%c%d", &a, &c, & b);
		printf("%c\n", c);
		
		if (c == '+')
		{
			num = a + b;
			printf("%d\n", num);
		}
		else if(c == '-')
		{
			num = a - b;
			printf("%d\n", num);
		}
		else if(c == '*')
		{
			num = a * b;
			printf("%d\n", num);
		}
		else if (c == '/')
		{
			num = a / b;
			printf("%d\n", num);
		}
		
		/*switch (c)
		{
		case '+':
			num = a + b;
			break;
		case '-':
			num = a - b;
			break;
		case '*':
			num = a * b;
			break;
		case '/':
			num = a / b;
			break;
		}*/
		 sprintf(result[i] , "%d%c%d=%d\n", a, c, b, num);
		 i++;
	}

	fclose(fp);
	fp = open_file("w");
	for (int j = 0; j < i; j++)
	{
		fputs(result[j], fp);
	}
	fclose(fp);
}

int main()
{
	
	my_random();
	read_data();

	system("pause");
	return 0;
}