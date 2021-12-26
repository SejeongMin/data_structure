/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getEdgeCountLG.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:01:54 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/20 16:02:28 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

int getEdgeCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return FALSE;
	return (pGraph->currentEdgeCount);
}