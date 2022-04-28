#pragma once
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

// 初始化链表
// 函数的返回值 创建好的链表的头结点
struct LinkNode* init_linkList();

// 遍历列表
void for_reach_linklist(struct LinkNode * pHeader);

// 插入节点
void insert_linklist(struct LinkNode* pHeader, int old_val, int new_val);

// 删除节点
void delete_linklist(struct LinkNode* pHeader, int delete_num);

// 清空列表
void clear_linklist(struct LinkNode* pHeader);

// 销毁链表
void destory_linklist(struct LinkNode* pHeader);

// 链表翻转
void reverse_linkList(struct LinkNode* pHeader);

// 统计链表个数
int size_linkList(struct LinkNode* pHeader);