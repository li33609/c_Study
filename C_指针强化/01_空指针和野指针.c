#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


//������
void test01() {

	//����ָ��
	int* p = NULL;
	//ָ��ָ��˭���Ͱ�˭�ĵ�ַ����ָ��
	int a = 10;
	p = &a;
	*p = 20;//*����ߵ���ֵ������ȷ���ڴ��д
	//*�ŷ����棬���ڴ��ж�ֵ
	int b = *p;
	

	printf("a:%d\n", a);
	printf("*p:%d\n", *p);
	printf("b:%d\n", b);
}

// ָ�벽��
void test02()
{
	char* p = NULL;

	printf("%d\n", p);
	printf("%d\n", p + 1);

	double* p1 = NULL;

	printf("%d\n", p1);
	printf("%d\n", p1 + 1);
}

// ��Ӧ��, ����Ӧ��
void test03()
{
	char buf[1024] = { 0 };
	int a = 1000;

	memcpy(buf, &a, sizeof(int));
	char* p = buf;

	printf("%d\n", *(int *)p);
}

typedef struct Person
{
	char a;
	int b;
	char buf[64];
	int d;
}PERSON;


void test04()
{
	PERSON student = {'a', 10, "hello world", 1000};
	char* p = &student;
	
	printf("d��ƫ����Ϊ��%d\n", offsetof(PERSON, d));

	printf("d��ֵΪ��%d\n", *(int *)(p + offsetof(PERSON, d)));
}


int main()
{
	test04();

	system("pause");
	return 0;
}