#ifndef _LINKED_Queue_
#define _LINKED_Queue_

#include <stdio.h>
#include <stdlib.h>

#include "linkedgraph.h"

#define f(x) #x

typedef struct QueueNodeType
{
	int		data; //vertaxID
	struct QueueNodeType* pRLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;	// ???? ?????? ????
	QueueNode* pFrontNode;		// Front ????? ??????
	QueueNode* pRearNode;		// Rear ????? ??????
} LinkedQueue;

LinkedQueue* createLinkedQueue();
int insertRearLD(LinkedQueue* pQueue, int vertexID);
QueueNode* deleteFrontLD(LinkedQueue* pQueue);
void deleteLinkedQueue(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);
void displayLinkedQueue(LinkedQueue *pQueue, int max);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif