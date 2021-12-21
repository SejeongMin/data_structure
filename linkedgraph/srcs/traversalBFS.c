/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversalBFS.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:53:48 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/21 13:56:16 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

void checkBFSVisited(LinkedGraph* pGraph, int start)
{
	int *visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));

	// for(int i = 0; i < pGraph->maxVertexCount; i++)
	// {
	// 	if (!visited[i])
	// 		treversalDFS(pGraph, i);
	// }
	traversalBFS(pGraph, start, visited);
	free(visited);
}	

//???? ??
void traversalBFS(LinkedGraph* pGraph, int startVertexID, int *visited)
{
	LinkedQueue *myQueue;
	LinkedQueue *displayQueue;
	
	LinkedNode *curr;
	int	data;

	myQueue = createLinkedQueue();
	displayQueue = createLinkedQueue();
	
	printf("BFS : %d\n", startVertexID);
	
	visited[startVertexID] = TRUE;
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
		data = deleteFrontLD(myQueue)->data;
		insertRearLD(displayQueue, data);
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
	displayLinkedQueue(displayQueue, pGraph->currentVertexCount);
	deleteLinkedQueue(myQueue);
	deleteLinkedQueue(displayQueue);
}