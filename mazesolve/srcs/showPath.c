#include "mazesolve.h"

void reverseStack(LinkedStack *pStack)
{
  StackNode *curr; //현재 노드를 가리킬 주소값의 그릇
  StackNode *next; //다음 노드를 가리킬 주소값의 그릇
  StackNode *prev; //역순링크를 위해 전 노드를 가리킬 주소값의 그릇

  curr = pStack->pTopElement;
  prev = 0;
  next = 0;
  
  //모든 노드를 순회할 때까지
  while (curr)
  {
    //next == 현재 노드의 다음 노드
    next = curr->pLink;
    //prv == 현재 노드의 전 노드 : 노드의 링크를 역순으로 연결
    curr->pLink = prev;
    //다음 단계 진행 위해 prev에 현재 노드의 주소를 넣어준다
    prev = curr;
    //다음 단계 진행 위해 curr에 다음 노드의 주소를 넣어준다
    curr = next;
  }

  //헤드 노드의 링크를 원래 리스트의 마지막 노드와 연결한다(현재는 첫 노드)
  pStack->pTopElement = prev;
  
}

void	showPath(LinkedStack* pStack)
{
    StackNode *node;
    if(!pStack)
        return ;
    reverseStack(pStack);
    node = pStack->pTopElement;
    while(node)
    {
        printf("%c ", node->data);
        node = node->pLink;
    }
    printf("\n");
    reverseStack(pStack);
}