#define _CRT_SECURE_NO_WARNINGS��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �������ڵ�
struct BinaryNode
{
	char ch; // ��ʾ��ĸ
	struct BinaryNode* LChild; // ����
	struct BinaryNode* RChild; // �Һ���
};

// �ݹ麯��
void recursion(struct BinaryNode* root)
{
	if (NULL == root)
	{
		return;
	}

	// �������

	// �ȸ�
	printf("%c\n", root->ch);

	// ����
	recursion(root->LChild);

	// ����
	recursion(root->RChild);
}

// ͳ��Ҷ������
void calculateLeafNum(struct BinaryNode* root, int* p)
{
	if (NULL == root)
	{
		return;
	}

	// ͳ��Ҷ��
	if (root->LChild == NULL && root->RChild == NULL)
	{
		(* p)++;
	}

	calculateLeafNum(root->LChild, p);
	calculateLeafNum(root->RChild, p);
}

// ͳ�����ĸ߶�
int getTreeHeight(struct BinaryNode* root)
{
	if (NULL == root)
	{
		return 0;
	}

	// ��ȡ�������ĸ߶�
	int LHeight = getTreeHeight(root->LChild);

	// ��ȡ�������ĸ߶�
	int RHeight = getTreeHeight(root->RChild);

	// ȡ����������һ���������ĸ߶�
	int height = LHeight > RHeight ? LHeight + 1 : RHeight + 1;

	return height;
}

// ����������
struct BinaryNode* copyTree(struct BinaryNode* root)
{
	if (NULL == root)
	{
		return NULL;
	}

	// �ȿ���������
	struct BinaryNode* LChild = copyTree(root->LChild);

	// �ٿ���������
	struct BinaryNode* RChild = copyTree(root->RChild);

	// �����½ڵ�
	struct BinaryNode* newNode = malloc(sizeof(struct BinaryNode));

	// �����������������ҵ��½ڵ�
	newNode->LChild = LChild;
	newNode->RChild = RChild;
	newNode->ch = root->ch;

	// ����
	return newNode;
}

void freeTree(struct BinaryNode* root)
{
	if (NULL == root)
	{
		return;
	}

	// ���ͷ�������
	freeTree(root->LChild);

	// ���ͷ�������
	freeTree(root->RChild);

	// ���ͷŸ��ڵ�
	freeTree(root);
}

void test01()
{
	struct BinaryNode nodeA = { 'A', NULL, NULL };
	struct BinaryNode nodeB = { 'B', NULL, NULL };
	struct BinaryNode nodeC = { 'C', NULL, NULL };
	struct BinaryNode nodeD = { 'D', NULL, NULL };
	struct BinaryNode nodeE = { 'E', NULL, NULL };
	struct BinaryNode nodeF = { 'F', NULL, NULL };
	struct BinaryNode nodeG = { 'G', NULL, NULL };
	struct BinaryNode nodeH = { 'H', NULL, NULL };

	// �����ڵ�Ĺ�ϵ
	nodeA.LChild = &nodeB;
	nodeA.RChild = &nodeF;

	nodeB.RChild = &nodeC;

	nodeC.LChild = &nodeD;
	nodeC.RChild = &nodeE;

	nodeF.RChild = &nodeG;

	nodeG.LChild = &nodeH;

	// ͳ�ƶ�����Ҷ������
	int num = 0;
	calculateLeafNum(&nodeA, &num);

	printf("����Ҷ�ӽڵ�������%d\n", num);

	// ͳ�Ƹ߶�
	int height = getTreeHeight(&nodeA);
	printf("���ĸ߶ȣ�%d\n", height);

	// ����������
	struct BinaryNode* newTree = copyTree(&nodeA);

	// ����
	recursion(newTree);

	// �ͷŶ�����
	freeTree(newTree);
}

int main()
{
	test01();

	return 0;
}