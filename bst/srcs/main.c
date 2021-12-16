#include "bst.h"

void	displayBST(BinSearchTree *tree)
{
	BinSearchTreeNode *cur;
	BinSearchTreeNode ele;
	LinkedStack *path;
	StackNode	*pop;
	int		i;
	int		tmp;
	int		key;
	int j = 0;

	i = 1;
	path = createLinkedStack();

	while (i < 100)
	{
		cur = tree->pRootNode;
		tmp = i;
		while (tmp > 1)
		{
			pushLS(path, tmp % 2);
			tmp /= 2;
		}
		while (!isLinkedStackEmpty(path) && cur != NULL)
		{
			pop = popLS(path);
			if (pop->data == 0)
				cur = cur->pLeftChild;
			else
				cur = cur->pRightChild;
			free(pop);
		}
		if (cur != NULL)
			printf("%d ", cur->key);
		i++;
	}
	free(path);
	printf("\n");
}

int test()
{
    BinSearchTree *pBinSearchTree;

    BinSearchTreeNode *delNode;
    BinSearchTreeNode node0 = {'a'};

    int number;
    pBinSearchTree = createBinSearchTree();
    while (1)
    {
        printf("1 : Insert\n2 : DeleteNode\n3 : Display\n4 : Delete\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("key : ");
            scanf("%d", &node0.key);
            insertElementBST(pBinSearchTree, node0);
            displayBST(pBinSearchTree);
            break;
        case 2:
			printf("delete key: ");
			scanf("%d", &node0.key);
            if (deleteElementBST(pBinSearchTree, node0.key))
        		printf("%d was deleted!\n", node0.key);
            displayBST(pBinSearchTree);
            break;
        case 3:
            displayBST(pBinSearchTree);
            break;
        case 4:
           deleteBinSearchTree(pBinSearchTree);
		   return (0);
            break;
        default:
            break;
        }
    }
    return (0);
}

int main(void)
{
	test();
	system("leaks bst");
}
