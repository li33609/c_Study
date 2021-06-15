#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// typedef
// 1.定义结构体别名
typedef struct Person
{
	char name[64];
	int age;
}PERSON;

// 2.区分数据类型
void test01()
{
	typedef char* p;
	p p1, p2;// （全部为char *类型）
}


int main()
{
	PERSON p1 = {"小米", 17};

	system("pause"); 
	return 0;
}
