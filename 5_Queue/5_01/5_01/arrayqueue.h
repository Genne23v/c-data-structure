//
//  example.h
//  5_01
//
//  Created by Wonkeun No on 2020-04-09.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef arrayqueue_h
#define arrayqueue_h

typedef struct ArrayQueueNodeType {
    char element;
}ArrayQueueNode;

typedef struct ArrayQueueType {
    int maxElementCount;
    int currentElementCount;
    int front;
    int rear;
    ArrayQueueNode *pElement;
}ArrayQueue;

ArrayQueue* createArrayQueue(int maxElementCount);
int enqueueArrayQueue(ArrayQueue* pQueue, ArrayQueueNode element);
ArrayQueueNode* dequeueArrayQueue(ArrayQueue* pQueue);
ArrayQueueNode* peekArrayQueue(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DFE_
#define _COMMON_QUEUE_DFE_

#define TRUE 1
#define FALSE 0

#endif /* example_h */
