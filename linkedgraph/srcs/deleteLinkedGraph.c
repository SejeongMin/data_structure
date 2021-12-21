/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteLinkedGraph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:31:51 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/21 00:10:20 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	if (!pGraph)
		return ;
	printf("v: %d\n", pGraph->currentVertexCount);
	// while (pGraph->currentVertexCount > 0)
	// {
	// 	removeVertexLG(pGraph, pGraph->currentVertexCount - 1);
	// 	free(pGraph->ppAdjEdge[pGraph->currentVertexCount - 1]);
	// }
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		removeVertexLG(pGraph, i);
		free(pGraph->ppAdjEdge[i]);
	}
	if (pGraph->currentEdgeCount != 0 || pGraph->currentVertexCount != 0)
		printf("deleteLinkedGraph failed!\n");
	free(pGraph->pVertex);
	free(pGraph->ppAdjEdge);
	free(pGraph);
}