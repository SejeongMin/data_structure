#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
    LinkedStack *stack;

    stack = (LinkedStack *)malloc(sizeof(LinkedStack));
    if(!stack)
        return (NULL);
    stack->currentElementCount = 0;
    stack->pTopElement = NULL;
    return(stack);
}

void deleteLinkedStack(LinkedStack* pStack)
{
    StackNode *pop;

    if(!pStack)
        return ;
    pop = popLS(pStack);
    while(pop)
    {
        free(pop);
        pop = popLS(pStack);
    }
    free(pStack);
}

StackNode* popLS(LinkedStack* pStack)
{
    StackNode *pop;

    if(!pStack || isLinkedStackEmpty(pStack))
        return(NULL);
    pop = pStack->pTopElement;
    pStack->pTopElement = pop->pLink;
    pStack->currentElementCount--;
    return(pop);
}

int pushLS(LinkedStack* pStack, int data)
{
    StackNode *node;

    if(!pStack)
        return(FALSE);
    node = (StackNode *)malloc(sizeof(StackNode));
    if(!node)
        return(FALSE);
    node->data = data;
    node->pLink = pStack->pTopElement;
    pStack->pTopElement = node;
    pStack->currentElementCount++;
    return(TRUE);    
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
    if(!pStack)
    {
        return(FALSE);
    }
    if(pStack->currentElementCount == 0)
        return (TRUE);
    return(FALSE);
}
