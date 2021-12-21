#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "linkedqueue.h"

typedef struct LinkedGraphType
{
	int maxVertexCount;		// �ִ� ��� ����
	int currentVertexCount;	// ���� ���Ǵ� ����� ����
	int currentEdgeCount;	// ���� ������ ����.
	int graphType;			// �׷��� ����: 1-Undirected, 2-Directed
	LinkedList** ppAdjEdge;	// ���� ������ ���� ���� ����Ʈ (������)�� �迭
	int *pVertex;			// ��� ������ ���� 1���� �迭
} LinkedGraph;




// �׷��� ����
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// �׷��� ����
void deleteLinkedGraph(LinkedGraph* pGraph);

// ���� �׷��� ���� �Ǵ�
int isEmptyLG(LinkedGraph* pGraph);

// ��� �߰�
int addVertexLG(LinkedGraph* pGraph, int vertexID);

// ���� �߰�
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// ����� ��ȿ�� ����.
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// ��� ����
int removeVertexLG(LinkedGraph* pGraph, int vertexID);

// ���� ����
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

// ���� ���� ��ȯ
int getEdgeCountLG(LinkedGraph* pGraph);

// ��� ���� ��ȯ
int getVertexCountLG(LinkedGraph* pGraph);

// �ִ� ��� ���� ��ȯ
int getMaxVertexCountLG(LinkedGraph* pGraph);

// �׷��� ���� ��ȯ.
int getGraphTypeLG(LinkedGraph* pGraph);

// �׷��� ���� ���
void displayLinkedGraph(LinkedGraph* pGraph);

void traversalDFS(LinkedGraph* pGraph, int startVertexID, int *visited);
void checkDFSVisited(LinkedGraph* pGraph, int start);

void traversalBFS(LinkedGraph* pGraph, int startVertexID, int *visited);
void checkBFSVisited(LinkedGraph* pGraph, int start);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define TRUE				1
#define FALSE				0

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2

#endif