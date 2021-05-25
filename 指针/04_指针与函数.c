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

void swap(int x, int y)
{
	int k = 0;

	k = x;
	x = y;
	y = k;
	printf("x = %d  y = %d\n",x ,y);

	return;
}


void swap2(int* x, int* y)
{
	int k = 0;

	k = *x;
	*x = *y;
	*y = k;
	printf("x = %d  y = %d\n", *x, *y);

	return;
}

/*
int main01()
{
	int a = 20;
	int b = 30;

	// swap(a, b);
	swap2(&a, &b);
	printf("a = %d  b = %d\n", a, b);

	system("pause");
	return 0;
}
*/

// 函数传入数组,数组会退化为指针
void print_arr(int *b, int len) // int *b
{
	int line = sizeof(b) / sizeof(b[0]); // b[0] == *(b+0)

	for (int i = 0; i < len; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");

	return;
}


int main02()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	print_arr(a, sizeof(a) / sizeof(a[0]));

	system("pause");
	return 0;
}

int num = 0; // 全局变量，到程序结束才会释放空间

int* getnum()
{
	// {}里面定义的变量为局部变量，局部变量在函数结束后的空间会被释放
	srand(time(NULL));
	num = rand();

	return &num;
}


int main()
{
	int* p = getnum();

	printf("%d \n", *p);

	system("pause");
	return 0;
}