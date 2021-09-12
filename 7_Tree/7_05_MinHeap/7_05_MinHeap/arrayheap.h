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
}HeapNode;

typedef struct ArrayHeapType {
    int maxElementCount;
    int currentElementCount;
    HeapNode* pElement;
}ArrayMaxHeap, ArrayMinHeap;

ArrayMaxHeap* createArrayMinHeap(int maxElementCount);
void deleteArrayMinHeap(ArrayMaxHeap* pArrayHeap);
void insertMinHeapArrayHeap(ArrayMaxHeap* pArrayHeap, HeapNode element);
HeapNode* deleteMinHeapArrayHeap(ArrayMaxHeap* pArrayHeap);

#endif /* arrayheap_h */

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE 1
#define FALSE 0

#endif
