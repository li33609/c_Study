#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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


int main()
{
	printf("hello main\n");
	fun2(3, 4);

	system("pause");
	return 0;
}