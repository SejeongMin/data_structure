/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createLinkedGraph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:10:48 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/21 00:15:30 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph* myGraph;

	// 그래프 생성
	myGraph = (LinkedGraph *)calloc(1, sizeof(LinkedGraph));
	if (!myGraph)
		return NULL;
	myGraph->maxVertexCount = maxVertexCount;
	myGraph->graphType = GRAPH_UNDIRECTED;

	// 엣지용 이차원 배열 메모리 할당
	myGraph->ppAdjEdge = (LinkedList **)calloc(maxVertexCount, sizeof(LinkedList *));
	if (!myGraph->ppAdjEdge) 
	{
		free(myGraph);
		return NULL;
	}
	// 엣지용 일차원 배열 메모리 할당
	while (--maxVertexCount >= 0)
	{
		myGraph->ppAdjEdge[maxVertexCount] = (LinkedList *)calloc(1, sizeof(LinkedList));
	}
	// 노드용 일차원 배열 메모리 할당
	myGraph->pVertex = (int *)calloc(myGraph->maxVertexCount, sizeof(int));
	if (!myGraph->ppAdjEdge)
	{
		free(myGraph);
		for(int i = 0; i < myGraph->maxVertexCount; i++)
		{
			free(myGraph->ppAdjEdge[i]);
		}
		free(myGraph->ppAdjEdge);
		return NULL;
	}
	return (myGraph);
}