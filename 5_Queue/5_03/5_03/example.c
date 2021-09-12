//
//  example.c
//  5_01
//
//  Created by Wonkeun No on 2020-04-09.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

void displayLinkedQueue(LinkedQueue* pQueue) {
    QueueNode* pNode = NULL;
    int i=0;
    if (pQueue != NULL) {
        printf("현재 노드 개수: %d\n", pQueue->currnetElementCount);
        pNode = pQueue->pFrontNode;
        while (pNode != NULL) {
            printf("[%d] - [%c]\n", i, pNode->data);
            i++;
            pNode = pNode->pLink;
        }
    }
}
int enqueueLinkedQueueChar(LinkedQueue* pQueue, char element) {
   QueueNode node = {0,};
    node.data = element;
    return enqueueLinkedQueue(pQueue, node);
}
int main(int argc, char *argv[]) {
    LinkedQueue* pQueue = NULL;
    QueueNode* pNode = NULL;
    // char value = 0;
    
    pQueue = createLinkedQueue();
    if (pQueue != NULL) {
        enqueueLinkedQueueChar(pQueue, 'A');
        enqueueLinkedQueueChar(pQueue, 'B');
        enqueueLinkedQueueChar(pQueue, 'C');
        enqueueLinkedQueueChar(pQueue, 'D');
        displayLinkedQueue(pQueue);
        
        pNode = dequeueLinkedQueue(pQueue);
        if (pNode != NULL) {
            printf("Dequeue Value-[%c]\n", pNode->data);
            free(pNode);
        }
        displayLinkedQueue(pQueue);
        
        pNode = peekLinkedQueue(pQueue);
        
        if (pNode != NULL) {
            printf("Peek Value-[%c]\n", pNode->data);
        }
        
        displayLinkedQueue(pQueue);
        
        enqueueLinkedQueueChar(pQueue, 'E');
        displayLinkedQueue(pQueue);
        }
return 0;
}
