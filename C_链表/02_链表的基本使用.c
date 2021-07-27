#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

#include "linklist.h"


void test01()
{
	// 初始化链表
	struct LinkNode * pUser = init_linkList();

	// 遍历链表
	printf("遍历链表：\n");
	for_reach_linklist(pUser);

	// 插入数据
	insert_linklist(pUser, 20, 100);
	insert_linklist(pUser, 21, 1000);

	// 插入后结果
	printf("插入后结果为：\n");
	for_reach_linklist(pUser);

	// 删除节点
	delete_linklist(pUser, 100);
	delete_linklist(pUser, 200);

	// 打印删除后的节点信息
	printf("删除后的链表：\n");
	for_reach_linklist(pUser);

	// 情空链表
	clear_linklist(pUser);
	printf("清空后的链表！");
	for_reach_linklist(pUser);

	// 销毁链表
	destory_linklist(pUser);
	printf("销毁后的链表！");
	for_reach_linklist(pUser);
}


int main()
{
	// 函数的名字为内存地址
	test01();

	system("pause");
	return 0;
}