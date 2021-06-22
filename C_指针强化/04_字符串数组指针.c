#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


//sizeof计算数组大小，数组包含'\0'字符
//strlen计算字符串的长度，到'\0'结束

// 字符串拷贝
// 直接进行拷贝
void my_strcpy01(char *dst, char *source)
{
	int len = strlen(source);

	for (int i = 0; i < len; i++)
	{
		dst[i] = source[i];
	}
	dst[len] = '\0';
}

// 利用字符串指针实现
void my_strcpy02(char* dst, char* source)
{
	while (*source != '\0')
	{
		*dst = *source;

		dst++;
		source++;
	}

	*dst = '\0';
}

void my_strcpy03(char* dst, char* source)
{
	while (*dst++ = *source++)
	{

	}
}

// 字符串翻转

void test01()
{
	char* str = "hello world";
	char buf[1024];

	// my_strcpy01(buf, str);
	// my_strcpy02(buf, str);
	my_strcpy03(buf, str);
	printf("buf=%s\n", buf);
}


// 字符串反转
// 直接反转
void rever_str01(char *source)
{
	int len = strlen(source);
	int end = len - 1;
	int start = 0;

	while (start < end)
	{
		char temp = source[start];
		source[start] = source[end];
		source[end] = temp;

		start++;
		end--;
	}
}

// 利用指针实现
void rever_str02(char* source)
{
	char* start = source;
	char* end = source + strlen(source) - 1;

	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}

void test02()
{
	char str[64] = "abcdefg";

	// rever_str01(str);
	rever_str02(str);
	printf("str=%s\n", str);
}


int main()
{
	test02();

	system("pause");
	return 0;
}