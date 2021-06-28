#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


// 二维数组定义
void test01()
{
	// 1
	int arr1[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	// 2
	// int arr2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	// 3
	// int arr3[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int(*p)[3] = arr1;
	printf("%d\n", *(*p+5));
	printf("%d\n", *(*(p + 1))+2); //第二行取值
	printf("%d\n", p[1][2]);
}

// void print_arr(int (*p)[3], int len1, int len2)
void print_arr(int p[3][3], int len1, int len2)
{
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			// printf("%d ", p[i][j]);
			printf("%d ", (*(*(p+i))+j));
		}
		printf("\n");
	}
}

// 二维数组定义
void test02()
{
	int arr1[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	print_arr(arr1, 3, 3);
}


int main()
{
	test02();

	system("pause");
	return 0;
}