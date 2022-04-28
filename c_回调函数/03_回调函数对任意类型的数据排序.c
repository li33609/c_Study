#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


void select_sort(void* arr, int eleSize, int len, int(*myComapre)(void*, void*))
{
	char* tmp = malloc(eleSize);

	for (int i = 0; i < len; i++)
	{
		// �϶�iΪ��Сֵ
		int min_or_max = i;

		for (int j = i + 1; j < len; j++)
		{
			// ��ȡjԪ���׵�ַ
			char* pJ = (char*)arr + eleSize * j;
			// ��ȡ��ǰԪ�ص����ֵ����Сֵ
			char* p_min_or_max = (char*)arr + eleSize * min_or_max;

			if (myComapre(pJ, p_min_or_max))
			{
				min_or_max = j;
			}
		}
		if (i != min_or_max) // ����϶���Сֵ�����ֵ ���Ǽ������min_or_max
		{
			// ͨ���ڴ濽��ʵ�ֽ���
			char* pI = (char*)arr + eleSize * i;
			char* pmin_or_max = (char*)arr + eleSize * min_or_max;

			memcpy(tmp, pI, eleSize);
			memcpy(pI, pmin_or_max, eleSize);
			memcpy(pmin_or_max, tmp, eleSize);
		}
	}
	if (tmp != NULL)
	{
		free(tmp);
	}
	tmp = NULL;
}

int compareInt(void* data1, void* data2)
{
	int* num1 = data1;
	int* num2 = data2;

	// ����
	if (*num1 < *num2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void test01()
{
	int arr[] = { 10, 50, 30, 20, 100, 60, 80, 40, 70, 90 };
	int len = sizeof(arr) / sizeof(arr[0]);

	select_sort(arr, sizeof(int), len, compareInt);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}


int main()
{
	test01();

	system("pause");
	return 0;
}