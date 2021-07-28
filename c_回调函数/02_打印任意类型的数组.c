#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


struct Person
{
	char name[64];
	int age;
};

// ����1 ���������׵�ַ 2 ������ÿ��Ԫ����ռ���ڴ�ռ� 3 ���鳤��
void printArray(void* arr, int eleSize, int len, void(*myPrint)(void *))
{
	char* p = arr;

	for (int i = 0; i < len; i++)
	{
		// ��ȡÿ��Ԫ���׵�ַ
		char* pAddr = p + eleSize * i;

		// printf("%d ", *(int*)pAddr);
		myPrint(pAddr);
	}
}

void printInt(void* data)
{
	int* num = data;
	printf("%d ", *num);
}

void test01()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int len = sizeof(arr) / sizeof(arr[1]);

	printArray(arr, sizeof(int), len, printInt);
}

void printStruct(void* data)
{
	struct Person* num = data;
	printf("������%s, ���䣺%d \n", num->name, num->age);

}

void test02()
{
	struct Person personArray[] =
	{
		{"aaa", 18},
		{"bbb", 16},
		{"ccc", 17},
		{"ddd", 20}
	};

	int len = sizeof(personArray) / sizeof(personArray[1]);
	printArray(personArray, sizeof(struct Person), len, printStruct);
}

int findArray(void* array, int eleSize, int len, void* data, int(*myCompare)(void*, void*))
{
	char* p = array;

	for (int i = 0; i < len; i++)
	{
		char* eleAddr = p + eleSize * i;
		
		if (myCompare(data, eleAddr))
		{
			return 1;
		}
	}
	return 0;
}

int comparePerson(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
	{
		return 1;
	}
	return 0;
}

// �����������Ƿ���ָ����Ԫ��
void test03()
{
	struct Person personArray[] =
	{
		{"aaa", 18},
		{"bbb", 16},
		{"ccc", 17},
		{"ddd", 20}
	};
	int len = sizeof(personArray) / sizeof(personArray[0]);

	struct Person p = { "ccc", 17 };

	int ret = findArray(personArray, sizeof(struct Person), len, &p, comparePerson);

	if (ret)
	{
		printf("�ҵ��ˣ�\n");
	}
	else
	{
		printf("û�ҵ���\n");
	}
}


int main()
{
	test03();

	system("pause");
	return 0;
}