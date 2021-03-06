#include "arraylist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList* pList;
	
	if (maxElementCount < 0)
	{
		printf("maxElementCount minus\n");
	}
	pList = (ArrayList *)malloc(sizeof(ArrayList));
	if (!pList)
	{
		printf("pList malloc failure\n");
		return (NULL);
	}
	pList->maxElementCount = maxElementCount;
	pList->currentElementCount = 0;
	pList->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!(pList->pElement))
	{
		printf("pElement malloc failure\n");
		free(pList);
		return (NULL);
	}
	memset(pList->pElement, 0, sizeof(ArrayListNode) * maxElementCount);
	return (pList);
}

int isArrayListFull(ArrayList* pList)
{
	if (pList == NULL)
	{
		return (-1);//-1이면 pList가 할당이 안되어있음
	}
	if (pList->currentElementCount == pList->maxElementCount)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

void clearArrayList(ArrayList* pList)
{
	if (pList == NULL)
	{
		return ;
	}
	memset(pList->pElement, 0, sizeof(ArrayListNode) * pList->maxElementCount);
	pList->currentElementCount = 0;
}

void deleteArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		clearArrayList(pList);
		free(pList->pElement);
		pList->pElement = NULL;
		free(pList);
		pList = NULL;
	}
}

int getArrayListLength(ArrayList* pList)
{
	if (pList == NULL)
	{
		return (0); //pList할당이 안되어있을 때.
	}
	return (pList->currentElementCount);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (pList == NULL)
	{
		return (NULL);
	}
	if (position >= 0 && position < pList->currentElementCount)
	{
		return (&(pList->pElement[position]));
	}
	else
	{
		return (NULL); //범위 안에 없는 것은 NULL로 처리.
	}
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	if (isArrayListFull(pList) == TRUE || pList == NULL || position > pList->currentElementCount || position < 0)
	{
		return (FALSE);
	}
	else
	{
		for(int i = pList->currentElementCount; i > position; i--)
		{
			pList->pElement[i] = pList->pElement[i - 1];
		}
		pList->pElement[position] = element;
		pList->currentElementCount++;
		return (TRUE);
	}
}

int removeALElement(ArrayList* pList, int position)
{
	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
	{
		return (FALSE);
	}
	else
	{
		for(int i = position; i < pList->currentElementCount - 1; i++)
		{
		pList->pElement[i] = pList->pElement[i + 1];
		}
		pList->pElement[pList->currentElementCount - 1].data = 0;
		pList->currentElementCount--;
		return (TRUE);
	}
}

void	displayArrayList(ArrayList* pList)
{
	if (pList == NULL)
	{
		return ;
	}
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		printf("arr[%d] : %d\n", i, pList->pElement[i].data);
	}
}

int main(void)
{
	ArrayList *p = createArrayList(5);
	ArrayListNode n;
	n.data = 3;
	addALElement(p, 0, n);
	displayArrayList(p);
	deleteArrayList(p);
	displayArrayList(p);
	return (0);
}
