#define _CRT_SECURE_NO_WARNINGS��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �ڵ�ṹ�����
struct LinkNode
{
	// ֻά��ָ����
	struct LinkNode* next;
};

struct LList
{
	struct LinkNode pHeader; // ͷ���
	int m_size;
};

typedef void* LinkList;

// ��ʼ���ڵ�
LinkList init_LinkList()
{
	struct LList* mylist = malloc(sizeof(struct LList));
	if (mylist == NULL)
	{
		return NULL;
	}

	mylist->m_size = 0;
	mylist->pHeader.next = NULL;

	return mylist;
}

// ��������
void insert_LinkList(LinkList list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList* mylist = list;
	if (pos < 0 || mylist->m_size - 1 < pos)
	{
		pos = mylist->m_size;
	}

	// ȡ���û����ݵ�ǰ4���ֽڿռ�
	struct LinkNode* myNode = data;

	// �ҵ�������λ�õ�ǰ���ڵ�
	struct LinkNode* pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// ����ָ��ָ��
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	mylist->m_size++;
}

// ����
void foreach_LinkList(LinkList list,void (*myPrint)(void *))
{
	if (list == NULL)
	{
		return;
	}

	struct LList* mylist = list;

	struct LinkNode* pCurrent = mylist->pHeader.next;

	for (int i = 0; i < mylist->m_size; i++)
	{
		// pCurrent�û�������׵�ַ
		myPrint(pCurrent);

		pCurrent = pCurrent->next;
	}
}

// ��λ��ɾ��
void removeByPos_LinkList(LinkList list, int pos)
{
	if (NULL == list)
	{
		return;
	}
	struct LList* mylist = list;

	if (pos < 0 || pos > mylist->m_size - 1)
	{
		return;
	}

	// �ҵ���ɾ����ǰ��
	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// ��¼��ɾ����λ��
	struct LinkNode* pDel = pCurrent->next;

	pCurrent->next = pDel->next;

	mylist->m_size--;
}



struct Person
{
	struct LinkNode node;
	char name[64];
	int age;
};

// �ص�����
void printPerson(void* data)
{
	struct Person* person = data;

	printf("����:%s, ����:%d \n", person->name, person->age);
}


void test01()
{
	// ��ʼ��
	LinkList mylist = init_LinkList();

	// ��������
	struct Person p1 = { NULL, "����", 18 };
	struct Person p2 = { NULL, "����", 20 };
	struct Person p3 = { NULL, "�ŷ�", 19 };
	struct Person p4 = { NULL, "����", 30 };
	struct Person p5 = { NULL, "����", 50 };
	
	// ��������
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist, 1, &p3);
	insert_LinkList(mylist, -1, &p4);
	insert_LinkList(mylist, 0, &p5);

	// �����б�
	foreach_LinkList(mylist, printPerson);

	// ɾ���ڵ�
	printf("----------------------\n");
	removeByPos_LinkList(mylist, 2);
	foreach_LinkList(mylist, printPerson);
}

int main()
{
	test01();

	return 0;
}