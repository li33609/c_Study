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

/*
// 野指针 没有定义指针的指向
int main01()
{
	// 没有初始化的指针(没赋值)
	// 指针p保存的地址一定是定义过的（向系统申请过）
	int *p; // 野指针

	// 解决
	// int a = 0;
	// p = &a;

	*p = 200;
	printf("%d\n",*p);

	system("pause");
	return 0;
}
*/

// 空指针
int main02()
{
	int a = 0;
	// 空指针，将指针的值赋为0（NULL）
	int *p = NULL; 

	// 使用指针时，将指针赋为NULL
	if (p != NULL)
	{
		p = &a;
	}

	*p = 200; // p保存的0x0000的地址，这个地址不可用，系统初始化
	printf("%d\n", *p);

	system("pause");
	return 0;
}


// 万能指针
int main03()
{
	// 不可以定义void类型变量，但是可以定义void *类型的指针，因为指针都是4个字节
	int a = 10;
	void  *p = (void *)&a;  // 万能指针可以保存任意的地址

	// printf("%d\n", *p); // error 内存大小不一致
	printf("%d\n", *(int *)p); // (int *)表示转化类型为int *

	system("pause");
	return 0;
}


// const修饰的指针
int main04()
{
	// const int a = 10; // const修饰值的内存不可以改变，地址可以改变
	int a = 10;
	int b = 20;
	
	// 这里const修饰的是*
	// const int *p = &a; // 不能通过 *p，修改p所指的空间内容
	// *p = 100; // erro
	 
	// const修饰变量p， p保存的地址不可以修改
	// int * const p = &a;
	// p = &b; // erro
	
	const int* const p = &a; // p 本身的指向不能改变，不能通过*p修改所指向的内容

	printf("*p = %d\n", *p);
	printf("a = %d\n", a);

	system("pause");
	return 0;
}


// 多级指针
int main()
{
	int a = 10;
	int *p = &a;
	// *q  int *p  int *(*q)
	int **q = &p;

	// 如果*和&相遇，相抵消
	// **q == *(*q) == *p == *（&a） == a   
	printf("%d\n", **q);
	
	system("pause");
	return 0;
}


