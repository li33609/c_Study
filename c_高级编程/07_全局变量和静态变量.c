#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// ��̬����
// ��ǰ�����ڴ�
// �����ڳ������
// Ĭ�������ڲ��������ԣ��ڵ�ǰ�ļ���ʹ��
static int a = 10;

// ȫ�ֱ��� 
// �ⲿ��������,�����������ļ���ʹ��ʱҪ��ǰ����
extern int b = 20;

// const���εĳ���,���ڳ��������ܵ�����������
// ����ֱ���޸�
const int c = 30;

void func()
{
	// const���εľֲ��������Ա��޸ģ���Ϊ����ջ��
	// α����
	const int d = 100;
	int* p = &d;
	*p = 10;

	printf("d = %d\n", d);
}

// �ַ�����������, �ַ������������޸�
void my_str()
{
	char* p1 = "hello world";
	char* p2 = "hello world";
	char* p3 = "hello world";
	char* p4 = "hello world";

	printf("%d\n", p1);
	printf("%d\n", p2);
	printf("%d\n", p3);
	printf("%d\n", p4);
}


int main()
{
	my_str();

	system("pause");
	return 0;
}