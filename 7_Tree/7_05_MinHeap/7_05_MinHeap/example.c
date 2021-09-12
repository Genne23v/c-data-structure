//
//  main.c
//  7_05
//
//  Created by Wonkeun No on 2020-04-17.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "arrayheap.h"

void displayArrayHeap(ArrayMinHeap* pHeap) {
    int i = 0;
    if (pHeap != NULL) {
        for (i=0; i <= pHeap->currentElementCount; i++) {
            printf("[%d], %d\n", i, pHeap->pElement[i]);
        }
    }
}
int main(int argc, const char * argv[]) {
    int maxHeapSize = 20;
    ArrayMinHeap* pHeap1 = NULL;
    
    HeapNode* pNode = NULL;
    HeapNode e1 = {10};
    HeapNode e2 = {40};
    HeapNode e3 = {30};
    HeapNode e4 = {20};
    HeapNode e5 = {50};
    
    pHeap1 = createArrayMinHeap(maxHeapSize);
    if (pHeap1 != NULL) {
        insertMinHeapArrayHeap(pHeap1, e1);
        insertMinHeapArrayHeap(pHeap1, e2);
        insertMinHeapArrayHeap(pHeap1, e3);
        insertMinHeapArrayHeap(pHeap1, e4);
        insertMinHeapArrayHeap(pHeap1, e5);
        
        printf("Min Heap:\n");
        displayArrayHeap(pHeap1);
        
        pNode = deleteMinHeapArrayHeap(pHeap1);
        if (pNode != NULL) {
            printf("deleteMinHeapArrayHeap() - [%d]\n", pNode->key);
            free(pNode);
        }
        printf("Min Heap:\n");
        displayArrayHeap(pHeap1);
        deleteMinHeapArrayHeap(pHeap1);
    }
    return 0;
}
