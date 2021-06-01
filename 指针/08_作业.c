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


int my_atoi(char *p)
{
	char* start = p;
	int num = 0;
	int flag = 0; // flag==0 整数 ==1负数

	if (*start == '-')
	{
		flag = 1;
		start += 1;
	}
	else if (*start == '+')
	{
		flag = 1;
		start += 1;
	}
	while (*start != '\0')
	{
		num = num * 10 + (*start - '0');
		start++;
	}
	if (flag == 0)
	{
		return num;
	}
	else
	{
		return -num;
	}

}


int main01()
{
	char num[] = "123444444";
	
	printf("%d\n", my_atoi(num));

	system("pause");
	return 0;
}


int main()
{
	char str[128] = "asdasd,asfcdsv,asdasd,adsd,,asd";
	char* q = str;
	
	while (*q != '\0')
	{
		if (*q == ',')
		{
			char* p = q;
			while (*p != '\0')
			{
				*p = *(p + 1);
				p++;
			}
		}
		else
		{
			q++;
		}
	}
	printf("%s\n", str);

	system("pause");
	return 0;
}