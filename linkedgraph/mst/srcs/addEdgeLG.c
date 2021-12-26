/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addEdgeLG.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:37:28 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/21 11:34:17 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	LinkedNode *dir_nextNode;	//??? ??? : toNode? ??
	LinkedNode *undir_nextNode; //??? ??? : toNode? ??

	if (!pGraph)
		return (FALSE);
	
	//??? ??
	dir_nextNode = (LinkedNode *)calloc(1, sizeof(LinkedNode));
	if (!dir_nextNode)
		return FALSE;
	
	//toNode? ID? ??
	dir_nextNode->vertaxID = toVertexID;
	
	if (! checkVertexValid(pGraph, fromVertexID) 
	|| !checkVertexValid(pGraph, toVertexID))
		return FAIL;
	
	//??!!!?? ??
		
	dir_nextNode->pLink = pGraph->ppAdjEdge[fromVertexID]->headNode->pLink;
	//Çìµå¶û dir_nextNode ¿¬°á
	pGraph->ppAdjEdge[fromVertexID]->headNode->pLink = dir_nextNode;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		undir_nextNode = (LinkedNode *)calloc(1, sizeof(LinkedNode));
		if (!undir_nextNode)
			return FALSE;
		undir_nextNode->vertaxID = fromVertexID;
			
		undir_nextNode->pLink = pGraph->ppAdjEdge[toVertexID]->headNode->pLink;
		//Çìµå¶û dir_nextNode ¿¬°á
		pGraph->ppAdjEdge[toVertexID]->headNode->pLink = undir_nextNode;
	}
	pGraph->currentEdgeCount++;
	return SUCCESS;
	
	return FAIL;
}