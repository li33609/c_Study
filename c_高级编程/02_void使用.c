#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// voidʹ��
// 1.������,������ͨ��void��������
// 2.��;���޶���������ֵ���޶���������
// 3.void * ������ָ��
int func()
{
	return 10;
}

void test01()
{
	printf("%d\n", func());
}

void test02()
{
	void* p = NULL;

	int* pInt = NULL;
	char* pChar = NULL;

	pInt = (int *)pChar; // error������ͬ���Ͳ��ܸ�ֵ,��Ҫ��������ת��

	pChar = p; // ���ý���ǿת
}


int main()
{
	test01();

	system("pause");
	return 0;
}