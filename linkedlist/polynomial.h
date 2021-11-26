#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct ListNodeType
{
  	float coef;
    int degree;
    struct ListNodeType* pLink;
} ListNode;
typedef struct LinkedListType
{
    int currentElementCount;
    ListNode headerNode;
} LinkedList;
LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);
void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
int addPolyNodeLast(LinkedList* pList, float coef, int degree);
LinkedList* polyAdd(LinkedList* pListA, LinkedList* pListB);
void displayPolyList(LinkedList* pList);
#endif
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_
#define TRUE		1
#define FALSE		0
#endif
