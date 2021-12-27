#include "quick_sort.h"

void    swap_Nodes(DoublyListNode *pnode1, DoublyListNode *pnode2)
{
    int temp = 0;

    temp = pnode1->data;
    pnode1->data = pnode2->data;
    pnode2->data = temp;
} // pRLink, PLLink 같은 포인터 관계 바꿀 필요없이 그냥 노드 값만 바꿔주는 것으로 충분. 

void    quick_sort(DoublyList *pList, DoublyListNode *left, DoublyListNode *pivot)
{
    DoublyListNode *pLeft = left;
    DoublyListNode *pRight = pivot;

    if (left == pivot)
        return ;
    while (1)
    {
        while (pLeft->data < pivot->data)
        {
            pLeft = pLeft->pRLink;
        }
        while (pRight->data > pivot->data)
        {
            if (pRight == pLeft)
                break ;
            pRight = pRight->pLLink;
        }
        if (pRight == pLeft)
            break ;
        swap_Nodes(pLeft, pRight);
        pLeft = pLeft->pRLink;
        pRight = pivot;
    }
    swap_Nodes(pLeft, pivot);
    if (pLeft != left)
        quick_sort(pList, left, pLeft->pLLink);
    if (pLeft != pivot)
        quick_sort(pList, pLeft->pRLink, pivot);
}

/* left : 앞단부터 살펴봤을 때 처음만나는 pivot보다 큰 값
* right : pivot(현재 보는 블럭의 뒷단)부터 앞쪽 방향으로 살폈을 때, 처음만나는 pivot보다 작은 값
*/
