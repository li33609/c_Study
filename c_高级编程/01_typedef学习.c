#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// typedef
// 1.����ṹ�����
typedef struct Person
{
	char name[64];
	int age;
}PERSON;

// 2.������������
void test01()
{
	typedef char* p;
	p p1, p2;// ��ȫ��Ϊchar *���ͣ�
}


int main()
{
	PERSON p1 = {"С��", 17};

	system("pause"); 
	return 0;
}
