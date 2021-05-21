#include<stdio.h>
#include<stdlib.h>


int main()
{

	int a = 123;
	int b = 056;
	int c = 0xab;
	unsigned int d = 0xffffffff;

	// 十进制
	printf("a=%d\n", a);
	// 八进制
	printf("b=%o\n", b);
	// 十六进制
	printf("c=%x\n", c);
	// 有符号十六进制打印
	printf("有符号十六进制打印 d=%d\n", d);
	// 无符号十六进制打印
	printf("无符号十六进制打印 d=%u\n", d);


	system("pause");

	return 0;
}