#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//定义指针的三步骤
//1 *与符号结合代表是一个指针变量  
//2 要保存谁的地址,将他的定义形式放在此处
//3 用*p替换掉定义的变量
//*p

//分析
//1与*结合代表这个一个指针变量
//2p是变量,p的类型是将变量p本身拖黑,剩下的类型就是指针变量的类型  int   *
//3指针变量p用来保存什么类型数据的地址 ,将指针变量p和指针变量p最近的*一起拖黑,
//剩下什么类型就保存什么类型数据的地址
//p = &a;


void my_atoi(char *p)
{
	char* start = p;
	char* end = &p[strlen(p) - 1];
	int num[128] = { 0 };
	int i = 0;

	while (*start != '\0')
	{
		num[i] =  *start - '0';

		i++;
		start++;
	}
	printf("%d\n", strlen(p));
	for (i = 0; i < strlen(p); i++)
	{
		printf("%d", num[i]);
	}
	printf("\n");
}


int main()
{
	char num[] = "123444444";
	
	printf("%d\n", strlen(num));

	my_atoi(num);
	int num1 = atoi(num);
	printf("%d\n", num1);

	system("pause");
	return 0;
}