#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int num = 0;
	int a = 10;
	int b = 3;
	int c = 0;

	// if后无;号
	/* if ( a == b )
	{
		printf("a==b\n");
		printf("a+b=%d\n", (int)(a + b));
	}
	else
	{
		printf("a*b=%d\n", (int)(a * b));
	} */

	/* printf("请输入一个整数:\n");
	scanf("%d", (int)&num);
	a = num % 4;
	if (0 == a) 
	{
		printf("余 0\n");
	}
	else if (1 == a)
	{
		printf("余 1\n");
	}
	else if (2 == a)
	{
		printf("余 2\n");
	}
	else if (3 == a)
	{
		printf("余 3\n");
	} */


	// 三目运算符
	/* c = a > b ? a : b;
	printf("c = %d\n", c); */

	// switch
	scanf("%d", (int)&num);
	a = num % 4;
	// switch只能是整数判断
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
		default: //上面的条件都不满足
			printf("无\n");
	}


	system("pause");
	return 0;
}