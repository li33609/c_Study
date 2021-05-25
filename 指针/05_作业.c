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

// 找出第二大数
int main()
{
	int a[] = { 5,100,32,45,21,67,32,68,41,99,13,71 };
	int len = sizeof(a) / sizeof(*a);
	int max = 0;
	int smax = 0;

	if (*a > *(a+1))
	{
		max = *a;
		smax = *(a + 1);
	}
	else
	{
		max = *(a + 1);
		smax = *a;
	}
	for (int i = 2; i < len; i++)
	{
		if (max < *(a+i))
		{
			max = *(a + i);
		}
		else if (max > *(a+i) && smax < *(a+i))
		{
			smax = *(a + i);
		}
	}
	printf("smax = %d\n", smax);

	system("pause");
	return 0;
}
