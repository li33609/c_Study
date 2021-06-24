#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


int My_Strstr(char *str, char *dst)
{
	int num = 0;

	while (*str != '\0')
	{
		if (*str != *dst)
		{
			str++;
			num++;

			continue;
		}

		char* subStr = str;
		char* subDst = dst;

		while (*subDst != '\0')
		{
			if (*subStr != *subDst)
			{
				str++;
				num++;
				break;
			}
			
			subDst++;
			subStr++;
		}

		if (*subDst == '\0')
		{
			return num;
		}
	}
	return -1;
}

void test01()
{
	char* str = "hellosoclolpwb";
	char* dst = "pwb";

	int ret = My_Strstr(str, dst);
	if (ret != -1)
	{
		printf("找到该字符串的位置: %d\n", ret);
	}
	else
	{
		printf("未查到改字符串！\n");
	}
}


int main()
{
	test01();

	system("pause");
	return 0;
}