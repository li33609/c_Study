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

void swap(int x, int y)
{
	int k = 0;

	k = x;
	x = y;
	y = k;
	printf("x = %d  y = %d\n",x ,y);

	return;
}


void swap2(int* x, int* y)
{
	int k = 0;

	k = *x;
	*x = *y;
	*y = k;
	printf("x = %d  y = %d\n", *x, *y);

	return;
}

/*
int main01()
{
	int a = 20;
	int b = 30;

	// swap(a, b);
	swap2(&a, &b);
	printf("a = %d  b = %d\n", a, b);

	system("pause");
	return 0;
}
*/

// ������������,������˻�Ϊָ��
void print_arr(int *b, int len) // int *b
{
	int line = sizeof(b) / sizeof(b[0]); // b[0] == *(b+0)

	for (int i = 0; i < len; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");

	return;
}


int main02()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	print_arr(a, sizeof(a) / sizeof(a[0]));

	system("pause");
	return 0;
}

int num = 0; // ȫ�ֱ���������������Ż��ͷſռ�

int* getnum()
{
	// {}���涨��ı���Ϊ�ֲ��������ֲ������ں���������Ŀռ�ᱻ�ͷ�
	srand(time(NULL));
	num = rand();

	return &num;
}


int main()
{
	int* p = getnum();

	printf("%d \n", *p);

	system("pause");
	return 0;
}