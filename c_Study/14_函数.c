#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// Ԥ������������
extern void swap(int a, int b);

// �޲��޷���ֵ���� 
// ������Ҫ�з���ֵ
void fun1()
{
	printf("hello fun\n");
	printf("hello data\n");

	return;
}

// �в��޷���ֵ���� 
// ��������ʱ��������β�,�β�ֻ�б�����ʱ�Ż����ռ�
// ���������вκ���ʱ���봫��
// ���ú���ʱ���������ʵ��
void fun2(int a, int b)
{
	int c = 0;
	c = a + b;
	printf("�������ĺ�Ϊ:%d\n", c);

	return;
}

// �в��з���ֵ���� 
int fun3(int a, int b)
{
	return a + b;
}

// ����ֵ
void swap(int a, int b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;

	printf("a = %d b = %d\n", a, b);

	return;
}


int main()
{
	int x = 3;
	int y = 5;
	int sum = 0;

	printf("hello main\n");

	// fun2(3, 4);
	// fun2(x, y);
	// ʵ�ο���Ϊ����������Ϊ���ʽ��ֻҪ����ƥ��
	// fun2(x + y, y * x);
	
	// ���Խӷ���ֵ��Ҳ���Բ��ӣ�����������Ҫһ��
	// ��������ֻ���ǵ��򴫵ݣ��β�-��ʵ��
	// sum = fun3(x, y);
	// printf("sum = %d\n", fun3(x, y));
	
	// ʵ�δ��βΣ��βε�ֵ�ı䣬ʵ��ֵ����
	swap(x, y);
	printf("x = %d y = %d\n", x, y);

	system("pause");
	return 0;
}