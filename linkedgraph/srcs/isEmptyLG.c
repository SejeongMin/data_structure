/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isEmptyLG.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:04:23 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/20 15:05:44 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

int isEmptyLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return FALSE;
	return (pGraph->currentVertexCount);
}