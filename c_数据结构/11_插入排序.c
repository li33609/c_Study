#define _CRT_SECURE_NO_WARNINGS；
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertSort(int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		if (arr[i] < arr[i-1])
		{
			int temp = arr[i];

			int j = i - 1;
			for ( ; j >= 0 && temp < arr[j]; j--)
			{
				arr[j + 1] = arr[j];// 数据后移
			}

			arr[j + 1] = temp;
		}

	}
}

void test01()
{
	int arr[] = { 1,5,10,0,8 };
	int len = sizeof(arr) / sizeof(int);

	// 插入排序
	insertSort(arr, len);

	// 遍历
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
}


int main()
{
	test01();

	return 0;
}