#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main01()
{
	int num = 0;
	int a = 0;
	int b = 0;
	int c;

	printf("请输入num：\n");
	scanf("%d", &num);
	a = num % 10;
	printf("这个个数的个位是：%d\n", a);
	b = num / 10 % 10;
	printf("这个个数的十位是：%d\n", b);
	c = num / 100 % 10;
	printf("这个个数的百位是：%d\n", c);

	system("pause");
	return 0;
}

int main()
{
	int a = 0;
	int b = 0;
	
	/* a++;
	printf("%d\n", a);
	++a;
	printf("%d\n", a);*/

	printf("%d\n", a == b);
	printf("%d\n", a < b);

	system("pause");
	return 0;
}