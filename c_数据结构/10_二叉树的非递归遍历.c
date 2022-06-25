#define _CRT_SECURE_NO_WARNINGS��
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "seqStack.h"

// �������ڵ�
struct BinaryNode
{
	char ch; // ��ʾ��ĸ
	struct BinaryNode* LChild; // ����
	struct BinaryNode* RChild; // �Һ���
	int flag; // �ڵ��־
};

void nonRecursion(struct BinaryNode* root)
{
	// ��ʼ��ջ
	SeqStack myStack = init_SeqStack();

	// �����ڵ���ջ
	push_SeqStack(myStack, root);

	//ֻҪջ�и�������0 ִ��ѭ��
	while (size_SeqStack(myStack) > 0)
	{
		// ��ȡջ��Ԫ��
		struct BinaryNode* topNode= top_SeqStack(myStack);
		// ��ջ
		pop_SeqStack(myStack);

		if (1 == topNode->flag)
		{
			printf("%c\n", topNode->ch);
			continue;
		}

		// �����־Ϊ�٣�����־��Ϊ��
		topNode->flag = 1;

		// �ж������������������ջ
		if (topNode->RChild != NULL)
		{
			push_SeqStack(myStack, topNode->RChild);
		}

		// �ж������������������ջ
		if (topNode->LChild != NULL)
		{
			push_SeqStack(myStack, topNode->LChild);
		}

		// �жϸ������������ջ
		push_SeqStack(myStack, topNode);
	}

	// ����
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

	// �����ڵ�Ĺ�ϵ
	nodeA.LChild = &nodeB;
	nodeA.RChild = &nodeF;

	nodeB.RChild = &nodeC;

	nodeC.LChild = &nodeD;
	nodeC.RChild = &nodeE;

	nodeF.RChild = &nodeG;

	nodeG.LChild = &nodeH;

	// ���÷ǵݹ麯��
	nonRecursion(&nodeA);
}

int main()
{
	test01();

	return 0;
}