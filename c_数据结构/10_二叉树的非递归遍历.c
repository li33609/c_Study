#define _CRT_SECURE_NO_WARNINGS；
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "seqStack.h"

// 二叉树节点
struct BinaryNode
{
	char ch; // 显示字母
	struct BinaryNode* LChild; // 左孩子
	struct BinaryNode* RChild; // 右孩子
	int flag; // 节点标志
};

void nonRecursion(struct BinaryNode* root)
{
	// 初始化栈
	SeqStack myStack = init_SeqStack();

	// 将根节点入栈
	push_SeqStack(myStack, root);

	//只要栈中个数大于0 执行循环
	while (size_SeqStack(myStack) > 0)
	{
		// 获取栈顶元素
		struct BinaryNode* topNode= top_SeqStack(myStack);
		// 出栈
		pop_SeqStack(myStack);

		if (1 == topNode->flag)
		{
			printf("%c\n", topNode->ch);
			continue;
		}

		// 如果标志为假，将标志改为真
		topNode->flag = 1;

		// 判断右子树，如果存在入栈
		if (topNode->RChild != NULL)
		{
			push_SeqStack(myStack, topNode->RChild);
		}

		// 判断左子树，如果存在入栈
		if (topNode->LChild != NULL)
		{
			push_SeqStack(myStack, topNode->LChild);
		}

		// 判断根，如果存在入栈
		push_SeqStack(myStack, topNode);
	}

	// 销毁
	destroy_SeqStack(myStack);
}

void test01()
{
	struct BinaryNode nodeA = { 'A', NULL, NULL, 0  };
	struct BinaryNode nodeB = { 'B', NULL, NULL, 0  };
	struct BinaryNode nodeC = { 'C', NULL, NULL, 0  };
	struct BinaryNode nodeD = { 'D', NULL, NULL, 0  };
	struct BinaryNode nodeE = { 'E', NULL, NULL, 0  };
	struct BinaryNode nodeF = { 'F', NULL, NULL, 0  };
	struct BinaryNode nodeG = { 'G', NULL, NULL, 0  };
	struct BinaryNode nodeH = { 'H', NULL, NULL, 0  };

	// 建立节点的关系
	nodeA.LChild = &nodeB;
	nodeA.RChild = &nodeF;

	nodeB.RChild = &nodeC;

	nodeC.LChild = &nodeD;
	nodeC.RChild = &nodeE;

	nodeF.RChild = &nodeG;

	nodeG.LChild = &nodeH;

	// 调用非递归函数
	nonRecursion(&nodeA);
}

int main()
{
	test01();

	return 0;
}