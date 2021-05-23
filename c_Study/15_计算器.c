#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mux(int a, int b)
{
	return a * b;
}

int dive(int a, int b)
{
	return a / b;
}


int main()
{
	int a = 0;
	int b = 0;
	int i = 0;
	char cmd[5] = { 0 };

	printf("ÇëÊäÈë¼ÆËãÆ÷ÃüÁîºÍÊı×Ö£º\n");
	printf("ÃüÁî£º¼Ó add£¬¼õ sub£¬³Ë£ºmux£¬³ı£ºdive\n");
	scanf("%s %d %d", cmd, &a, &b);

	if (0 == strcmp(cmd, "add"))
	{
		printf("result = %d\n", add(a, b));
	}
	else if (0 == strcmp(cmd, "sub"))
	{
		printf("result = %d\n", sub(a, b));
	}
	else if (0 == strcmp(cmd, "mux"))
	{
		printf("result = %d\n", mux(a, b));
	}
	else if (0 == strcmp(cmd, "dive"))
	{
		printf("result = %d\n", dive(a, b));
	}
	else if(0 == strcmp(cmd, "exit"))
	{
		exit(0);
	}
	else
	{
		printf("ÊäÈëÃüÁî´íÎó¡£\n");
	}
	
	system("pause");
	return 0;
}