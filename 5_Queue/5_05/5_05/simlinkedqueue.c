//
//  linkedqueue.c
//  5_03
//
//  Created by Wonkeun No on 2020-04-10.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simdef.h" 
#include "simlinkedqueue.h"

LinkedQueue* createLinkedQueue() {
    LinkedQueue* pReturn = NULL;
    // int i=0;
    
    pReturn = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(LinkedQueue));
    }else {
        printf("오류, 메모리 할당, createLinkedQueue()\n");
    }
    return pReturn;
}
int enqueueLinkedQueue(LinkedQueue* pQueue, QueueNode element) {
    int ret = FALSE;
    QueueNode* pNode = NULL;
    
    if (pQueue != NULL) {
        pNode = (QueueNode*)malloc(sizeof(QueueNode));
        if (pNode != NULL) {
            *pNode = element;
            pNode->pLink = NULL;
            
            if (isLinkedQueueEmpty(pQueue) == TRUE) {
                pQueue->pFrontNode = pNode;
                pQueue->pRearNode = pNode;
            }else {
                pQueue->pRearNode->pLink = pNode;
                pQueue->pRearNode = pNode;
            }
            pQueue->currnetElementCount++;
            ret = TRUE;
        }else {
            printf("오류, 메모리 할당, enqueueLinkedQueue()\n");
        }
    }
    return ret;
}
QueueNode* dequeueLinkedQueue(LinkedQueue* pQueue) {
    QueueNode* pReturn = NULL;
    if (pQueue != NULL) {
        if (isLinkedQueueEmpty(pQueue) == FALSE) {
            pReturn = pQueue->pFrontNode;
            pQueue->pFrontNode = pQueue->pFrontNode->pLink;
            pReturn->pLink = NULL;
            
            pQueue->currnetElementCount--;
            if (isLinkedQueueEmpty(pQueue) == TRUE) {
                pQueue->pRearNode = NULL;
            }
        }
    }
    return pReturn;
}
QueueNode* peekLinkedQueue(LinkedQueue* pQueue) {
    QueueNode* pReturn = NULL;
    if (pQueue != NULL) {
        if (isLinkedQueueEmpty(pQueue) == FALSE) {
            pReturn = pQueue->pFrontNode;
        }
    }
    return pReturn;
}
void deleteLinkedQueue(LinkedQueue* pQueue) {
    QueueNode* pNode = NULL;
    QueueNode* pDelNode = NULL;
    
    if (pQueue != NULL) {
        pNode = pQueue->pFrontNode;
        while (pNode != NULL) {
            pDelNode = pNode;
            pNode = pNode->pLink;
            
            free(pDelNode);
        }
        free(pQueue);
    }
}
int isLinkedQueueFull(LinkedQueue* pQueue) {
    int ret = FALSE;
    return ret;
}
int isLinkedQueueEmpty(LinkedQueue* pQueue) {
    int ret = FALSE;
    
    if (pQueue != NULL) {
        if (pQueue->currnetElementCount == 0) {
            ret = TRUE;
        }
    }
    return ret;
}
