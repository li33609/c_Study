#define _CRT_SECURE_NO_WARNINGS��
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// ����һ���ṹ����������
// �ؼ��� struct ��������Ǹ��ṹ������
// struct Ϊ�ؼ���,stuΪ����,{}��Ϊ�ṹ���Ա,����Ϊ��������
// ����ṹ��������Ҫ;
// �ṹ��û�ռ䣬�����Ը��ṹ�帳ֵ
struct stu
{
	int id;
	int age;
	char name[128];
} a, b; // ��������ʱ��ͬʱ�����������ṹ�����

struct stu c; // ����ʱ��һ�ַ�ʽ

int main()
{
	// struct stu d = {1, 20, "lishijie"}; // ��ʼ��ֵ
	// struct stu d = { .age =  "lishijie" }; // ����ԭ�س�ʼ��ֵ������Ԫ��Ϊ0
	// ���ʽṹ���Ա����ʱ��ʹ��.����в���
	struct stu d;

	/*
	d.id = 1;
	d.age = 20;
	strcpy(d.name, "xiaoli");
	printf("%d %d %s\n", d.id, d.age, d.name);
	*/

	// ʹ��ָ����в���->
	(&d)->id = 2;
	(&d)->age = 20;
	strcpy((&d)->name , "zhangsan");
	printf("%d %d %s\n", (&d)->id, (&d)->age, (&d)->name);

	system("pause");
	return 0;
}