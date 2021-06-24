#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


typedef struct Preson
{
	char name[64];
	int id;
	int age;
	int score;
}PERSON;

// 加const修饰函数中的形参，防止别人修改
struct_printf(const PERSON *person)
{
	// person->score = 100; // error

	printf("姓名:%s id:%d 年龄:%d 分数:%d\n", person->name, person->id, person->age, person->score);
}

void test01()
{
	PERSON p1 = {"Bob", 1, 18, 60};

	struct_printf(&p1);
}


int main()
{
	test01();

	system("pause");
	return 0;
}