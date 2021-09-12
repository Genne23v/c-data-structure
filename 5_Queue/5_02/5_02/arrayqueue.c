//
//  main.c
//  5_01
//
//  Created by Wonkeun No on 2020-04-09.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount) {
    ArrayQueue* pReturn = NULL;
    
    if (maxElementCount >0) {
        pReturn = (ArrayQueue*)malloc(sizeof(ArrayQueue));
        if (pReturn != NULL) {
            memset(pReturn, 0, sizeof(ArrayQueue));
            pReturn->maxElementCount = maxElementCount;
            pReturn->front = -1;
            pReturn->rear = -1;
        } else {
            printf("오류, 메모리할당, createArrayQueue()\n");
            return NULL;
        }
    }else {
        printf("오류, 큐 크기는 0보다 커야 합니다.\n");
        return NULL;
    }
    pReturn->pElement = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode)*maxElementCount);
    if (pReturn->pElement != NULL) {
        memset(pReturn->pElement, 0, sizeof(ArrayQueueNode)*maxElementCount);
    } else {
        printf("오류, 메모리 할당2, createArrayQueue()\n");
        free(pReturn);
        return NULL;
    }
    return pReturn;
}
int enqueueArrayQueue(ArrayQueue* pQueue, ArrayQueueNode element) {
    int ret = FALSE;
    
    if (pQueue != NULL) {
        if (isArrayQueueFull(pQueue) == FALSE) {
            pQueue->rear = (pQueue->rear +1) % pQueue->maxElementCount;
            pQueue->pElement[pQueue->rear] = element;
            pQueue->currentElementCount++;
            
            ret = TRUE;
        } else {
            printf("오류, 큐가 가득 찼습니다, enqueueArrayQueue()\n");
        }
    }
    return ret;
}
ArrayQueueNode* dequeueArrayQueue(ArrayQueue* pQueue) {
    ArrayQueueNode* pReturn = NULL;
    if (pQueue != NULL) {
        if (isArrayQueueEmpty(pQueue) == FALSE) {
            pReturn = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode));      //새로운 배열에 프론트 값 복사
            if (pReturn != NULL) {
                pQueue->front = (pQueue->front +1) % pQueue->maxElementCount;    //프론트 위치 변경
                pReturn->element = pQueue->pElement[pQueue->front].element; //반환 노드값을 복사하고 프론트 위치만 바꿔서 배열갯수 줄임
                pQueue->currentElementCount--;  //메모리 해제는 디큐를 호출한 함수쪽에서 반환한 값을 사용하고 해제 (왜 그래야 하지?)
            } else {
                printf("오류, 메모리할당, dequeueArrayQueue()\n");
            }
        }
    }
    return pReturn;
}
ArrayQueueNode* peekArrayQueue(ArrayQueue* pQueue) {
    ArrayQueueNode* pReturn = NULL;
    if (pQueue != NULL) {
        if (isArrayQueueEmpty(pQueue) == FALSE) {
            pReturn = &(pQueue->pElement[pQueue->front +1]);
        }
    }
    return pReturn;
}
void deleteArrayQueue(ArrayQueue* pQueue) {
    if (pQueue != NULL) {
        if (pQueue->pElement != NULL) {
            free(pQueue->pElement);
        }
        free(pQueue);
    }
}
int isArrayQueueFull(ArrayQueue* pQueue) {
    int ret = FALSE;
    
    if (pQueue != NULL) {
        if (pQueue->currentElementCount == pQueue->maxElementCount) {
            ret = TRUE;     //새로운 노드를 넣을 공간이 있어도 들어갈 리어가 없으면 인큐가 안된다 
        }
    }
    return ret;
}
int isArrayQueueEmpty(ArrayQueue* pQueue) {
    int ret = FALSE;
    
    if (pQueue != NULL) {
        if (pQueue->currentElementCount == 0) {
            ret = TRUE;
        }
    }
    return ret;
}
