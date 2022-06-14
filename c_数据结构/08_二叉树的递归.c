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

	// ͨ���ݹ麯����ʵ���������
	recursion(&nodeA);
}

int main()
{
	test01();

	return 0;
}