//
//  arrayheap.h
//  7_05
//
//  Created by Wonkeun No on 2020-04-17.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef arrayheap_h
#define arrayheap_h

#include <stdio.h>

typedef struct HeapElementType {
    int key;
    char data;
    struct HeapElementType* pLeftChild;
    struct HeapElementType* pRightChild;
}HeapNode;

typedef struct LinkedListHeapType {
    int currentElementCount;
    HeapNode* pRootNode;
}LinkedListMaxHeap, LinkedListMinHeap;

LinkedListMaxHeap* createLinkedListMaxHeap(void);
int deleteLinkedListMaxHeap(LinkedListMaxHeap* pLinkedListHeap);
int insertMaxHeapLinkedListHeap(LinkedListMaxHeap* pLinkedListHeap, HeapNode element);
HeapNode* deleteMaxHeapLinkedListHeap(LinkedListMaxHeap* pLinkedListHeap);

#endif /* arrayheap_h */

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE 1
#define FALSE 0

#endif
