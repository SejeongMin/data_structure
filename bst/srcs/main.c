#include "bst.h"

int getLevel(BinSearchTreeNode* node)
{
    if (node == NULL) return 0;

    int lLevel = getLevel(node->pLeftChild);
    int rLevel = getLevel(node->pRightChild);

    if (lLevel > rLevel) return lLevel + 1;
    else return rLevel + 1;
}

int	get_pow(int x, int y)
{
	int ret = 1;

	for(int i = 0; i < y; i++){
		ret *= x;
	}
	return (ret);
}

void	displayBST(BinSearchTree *tree)
{
	BinSearchTreeNode *cur;
	BinSearchTreeNode ele;
	LinkedStack *path;
	StackNode	*pop;
	int		i;
	int		tmp;
	int		key;
	int		size = 0;
	int		cnt = 0;
	int		exp = 0;
	int		depth = 0;

	i = 1;
	path = createLinkedStack();
	depth = getLevel(tree->pRootNode);
	size = get_pow(2, depth) - 1;
	printf("\n---------------\n");
	while (cnt < size)
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
		if (i == get_pow(2, exp))
		{
			for(int j = 0; j < depth - exp; j++)
				printf("  ");
		}
		if (cur != NULL)
			printf("%d ", cur->key);
		else
			printf("X ");
		if ((i - (i / 2)) == get_pow(2, exp))
		{
			printf("\n");
			exp++;
		}
		i++;
		cnt++;
	}
	printf("\n---------------\n");
	free(path);
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
