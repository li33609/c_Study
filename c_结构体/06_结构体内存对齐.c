#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

#pragma pack (show) // �鿴����ģ����ֵΪ8 ���Ըĳ�2��n�η�

// �ڴ����
// 1.��0��ʼ����ƫ����
// 2.�����ԵĴ�С�� ����ģ���� ȡ��Сֵ�� ��������
// ���������Լ�����Ⱥ��������ƫ�ƣ��������� ���䵽 �����ģ���� ����ṹ��������������� ��������

typedef struct person
{
	int a; // 0~3
	char b; // 4~7
	double c; // 8~15
	float d; // 16`19 
}Teacher;


void test01()
{
	printf("�ṹ��Ĵ�СΪ��%d\n", sizeof(Teacher));
}


int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}