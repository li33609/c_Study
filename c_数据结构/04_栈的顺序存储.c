#define _CRT_SECURE_NO_WARNINGS��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1024

// ջ��˳��洢
struct SStack
{
	void* data[MAX];
	int m_Size;
};

typedef void* SeqStack;

// ��ʼ��ջ
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

// ��ջ
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

	// �ж�ջ�Ƿ���
	if (myStack->m_Size == MAX)
	{
		return;
	}
	// ����β��
	myStack->data[myStack->m_Size] = data;
	// ���´�С
	myStack->m_Size++;
}

// ��ջ
void pop_SeqStack(SeqStack stack)
{
	// β��ɾ��
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

// ����ջ��
void* top_SeqStack(SeqStack stack)
{
	// ������������һ��Ԫ��
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

// ջ�Ĵ�С
int size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}
	struct SStack* myStack = stack;

	return myStack->m_Size;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1; // �����ָ��
	}
	struct SStack* myStack = stack;

	if (0 == myStack->m_Size)
	{
		return 1; // ����Ϊ��
	}

	return 0; // ��Ϊ�գ� ��
}

// ����
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
	// ����ջ
	SeqStack myStack = init_SeqStack();

	struct Person p1 = { "����", 18 };
	struct Person p2 = { "����", 20 };
	struct Person p3 = { "�ŷ�", 19 };
	struct Person p4 = { "����", 30 };
	struct Person p5 = { "����", 50 };
	struct Person p6 = { "��", 16 };

	// ��ջ
	push_SeqStack(myStack, &p1);
	push_SeqStack(myStack, &p2);
	push_SeqStack(myStack, &p3);
	push_SeqStack(myStack, &p4);
	push_SeqStack(myStack, &p5);

	printf("ջ�Ĵ�С:%d\n", size_SeqStack(myStack));

	while (isEmpty_SeqStack(myStack) == 0) // ջ��Ϊ�գ���ʼ�鿴ջ�������ҳ�ջ
	{
		struct Person* pTop = top_SeqStack(myStack);
		printf("ջ��Ԫ��-����:%s  ����:%d\n", pTop->name, pTop->age);

		// ��ջ
		pop_SeqStack(myStack);
	}

	printf("ջ�Ĵ�С:%d\n", size_SeqStack(myStack));
	destory_SeqStack(myStack);
}


int main()
{
	test01();

	return 0;
}