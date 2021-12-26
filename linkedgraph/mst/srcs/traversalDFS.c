/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversalDFS.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:56:20 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/24 15:55:31 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

void checkDFSVisited(LinkedGraph* pGraph, int start)
{
	int *visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));

	// for(int i = 0; i < pGraph->maxVertexCount; i++)
	// {
	// 	if (!visited[i])
	// 		treversalDFS(pGraph, i);
	// }
	traversalDFS(pGraph, start, visited);
	free(visited);
}	

//?? ???
void traversalDFS(LinkedGraph* pGraph, int startVertexID, int *visited)
{
	LinkedNode *curr;
	visited[startVertexID] = 1;
	
	printf("DFS : %d\n", startVertexID);
	curr = pGraph->ppAdjEdge[startVertexID]->headNode->pLink;
	while (curr)
	{
		if (visited[curr->vertaxID] == 0)
			traversalDFS(pGraph, curr->vertaxID, visited);
		curr = curr->pLink;
	}
}