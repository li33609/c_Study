#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


// ��λȡ��
void test01()
{
	int num = 2;

	printf("~num=%d\n", ~num);
}

// ��λ��
void test02()
{
	// �ж���ż��
	int num = 124;

	if ((num & 1) == 0)
	{
		printf("ż����\n");
	}
	else
	{
		printf("������\n");
	}
}

//��λ��
void test03()
{
	int num1 = 3;
	int num2 = 5;

	printf("num1 | num2 = %d\n", num1 | num2);
}

// ��λ���
void test04()
{
	// ���ֽ���
	int a = 8;
	int b = 9;

	// ���� 1
	/*a = a ^ b;
	b = a ^ b;
	a = a ^ b;*/

	// ���� 2
	a = a + b;
	b = a - b;
	a = a - b;

	printf("a=%d,b=%d\n", a, b);
}

// ����,<<,���Ƽ�λ,ԭ������2�ļ��η�
// �����෴,>>
void test05()
{
	int a = 8;
	
	printf("a=%d\n", a <<= 3);
}


int main()
{
	test05();

	system("pause");
	return 0;
}
