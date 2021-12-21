/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getGraphTypeLG.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:04:30 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/20 16:04:57 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

int getGraphTypeLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return FALSE;
	return (pGraph->graphType);
}