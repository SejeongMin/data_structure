/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeEdgeLG.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:13:48 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/21 11:26:01 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	LinkedNode *headNode; //헤드노드 그릇
	LinkedNode *prevNode; //삭제할 노드의 전 노드 그릇
	LinkedNode *delNode;  //삭제할 노드 그릇
	
	//그릇에 헤드노드 복사
	headNode = pGraph->ppAdjEdge[fromVertexID]->headNode;
	
	if (!pGraph)
		return FALSE;
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
	{
		printf("node do not exist");
		return FAIL;
	}
	
	delNode = headNode;
	prevNode = headNode;
	while (delNode)
	{
		//delNode가 toNode와 일치하면 break
		if (delNode->vertaxID == toVertexID)
		{
			break;
		}
		//다음 순서로 연결
		prevNode = delNode;
		delNode = delNode->pLink;
	}
	if (!delNode)
		return FALSE;
	//prevNode의 링크를 delNode 다음 노드로 연결시켜줌	
	prevNode->pLink = delNode->pLink;
	// free(delNode);
	
	if (pGraph->graphType == GRAPH_UNDIRECTED && headNode)
	{
		headNode = pGraph->ppAdjEdge[toVertexID]->headNode;
		delNode = headNode;
		prevNode = headNode;
		while (delNode)
		{
			if (delNode->vertaxID == fromVertexID)
			{
				break;
			}
			prevNode = delNode;
			delNode = delNode->pLink;
		}
		if (!delNode)
			return FALSE;
		prevNode->pLink = delNode->pLink;
		// free(delNode);
	}
	pGraph->currentEdgeCount--;
	return SUCCESS;
}