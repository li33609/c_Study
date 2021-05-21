#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char a;
	char ch;
	char b;
	// 默认存六位
	// float存7位
	float c;
	// double存15位
	double d;

	a = 'a';
	ch = '8';
	c = 3.14;
	d = 2.1315151313131;

	// scanf("%c", &b);
	// printf("b=%c\n", b);
	printf("a=%d\n", a);
	printf("a=%c\n", a);
	printf("c=%f\n", c);
	printf("d=%.10lf\n", d);


	system("pause");
	return 0;
}