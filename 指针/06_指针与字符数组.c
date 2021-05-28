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

// 指针与字符串
int main01()
{
	char ch[] = "helloworld";
	// 第义一个指针保存数组首元素地址
	char* p = ch;

	*p = 'm';
	printf("%s\n", p);
	printf("%s\n", p+3);
	printf("%c\n", *(p + 3));
	printf("%d\n", sizeof(ch)); // 11
	printf("%d\n", sizeof(p)); // 4
	printf("%d\n", strlen(ch)); // 
	printf("%d\n", strlen(p)); //

	system("pause");
	return 0;
}


int main02()
{
	char ch[] = "helloworld";
	char* p = ch;

	p = "abcdef"; // 字符串常量存文字常量区
	printf("%s\n", p);
	printf("%d\n", sizeof(p)); // 4
	printf("%d\n", sizeof("abcdef")); // 7

	system("pause");
	return 0;
}


char * my_strcat(char *ch1,char *ch2)
{
	int n = strlen(ch1);
	int i = 0;

	while (*(ch2 + i)!= 0)
	{
		*(ch1 + n + i) = *(ch2 + i);
		// ch1[n+i] = ch2[i];
		i++;
	}
	*(ch1 + n + i) = 0;

	return ch1;
}

int main03()
{
	char str1[128] = "hello";
	char str2[128] = "world";

	// my_strcat(str1, str2);

	printf("%s\n", my_strcat(str1, str2));

	system("pause");
	return 0;
}


// 字符指针数组
int main()
{
	char* p1 = "hello";
	char* p2 = "world";
	char* p3 = "hahaha";
	char* num[3] = {p1,p2,p3};
	char** p = num;

	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", num[i]);
	}
	printf("%c\n", *(num[1]+1));
	printf("%c\n", *(num[2]+2));
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", *(p + i));
	}
	printf("%c\n", *(*(p + 1) + 1));

	system("pause");
	return 0;
}

