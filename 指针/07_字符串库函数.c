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


int main01()
{
	char str1[128] = "world";
	char str2[128] = "hello";

	// 字符串拷贝
	// strcpy(str1, str2);
	// 拷贝2个字符
	// strncpy(str1, str2, 2);
	// printf("%s\n", str1);
	
	// 链接
	strcat(str2, str1);
	printf("%s\n", str2);
	strncat(str2, str1, 2);
	printf("%s\n", str2);
	
	// 数组比较大小(str1 > str2 == 1, str1 = str2 == 0, str1 < str2 == -1)
	printf("%d\n", strcmp(str1, str2));
	printf("%d\n", strncmp(str1, str2, 1));

	system("pause");
	return 0;
}


// 组包函数
int main02()
{
	int year = 2021;
	int month = 5;
	int day = 28;
	char buf[128] = "hello";

	// 将打印结果存到buf数组中
	int len = sprintf(buf, "year=%d month=%d day=%d \n", year, month, day); // 返回组合包长度
	printf("buf=[%s]", buf);
	printf("len=%d\n", len);

	system("pause");
	return 0;
}


// 拆包函数
int main03()
{
	int year = 0;
	int month = 0;
	int day = 0;
	char buf[1024] = "2021:05:20";

	sscanf(buf, "%d:%d:%d", &year, &month, &day); // 从buf中获取数据
	printf("%d %d %d\n", year, month, day);

	system("pause");
	return 0;
}


char* my_strchar(char *q, char ch)
{
	int i = 0;

	while (q[i] != 0)
	{
		if (q[i] == ch)
			return &q[i];
		i++;
	}
	if (q[i] == 0)
	{
		return NULL;
	}
}


// 在数组中查找字符所在位置，成功则返回该值的地址，失败返回NULL
int main04()
{
	char str[] = "sadasddwdsfdcdsf";
	// char* p = strchr(str, 'a');
	char* p = my_strchar(str, 'a');

	printf("%s\n", p);

	system("pause");
	return 0;
}


// 在数组中查找字符串所在位置，成功则返回该值的地址，失败返回NULL
int main()
{
	char str1[] = "sadasddwdsfdcdsf";
	char str2[] =  "ad";
	char* p = strstr(str1, str2);

	printf("%s\n", p);

	system("pause");
	return 0;
}