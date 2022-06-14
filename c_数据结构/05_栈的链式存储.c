#define _CRT_SECURE_NO_WARNINGS��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LinkNode
{
	// ֻά��ָ����
	struct LinkNode* next;
};

struct LStack
{
	struct LinkNode pHeader;
	int m_Size;
};

typedef void* LinkStack;


// ��ʼ��ջ
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

// ��ջ
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

	// ȡ���û�ǰ�ĸ��ֽ�
	struct LinkNode* myNode = data;

	myNode->next = myStack->pHeader.next;
	myStack->pHeader.next = myNode;

	myStack->m_Size++;
}

// ��ջ
void pop_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return;
	}

	struct LStack* myStack = stack;

	// ����ͷɾ
	if (myStack->m_Size == 0)
	{
		return;
	}

	// ����ָ���һ���ڵ��ָ��
	struct LinkNode* pFirst = myStack->pHeader.next;

	// ���½ڵ�
	myStack->pHeader.next = pFirst->next;

	myStack->m_Size--;
}

// ����ջ��
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

// ջ�Ĵ�С
int size_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct LStack* myStack = stack;

	return myStack->m_Size;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty_LinkStack(LinkStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct LStack* myStack = stack;

	if (myStack->m_Size == 0)
	{
		return 1; // Ϊ��
	}

	return 0; // ��Ϊ�գ� ��
}

// ����
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
	// ����ջ
	LinkStack myStack = init_LinkStack();

	struct Person p1 = { NULL,"����", 18 };
	struct Person p2 = { NULL,"����", 20 };
	struct Person p3 = { NULL,"�ŷ�", 19 };
	struct Person p4 = { NULL,"����", 30 };
	struct Person p5 = { NULL,"����", 50 };
	struct Person p6 = { NULL,"��", 16 };

	// ��ջ
	push_LinkStack(myStack, &p1);
	push_LinkStack(myStack, &p2);
	push_LinkStack(myStack, &p3);
	push_LinkStack(myStack, &p4);
	push_LinkStack(myStack, &p5);

	printf("ջ�Ĵ�С:%d\n", size_LinkStack(myStack));

	while (isEmpty_LinkStack(myStack) == 0) // ջ��Ϊ�գ���ʼ�鿴ջ�������ҳ�ջ
	{
		struct Person* pTop = top_LinkStack(myStack);
		printf("ջ��Ԫ��-����:%s  ����:%d\n", pTop->name, pTop->age);

		// ��ջ
		pop_LinkStack(myStack);
	}

	printf("ջ�Ĵ�С:%d\n", size_LinkStack(myStack));
	destory_LinkStack(myStack);
}


int main()
{
	test01();

	return 0;
}