#pragma once
#define _CRT_SECURE_NO_WARNINGS��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �ڵ�ṹ��
struct LinkNode
{
	struct LinkNode* next;
};

// ���нṹ��
struct LQueue
{
	struct LinkNode pHeadder;
	int m_Size;
	struct LinkNode* pTail��
};

typedef void* LinkQueue;


// ��ʼ������
LinkQueue init_LinkQueue();

// ���
void push_LinkNode(LinkQueue queue, void* data);

// ����
void push_LinkNode(LinkQueue queue);

// ���ض�ͷ
void* front_LinkNode(LinkQueue queue);

// ���ض�β
void* back_LinkNode(LinkQueue queue);

// �ж��Ƿ�Ϊ��

// ���ٶ���