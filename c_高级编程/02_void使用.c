#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// voidʹ��
// 1.������,������ͨ��void��������
// 2.��;���޶���������ֵ���޶���������

void func()
{
	return 10;
}

void test01()
{
	printf("%d\n", func());
}

int main()
{
	test01();

	system("pause");
	return 0;
}