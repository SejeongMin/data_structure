#ifndef _LINKEDLIST_
#define _LINKEDLIST_

// typedef struct ListNodeType
// {
// 	int data;
// 	struct ListNodeType* pLink;
// } ListNode;

// typedef struct LinkedListType
// {
// 	int currentElementCount;	// 현재 저장된 원소의 개수
// 	ListNode headerNode;		// 헤더 노드(Header Node)
// } LinkedList;


typedef struct LinkedNodeType
{
	int vertaxID;	//vertax 값	
	int weight; 	//가중치
	struct LinkedNodeType* pLink;
} LinkedNode;

typedef struct LinkedListType
{
	LinkedNode *headNode;
}LinkedList;
//
// LinkedList* createLinkedList();
// int addLLElement(LinkedList* pList, int position, LinkedNode element);
int removeLLElement(LinkedList* pList, int position);
LinkedNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
// int getLinkedListLength(LinkedList* pList);
// void deleteLinkedList(LinkedList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif