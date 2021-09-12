//
//  example.c
//  5_01
//
//  Created by Wonkeun No on 2020-04-09.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "arrayqueue.h"

void displayArrayQueue(ArrayQueue* pQueue) {
    int i=0, maxElementIndex =0, pos =0;
    if (pQueue != NULL) {
        printf("큐의 크기 : %d, 현재 노드 개수 : %d\n", pQueue->maxElementCount, pQueue->currentElementCount);
        
        maxElementIndex = pQueue->front + pQueue->currentElementCount;  //front부터 원소 개수만큼 배열 이동. Index값이 front보다 작아질 수 있음
        for (i = pQueue->front+1; i <= maxElementIndex; i++) {  //1,2,3,0인 배열은 2부터 5까지 루프
            pos = i % pQueue->maxElementCount;                  //2,3,0,1 배열
            printf("[%d] - [%c]\n", pos, pQueue->pElement[pos].element);
        }
    }
}
int enqueueArrayQueueChar(ArrayQueue* pQueue, char element) {
    ArrayQueueNode node = {0,};
    node.element = element;
    return enqueueArrayQueue(pQueue, node);
}
int main(int argc, char *argv[]) {
    ArrayQueue* pQueue = NULL;
    ArrayQueueNode* pNode = NULL;
    char value = 0;
    
    pQueue = createArrayQueue(4);
    if (pQueue != NULL) {
        enqueueArrayQueueChar(pQueue, 'A');
        enqueueArrayQueueChar(pQueue, 'B');
        enqueueArrayQueueChar(pQueue, 'C');
        enqueueArrayQueueChar(pQueue, 'D');
        displayArrayQueue(pQueue);
        
        pNode = dequeueArrayQueue(pQueue);
        if (pNode != NULL) {
            printf("Dequeue Value-[%c]\n", pNode->element);
            free(pNode);
        }
        displayArrayQueue(pQueue);
        
        pNode = peekArrayQueue(pQueue);
        
        if (pNode != NULL) {
            printf("Peek Value-[%c]\n", pNode->element);
        }
        
        displayArrayQueue(pQueue);
        
        enqueueArrayQueueChar(pQueue, 'E');
        displayArrayQueue(pQueue);
        }
return 0;
}
