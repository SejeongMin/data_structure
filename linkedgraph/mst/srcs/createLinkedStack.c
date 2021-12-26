/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createLinkedStack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:50:24 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/29 17:30:26 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

LinkedStack* createLinkedStack()
{
	//링크드스택의 머리 생성 
	LinkedStack *headPointer;

	//메모리 할당
	headPointer = (LinkedStack*)malloc(sizeof(LinkedStack));
	//말록 실패 시 종료
	if (!headPointer)
		return(FALSE);
	//초기화 작업
	headPointer->currentSize = 0;
	headPointer->pTop = 0;
	
	return (headPointer);
}