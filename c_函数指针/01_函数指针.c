#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


void func(int a, char b)
{
	printf("hello world!\n");
}

void func1()
{
	printf("hello world1!\n");
}

void func2()
{
	printf("hello world2!\n");
}

void func3()
{
	printf("hello world3!\n");
}

void test01()
{
	// �ȶ��庯�����ͣ���ͨ�����Ͷ���ָ�����
	typedef void(FUNC_TYPE)(int, char); // �����һ���������ͣ�����ֵ��void���β���(int, char)

	FUNC_TYPE* pFunc = func;

	pFunc(10, "a");
}

void test02()
{
	// �ȶ��庯��ָ������ͣ�ͨ�����Ͷ��庯��ָ�����
	typedef void(*FUNC_TYPE)(int, char);

	FUNC_TYPE pFunc = func;
	pFunc(10, "a");
}

void test03()
{
	// ֱ�Ӷ��庯������
	void(*p)(int, char) = func;
	p(30, "A");
}

// ����ָ������
void test04()
{
	void(*func_array[3])();

	func_array[0] = func1;
	func_array[1] = func2;
	func_array[2] = func3;

	for (int i = 0; i < 3; i++)
	{
		func_array[i]();
	}
}

int main()
{
	test04();

	system("pause");
	return 0;
}