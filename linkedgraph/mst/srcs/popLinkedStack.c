/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popLinkedStack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:07:51 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/30 15:35:43 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

StackNode*		popLinkedStack(LinkedStack* pStack)
{

    //예외 처리
	if (!pStack)
        return (FALSE);
   if (!isLinkedStackEmpty(pStack))
    {
        //반환할 pop 노드의 주소를 담을 그릇 생성
        StackNode *pop_Node;
    
        //pop_Node에 현재 top노드의 주소 할당
        pop_Node = pStack->pTop;

        //pStack->pTop = NULL;
        //기존 두번째 노드와 헤드 연결 -> top 교체
        
        pStack->pTop = pop_Node->pLink;
        pStack->currentSize--;

        return (pop_Node);
    }
    else
        return(NULL);
}