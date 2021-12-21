/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getLLElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:25:10 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/20 23:16:52 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"

LinkedNode* getLLElement(LinkedList* pList, int position)
{
	LinkedNode *curr;
	int		index = 0;
	
	//매개변수 position에 노드 개수보다 큰 수가 인자로 들어왔을 시 에러
	// if (position >= pList->currentElementCount)
	// 	return (FALSE);
	//curr은 현재 position 0의 노드의 주소값을 참조
	curr = pList->headNode->pLink;
	
	//노드 순회
	while (index < position)
	{
		curr = curr->pLink;
		index++;
	}
	return (curr);
}