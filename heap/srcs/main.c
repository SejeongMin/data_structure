#include "heap.h"

void	displayHeap(ArrayHeap *pArrayHeap)
{
    int i = 1;
    if (!pArrayHeap)
      	return ;
    while (i <= pArrayHeap->currentElementCount)
    {
		printf("%d ", pArrayHeap->pElement[i].key);
		i++;
    }
    printf("\n");
}

void	test()
{
    ArrayHeap *pArrayHeap;

    HeapNode *delNode;
    HeapNode node0 = {'a'};

    int number;
    pArrayHeap = createArrayHeap(100);
    while (1)
    {
        printf("1 : Insert\n2 : DeleteNode\n3 : Display\n4 : Delete\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("key : ");
            scanf("%d", &node0.key);
            insertHeapNode(pArrayHeap, node0);
            displayHeap(pArrayHeap);

            break;
        case 2:
            delNode = deleteHeapNode(pArrayHeap);
			if (delNode)
			{
				printf("%d was deleted!\n", delNode->key);
				free(delNode);
				displayHeap(pArrayHeap);
			}
            break;
        case 3:
            displayHeap(pArrayHeap);
            break;
        case 4:
           deleteArrayHeap(pArrayHeap);
		   return ;
        	break;
        default:
            break;
        }
    }
    return ;
}

int main(void)
{
	test();
	system("leaks heap");
}