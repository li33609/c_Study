#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


struct LinkNode
{
	// ������
	int num;
	// ָ����
	struct LinkNode* next;
};

// ��̬����(��ջ��)
void test01()
{
	// �ڵ㴴��
	struct LinkNode node1 = { 10, NULL };
	struct LinkNode node2 = { 20, NULL };
	struct LinkNode node3 = { 30, NULL };
	struct LinkNode node4 = { 40, NULL };
	struct LinkNode node5 = { 50, NULL };

	// ������ϵ
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	// ��������
	struct LinkNode* pCurrent = &node1;

	while ( pCurrent != NULL )
	{
		printf("%d ", pCurrent->num);
		pCurrent = pCurrent->next;
	}
}

// ��̬����(�ڶ���)
void test02()
{
	// �ڵ㴴��
	struct LinkNode* node1 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node2 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node3 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node4 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node5 = malloc(sizeof(struct LinkNode));

	// ������ϵ
	node1->num = 10;
	node1->next = node2;

	node2->num = 20;
	node2->next = node3;

	node3->num = 30;
	node3->next = node4;

	node4->num = 40;
	node4->next = node5;

	node5->num = 50;
	node5->next = NULL;

	// ��������
	struct LinkNode* pCurrent = node1;

	while (pCurrent != NULL)
	{
		printf("%d ", pCurrent->num);
		pCurrent = pCurrent->next;
	}

	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
}


int main()
{
	test02();

	system("pause");
	return 0;
}