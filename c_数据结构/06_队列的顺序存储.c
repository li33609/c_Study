#define _CRT_SECURE_NO_WARNINGS；
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dynamicArray.h"

#define MAX 1024

typedef void* seqQueue;

//初始化队列
seqQueue init_SeqQueue()
{
	struct dynamicArray* array = init_dynamicArray(MAX);

	return array;
}
//入队
void push_SeqQueue(seqQueue queue, void* data)
{
	//等价于 尾插
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
//出队
void pop_SeqQueue(seqQueue queue)
{
	//等价于  头删除
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
//返回队头元素
void* front_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray* array = queue;

	return array->pAddr[0];

}

//返回队尾元素
void* back_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray* array = queue;

	return array->pAddr[array->m_Size - 1];

}

//队列大小
int size_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct dynamicArray* array = queue;

	return array->m_Size;

}

//判断是否为空
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

//销毁队列
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
	// 初始化队列
	seqQueue myQueue = init_SeqQueue();

	// 准备数据
	struct Person p1 = { "赵云", 18 };
	struct Person p2 = { "关羽", 20 };
	struct Person p3 = { "张飞", 19 };
	struct Person p4 = { "刘备", 30 };
	struct Person p5 = { "黄忠", 50 };
	struct Person p6 = { "马超", 16 };

	// 入队
	push_SeqQueue(myQueue, &p1);
	push_SeqQueue(myQueue, &p2);
	push_SeqQueue(myQueue, &p3);
	push_SeqQueue(myQueue, &p4);
	push_SeqQueue(myQueue, &p5);

	// 队列大小
	printf("队列大小:%d\n", size_SeqQueue(myQueue));

	// 通过循环入队 队尾 执行出队
	while (isEmpty_SeqQueue(myQueue) == 0)
	{
		struct Person* personFront = front_SeqQueue(myQueue);
		printf("队头元素 姓名:%s 年龄:%d\n", personFront->name, personFront->age);

		struct Person* personBack = back_SeqQueue(myQueue);
		printf("队尾元素 姓名:%s 年龄:%d\n", personBack->name, personBack->age);

		// 出队
		pop_SeqQueue(myQueue);
	}

	// 队列大小
	printf("队列大小:%d\n", size_SeqQueue(myQueue));
	destroy_SeqQueue(myQueue);
}


int main()
{
	test01();

	return 0;
}