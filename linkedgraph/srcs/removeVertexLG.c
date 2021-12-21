/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeVertexLG.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:06:05 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/21 11:28:50 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	LinkedNode *curr; //순회용 포인터 그릇
	
	int count = 0; 
	
	if (!pGraph)
		return FALSE;	
	if (!checkVertexValid(pGraph, vertexID))
		return FAIL;
	printf("********");
	printf("checkheadnode : %d\n", pGraph->ppAdjEdge[vertexID]->headNode->vertaxID);
	curr = pGraph->ppAdjEdge[vertexID]->headNode->pLink;
	printf("curr in\n");
	printf("type: %d\n", pGraph->graphType);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		printf("if in\n");
		// printf("curr's ID : %d\n", curr->vertaxID);
		while (curr)
		{
			printf("while in");
			// curr->vertax : 0 vertex : 1
			removeEdgeLG(pGraph, curr->vertaxID, vertexID);
			curr = curr->pLink;
			pGraph->currentEdgeCount--;
			count++;
		}
	}
	printf("before success");
	clearLinkedList(pGraph->ppAdjEdge[vertexID]);
	pGraph->currentEdgeCount -= count;
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;	
	return SUCCESS;
}