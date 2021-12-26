/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteLinkedGraph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:31:51 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/26 18:47:27 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	if (!pGraph)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		removeVertexLG(pGraph, i);
		free(pGraph->ppAdjEdge[i]->headNode);
		free(pGraph->ppAdjEdge[i]);
	}
	if (pGraph->currentEdgeCount != 0 || pGraph->currentVertexCount != 0)
		printf("deleteLinkedGraph failed!\n");
	free(pGraph->pVertex);
	free(pGraph->ppAdjEdge);
	free(pGraph);
}