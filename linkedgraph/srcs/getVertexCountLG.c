/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getVertexCountLG.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:02:43 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/20 16:03:27 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

int getVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return FALSE;
	return (pGraph->currentVertexCount);
}