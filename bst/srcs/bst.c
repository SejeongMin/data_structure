#include "bst.h"

BinSearchTree *createBinSearchTree()
{
	BinSearchTree *pBinSearchTree;
  
	pBinSearchTree = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (!pBinSearchTree)
	{
		printf("Malloc error\n");
		return (NULL);
	}
	pBinSearchTree->pRootNode = NULL;
	return (pBinSearchTree);
}

int insertElementBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element)
{
	BinSearchTreeNode *node;
  	BinSearchTreeNode *parent;

	if (!pBinSearchTree)
  	return (FALSE);
  	node = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	*node = element;
	node->pLeftChild = NULL;
	node->pRightChild = NULL;
	parent = pBinSearchTree->pRootNode;
	if (!parent)  // RootNode가 없으면 RootNode에 삽입
		pBinSearchTree->pRootNode = node;
	while (parent) // addNode 를 넣을 위치 찾기
	{
		if (parent->key == node->key) // key 중복시 FALSE 반환
			return (FALSE);
		if (node->key > parent->key)
		{
			if (!parent->pRightChild)
			{
				parent->pRightChild = node;
				break;
			}
			parent = parent->pRightChild;
		}
		else
		{
			if (!parent->pLeftChild)
			{
				parent->pLeftChild = node;
					break;
			}
			parent = parent->pLeftChild;
		}
  	}
  	return (TRUE);
}

int deleteElementBST(BinSearchTree *pBinSearchTree, int key)
{
	if (!pBinSearchTree)
  	return (FALSE);
	BinSearchTreeNode *delNode;
	BinSearchTreeNode *parent = NULL;
	BinSearchTreeNode *child;
	BinSearchTreeNode *tmp;
	
	delNode = pBinSearchTree->pRootNode;
	while (delNode)
	{
		if(delNode->key == key)
			break;
		parent = delNode;
		if (delNode->key > key)
			delNode = delNode->pLeftChild;
		else
			delNode = delNode->pRightChild;
	}
	if (!delNode)
	{
		printf("No node\n");
		return (FALSE);
	}
	if (!delNode->pLeftChild && !delNode->pRightChild)
	{
		if (parent->pLeftChild->key == delNode->key)
			parent->pLeftChild = NULL;
		else
			parent->pRightChild = NULL;
		free(delNode);
	}
	else if ((!delNode->pLeftChild && delNode->pRightChild) || (delNode->pLeftChild && !delNode->pRightChild))
	{
		if (delNode->pLeftChild)
			child = delNode->pLeftChild;
		else
			child = delNode->pRightChild;
		if (parent)
		{
		if (parent->pLeftChild->key == delNode->key)
			parent->pLeftChild = child;
		else
			parent->pRightChild = child;
		}
		else
			pBinSearchTree->pRootNode = child;
		free(delNode);
	}
	else
	{
		tmp = delNode->pLeftChild;
		while (tmp->pRightChild->pRightChild)
		{
			tmp = tmp->pRightChild;
		}
		if (parent != NULL)
		{
			if (parent->pLeftChild->key == delNode->key)
				parent->pLeftChild = tmp->pRightChild;
			else
				parent->pRightChild = tmp->pRightChild;
		}
		tmp->pRightChild->pLeftChild = tmp;
		tmp->pRightChild->pRightChild = delNode->pRightChild;
		tmp->pRightChild = NULL;
		free(delNode);
	}
  	return (TRUE);
}

BinSearchTreeNode *searchRecursiveBST(BinSearchTree *pBinSearchTree, int key)
{
	if (!pBinSearchTree)
  		return (NULL);
  	return (searchInternalRecursiveBST(pBinSearchTree->pRootNode, key));
}

BinSearchTreeNode *searchInternalRecursiveBST(BinSearchTreeNode *pTreeNode, int key)
{
	if (!pTreeNode)
		return (NULL);
	if (pTreeNode->key == key) // key 를 찾았을때
		return (pTreeNode);
	else if (pTreeNode->key < key)
		return (searchInternalRecursiveBST(pTreeNode->pRightChild, key)); // temp의 key가 인자로 받은 key보다 작으면 오른쪽 영역을 탐색한다.
	else
		return (searchInternalRecursiveBST(pTreeNode->pLeftChild, key)); // temp의 key가 인자로 받은 key보다 크면 왼쪽 영역을 탐색한다.
}

BinSearchTreeNode *searchBST(BinSearchTree *pBinSearchTree, int key)
{
	if(pBinSearchTree)
  	return (NULL);
  	BinSearchTreeNode *temp;
  
  	temp = pBinSearchTree->pRootNode;
  	while (temp)
	{
		if (temp->key == key) // key 를 찾았을때
			break;
		if (temp->key < key) // temp의 key가 인자로 받은 key보다 작으면 오른쪽 영역을 탐색한다.
			temp = temp->pRightChild;
		else // temp의 key가 인자로 받은 key보다 크면 왼쪽 영역을 탐색한다.
			temp = temp->pLeftChild;
	}
	return (temp);
}

void deleteBinSearchTree(BinSearchTree *pBinSearchTree)
{
	if (!pBinSearchTree)
  	return ;
	deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
	free(pBinSearchTree);
}

void deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode)
{
	if (!pTreeNode)
  	return ;
	deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
	deleteBinSearchTreeInternal(pTreeNode->pRightChild);
	free(pTreeNode);
}
