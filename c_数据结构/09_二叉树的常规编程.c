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

// 拷贝二叉树
struct BinaryNode* copyTree(struct BinaryNode* root)
{
	if (NULL == root)
	{
		return NULL;
	}

	// 先拷贝左子树
	struct BinaryNode* LChild = copyTree(root->LChild);

	// 再拷贝右子树
	struct BinaryNode* RChild = copyTree(root->RChild);

	// 创建新节点
	struct BinaryNode* newNode = malloc(sizeof(struct BinaryNode));

	// 将拷贝的左右子树挂到新节点
	newNode->LChild = LChild;
	newNode->RChild = RChild;
	newNode->ch = root->ch;

	// 返回
	return newNode;
}

void freeTree(struct BinaryNode* root)
{
	if (NULL == root)
	{
		return;
	}

	// 先释放左子树
	freeTree(root->LChild);

	// 再释放右子树
	freeTree(root->RChild);

	// 再释放根节点
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

	// 拷贝二叉树
	struct BinaryNode* newTree = copyTree(&nodeA);

	// 遍历
	recursion(newTree);

	// 释放二叉树
	freeTree(newTree);
}

int main()
{
	test01();

	return 0;
}