#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �꺯��,��Ԥ����׶����˺��滻
// ��Ƶ����С�ĺ����� ��װΪ�꺯���������˳�ջ��ջ��ʱ��
// �ŵ㣺�Կռ任ʱ��(ִ��Ч�ʸ�)
#define MY_ADD(x, y) ((x) + (y))

void test01()
{
	int a = 20;
	int b = 30;

	printf("a+b=%d\n", MY_ADD(a, b) * 6);
}


int main()
{

	test01();

	system("pause");
	return 0;
}