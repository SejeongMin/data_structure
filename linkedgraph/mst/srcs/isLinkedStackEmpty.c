/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isLinkedStackEmpty.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:12:55 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/29 19:08:51 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int			isLinkedStackEmpty(LinkedStack* pStack)
{
	if (pStack->currentSize == 0)
		return (TRUE);
	else
		return (FALSE);
}