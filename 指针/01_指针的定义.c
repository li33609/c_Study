#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//����ָ���������
//1 *����Ž�ϴ�����һ��ָ�����  
//2 Ҫ����˭�ĵ�ַ,�����Ķ�����ʽ���ڴ˴�
//3 ��*p�滻������ı���
//*p

//����
//1��*��ϴ������һ��ָ�����
//2p�Ǳ���,p�������ǽ�����p�����Ϻ�,ʣ�µ����;���ָ�����������  int   *
//3ָ�����p��������ʲô�������ݵĵ�ַ ,��ָ�����p��ָ�����p�����*һ���Ϻ�,
//ʣ��ʲô���;ͱ���ʲô�������ݵĵ�ַ
//p = &a;

int main01()
{
	int a = 0;
	// ����ָ��������
	int *p = &a;
	int b = 11;

	*p = 100;
	printf("a = %d, *p = %d\n", a, *p);

	p = &b;
	*p = 22;
	printf("b = %d, *p = %d\n", b, *p);

	system("pause");
	return 0;
}

int main02()
{
	int *p1;
	char *p2;
	short *p3;
	short **p4;

	printf("%d\n", sizeof(p1));
	printf("%d\n", sizeof(p2));
	printf("%d\n", sizeof(p3));
	printf("%d\n", sizeof(p4));

	system("pause");
	return 0;
}


int main()
{
	int num = 0x01020304;
	int *p1 = &num;
	char *p2 = (char *)&num;
	short *p3 = (short*)& num;

	printf("%u\n", p1);
	printf("%u\n", p2);
	printf("%u\n", p3);

	printf("%u\n", p1+1);
	printf("%u\n", p2+1);
	printf("%u\n", p3+1);

	system("pause");
	return 0;
}