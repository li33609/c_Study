#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>

#include "linklist.h"


void test01()
{
	// ��ʼ������
	struct LinkNode * pUser = init_linkList();

	// ��������
	printf("��������\n");
	for_reach_linklist(pUser);

	// ��������
	insert_linklist(pUser, 20, 100);
	insert_linklist(pUser, 21, 1000);

	// �������
	printf("�������Ϊ��\n");
	for_reach_linklist(pUser);

	// ɾ���ڵ�
	delete_linklist(pUser, 100);
	delete_linklist(pUser, 200);

	// ��ӡɾ����Ľڵ���Ϣ
	printf("ɾ���������\n");
	for_reach_linklist(pUser);

	// �������
	clear_linklist(pUser);
	printf("��պ������");
	for_reach_linklist(pUser);

	// ��������
	destory_linklist(pUser);
	printf("���ٺ������");
	for_reach_linklist(pUser);
}


int main()
{
	// ����������Ϊ�ڴ��ַ
	test01();

	system("pause");
	return 0;
}