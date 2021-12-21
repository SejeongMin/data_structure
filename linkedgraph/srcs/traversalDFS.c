/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traversalDFS.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:56:20 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/21 12:31:19 by sujilee          ###   ########.fr       */
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

//재귀돌릴 함수
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