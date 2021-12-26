/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 02:55:43 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/23 22:10:54 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_
#define _STACK_

typedef struct StackNode
{
	int data;
	struct StackNode* pLink;
} StackNode;

typedef struct LinkedStack
{
	int currentSize;		// 현재 스택의 사이즈
	StackNode* pTop;		// 탑(Top) 노드를 가리키는 포인터
} LinkedStack;


LinkedStack*	createLinkedStack();
int				pushLinkedStack(LinkedStack* pStack, StackNode element);
StackNode*		popLinkedStack(LinkedStack* pStack);
StackNode*		peekLinkedStack(LinkedStack* pStack);
int				isLinkedStackEmpty(LinkedStack* pStack);
void			deleteLinkedStack(LinkedStack* pStack);
void			displayLinkedStack(LinkedStack* pStack);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
