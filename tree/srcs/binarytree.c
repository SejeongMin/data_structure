#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *tree;

	tree = (BinTree *)malloc(sizeof(BinTree));
	if (!tree)
		return (NULL);
	tree->pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!tree->pRootNode)
		return (NULL);
	*(tree->pRootNode) = rootNode;
	tree->pRootNode->pLeftChild = NULL;
	tree->pRootNode->pRightChild = NULL;
	return (tree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return (NULL);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *node;

	if (!pParentNode)
		return (NULL);
	node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!node)
		return (NULL);
	node->data = element.data;
	node->pLeftChild = NULL;
	node->pRightChild = NULL;
	pParentNode->pLeftChild = node;
	return (node);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *node;

	if (!pParentNode)
		return (NULL);
	node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!node)
		return (NULL);
	node->data = element.data;
	node->pLeftChild = NULL;
	node->pRightChild = NULL;
	pParentNode->pRightChild = node;
	return (node);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree)
		return ;
	deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (!pNode)
		return ;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
}
