#include "linkedlist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	displayLinkedList(LinkedList* pList)
{
    ListNode* pNode = NULL;
    if (pList == NULL)
	{
        return ;
	}
    pNode = &(pList->headerNode);
    printf("원소개수 : %d\n", pList->currentElementCount);
    for (int i = 0; i < pList->currentElementCount; i++)
    {
        printf("%d번째: %d\n", i, pNode->data);
        pNode = pNode->pLink;
    }
}

LinkedList* createLinkedList()
{
    LinkedList* pList = NULL;
    pList = (LinkedList*)malloc(sizeof(LinkedList));
    if (pList == NULL)
    {
        printf("malloc failure\n");
        return (NULL);
    }
    memset(pList, 0, sizeof(LinkedList));
    return (pList);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
    ListNode* pNode = NULL;
    ListNode* nextNode = NULL;
    if (pList != NULL)
    {
        if (position >= 0 && position <= pList->currentElementCount)
        {
            nextNode = (ListNode*)malloc(sizeof(ListNode));
            if (nextNode != NULL)
            {
                pNode = &(pList->headerNode);
                *nextNode = element;
                nextNode->pLink = NULL;
                for (int i = 0; i < position; i++)
                {
                    pNode = pNode->pLink;
                }
                nextNode->pLink = pNode->pLink;
                pNode->pLink = nextNode;
                pList->currentElementCount++;
                return (TRUE);
            }
        }
        else
        {
            printf("out of index\n");
        }
    }
    return (FALSE);
}

int removeLLElement(LinkedList* pList, int position)
{
    ListNode* pNode = NULL;
    ListNode* removeNode = NULL;

    if (pList != NULL)
    {
        if (position >= 0 && position < pList->currentElementCount)
        {
            pNode = &(pList->headerNode);
            for (int i = 0; i < position; i++)
            {
                pNode = pNode->pLink;
            }
            removeNode = pNode->pLink;
            pNode->pLink = removeNode->pLink;
            free(removeNode);
            pList->currentElementCount--;
            return (TRUE);
        }
    }
    return (FALSE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
    ListNode* pNode = NULL;
    if (pList != NULL)
    {
        pNode = &(pList->headerNode);
        if (position >= 0 && position < pList->currentElementCount)
        {
            for (int i = 0; i <= position; i++)
            {
                pNode = pNode->pLink;
            }
            return (pNode);
        }
    }
    return (NULL);
}

int getLinkedListLength(LinkedList* pList)
{
    if (pList != NULL)
    {
        return (pList->currentElementCount);
    }
    return (-1);
}

void clearLinkedList(LinkedList* pList)
{
    while (removeLLElement(pList, 0));
}

void deleteLinkedList(LinkedList* pList)
{
    if (pList != NULL)
    {
        clearLinkedList(pList);
        memset(pList, 0, sizeof(LinkedList));
        free(pList);
    }
	pList = NULL;
}

int main(void)
{
    LinkedList* p;
    ListNode n;
    ListNode n2;
    ListNode n3;
    n.data = 1;
    n.pLink = NULL;
    n2.data = 2;
    n2.pLink = NULL;
    n3.data = 3;
    n3.pLink = NULL;
    p = createLinkedList();
	addLLElement(p, 0, n);
    displayLinkedList(p);
    addLLElement(p, 1, n2);
    displayLinkedList(p);
    addLLElement(p, 2, n3);
    displayLinkedList(p);
    removeLLElement(p, 2);
    displayLinkedList(p);
	clearLinkedList(p);
	displayLinkedList(p);
	deleteLinkedList(p);
}