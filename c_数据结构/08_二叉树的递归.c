#define _CRT_SECURE_NO_WARNINGS；
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 二叉树节点
struct BinaryNode
{
	char ch; // 显示字母
	struct BinaryNode* LChild; // 左孩子
	struct BinaryNode* RChild; // 右孩子
};

// 递归函数
void recursion(struct BinaryNode* root)
{
	if (NULL == root)
	{
		return;
	}

	// 先序遍历

	// 先根
	printf("%c\n", root->ch);

	// 再左
	recursion(root->LChild);

	// 再右
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

	// 建立节点的关系
	nodeA.LChild = &nodeB;
	nodeA.RChild = &nodeF;

	nodeB.RChild = &nodeC;

	nodeC.LChild = &nodeD;
	nodeC.RChild = &nodeE;

	nodeF.RChild = &nodeG;

	nodeG.LChild = &nodeH;

	// 通过递归函数，实现先序遍历
	recursion(&nodeA);
}

int main()
{
	test01();

	return 0;
}