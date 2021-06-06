#define _CRT_SECURE_NO_WARNINGS£»
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct student
{
	char name[50];//ĞÕÃû
	unsigned int age;
	int score;//³É¼¨
}student;

void printf_stu(struct student *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s %d %d\n", (*(p + i)).name, (*(p + i)).age, (*(p + i)).score);
	}
}

void my_sort(struct student* p, int n)
{
	student tmp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if ((*(p + j)).score < (*(p + j + 1)).score)
			{
				tmp = (*(p + j + 1)); 
				(*(p + j + 1)) = (*(p + j));
				(*(p + j)) = tmp;
			}
		}
	}
}


int main()
{
	struct student stu[5] = 
	{
		{"mike", 18, 90},
		{"jiang", 18, 80},
		{"lily", 30, 70},
		{"lucy", 22, 88},
		{"lilei", 33, 60}
	};
	int n = sizeof(stu) / sizeof(stu[0]);

	printf_stu(stu, n);
	my_sort(stu, n);
	printf("\n");
	printf_stu(stu, n);


	system("pause");
	return 0;
}