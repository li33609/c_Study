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
	int a = 0;
	// 定义指针三步骤
	int *p = &a;
	int b = 11;

	*p = 100;
	printf("a = %d, *p = %d\n", a, *p);

	p = &b;
	*p = 22;
	printf("b = %d, *p = %d\n", b, *p);

	system("pause");
	return 0;
}

int main02()
{
	int *p1;
	char *p2;
	short *p3;
	short **p4;

	printf("%d\n", sizeof(p1));
	printf("%d\n", sizeof(p2));
	printf("%d\n", sizeof(p3));
	printf("%d\n", sizeof(p4));

	system("pause");
	return 0;
}


int main()
{
	int num = 0x01020304;
	int *p1 = &num;
	char *p2 = (char *)&num;
	short *p3 = (short*)& num;

	printf("%u\n", p1);
	printf("%u\n", p2);
	printf("%u\n", p3);

	printf("%u\n", p1+1);
	printf("%u\n", p2+1);
	printf("%u\n", p3+1);

	system("pause");
	return 0;
}