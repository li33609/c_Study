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


int my_atoi(char *p)
{
	char* start = p;
	int num = 0;
	int flag = 0; // flag==0 ���� ==1����

	if (*start == '-')
	{
		flag = 1;
		start += 1;
	}
	else if (*start == '+')
	{
		flag = 1;
		start += 1;
	}
	while (*start != '\0')
	{
		num = num * 10 + (*start - '0');
		start++;
	}
	if (flag == 0)
	{
		return num;
	}
	else
	{
		return -num;
	}

}


int main01()
{
	char num[] = "123444444";
	
	printf("%d\n", my_atoi(num));

	system("pause");
	return 0;
}


int main()
{
	char str[128] = "asdasd,asfcdsv,asdasd,adsd,,asd";
	char* q = str;
	
	while (*q != '\0')
	{
		if (*q == ',')
		{
			char* p = q;
			while (*p != '\0')
			{
				*p = *(p + 1);
				p++;
			}
		}
		else
		{
			q++;
		}
	}
	printf("%s\n", str);

	system("pause");
	return 0;
}