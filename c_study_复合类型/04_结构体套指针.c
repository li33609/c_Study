#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 变量用. 指针用->
struct t
{
	int a;
};

struct tea
{
	int id;
	char *p;
	struct t *b;
};


int main01()
{
	struct tea *tmp = (struct tea *)malloc(sizeof(struct tea));

	tmp->id = 100;
	tmp->p = "hello";
	// strcpy(tmp->p, "hello") // error 野指针;

	printf("%s\n", tmp->p);

	free(tmp->p);
	free(tmp->b);
	free(tmp);

	system("pause");
	return 0;
}


int main02()
{
	struct tea* tmp = (struct tea*)malloc(sizeof(struct tea));

	// 变量用. 指针用->
	tmp->id = 50;
	tmp->p = "hello";
	tmp->b = (struct t *)malloc(128); // 要给b申请空间
	tmp->b->a = 200; //

	printf("%d\n", tmp->b->a);

	system("pause");
	return 0;
}


struct stu
{
	int id;
	int class;
};

void set_struct(struct stu *p,int n)
{
	for (int i = 0; i < n; i++)
	{
		(*(p + i)).id = i + 1;
		(*(p + i)).class = i + 10;
	}
}


int main()
{
	struct stu num[5];
	int n = sizeof(num) / sizeof(num[0]);
	
	memset(num, 0, n);
	set_struct(num, n);
	printf("%d \n", n);
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", num[i].id, num[i].class);
	}

	system("pause");
	return 0;
}