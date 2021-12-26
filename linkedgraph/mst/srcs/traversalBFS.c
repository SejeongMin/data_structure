/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversalBFS.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:53:48 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/24 16:54:07 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

int checkBFSVisited(LinkedGraph* pGraph, int start)
{
	int *visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));

	// for(int i = 0; i < pGraph->maxVertexCount; i++)
	// {
	// 	if (!visited[i])
	// 		treversalDFS(pGraph, i);
	// }
	traversalBFS(pGraph, start, visited);
	free(visited);
	return (1);
}	

//???? ??
int traversalBFS(LinkedGraph* pGraph, int startVertexID, int *visited)
{
	LinkedQueue *myQueue;

	
	LinkedNode *curr;
	QueueNode *delNode;
	int	data;

	myQueue = createLinkedQueue();

	
	printf("BFS : %d\n", startVertexID);
	
	visited[startVertexID] = FALSE;
	//?? ?? ??
	insertRearLD(myQueue, startVertexID);

	//?? ?? ????
	while (!isLinkedQueueEmpty(myQueue))
	{
		//?? ?? -> ?? ?? ?? ??
		//?? ?? & ?? -> ???? ?? ???? ?? ??
		//???? ?? & ?? ->  "
		//visited == TRUE ? ?? ?? 

		//data? ??? ??? vertaxID? ???
		delNode = deleteFrontLD(myQueue);
		data = delNode->data;
		free(delNode);
		if (data == pGraph->pVertex[startVertexID])
		{
			free(visited);
			return (TRUE);
		}
		// insertRearLD(displayQueue, data);
		//curr? ??? ?? ?? ??
		curr = pGraph->ppAdjEdge[data]->headNode->pLink;
		// printf("curr data: %d\n", curr->vertaxID);
		//??? ??? ??? ?? ??? ?? ?? visited ??
		while (curr)
		{
			if (visited[curr->vertaxID] == FALSE)
			{
				visited[curr->vertaxID] = TRUE;
				insertRearLD(myQueue, curr->vertaxID);
			}
			curr = curr->pLink;
		}
	}
	deleteLinkedQueue(myQueue);
	return (FALSE);
}