/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayLinkedStack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:14:33 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/29 19:29:13 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

void			displayLinkedStack(LinkedStack* pStack)
{
	//현재 사이즈와 인덱스에 따른 데이터값 출력하는 함수
	
		//예외 처리
		if (!pStack)
			return ;
		StackNode *curr;	//순회용 포인터 생성
		int	idx = pStack->currentSize - 1;
		
		curr = pStack->pTop;
		printf("stack size : %d\n", pStack->currentSize);
		while (curr)
		{
			printf("{index: %d, data: %d}\n", idx, curr->data);
			curr = curr->pLink;
			idx--;
		}
	
}