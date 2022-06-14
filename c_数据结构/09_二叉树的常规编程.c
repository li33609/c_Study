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

// 统计叶子数量
void calculateLeafNum(struct BinaryNode* root, int* p)
{
	if (NULL == root)
	{
		return;
	}

	// 统计叶子
	if (root->LChild == NULL && root->RChild == NULL)
	{
		(* p)++;
	}

	calculateLeafNum(root->LChild, p);
	calculateLeafNum(root->RChild, p);
}

// 统计树的高度
int getTreeHeight(struct BinaryNode* root)
{
	if (NULL == root)
	{
		return 0;
	}

	// 获取左子树的高度
	int LHeight = getTreeHeight(root->LChild);

	// 获取右子树的高度
	int RHeight = getTreeHeight(root->RChild);

	// 取最大的子树加一，就是树的高度
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

	// 建立节点的关系
	nodeA.LChild = &nodeB;
	nodeA.RChild = &nodeF;

	nodeB.RChild = &nodeC;

	nodeC.LChild = &nodeD;
	nodeC.RChild = &nodeE;

	nodeF.RChild = &nodeG;

	nodeG.LChild = &nodeH;

	// 统计二叉树叶子数量
	int num = 0;
	calculateLeafNum(&nodeA, &num);

	printf("树的叶子节点数量：%d\n", num);

	// 统计高度
	int height = getTreeHeight(&nodeA);
	printf("树的高度：%d\n", height);
}

int main()
{
	test01();

	return 0;
}