#include "primMST.h"
#include "stack.h"



//prim 알고리즘을 사용한 실질적인 신장트리 변환 함수
LinkedGraph* primMST(LinkedGraph* pGraph, int vertexID)
{
	LinkedGraph *myMst; //새로 만들 mst 그래프
	LinkedQueue *nodes;	//기존 그래프에 존재하는 모든 vertex를 쌓아놓은 큐
	QueueNode *node;	//nodes에서 pop한 현재 기준 vertex


	if (!pGraph)
		return FALSE;
	//최소 신장 트리용 새 그래프 그릇 생성
	myMst = createLinkedGraph(pGraph->currentVertexCount);
	//유효성 검사하며 새 그래프에 vertex들을 채운다
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
			addVertexLG(myMst, i);
	}

	//findBFSNodes함수로 존재하는 모든 노드를 찾아 nodes 큐에 인큐
	nodes =	findBFSNodes(pGraph, vertexID);
	
	//nodes에서 작업할 vertex를 디큐해 node에 넣어줌
	node = deleteFrontLD(nodes);
	while (node)
	{
		checkEdge(pGraph, myMst, node->data);
		free(node);
		node = deleteFrontLD(nodes);	
	}
	deleteLinkedQueue(nodes);
	return (myMst);
}

//부속된 간선 중 가중치가 가장 작은 간선 추출 -> 가장 작은 가중치로 연결된 노드 반환
void getMinWeightEdge(LinkedGraph *pGraph, int vertexID, LinkedNode *nextNode)
{
	LinkedNode *curr;

	if (!pGraph)
		return ;
	//curr에 인자로 들어온 vertexID의 인접노드 담아줌
	curr = pGraph->ppAdjEdge[vertexID]->headNode->pLink;
	if (!curr)
	{
		nextNode->vertaxID = -1;
		return ;
	}

	nextNode->weight = curr->weight;
	nextNode->vertaxID = curr->vertaxID;
	
	//해당 vertex의 모든 인접노드를 돌면서 minWeightEdge를 가진 노드를 nextNode에 할당
	while (curr)
	{	
		if (curr->weight < nextNode->weight)
		{
			nextNode->weight = curr->weight;
			nextNode->vertaxID = curr->vertaxID;
		}
		curr = curr->pLink;
	}
	return ;
}

void checkEdge(LinkedGraph *pGraph, LinkedGraph *myMst, int vertexID)
{
	int prevNodeID;
	LinkedNode nextNode;

	prevNodeID = vertexID;
	while (myMst->currentEdgeCount < myMst->currentVertexCount - 1)
	{
		getMinWeightEdge(pGraph, prevNodeID, &nextNode);
		//더 이상 인접 노드가 없으면 break
		if (nextNode.vertaxID == -1)
			break ;
		//순환이 없으면 간선 추가
		if (!checkCycle(myMst, prevNodeID, nextNode.vertaxID))
		{
			addEdgewithWeightLG(myMst, prevNodeID, nextNode.vertaxID, nextNode.weight);
			break ;
		}
	}
}

int InitAndPushStack(LinkedStack *pStack, int nodeID)
{
	//node의 모든 내용 초기화
	StackNode node = {0,};
	node.data = nodeID;
	return pushLinkedStack(pStack, node);
}

int checkCycle(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	int pReturn = FALSE; //반환할 결과 FALSE : 사이클 없음

	int idx = 0;
	int vertexID = 0;
	LinkedStack * stack = NULL;		//탐색용 스택
	StackNode *stackNode = NULL;	//pop된 노드
	LinkedNode *node = NULL;

	int *visited = NULL;

	if (!pGraph)
		return FALSE;
	
	stack = createLinkedStack();
	if (!stack)
		return FALSE;
	
	visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
	if (!visited)
	{
		free(visited); //추가
		deleteLinkedStack(stack);
		return FALSE;
	}

	visited[fromVertexID] = 1;
	
	//fromVertextID를 stack에 담아준 후 
	InitAndPushStack(stack, fromVertexID);
	//탐색용 스택이 비워질때까지
	while (!isLinkedStackEmpty(stack))
	{
		stackNode = popLinkedStack(stack);
		if (stackNode)
		{
			// 0 -> 2 -> 1 
			// 0에서 새로 추가할 1까지의 간선이 이미 있나 체크 (0, 1)
			vertexID = stackNode->data;
			if (vertexID == toVertexID)
			{
				printf(" graph overlapped %d, %d\n", fromVertexID, toVertexID);
				pReturn = TRUE;
				free(stackNode); //추가
				break;
			}
			//node에 해당 VertexID의 인접노드 할당
			node = pGraph->ppAdjEdge[vertexID]->headNode->pLink;
			//해당 VertexID의 모든 인접노드를 돌면서
			while (node)
			{
				//방문하지 않은 노드가 있다면 스택에 푸시해주고 방문표시
				idx = node->vertaxID;
				if (visited[idx] == FALSE)
				{
					visited[idx] = TRUE;
					InitAndPushStack(stack, idx);
				}
				node = node->pLink;
			}
			free(stackNode); //추가
		}
	}
	free(visited);
	deleteLinkedStack(stack);
	return pReturn;
}
