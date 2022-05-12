#define _CRT_SECURE_NO_WARNINGS；
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 节点结构体
struct LinkNode
{
	// 数据域
	void* data;
	struct LinkNode* next;
};

// 链表结构体
struct LList
{
	struct LinkNode pHeader; // 头节点
	int m_Size;
};

typedef void* LinkList;

// 初始化链表
LinkList init_LinkList()
{
	// 分配内存
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

// 插入节点
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
		// 无效位置
		pos = mylist->m_Size;
	}

	// 创建临时节点，通过循环找到待插入位置
	struct LinkNode* pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// 此时pCurrent为插入节点

	// 创建新节点
	struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;
	newNode->next = NULL;

	// 建立节点之间的关系
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	// 更新链表长度
	mylist->m_Size++;
}

// 遍历链表
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

// 删除节点(点)
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

	// 删除的节点
	struct LinkNode* pDel = pCurrent->next;

	// 更改节点
	pCurrent->next = pDel->next;

	free(pDel);
	pDel = NULL;

	// 更新列表长度
	mylist->m_Size--;
}

// 按值删除
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

	// 将list还原真实链表结构体
	struct LList* mylist = list;

	// 创建两个辅助指针变量
	struct LinkNode* pPre = &mylist->pHeader;
	struct LinkNode* pCurrent = mylist->pHeader.next;

	// 遍历链表，找用户删除数据
	for (int i = 0; i < mylist->m_Size; i++)
	{
		if (myCompare(data, pCurrent->data))
		{
			// 找到要删除的数据
			pPre->next = pCurrent->next;

			free(pCurrent);
			pCurrent = NULL;

			// 更新列表长度
			mylist->m_Size--;

			break;
		}
		// 辅助指针向后移动
		pPre = pCurrent;
		pCurrent = pCurrent->next;
	}
}

// 返回链表长度
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	// 将list还原真实链表结构体
	struct LList* mylist = list;

	return mylist->m_Size;
}

// 清空链表
void clear_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	// 将list还原真实链表结构体
	struct LList* mylist = list;

	struct LinkNode* pCurrent = mylist->pHeader.next;
	for (int i = 0; i < mylist->m_Size; i++)
	{
		// 记录下一个节点位置
		struct LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}

	mylist->pHeader.next = NULL;
	mylist->m_Size = 0;
}

// 销毁
void destory_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return;
	}
	// 先清空列表
	clear_LinkList(list);

	free(list);

	list = NULL;
}


struct Person
{
	char name[64];
	int age;
};

// 回调函数
void printPerson(void *data)
{
	struct Person* person = data;
	printf("姓名：%s, 年龄：%d\n", person->name, person->age);
}

int ComparePerson(void* data1, void* data2)
{
	struct Person* p1 = data1;
	struct Person* p2 = data2;

	return (strcmp(p1->name, p2->name)) == 0 && p1->age == p2->age;
}

void test01()
{
	// 初始化链表
	LinkList mylist = init_LinkList();

	struct Person p1 = { "赵云", 18 };
	struct Person p2 = { "关羽", 20 };
	struct Person p3 = { "张飞", 19 };
	struct Person p4 = { "刘备", 30 };
	struct Person p5 = { "黄忠", 50 };
	struct Person p6 = { "马超", 16 };

	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist, 1, &p3);
	insert_LinkList(mylist, -1, &p4);
	insert_LinkList(mylist, 1, &p5);
	insert_LinkList(mylist, -1, &p6);

	// 遍历
	foreach_LinkList(mylist, printPerson);
	printf("链表长度：%d\n", size_LinkList(mylist));

	// 删除
	printf("---------------------------\n");
	printf("删除4号！\n");
	removeByPos_LinkList(mylist, 4);
	foreach_LinkList(mylist, printPerson);
	printf("链表长度：%d\n", size_LinkList(mylist));

	struct Person p = { "关羽", 20 };
	printf("---------------------------\n");
	printf("删除关羽！\n");
	removeByName(mylist, &p, ComparePerson);
	foreach_LinkList(mylist, printPerson);
	printf("链表长度：%d\n", size_LinkList(mylist));

	// 清空链表
	printf("---------------------------\n");
	printf("清空链表");
	clear_LinkList(mylist);
	foreach_LinkList(mylist, printPerson);
	printf("链表长度：%d\n", size_LinkList(mylist));

	// 销毁链表
	printf("---------------------------\n");
	printf("销毁链表");
	destory_LinkList(mylist);
	mylist = NULL;
}

int main()
{
	test01();

	return 0;
}