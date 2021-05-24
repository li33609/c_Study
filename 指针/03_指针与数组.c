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

// 在使用时,对一个表达式取*,就会对表达式减一级*,如果对表达式取&,就会加一级*

int main01()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int *p = a; // 指针p保存首元素地址

	for (int i = 0; i < sizeof(a) / sizeof(a[0]) ; i++)
	{
		printf("%d\n", *(p+i));
	}

	system("pause");
	return 0;
}


int main02()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = a; 
	int *q = (int *)(&a+1) - 1;
	// int* q = &a[9];

	// 两指针相加没意义
	printf("%d\n", q - p);

	system("pause");
	return 0;
}


int main03()
{
	// []不是数组专属 
	// [] == *() 
	int b[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int a = 0;
	int* p = b;

	// p[0] == *(p+0)
	// p[0] = 100;
	// printf("%d\n",a);

	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		printf("%d ", p[i]); // p[i] == *(p+i)
	}

	system("pause");
	return 0;
}


// 指针数组
int main04()
{
	int a = 20;
	int b = 30;
	int c = 40;
	int* num[3] = {&a, &b, &c};
	int line = sizeof(num) / sizeof(num[0]);

	for (int i = 0; i < line; i++)
	{
		printf("%d ", *num[i]);
	}
	
	system("pause");
	return 0;
}


// 定义一个指针来保存数组num首元素地址
int main()
{
	int a = 20;
	int b = 30;
	int c = 40;
	int* num[3] = { &a, &b, &c };
	int line = sizeof(num) / sizeof(num[0]);
	int** k = num;

	for (int i = 0; i < line; i++)
	{
		printf("%d ",**(k+i));
	}

	system("pause");
	return 0;
}