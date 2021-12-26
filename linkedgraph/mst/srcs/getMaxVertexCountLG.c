/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getMaxVertexCountLG.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:03:36 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/20 16:04:20 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return FALSE;
	return (pGraph->maxVertexCount);
}