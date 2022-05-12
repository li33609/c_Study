#define _CRT_SECURE_NO_WARNINGS��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �ڵ�ṹ��
struct LinkNode
{
	// ������
	void* data;
	struct LinkNode* next;
};

// ����ṹ��
struct LList
{
	struct LinkNode pHeader; // ͷ�ڵ�
	int m_Size;
};

typedef void* LinkList;

// ��ʼ������
LinkList init_LinkList()
{
	// �����ڴ�
	struct LList* mylist = malloc(sizeof(struct LList));
	if (mylist == NULL)
	{
		return NULL;
	}

	mylist->pHeader.data = NULL;
	mylist->pHeader.next = NULL;
	mylist->m_Size = 0;

	return mylist;
}

// ����ڵ�
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
	if (pos < 0 || pos > mylist->m_Size)
	{
		// ��Чλ��
		pos = mylist->m_Size;
	}

	// ������ʱ�ڵ㣬ͨ��ѭ���ҵ�������λ��
	struct LinkNode* pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// ��ʱpCurrentΪ����ڵ�

	// �����½ڵ�
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	// �����ڵ�֮��Ĺ�ϵ
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	// ����������
	mylist->m_Size++;
}

// ��������
void foreach_LinkList(LinkList list, void(*myPrint)(void*))
{
	if (list == NULL)
	{
		return;
	}
	struct LList* mylist = list;
	struct LinkNode* pCurrent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_Size; i++)
	{
		myPrint(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

// ɾ���ڵ�(��)
void removeByPos_LinkList(LinkList list, int pos)
{
	if(list == NULL)
	{
		return;
	}

	struct LList* mylist = list;
	if (pos < 0 || mylist->m_Size - 1 < pos)
	{
		return;
	}

	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// ɾ���Ľڵ�
	struct LinkNode* pDel = pCurrent->next;

	// ���Ľڵ�
	pCurrent->next = pDel->next;

	free(pDel);
	pDel = NULL;

	// �����б���
	mylist->m_Size--;
}

// ��ֵɾ��
void removeByName(LinkList list, void* data, int(*myCompare)(void*, void*))
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	// ��list��ԭ��ʵ����ṹ��
	struct LList* mylist = list;

	// ������������ָ�����
	struct LinkNode* pPre = &mylist->pHeader;
	struct LinkNode* pCurrent = mylist->pHeader.next;

	// �����������û�ɾ������
	for (int i = 0; i < mylist->m_Size; i++)
	{
		if (myCompare(data, pCurrent->data))
		{
			// �ҵ�Ҫɾ��������
			pPre->next = pCurrent->next;

			free(pCurrent);
			pCurrent = NULL;

			// �����б���
			mylist->m_Size--;

			break;
		}
		// ����ָ������ƶ�
		pPre = pCurrent;
		pCurrent = pCurrent->next;
	}
}

// ����������
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	// ��list��ԭ��ʵ����ṹ��
	struct LList* mylist = list;

	return mylist->m_Size;
}

// �������
void clear_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	// ��list��ԭ��ʵ����ṹ��
	struct LList* mylist = list;

	struct LinkNode* pCurrent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_Size; i++)
	{
		// ��¼��һ���ڵ�λ��
		struct LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	mylist->pHeader.next = NULL;
	mylist->m_Size = 0;
}

// ����
void destory_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	// ������б�
	clear_LinkList(list);

	free(list);

	list = NULL;
}


struct Person
{
	char name[64];
	int age;
};

// �ص�����
void printPerson(void *data)
{
	struct Person* person = data;
	printf("������%s, ���䣺%d\n", person->name, person->age);
}

int ComparePerson(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return (strcmp(p1->name, p2->name)) == 0 && p1->age == p2->age;
}

void test01()
{
	// ��ʼ������
	LinkList mylist = init_LinkList();

	struct Person p1 = { "����", 18 };
	struct Person p2 = { "����", 20 };
	struct Person p3 = { "�ŷ�", 19 };
	struct Person p4 = { "����", 30 };
	struct Person p5 = { "����", 50 };
	struct Person p6 = { "��", 16 };

	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist, 1, &p3);
	insert_LinkList(mylist, -1, &p4);
	insert_LinkList(mylist, 1, &p5);
	insert_LinkList(mylist, -1, &p6);

	// ����
	foreach_LinkList(mylist, printPerson);
	printf("�����ȣ�%d\n", size_LinkList(mylist));

	// ɾ��
	printf("---------------------------\n");
	printf("ɾ��4�ţ�\n");
	removeByPos_LinkList(mylist, 4);
	foreach_LinkList(mylist, printPerson);
	printf("�����ȣ�%d\n", size_LinkList(mylist));

	struct Person p = { "����", 20 };
	printf("---------------------------\n");
	printf("ɾ������\n");
	removeByName(mylist, &p, ComparePerson);
	foreach_LinkList(mylist, printPerson);
	printf("�����ȣ�%d\n", size_LinkList(mylist));

	// �������
	printf("---------------------------\n");
	printf("�������");
	clear_LinkList(mylist);
	foreach_LinkList(mylist, printPerson);
	printf("�����ȣ�%d\n", size_LinkList(mylist));

	// ��������
	printf("---------------------------\n");
	printf("��������");
	destory_LinkList(mylist);
	mylist = NULL;
}

int main()
{
	test01();

	return 0;
}