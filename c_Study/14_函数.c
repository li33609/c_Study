#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 预先声明函数体
extern void swap(int a, int b);

// 无参无返回值函数 
// 函数需要有返回值
void fun1()
{
	printf("hello fun\n");
	printf("hello data\n");

	return;
}

// 有参无返回值函数 
// 函数定义时（）里叫形参,形参只有被调用时才会分配空间
// 函数调用有参函数时必须传参
// 调用函数时（）里面叫实参
void fun2(int a, int b)
{
	int c = 0;
	c = a + b;
	printf("两个数的和为:%d\n", c);

	return;
}

// 有参有返回值函数 
int fun3(int a, int b)
{
	return a + b;
}

// 交换值
void swap(int a, int b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;

	printf("a = %d b = %d\n", a, b);

	return;
}


int main()
{
	int x = 3;
	int y = 5;
	int sum = 0;

	printf("hello main\n");

	// fun2(3, 4);
	// fun2(x, y);
	// 实参可以为变量，可以为表达式，只要类型匹配
	// fun2(x + y, y * x);
	
	// 可以接返回值，也可以不接，变量类型需要一致
	// 参数传递只能是单向传递，形参-》实参
	// sum = fun3(x, y);
	// printf("sum = %d\n", fun3(x, y));
	
	// 实参传形参，形参的值改变，实参值不变
	swap(x, y);
	printf("x = %d y = %d\n", x, y);

	system("pause");
	return 0;
}