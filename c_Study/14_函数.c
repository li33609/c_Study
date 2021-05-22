#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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


int main()
{
	printf("hello main\n");
	fun2(3, 4);

	system("pause");
	return 0;
}