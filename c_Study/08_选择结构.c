#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int num = 0;
	int a = 10;
	int b = 3;
	int c = 0;

	// if����;��
	/* if ( a == b )
	{
		printf("a==b\n");
		printf("a+b=%d\n", (int)(a + b));
	}
	else
	{
		printf("a*b=%d\n", (int)(a * b));
	} */

	/* printf("������һ������:\n");
	scanf("%d", (int)&num);
	a = num % 4;
	if (0 == a) 
	{
		printf("�� 0\n");
	}
	else if (1 == a)
	{
		printf("�� 1\n");
	}
	else if (2 == a)
	{
		printf("�� 2\n");
	}
	else if (3 == a)
	{
		printf("�� 3\n");
	} */


	// ��Ŀ�����
	/* c = a > b ? a : b;
	printf("c = %d\n", c); */

	// switch
	scanf("%d", (int)&num);
	a = num % 4;
	// switchֻ���������ж�
	switch (a)
	{
	    case 0:
			printf("0\n");
			break;
		case 1:
			printf("1\n");
			break;
		case 2:
			printf("2\n");
			break;
		case 3:
			printf("3\n");
			break;
		default: //�����������������
			printf("��\n");
	}


	system("pause");
	return 0;
}