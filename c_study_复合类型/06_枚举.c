#define _CRT_SECURE_NO_WARNINGS；
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 枚举
enum ab {SUN, RAIN, SNOW}; // 0 1 2

// 
enum my_bool { false, true };
typedef enum my_bool bool; // 取别名

int main()
{
	bool a;

	a = false;
	printf("%d\n", a);
	
	system("pause");
	return 0;
}