#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	char a;
	char ch;
	char b;
	// Ĭ�ϴ���λ
	// float��7λ
	float c;
	// double��15λ
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