#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// sizeof

// 1.���ʲ���һ���������������
void my_sizeof01()
{
	double a = 3.14;

	printf("sizeof = %d\n", sizeof(a));
	printf("sizeof = %d\n", sizeof a);
}

// 2.�������޷������ͣ�unsigned int��
void my_sizeof02()
{
	unsigned int a = 20;

	if (sizeof(int) - 5)
	{
		printf("����0\n");
		printf("%u\n", sizeof(int) - 5);
	}
	else
	{
		printf("С��0\n");
	}
	
}

void count_sizeof(int* buf)
{
	printf("sizeof = %d\n", sizeof(buf));
}

// 3.sizeofͳ�������С
void my_sizeof03()
{
	int buf[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	count_sizeof(buf);
}


int main()
{
	my_sizeof03();

	system("pause");
	return 0;
}