/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peekLinkedStack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:07:18 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/29 18:08:37 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

StackNode*		peekLinkedStack(LinkedStack* pStack)
{
	if (!pStack)
		return (FALSE);
	return (pStack->pTop);
}