#define _CRT_SECURE_NO_WARNINGS��
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// malloc���ص�(void *)������Ҫ��������ת��
int main()
{
	int *p = (int *)malloc(sizeof(int) * 10);
	memset(p, 0, sizeof(int) * 10);
	free(p); // �ͷ��ڴ� malloc����Ŀռ䲻���ͷ�����

	// *p = 1000;

	for (int i = 0; i < 100; i++)
	{
		printf("%d ", *(p + i));
	}
	
	system("pause");
	return 0;
}