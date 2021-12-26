#ifndef _PRIM_MST_
#define _PRIM_MST_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "linkedqueue.h"
#include "linkedgraph.h"
#include "stack.h"




typedef struct GraphEdgeType {
	int	fromVertexID; 	//시작노드
	int toVertexID;		//종료노드
	int weight;			//가중치
} GraphEdge;


//순환 검사
int checkCycle(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

//실질적인 프림 알고리즘
LinkedGraph* primMST(LinkedGraph* pGraph, int vertexID);

//부속된 간선 중 가중치가 가장 작은 간선 추출(순환 발생 x)
void getMinWeightEdge(LinkedGraph *pGraph, int vertexID, LinkedNode *nextnode);

void checkEdge(LinkedGraph *pGraph, LinkedGraph *myMst, int vertexID);
LinkedQueue* findBFSNodes(LinkedGraph* pGraph, int start);
LinkedQueue* findNodes(LinkedGraph* pGraph, int startVertexID, int *visited);
int InitAndPushStack(LinkedStack *pStack, int nodeID);


#endif