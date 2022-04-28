#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>


struct LinkNode
{
	// ������
	int num;
	// ָ����
	struct LinkNode* next;
};

// ��ʼ������
// �����ķ���ֵ �����õ������ͷ���
struct LinkNode* init_linkList();

// �����б�
void for_reach_linklist(struct LinkNode * pHeader);

// ����ڵ�
void insert_linklist(struct LinkNode* pHeader, int old_val, int new_val);

// ɾ���ڵ�
void delete_linklist(struct LinkNode* pHeader, int delete_num);

// ����б�
void clear_linklist(struct LinkNode* pHeader);

// ��������
void destory_linklist(struct LinkNode* pHeader);

// ����ת
void reverse_linkList(struct LinkNode* pHeader);

// ͳ���������
int size_linkList(struct LinkNode* pHeader);