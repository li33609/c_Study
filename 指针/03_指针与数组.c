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

// ��ʹ��ʱ,��һ�����ʽȡ*,�ͻ�Ա��ʽ��һ��*,����Ա��ʽȡ&,�ͻ��һ��*

int main01()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int *p = a; // ָ��p������Ԫ�ص�ַ

	for (int i = 0; i < sizeof(a) / sizeof(a[0]) ; i++)
	{
		printf("%d\n", *(p+i));
	}

	system("pause");
	return 0;
}


int main02()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = a; 
	int *q = (int *)(&a+1) - 1;
	// int* q = &a[9];

	// ��ָ�����û����
	printf("%d\n", q - p);

	system("pause");
	return 0;
}


int main03()
{
	// []��������ר�� 
	// [] == *() 
	int b[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int a = 0;
	int* p = b;

	// p[0] == *(p+0)
	// p[0] = 100;
	// printf("%d\n",a);

	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		printf("%d ", p[i]); // p[i] == *(p+i)
	}

	system("pause");
	return 0;
}


// ָ������
int main04()
{
	int a = 20;
	int b = 30;
	int c = 40;
	int* num[3] = {&a, &b, &c};
	int line = sizeof(num) / sizeof(num[0]);

	for (int i = 0; i < line; i++)
	{
		printf("%d ", *num[i]);
	}
	
	system("pause");
	return 0;
}


// ����һ��ָ������������num��Ԫ�ص�ַ
int main()
{
	int a = 20;
	int b = 30;
	int c = 40;
	int* num[3] = { &a, &b, &c };
	int line = sizeof(num) / sizeof(num[0]);
	int** k = num;

	for (int i = 0; i < line; i++)
	{
		printf("%d ",**(k+i));
	}

	system("pause");
	return 0;
}