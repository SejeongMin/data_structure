#include "heap.h"
ArrayHeap *createArrayHeap(int maxElementCount)
{
	ArrayHeap *pArrayHeap;
  
	if (!(pArrayHeap = (ArrayHeap *)malloc(sizeof(ArrayHeap))))
		return (NULL);
	if (!(pArrayHeap->pElement = (HeapNode *)malloc(sizeof(HeapNode) * (maxElementCount + 1))))
	{
		free(pArrayHeap);
		return (NULL);
	}
	pArrayHeap->maxElementCount = maxElementCount;
	pArrayHeap->currentElementCount = 0;
	return (pArrayHeap);
}

void insertHeapNode(ArrayHeap *pArrayHeap, HeapNode element)
{
	if (!pArrayHeap || isFullArrayHeap(pArrayHeap))
  	return ;
	int nextPos ;
	nextPos = ++(pArrayHeap->currentElementCount);
	while (nextPos != 1 && pArrayHeap->pElement[nextPos / 2].key < element.key)
	{
		pArrayHeap->pElement[nextPos].key = pArrayHeap->pElement[nextPos / 2].key;
		nextPos /= 2;
	}
	pArrayHeap->pElement[nextPos] = element;
}

int isFullArrayHeap(ArrayHeap *pArrayHeap)
{
	if (!pArrayHeap)
  		return (0);
  	return (pArrayHeap->maxElementCount == pArrayHeap->currentElementCount);
}

int isEmptyArrayHeap(ArrayHeap *pArrayHeap)
{
    if (!pArrayHeap)
        return (FALSE);
    if (pArrayHeap->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

HeapNode *deleteHeapNode(ArrayHeap *pArrayHeap)
{
	if (!pArrayHeap)
        return (NULL);
	if (isEmptyArrayHeap(pArrayHeap))
			return (NULL);
	int temp;
	int parent = 1;
	int child = 2;
	HeapNode *delNode;
	HeapNode *tempNode;

    if (!(delNode = (HeapNode *)malloc(sizeof(HeapNode))))
        return (NULL);
    *delNode = pArrayHeap->pElement[1];

    temp = pArrayHeap->currentElementCount--;
    tempNode = &(pArrayHeap->pElement[temp]);

    while (child <= pArrayHeap->currentElementCount)
    {
        if (child < pArrayHeap->currentElementCount && pArrayHeap->pElement[child].key < pArrayHeap->pElement[child + 1].key)
            child++;
        if (tempNode->key >= pArrayHeap->pElement[child].key)
            break;
        pArrayHeap->pElement[parent] = pArrayHeap->pElement[child];
        parent = child;
        child *= 2;
    }
    pArrayHeap->pElement[parent] = *tempNode;
    return (delNode);
}

void deleteArrayHeap(ArrayHeap *pArrayHeap)
{
	if (!pArrayHeap)
  	return ;
  	if (pArrayHeap->pElement)
		free(pArrayHeap->pElement);
  	free(pArrayHeap);
}