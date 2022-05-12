#define _CRT_SECURE_NO_WARNINGS；
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1024

// 栈的顺序存储
struct SStack
{
	void* data[MAX];
	int m_Size;
};

typedef void* SeqStack;

// 初始化栈
SeqStack init_SeqStack()
{
	struct SStack* myStack = malloc(sizeof(struct SStack));
	if (NULL == myStack)
	{
		return;
	}

	memset(myStack->data, 0, sizeof(void*) * MAX);
	myStack->m_Size = 0;

	return myStack;
}

// 入栈
void push_SeqStack(SeqStack stack, void* data)
{
	if (NULL == stack)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct SStack* myStack = stack;

	// 判断栈是否满
	if (myStack->m_Size == MAX)
	{
		return;
	}
	// 进行尾插
	myStack->data[myStack->m_Size] = data;
	// 更新大小
	myStack->m_Size++;
}

// 出栈
void pop_SeqStack(SeqStack stack)
{
	// 尾部删除
	if (NULL == stack)
	{
		return;
	}
	struct SStack* myStack = stack;

	if (myStack->m_Size == 0)
	{
		return;
	}
	myStack->data[myStack->m_Size - 1] == NULL;

	myStack->m_Size--;
}

// 返回栈顶
void* top_SeqStack(SeqStack stack)
{
	// 返回数组的最后一个元素
	if (NULL == stack)
	{
		return NULL;
	}
	struct SStack* myStack = stack;

	if (myStack->m_Size == 0)
	{
		return NULL;
	}

	return myStack->data[myStack->m_Size - 1];
}

// 栈的大小
int size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct SStack* myStack = stack;

	return myStack->m_Size;
}

// 判断栈是否为空
int isEmpty_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1; // 传入空指针
	}
	struct SStack* myStack = stack;

	if (0 == myStack->m_Size)
	{
		return 1; // 代表为真
	}

	return 0; // 不为空， 假
}

// 销毁
void destory_SeqStack(SeqStack stack)
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
	char name[64];
	int age;
};

void test01()
{
	// 创建栈
	SeqStack myStack = init_SeqStack();

	struct Person p1 = { "赵云", 18 };
	struct Person p2 = { "关羽", 20 };
	struct Person p3 = { "张飞", 19 };
	struct Person p4 = { "刘备", 30 };
	struct Person p5 = { "黄忠", 50 };
	struct Person p6 = { "马超", 16 };

	// 入栈
	push_SeqStack(myStack, &p1);
	push_SeqStack(myStack, &p2);
	push_SeqStack(myStack, &p3);
	push_SeqStack(myStack, &p4);
	push_SeqStack(myStack, &p5);

	printf("栈的大小:%d\n", size_SeqStack(myStack));

	while (isEmpty_SeqStack(myStack) == 0) // 栈不为空，开始查看栈顶，并且出栈
	{
		struct Person* pTop = top_SeqStack(myStack);
		printf("栈顶元素-姓名:%s  年龄:%d\n", pTop->name, pTop->age);

		// 出栈
		pop_SeqStack(myStack);
	}

	printf("栈的大小:%d\n", size_SeqStack(myStack));
	destory_SeqStack(myStack);
}


int main()
{
	test01();

	return 0;
}