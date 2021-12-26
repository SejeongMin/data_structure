/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeLLElement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:36:31 by sujilee           #+#    #+#             */
/*   Updated: 2021/12/26 18:50:28 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"
#include <stdlib.h>

int removeLLElement(LinkedList* pList, int position)
{
	LinkedNode *prev;		//������ ����� �� ����� �ּҸ� ���� �׸�
	LinkedNode *remove;	//������ ����� �ּҸ� ���� �׸�
	
	//����ó��
	// if (pList->currentElementCount <= 0 ||
	// 	position > pList->currentElementCount ||
	// 	position < 0)
	// 	return (FALSE);
	if (pList->headNode == NULL || pList->headNode->pLink == NULL)
		return (FALSE);
	
	//�����ϰ� ���� ����� �ּҰ��� �Լ��� �޾ƿ´�.
	remove = getLLElement(pList, position);
	
	//�����ϰ� ���� ����� ��ġ�� ��� ������ ���
	if (position == 0)
	{
		pList->headNode->pLink = remove->pLink;
	}
	else
	{
		prev = getLLElement(pList, position - 1);
		prev->pLink = remove->pLink;
	}
	
	// remove->data = 0;
	// remove->pLink = 0;
	free(remove);
	
	// pList->currentElementCount--;
	return (TRUE);
}