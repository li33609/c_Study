#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


void my_sort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i+1 ; j < len; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			int tmp = arr[min];
			arr[min] = arr[i];
			arr[i] = tmp;
		}
	}
}

void printf_arr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Ñ¡ÔñÅÅÐò(Êý×ÖÅÅÐò)
void test01()
{
	int arr[] = {3, 5, 8, 2, 6, 15, 1};
	int len = sizeof(arr) / sizeof(arr[0]);

	my_sort(arr, len);
	printf_arr(arr, len);
}

void select_sort(char *parr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (strcmp(parr[max], parr[j]) == -1)
			{
				max = j;
			}
		}
		if (i != max)
		{
			char* tmp = parr[max];
			parr[max] = parr[i];
			parr[i] = tmp;
		}
	}
}

printf_arr2(char * arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");
}

// ×ÖÄ¸ÅÅÐò
void test02()
{
	char* parr[] = { "aaa", "ccc", "fff", "ddd", "eee" };
	int len = sizeof(parr) / sizeof(parr[0]);


	select_sort(parr, len);
	printf_arr2(parr, len);
}


int main()
{
	test02();

	system("pause");
	return 0;
}