#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ڵ�ṹ��
struct QueueNode
{
	struct QueueNode* next;

};

//�����Ľṹ�� --- ����
struct LQueue
{
	struct QueueNode pHeader; //ͷ�ڵ�
	int m_Size; //���еĴ�С
	struct QueueNode* pTail; //��¼β�ڵ��ָ��
};

typedef void* LinkQueue;
//初始化队列
LinkQueue init_LinkQueue()
{
	struct LQueue* myQueue = malloc(sizeof(struct LQueue));
	if (myQueue == NULL)
	{
		return NULL;
	}

	myQueue->m_Size = 0;
	myQueue->pHeader.next = NULL;
	myQueue->pTail = &myQueue->pHeader; //尾节点开始指向的就是头节点
	return myQueue;
}
//入队
void push_LinkQueue(LinkQueue queue, void* data)
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

	struct LQueue* myQueue = queue;

	struct QueueNode* myNode = data;


	//更改指针指向
	myQueue->pTail->next = myNode;
	myNode->next = NULL;
	//更新尾节点
	myQueue->pTail = myNode;

	//更新队列大小
	myQueue->m_Size++;

}
//出队
void pop_LinkQueue(LinkQueue queue)
{
	//等价于 头删 

	if (queue == NULL)
	{
		return;
	}
	struct LQueue* myQueue = queue;

	if (myQueue->m_Size == 0)
	{
		return;
	}

	if (myQueue->m_Size == 1)
	{
		myQueue->pHeader.next = NULL;
		myQueue->pTail = &myQueue->pHeader; //维护尾节点指针
		myQueue->m_Size = 0;
		return;
	}

	//记录第一个节点
	struct QueueNode* pFirst = myQueue->pHeader.next;

	myQueue->pHeader.next = pFirst->next;

	//更新队列大小
	myQueue->m_Size--;

}
//返回队头
void* front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue* myQueue = queue;

	return myQueue->pHeader.next;

}
//返回队尾
void* back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue* myQueue = queue;

	return myQueue->pTail;

}
//返回队列大小
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue* myQueue = queue;

	return myQueue->m_Size;

}
//判断队列是否为空
int isEmpty_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue* myQueue = queue;

	if (myQueue->m_Size == 0)
	{
		return 1;
	}

	return 0;

}
//销毁队列
void destroy_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	free(queue);
	queue = NULL;
}



struct Person
{
	void* node;
	char name[64];
	int age;
};

void test01()
{
	//初始化队列
	LinkQueue myQueue = init_LinkQueue();

	//准备数据
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };

	//入队
	push_LinkQueue(myQueue, &p1);
	push_LinkQueue(myQueue, &p2);
	push_LinkQueue(myQueue, &p3);
	push_LinkQueue(myQueue, &p4);
	push_LinkQueue(myQueue, &p5);

	printf("队列大小为：%d\n", size_LinkQueue(myQueue));

	while (isEmpty_LinkQueue(myQueue) == 0)
	{
		//队头元素
		struct Person* pFront = front_LinkQueue(myQueue);
		printf("链式存储 队头元素姓名：%s 年龄：%d \n", pFront->name, pFront->age);

		//队尾元素
		struct Person* pBack = back_LinkQueue(myQueue);
		printf("链式存储 队尾元素姓名：%s 年龄：%d \n", pBack->name, pBack->age);

		//出队
		pop_LinkQueue(myQueue);
	}

	printf("队列大小为：%d\n", size_LinkQueue(myQueue));

	//销毁队列
	destroy_LinkQueue(myQueue);
	myQueue = NULL;
}


int main()
{
	test01();

	return 0;
}