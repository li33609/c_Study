#define _CRT_SECURE_NO_WARNINGS；
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 节点结构体设计
struct LinkNode
{
	// 只维护指针域
	struct LinkNode* next;
};

struct LList
{
	struct LinkNode pHeader; // 头结点
	int m_size;
};

typedef void* LinkList;

// 初始化节点
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

// 插入链表
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

	// 取出用户数据的前4个字节空间
	struct LinkNode* myNode = data;

	// 找到待插入位置的前驱节点
	struct LinkNode* pCurrent = &mylist->pHeader;

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// 更改指针指向
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	mylist->m_size++;
}

// 遍历
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
		// pCurrent用户输入的首地址
		myPrint(pCurrent);

		pCurrent = pCurrent->next;
	}
}

// 按位置删除
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

	// 找到待删除的前驱
	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	// 记录待删除的位置
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

// 回调函数
void printPerson(void* data)
{
	struct Person* person = data;

	printf("姓名:%s, 年龄:%d \n", person->name, person->age);
}


void test01()
{
	// 初始化
	LinkList mylist = init_LinkList();

	// 创建数据
	struct Person p1 = { NULL, "赵云", 18 };
	struct Person p2 = { NULL, "关羽", 20 };
	struct Person p3 = { NULL, "张飞", 19 };
	struct Person p4 = { NULL, "刘备", 30 };
	struct Person p5 = { NULL, "黄忠", 50 };
	
	// 插入数据
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist, 1, &p3);
	insert_LinkList(mylist, -1, &p4);
	insert_LinkList(mylist, 0, &p5);

	// 遍历列表
	foreach_LinkList(mylist, printPerson);

	// 删除节点
	printf("----------------------\n");
	removeByPos_LinkList(mylist, 2);
	foreach_LinkList(mylist, printPerson);
}

int main()
{
	test01();

	return 0;
}