//
//  linkedqueue.h
//  5_03
//
//  Created by Wonkeun No on 2020-04-10.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef bintreelinkedqueue_h
#define bintreelinkedqueue_h
#include "bintreetraversal.h"

typedef struct QueueNodeType {
    BinTree* data;
    struct QueueNodeType* pLink;
}QueueNode;

typedef struct LinkedQueueType {
    int currnetElementCount;
    QueueNode* pFrontNode;
    QueueNode* pRearNode;
}LinkedQueue;


LinkedQueue* createLinkedQueue(void);
int enqueueLinkedQueue(LinkedQueue* pQueue, QueueNode element);
QueueNode* dequeueLinkedQueue(LinkedQueue* pQueue);
QueueNode* peekLinkedQueue(LinkedQueue* pQueue);
void deleteLinkedQueue(LinkedQueue* pQueue);
int isLinkedQueueFull(LinkedQueue* pQueue);
int isLinkedQueueEmpty(LinkedQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE 1
#define FALSE 0

#endif /* linkedqueue_h */
