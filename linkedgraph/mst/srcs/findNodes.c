/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findNodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:53:48 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/24 15:53:47 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"
#include "linkedqueue.h"
#include "primMST.h"

LinkedQueue* findBFSNodes(LinkedGraph* pGraph, int start)
{
	int *visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
	
	return (findNodes(pGraph, start, visited));
}

LinkedQueue* findNodes(LinkedGraph* pGraph, int startVertexID, int *visited)
{
	LinkedQueue *myQueue; //BFS시 탐색 전 노드를 미리 담아놓는 공간
	LinkedQueue *displayQueue; //myQueue에서 pop되어 실제 탐색이 된 노드
	
	LinkedNode *curr; //순회용 그릇
	QueueNode *delNode;
	int	data;

	myQueue = createLinkedQueue();
	displayQueue = createLinkedQueue();
	
	visited[startVertexID] = TRUE;
	//탐색을 시작한 vertexID를 큐에 인큐
	insertRearLD(myQueue, startVertexID);

	//모든 노드가 pop 될때까지 -> 존재하는 모든 vertex를 탐색할때까지
	while (!isLinkedQueueEmpty(myQueue))
	{


		//data : 탐색이 완료된 vertex의 ID, 해당 vertex를 pop
		delNode = deleteFrontLD(myQueue);
		data = delNode->data;
		free(delNode);
		//위에서 pop된 vertexID를 완료용 큐에 푸시
		insertRearLD(displayQueue, data);
		
		//curr : 해당 vertaxID의 인접노드 
		curr = pGraph->ppAdjEdge[data]->headNode->pLink;
	
		//해당 vertexID의 모든 인접노드를 돌때까지
		while (curr)
		{
			//방문되지 않은 노드이면 방문 표시를 하고 탐색용노드에 푸시 
			if (visited[curr->vertaxID] == FALSE)
			{
				visited[curr->vertaxID] = TRUE;
				insertRearLD(myQueue, curr->vertaxID);
			}
			curr = curr->pLink;
		}
	}
	deleteLinkedQueue(myQueue);
	free(visited);
	return (displayQueue);
}