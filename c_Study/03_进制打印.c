#include<stdio.h>
#include<stdlib.h>


int main()
{

	int a = 123;
	int b = 056;
	int c = 0xab;
	unsigned int d = 0xffffffff;

	// ʮ����
	printf("a=%d\n", a);
	// �˽���
	printf("b=%o\n", b);
	// ʮ������
	printf("c=%x\n", c);
	// �з���ʮ�����ƴ�ӡ
	printf("�з���ʮ�����ƴ�ӡ d=%d\n", d);
	// �޷���ʮ�����ƴ�ӡ
	printf("�޷���ʮ�����ƴ�ӡ d=%u\n", d);


	system("pause");

	return 0;
}