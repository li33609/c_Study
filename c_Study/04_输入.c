#include<stdio.h>
#include<stdlib.h>


int main()
{

	int num = 0;

	scanf("%d", &num);
	printf("%d\n", num);
	printf("所占字节大小:%d\n", sizeof(num));


	system("pause");

	return 0;
}