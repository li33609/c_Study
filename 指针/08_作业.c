#define _CRT_SECURE_NO_WARNINGS��
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//����ָ���������
//1 *����Ž�ϴ�����һ��ָ�����  
//2 Ҫ����˭�ĵ�ַ,�����Ķ�����ʽ���ڴ˴�
//3 ��*p�滻������ı���
//*p

//����
//1��*��ϴ������һ��ָ�����
//2p�Ǳ���,p�������ǽ�����p�����Ϻ�,ʣ�µ����;���ָ�����������  int   *
//3ָ�����p��������ʲô�������ݵĵ�ַ ,��ָ�����p��ָ�����p�����*һ���Ϻ�,
//ʣ��ʲô���;ͱ���ʲô�������ݵĵ�ַ
//p = &a;


void my_atoi(char *p)
{
	char* start = p;
	char* end = &p[strlen(p) - 1];
	int num[128] = { 0 };
	int i = 0;

	while (*start != '\0')
	{
		num[i] =  *start - '0';

		i++;
		start++;
	}
	printf("%d\n", strlen(p));
	for (i = 0; i < strlen(p); i++)
	{
		printf("%d", num[i]);
	}
	printf("\n");
}


int main()
{
	char num[] = "123444444";
	
	printf("%d\n", strlen(num));

	my_atoi(num);
	int num1 = atoi(num);
	printf("%d\n", num1);

	system("pause");
	return 0;
}