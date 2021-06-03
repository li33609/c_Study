#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// memset
int main01()
{
	int a = 10;
	char buf[10] = "";

	// memset 清除变量中的内容
	strcpy(buf, "hello");
	memset(&a, 0, sizeof(a));
	memset(buf, 0, sizeof(buf));
	printf("a = %d\n", a); // a=0
	printf("buf = %s\n", buf); // buf=

	//	将前9个字符置为'a'
	memset(buf, 'a', sizeof(buf)-1);
	printf("buf = %s\n", buf);

	system("pause");
	return 0;
}


// memcpy 内存拷贝
int main02()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[10] = { b };

	memcpy(b, a, sizeof(int)*5);
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		printf("b=%d ", b[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}


// memcpy 内存拷贝
int main03()
{
	char str1[128] = "";
	char str2[128] = "hello\0 world \0";

	// memcpy(str1, str2, sizeof(int) * 6);// 遇到\0不结束
	strncpy(str1, str2, sizeof(int) * 7); // 遇到\0结束
	printf("str1=%s ", str1);

	system("pause");
	return 0;
}


// memcmp 比较 遇到\0不会结束
int main()
{
	char str1[128] = { 1, 2, 3, 4, 5, 6, 7 };
	char str2[128] = { 1, 2, 3, 4, 5, 6, 7 };
	char str3[128] = "hello\0 world sdf";
	char str4[128] = "hello\0 world \0";

	printf("%d\n", memcmp(str1, str2, sizeof(char) * 7));
	printf("%d\n", memcmp(str3, str4, sizeof(str2)));
	

	system("pause");
	return 0;
}