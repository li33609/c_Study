#define _CRT_SECURE_NO_WARNINGS��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dynamicArray.h"

#define MAX 1024

typedef void* seqQueue;

//��ʼ������
seqQueue init_SeqQueue()
{
	struct dynamicArray* array = init_dynamicArray(MAX);

	return array;
}
//���
void push_SeqQueue(seqQueue queue, void* data)
{
	//�ȼ��� β��
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct dynamicArray* array = queue;

	if (array->m_Size >= MAX)
	{
		return;
	}

	insert_dynamicArray(array, array->m_Size, data);
}
//����
void pop_SeqQueue(seqQueue queue)
{
	//�ȼ���  ͷɾ��
	if (queue == NULL)
	{
		return;
	}

	struct dynamicArray* array = queue;

	if (array->m_Size <= 0)
	{
		return;
	}
	removeByPos_dynamicArray(array, 0);
}
//���ض�ͷԪ��
void* front_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray* array = queue;

	return array->pAddr[0];

}

//���ض�βԪ��
void* back_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray* array = queue;

	return array->pAddr[array->m_Size - 1];

}

//���д�С
int size_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct dynamicArray* array = queue;

	return array->m_Size;

}

//�ж��Ƿ�Ϊ��
int isEmpty_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct dynamicArray* array = queue;
	if (array->m_Size == 0)
	{
		return 1;
	}

	return 0;
}

//���ٶ���
void destroy_SeqQueue(seqQueue queue)
{

	if (queue == NULL)
	{
		return;
	}

	destroy_dynamicArray(queue);
	queue = NULL;
}



struct Person
{
	char name[64];
	int age;
};


void test01()
{
	// ��ʼ������
	seqQueue myQueue = init_SeqQueue();

	// ׼������
	struct Person p1 = { "����", 18 };
	struct Person p2 = { "����", 20 };
	struct Person p3 = { "�ŷ�", 19 };
	struct Person p4 = { "����", 30 };
	struct Person p5 = { "����", 50 };
	struct Person p6 = { "��", 16 };

	// ���
	push_SeqQueue(myQueue, &p1);
	push_SeqQueue(myQueue, &p2);
	push_SeqQueue(myQueue, &p3);
	push_SeqQueue(myQueue, &p4);
	push_SeqQueue(myQueue, &p5);

	// ���д�С
	printf("���д�С:%d\n", size_SeqQueue(myQueue));

	// ͨ��ѭ����� ��β ִ�г���
	while (isEmpty_SeqQueue(myQueue) == 0)
	{
		struct Person* personFront = front_SeqQueue(myQueue);
		printf("��ͷԪ�� ����:%s ����:%d\n", personFront->name, personFront->age);

		struct Person* personBack = back_SeqQueue(myQueue);
		printf("��βԪ�� ����:%s ����:%d\n", personBack->name, personBack->age);

		// ����
		pop_SeqQueue(myQueue);
	}

	// ���д�С
	printf("���д�С:%d\n", size_SeqQueue(myQueue));
	destroy_SeqQueue(myQueue);
}


int main()
{
	test01();

	return 0;
}