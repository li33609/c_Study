#define _CRT_SECURE_NO_WARNINGS��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ��̬����ṹ��
struct dynamicArray
{
	// ��ʵ�ڶ������������ָ��
	void** pAddr;
	// ��������
	int n_Capacity;
	// �����С
	int n_Size;
};

// ��ʼ������  ��ʼ���������� ����ֵ ����ָ��
struct dynamicArray* init_dynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	// ����������ڴ�
	struct dynamicArray* arr = malloc(sizeof(struct dynamicArray));

	if (arr == NULL)
	{
		return NULL;
	}
	// �����Գ�ʼ��
	arr->pAddr = malloc(sizeof(void *) * capacity);
	arr->n_Capacity = capacity;
	arr->n_Size = 0;

	return arr;
}

// ��������
void insert_dynamicArray(struct dynamicArray* arr, void* data, int pos)
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos < 0 || pos > arr->n_Size)
	{
		// β��
		pos = arr->n_Size;
	}

	// �ж������Ƿ�����
	if (arr->n_Size == arr->n_Capacity)
	{
		// 1.�������Ŀռ�
		int newCapacity = arr->n_Capacity * 2;

		// 2.���ٿռ�
		void** newSpace = malloc(sizeof(void*) * newCapacity);

		// 3.��ԭ�ռ����ݿ������¿ռ���
		memcpy(newSpace, arr->pAddr, sizeof(void*) * arr->n_Capacity);

		// 4.�ͷſռ�
		free(arr->pAddr);

		// 5.����ָ��
		arr->pAddr = newSpace;

		// 6.��������
		arr->n_Capacity = newCapacity;
	}

	// ����Ԫ�ز���
	for (int i = arr->n_Size - 1; i >= pos; --i)
	{
		arr->pAddr[i + 1] = arr->pAddr[i];
	}

	// ��������
	arr->pAddr[pos] = data;

	// ��������
	arr->n_Size++;
}

// ����
void foreach_dynamicArray(struct dynamicArray* arr, void(*myPrint)(void*))
{
	if (arr == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->n_Size; ++i)
	{
		myPrint(arr->pAddr[i]);
	}
}

// ɾ��
// ����λ��ɾ��
void removeByPos_dynamicArray(struct dynamicArray *arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}
	if (pos < 0 || pos > arr->n_Size - 1)
	{
		return;
	}

	// ɾ��ָ��Ԫ��(��ǰ������)
	for(int i = pos; i < arr->n_Size; ++i)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}

	arr->n_Size--;
}

// ��ֵ�ķ�ʽ
void removeByValue_dynamicArray(struct dynamicArray* arr, void* data, int(*myCompare)(void*, void*))
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->n_Size; ++i)
	{
		// if (arr->pAddr[i] == data)
		// ���ûص����������û��Լ��������ǶԱ�����
		if(myCompare(arr->pAddr[i], data))
		{
			removeByPos_dynamicArray(arr, i);
			break;
		}
	}
}

// ��������
void destory_dynamicArray(struct dynamicArray *arr)
{
	if (arr == NULL)
	{
		return;
	}

	// �ڲ�ά���ڶ�������ָ�����ͷ�
	if (arr->pAddr != NULL)
	{
		free(arr->pAddr);
	}

	free(arr);
}


struct Person
{
	char name[64];
	int age;
};

// �ص���������ӡ����
void printPerson(void* data)
{
	struct Person* person = data;
	printf("������%s, ����%d\n", person->name, person->age);
}

// �ص���������ֵɾ��
int comparePerson(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

// ���Զ�̬����
void test01()
{
	// ��ʼ����̬����
	struct dynamicArray* arr = init_dynamicArray(5);

	struct Person p1 = { "����", 18 };
	struct Person p2 = { "����", 20 };
	struct Person p3 = { "�ŷ�", 19 };
	struct Person p4 = { "����", 30 };
	struct Person p5 = { "����", 50 };
	struct Person p6 = { "��", 16 };

	printf("����������%d\n", arr->n_Capacity);
	printf("�����С��%d\n", arr->n_Size);

	// ��������
	insert_dynamicArray(arr, &p1, 0);
	insert_dynamicArray(arr, &p2, 0);
	insert_dynamicArray(arr, &p3, 1);
	insert_dynamicArray(arr, &p4, -1);
	insert_dynamicArray(arr, &p5, 1);
	insert_dynamicArray(arr, &p6, 0);

	// 
	foreach_dynamicArray(arr, printPerson);

	printf("����������%d\n", arr->n_Capacity);
	printf("�����С��%d\n", arr->n_Size);

	// ɾ��2
	removeByPos_dynamicArray(arr, 2);
	printf("ɾ��2��ĸ��£�\n");
	foreach_dynamicArray(arr, printPerson);

	struct Person p = { "����", 30 };
	// 
	printf("ɾ��������ĸ��£�\n");
	removeByValue_dynamicArray(arr, &p, comparePerson);
	foreach_dynamicArray(arr, printPerson);

	destory_dynamicArray(arr);
	arr = NULL;
}


int main()
{
	test01();

	return 0;
}