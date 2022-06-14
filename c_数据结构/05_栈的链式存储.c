#define _CRT_SECURE_NO_WARNINGS；
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkNode
{
	// 只维护指针域
	struct LinkNode* next;
};

struct LStack
{
	struct LinkNode pHeader;
	int m_Size;
};

typedef void* LinkStack;


// 初始化栈
LinkStack init_LinkStack()
{
	struct LStack* myStack = malloc(sizeof(struct LStack));
	if (NULL == myStack)
	{
		return;
	}

	myStack->pHeader.next = NULL;
	myStack->m_Size = 0;

	return myStack;
}

// 入栈
void push_LinkStack(LinkStack stack, void* data)
{
	if (NULL == stack)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}

	struct LStack* myStack = stack;

	// 取出用户前四个字节
	struct LinkNode* myNode = data;

	myNode->next = myStack->pHeader.next;
	myStack->pHeader.next = myNode;

	myStack->m_Size++;
}

// 出栈
void pop_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	struct LStack* myStack = stack;

	// 本质头删
	if (myStack->m_Size == 0)
	{
		return;
	}

	// 创建指向第一个节点的指针
	struct LinkNode* pFirst = myStack->pHeader.next;

	// 更新节点
	myStack->pHeader.next = pFirst->next;

	myStack->m_Size--;
}

// 返回栈顶
void* top_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return;
	}
	struct LStack* myStack = stack;

	if (myStack->m_Size == 0)
	{
		return NULL;
	}

	return myStack->pHeader.next;
}

// 栈的大小
int size_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct LStack* myStack = stack;

	return myStack->m_Size;
}

// 判断栈是否为空
int isEmpty_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct LStack* myStack = stack;

	if (myStack->m_Size == 0)
	{
		return 1; // 为空
	}

	return 0; // 不为空， 假
}

// 销毁
void destory_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	free(stack);
	stack = NULL;
}




struct Person
{
	int* a;
	char name[64];
	int age;
};

void test01()
{
	// 创建栈
	LinkStack myStack = init_LinkStack();

	struct Person p1 = { NULL,"赵云", 18 };
	struct Person p2 = { NULL,"关羽", 20 };
	struct Person p3 = { NULL,"张飞", 19 };
	struct Person p4 = { NULL,"刘备", 30 };
	struct Person p5 = { NULL,"黄忠", 50 };
	struct Person p6 = { NULL,"马超", 16 };

	// 入栈
	push_LinkStack(myStack, &p1);
	push_LinkStack(myStack, &p2);
	push_LinkStack(myStack, &p3);
	push_LinkStack(myStack, &p4);
	push_LinkStack(myStack, &p5);

	printf("栈的大小:%d\n", size_LinkStack(myStack));

	while (isEmpty_LinkStack(myStack) == 0) // 栈不为空，开始查看栈顶，并且出栈
	{
		struct Person* pTop = top_LinkStack(myStack);
		printf("栈顶元素-姓名:%s  年龄:%d\n", pTop->name, pTop->age);

		// 出栈
		pop_LinkStack(myStack);
	}

	printf("栈的大小:%d\n", size_LinkStack(myStack));
	destory_LinkStack(myStack);
}


int main()
{
	test01();

	return 0;
}