#include "linklist.h"


// 初始化链表
// 函数的返回值 创建好的链表的头结点
struct LinkNode* init_linkList()
{
	struct LinkNode* pHeader = malloc(sizeof(struct LinkNode));
	if (pHeader == NULL)
	{
		return;
	}

	pHeader->num = -1;
	pHeader->next = NULL;

	// 创建尾节点位置，方便尾插
	struct LinkNode* pTail = pHeader;
	int val = -1;

	while (1)
	{
		printf("请插入数据，-1代表结束!\n");
		scanf("%d", &val);

		if (val == -1)
		{
			break;
		}

		// 创建新列表
		struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
		newNode->num = val;
		newNode->next = NULL;

		// 更新节点指向
		pTail->next = newNode;
		pTail = newNode;
	}

	// 返回给用户
	return pHeader;
}

// 遍历列表
void for_reach_linklist(struct LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}

	struct LinkNode* pCurrent = pHeader->next;

	while ( pCurrent != NULL )
	{
		// printf("%d ", pCurrent->num);
		pCurrent = pCurrent->next;
	}
	printf("\n");
}

// 插入节点
void insert_linklist(struct LinkNode* pHeader, int old_val, int new_val)
{
	if (pHeader == NULL)
	{
		return;
	}

	// 定义前后链表
	struct LinkNode* pPrev = pHeader;
	struct LinkNode* pCurrent = pHeader->next;

	while ( pCurrent != NULL )
	{
		// 判断链表中的值是否和用户输入相同,相同则跳出循环
		if ( pCurrent->num == old_val )
		{
			break;
		}

		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	struct LinkNode *new_node = malloc(sizeof(struct LinkNode));
	new_node->next = NULL;
	new_node->num = new_val;

	// 进行插入操作(更改指针指向)
	new_node->next = pCurrent;
	pPrev->next = new_node;
}

// 删除节点
void delete_linklist(struct LinkNode* pHeader, int delete_num)
{
	if ( pHeader == NULL )
	{
		return;
	}

	// 定义前后链表
	struct LinkNode* pPrev = pHeader;
	struct LinkNode* pCurrent = pHeader->next;

	while (pCurrent != NULL)
	{
		// 先让指针找到位置
		if (pCurrent->num == delete_num)
		{
			break;
		}

		// 没找到继续移动指针
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	if (pCurrent == NULL)
	{
		printf("没有用户所需值：%d！\n", delete_num);
		return;
	}


	// 更改指针指向
	pPrev->next = pCurrent->next;

	// 删除节点
	free(pCurrent);
	pCurrent = NULL;
}

// 清空列表
void clear_linklist(struct LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}

	// 创建节点
	struct LinkNode* pCurrent = pHeader->next;
	while (pCurrent != NULL)
	{
		// 先记录pCurrent的下一个节点
		struct LinkNode* pNext = pCurrent->next;
		// 释放pCurrent
		free(pCurrent);
		// 节点向后移动
		pCurrent = pNext;
	}

	// 头结点置空
	pHeader->next = NULL;
}

// 销毁链表
void destory_linklist(struct LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}

	// 先清空列表
	clear_linklist(pHeader);

	// 销毁头结点
	free(pHeader);
	pHeader = NULL;
}

// 链表翻转
void reverse_linkList(struct LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return 0;
	}

	struct LinkNode* pPrev = NULL;
	struct LinkNode* pCurrent = pHeader->next;
	struct LinkNode* pNext = NULL;

	while (pCurrent != NULL)
	{
		pNext = pCurrent->next;

		// 更改指向
		pCurrent->next = pPrev;

		// 移动辅助指针
		pPrev = pCurrent;
		pCurrent = pNext;
	}
	// 更新头结点
	pHeader->next = pPrev;
}

// 统计链表个数
int size_linkList(struct LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return 0;
	}
	int num = 0;

	struct LinkNode* pCurrent = pHeader->next;

	while (pCurrent != NULL)
	{
		pCurrent = pCurrent->next;
		num++;
	}

	return num;
}