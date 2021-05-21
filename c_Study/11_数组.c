#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int i ;
	int num[10] = { 1,2,3,4,5,6,7,8,9,10 };
	// int num[10] = {[5]=5};

	// 数组值不能整体操作
    // 数组的每个元素都是变量
	printf("%d\n", sizeof(double)); // 数组个数
	for (i = 0; i < sizeof(num) / sizeof(num[0]); i++)
	{
		printf("%d ", num[i]);
	}

	system("pause");
	return 0;
}