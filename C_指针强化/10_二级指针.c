#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


// ����ָ����������
void printf_arr(int **pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("��%d��Ԫ��,p=%d\n",i+1 ,*pArray[i]);
	}
}

// ������������ڴ�
void test01()
{
	int **pArray = malloc(sizeof(int*) * 5);
	int a1 = 100;
	int a2 = 200;
	int a3 = 300;
	int a4 = 400;
	int a5 = 500;

	pArray[0] = &a1;
	pArray[1] = &a2;
	pArray[2] = &a3;
	pArray[3] = &a4;
	pArray[4] = &a5;

	printf_arr(pArray, 5);

	if (pArray != NULL)
	{
		free(pArray);
		pArray = NULL;
	}
}

// ��ջ�Ͽ����ڴ�
void test02()
{
	int* pArray[5];

	for (int i = 0; i < 5; i++)
	{
		pArray[i] = malloc(4);
		*(pArray[i]) = i + 100;
	}

	int len = sizeof(pArray) / sizeof(pArray[0]);
	printf_arr(pArray, len);

	for (int i = 0; i < len; i++)
	{
		if (pArray[i] != NULL)
		{
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}
}


int main()
{
	test02();

	system("pause");
	return 0;
}