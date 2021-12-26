/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushLinkedStack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:59:25 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/24 15:50:47 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int		pushLinkedStack(LinkedStack* pStack, StackNode element)
{
	//링크드스택에 push해 줄 노드 생성
	StackNode *new_top;
	
	//예외 처리
	if (!pStack)
		return (FALSE);
	//메모리 할당
	new_top = (StackNode*)malloc(sizeof(StackNode));
	//매개변수 element로 들어온 노드의 data값을 new_node에 복사
	new_top->data = element.data;
	//new_node(새 top)와 기존 top 링크 연결
	new_top->pLink = pStack->pTop;
	//헤드 노드와 링크 연결
	pStack->pTop = new_top;
	pStack->currentSize++;

	return (TRUE);
}