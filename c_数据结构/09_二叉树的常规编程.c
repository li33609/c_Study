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
}

int main()
{
	test01();

	return 0;
}