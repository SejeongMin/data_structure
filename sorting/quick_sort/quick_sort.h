#ifndef _SORT_
#define _SORT_

#include "doublylist/doublylist.h"

// =====================  MAIN ============================
void    displayDl(DoublyList *pList);
DoublyList *lst_cpy(DoublyList *pList);

// ====================== QUICK SORT ======================
void    quick_sort(DoublyList *pList, DoublyListNode *left, DoublyListNode *pivot);
// DoublyListNode  *find_left(DoublyListNode *head, DoublyListNode *left, DoublyListNode *pivot);
// DoublyListNode  *find_right(DoublyListNode *head, DoublyListNode *left, DoublyListNode *pivot);
void    swap_Nodes(DoublyListNode *pnode1, DoublyListNode *pnode2);

#endif