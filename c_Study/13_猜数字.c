#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	// 设置随机数种子
	srand(10);
	// 获得随机数
	int a = rand();
	printf("a = %d\n", a);

	
	system("pause");
	return 0;
}
