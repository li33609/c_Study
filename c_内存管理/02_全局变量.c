#define _CRT_SECURE_NO_WARNINGS��
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int num11; // ȫ�ֱ����޷��ͷ�, ��������������
static int num22;// ��̬ȫ�ֱ�������������Ҳ�����������ļ�ʹ��


void fun1()
{
	num11 = 11;
}


int main()
{
	printf("%d\n", num11);
	fun1();
	printf("%d\n", num11);
	
	system("pause");
	return 0;
}