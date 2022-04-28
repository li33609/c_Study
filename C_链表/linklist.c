#include "linklist.h"


// ��ʼ������
// �����ķ���ֵ �����õ������ͷ���
struct LinkNode* init_linkList()
{
	struct LinkNode* pHeader = malloc(sizeof(struct LinkNode));
	if (pHeader == NULL)
	{
		return;
	}

	pHeader->num = -1;
	pHeader->next = NULL;

	// ����β�ڵ�λ�ã�����β��
	struct LinkNode* pTail = pHeader;
	int val = -1;

	while (1)
	{
		printf("��������ݣ�-1�������!\n");
		scanf("%d", &val);

		if (val == -1)
		{
			break;
		}

		// �������б�
		struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
		newNode->num = val;
		newNode->next = NULL;

		// ���½ڵ�ָ��
		pTail->next = newNode;
		pTail = newNode;
	}

	// ���ظ��û�
	return pHeader;
}

// �����б�
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

// ����ڵ�
void insert_linklist(struct LinkNode* pHeader, int old_val, int new_val)
{
	if (pHeader == NULL)
	{
		return;
	}

	// ����ǰ������
	struct LinkNode* pPrev = pHeader;
	struct LinkNode* pCurrent = pHeader->next;

	while ( pCurrent != NULL )
	{
		// �ж������е�ֵ�Ƿ���û�������ͬ,��ͬ������ѭ��
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

	// ���в������(����ָ��ָ��)
	new_node->next = pCurrent;
	pPrev->next = new_node;
}

// ɾ���ڵ�
void delete_linklist(struct LinkNode* pHeader, int delete_num)
{
	if ( pHeader == NULL )
	{
		return;
	}

	// ����ǰ������
	struct LinkNode* pPrev = pHeader;
	struct LinkNode* pCurrent = pHeader->next;

	while (pCurrent != NULL)
	{
		// ����ָ���ҵ�λ��
		if (pCurrent->num == delete_num)
		{
			break;
		}

		// û�ҵ������ƶ�ָ��
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

	if (pCurrent == NULL)
	{
		printf("û���û�����ֵ��%d��\n", delete_num);
		return;
	}


	// ����ָ��ָ��
	pPrev->next = pCurrent->next;

	// ɾ���ڵ�
	free(pCurrent);
	pCurrent = NULL;
}

// ����б�
void clear_linklist(struct LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}

	// �����ڵ�
	struct LinkNode* pCurrent = pHeader->next;
	while (pCurrent != NULL)
	{
		// �ȼ�¼pCurrent����һ���ڵ�
		struct LinkNode* pNext = pCurrent->next;
		// �ͷ�pCurrent
		free(pCurrent);
		// �ڵ�����ƶ�
		pCurrent = pNext;
	}

	// ͷ����ÿ�
	pHeader->next = NULL;
}

// ��������
void destory_linklist(struct LinkNode* pHeader)
{
	if (pHeader == NULL)
	{
		return;
	}

	// ������б�
	clear_linklist(pHeader);

	// ����ͷ���
	free(pHeader);
	pHeader = NULL;
}

// ����ת
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

		// ����ָ��
		pCurrent->next = pPrev;

		// �ƶ�����ָ��
		pPrev = pCurrent;
		pCurrent = pNext;
	}
	// ����ͷ���
	pHeader->next = pPrev;
}

// ͳ���������
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