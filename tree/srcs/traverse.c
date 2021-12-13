#include "bintree.h"

void preorder(BinTreeNode *currentNode)
{
	if (!currentNode)
		return ;
    printf("%c->", currentNode->data);
    preorder(currentNode->pLeftChild);
    preorder(currentNode->pRightChild);
}

void inorder(BinTreeNode *currentNode)
{
	if (!currentNode)
		return ;
    inorder(currentNode->pLeftChild);
    printf("%c->", currentNode->data);
    inorder(currentNode->pRightChild);
}

void postorder(BinTreeNode *currentNode)
{
	if (!currentNode)
		return ;
	postorder(currentNode->pLeftChild);
	postorder(currentNode->pRightChild);
	printf("%c->", currentNode->data);
}
