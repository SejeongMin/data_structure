/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeVertexLG.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:06:05 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/26 18:48:42 by semin            ###   ########.fr       */
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
	curr = pGraph->ppAdjEdge[vertexID]->headNode->pLink;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		while (curr)
		{
			// curr->vertax : 0 vertex : 1
			removeEdgeLG(pGraph, curr->vertaxID, vertexID);
			curr = curr->pLink;
			pGraph->currentEdgeCount--;
			count++;
		}
	}
	clearLinkedList(pGraph->ppAdjEdge[vertexID]);
	pGraph->currentEdgeCount -= count;
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return SUCCESS;
}