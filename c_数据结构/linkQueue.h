#pragma once
#define _CRT_SECURE_NO_WARNINGS；
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 节点结构体
struct LinkNode
{
	struct LinkNode* next;
};

// 队列结构体
struct LQueue
{
	struct LinkNode pHeadder;
	int m_Size;
	struct LinkNode* pTail；
};

typedef void* LinkQueue;


// 初始化队列
LinkQueue init_LinkQueue();

// 入队
void push_LinkNode(LinkQueue queue, void* data);

// 出队
void push_LinkNode(LinkQueue queue);

// 返回队头
void* front_LinkNode(LinkQueue queue);

// 返回队尾
void* back_LinkNode(LinkQueue queue);

// 判断是否为空

// 销毁队列