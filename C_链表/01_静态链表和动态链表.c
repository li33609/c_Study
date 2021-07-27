#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


struct LinkNode
{
	// 数据域
	int num;
	// 指针域
	struct LinkNode* next;
};

// 静态链表(在栈区)
void test01()
{
	// 节点创建
	struct LinkNode node1 = { 10, NULL };
	struct LinkNode node2 = { 20, NULL };
	struct LinkNode node3 = { 30, NULL };
	struct LinkNode node4 = { 40, NULL };
	struct LinkNode node5 = { 50, NULL };

	// 建立关系
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	// 遍历链表
	struct LinkNode* pCurrent = &node1;

	while ( pCurrent != NULL )
	{
		printf("%d ", pCurrent->num);
		pCurrent = pCurrent->next;
	}
}

// 动态链表(在堆区)
void test02()
{
	// 节点创建
	struct LinkNode* node1 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node2 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node3 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node4 = malloc(sizeof(struct LinkNode));
	struct LinkNode* node5 = malloc(sizeof(struct LinkNode));

	// 建立关系
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

	// 遍历链表
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