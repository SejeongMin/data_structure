#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct HeapElementType
{
    int key;
    char data;
} HeapNode;

typedef struct ArrayHeapType
{
    int maxElementCount;
    int currentElementCount;
    HeapNode *pElement;
} ArrayHeap;

ArrayHeap *createArrayHeap(int maxElementCount);
void insertHeapNode(ArrayHeap *pArrayHeap, HeapNode element);
void deleteArrayHeap(ArrayHeap *pArrayHeap);
int isFullArrayHeap(ArrayHeap *pArrayHeap);
HeapNode *deleteHeapNode(ArrayHeap *pArrayHeap);
#endif
#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_
#define TRUE 1
#define FALSE 0
#endif