/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayLinkedGraph.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:41:03 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/21 11:32:11 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

void displayLinkedGraph(LinkedGraph* pGraph)
{
	int idx = 0;
	LinkedNode *curr;

	
	if (!pGraph)
		return ;
	printf("MVC : %d\n", pGraph->maxVertexCount);
	printf("CVC : %d\n", pGraph->currentVertexCount);
	printf("CEC : %d\n", pGraph->currentEdgeCount);
	printf("G T : %s\n", pGraph->graphType == 1 ? "GRAPH_UNDIRECTED" : "GRAPH_DIRECTED");

	printf("---------\n");
	printf("%d\n", pGraph->maxVertexCount);
	while (idx < pGraph->maxVertexCount)
	{
		if (pGraph->ppAdjEdge[idx]->headNode)
		{
			printf("headnode (%d) : ", pGraph->ppAdjEdge[idx]->headNode->vertaxID);
			curr = pGraph->ppAdjEdge[idx]->headNode->pLink;
			while (curr)
			{
				printf(" --%d--> %d", curr->weight, curr->vertaxID);
				curr = curr->pLink;
			}	
		}
		printf("\n");
		idx++;
	}
	
	// for (int idx = 0; idx < pGraph->maxVertexCount; idx++)
	// {
	// 	printf("%d : ", idx);
	// 	curr = pGraph->ppAdjEdge[idx]->headNode->pLink;
	// 	while (curr)
	// 	{
	// 		printf("--%d--> %d", curr->weight, curr->vertaxID);
	// 		curr = curr->pLink;
	// 	}	
	// 	printf("\n");
	// }
}