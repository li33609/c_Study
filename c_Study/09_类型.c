#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	// 数据转换从大内存到小内存
	int a = 14.444444;
	double b = a;

	printf("%d\n", (int)3.14);
	printf("%lf\n", (double)a);

	system("pause");
	return 0;
}