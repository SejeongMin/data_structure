/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addVertexLG.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:28:00 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/21 11:01:23 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	LinkedNode *head;

	if (!pGraph)
		return FALSE;
	if (vertexID >= pGraph->maxVertexCount)
		return FALSE;
	if (pGraph->pVertex[vertexID])
	{
		printf("vertaxID already exist!\n");
		return FAIL;
	}
	head = (LinkedNode *)malloc(sizeof(LinkedNode));
	head->vertaxID = vertexID;
	head->pLink = 0;
	head->weight = 0;
	pGraph->ppAdjEdge[vertexID]->headNode = head;
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;

	return SUCCESS;
}