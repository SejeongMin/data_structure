#include "../includes/bintree.h"

void	insertNode(BinTree *tree)
{
	BinTreeNode *cur;
	BinTreeNode ele;
	LinkedStack *path;
	StackNode	*pop;
	int		i;
	int		tmp;
	char	data;
	int j = 0;

	i = 1;
	path = createLinkedStack();

	while (1)
	{
		printf("input data: ");
		if (scanf(" %c", &data) == EOF)
		{
			rewind(stdin);
			printf("\n");
			break ;
		}
		ele.data = data;
		i++;
		cur = tree->pRootNode;
		tmp = i;
		tmp /= 2;
		while (tmp > 1)
		{
			pushLS(path, tmp % 2);
			tmp /= 2;
		}
		while (!isLinkedStackEmpty(path))
		{
			pop = popLS(path);
			if (pop->data == 0)
				cur = cur->pLeftChild;
			else
				cur = cur->pRightChild;
			free(pop);
		}
		if (i % 2 == 0)
			insertLeftChildNodeBT(cur, ele);
		else
			insertRightChildNodeBT(cur, ele);
	}
	free(path);
}

int		main(void)
{
	BinTree *tree;
	BinTreeNode	root;
	char c;

	printf("root node: ");
	scanf(" %c", &root.data);
	tree = makeBinTree(root);
	insertNode(tree);

	while(1)
	{
		printf("Preorder Inorder poStorder: ");
		scanf(" %c", &c);
		switch (c)
		{
		case 'P':
			preorder(tree->pRootNode);
			printf("\n");
			break;
		case 'I':
			inorder(tree->pRootNode);
			printf("\n");
			break;
		case 'S':
			postorder(tree->pRootNode);
			printf("\n");
			break;
		case 'D':
			deleteBinTree(tree);
			system("leaks binarytree");
			return (0);
			break;
		default:
			break;
		}
	}
	return (0);
}
