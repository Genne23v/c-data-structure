//
//  arrayheap.c
//  7_05
//
//  Created by Wonkeun No on 2020-04-17.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlistheap.h"

LinkedListMaxHeap* createLinkedListMaxHeap() {
    LinkedListMaxHeap* pReturn = NULL;
            pReturn = (LinkedListMaxHeap*)malloc(sizeof(LinkedListMaxHeap));
        if (pReturn != NULL) {
            pReturn->pRootNode = NULL;
            pReturn->currentElementCount = 0;
        } else {
            printf("오류, 메모리 할당, createLinkedListMaxHeap()\n");
        }
    return pReturn;
}
int insertMaxHeapLinkedListHeap(LinkedListMaxHeap* pHeap, HeapNode element) {
    int ret = TRUE;
    HeapNode* pParentNode = NULL;
    HeapNode* pNewNode = NULL;
    
    if (pHeap == NULL) {
        ret = FALSE;
        return ret;
    }
    pParentNode = pHeap->pRootNode;
    if (pParentNode->key >= element.key) {
        
    } else (element.key > pParentNode->key){
        
    }
    return ret;
}
HeapNode* deleteMaxHeapLinkedListHeap(LinkedListMaxHeap* pHeap) {
    HeapNode* pReturn = NULL;
    HeapNode* pTemp = NULL;
    
    int i = 0;
    int parent = 0, child = 0;
    
    if (pHeap != NULL & pHeap->currentElementCount > 0) {
        pReturn = (HeapNode*)malloc(sizeof(HeapNode));
        if (pReturn == NULL) {
            printf("오류, 메모리 할당, deleteMaxHeapArrayHeap()\n");
            return NULL;
        }
        *pReturn = pHeap->pElement[1];
        i = pHeap->currentElementCount;
        pTemp = &(pHeap->pElement[i]);
        pHeap->currentElementCount--;
        
        parent = 1;
        child = 2;          //루프가 시작되는 곳은 루트 노드와 왼쪽 자식 노드
        
        while (child <= pHeap->currentElementCount) {       //히프의 마지막 위치에 있는 노드를 만날때 까지 루프
            if (child < pHeap->currentElementCount && pHeap->pElement[child].key < pHeap->pElement[child+1].key) {
                child++;
            }
            if (pTemp->key >= pHeap->pElement[child].key) {
                break;
            }
            pHeap->pElement[parent] = pHeap->pElement[child];       //현재 노드를 부모 노드로 이동시키고 아래로 이동
            parent = child;
            child *= 2;
        }// end-of-while
        pHeap->pElement[parent] = *pTemp;
    }
    return pReturn;
}
void deleteArrayMaxHeap(ArrayMaxHeap* pHeap) {
    if (pHeap != NULL) {
        if (pHeap->pElement != NULL) {
            free(pHeap->pElement);
        }
        free(pHeap);
    }
}

