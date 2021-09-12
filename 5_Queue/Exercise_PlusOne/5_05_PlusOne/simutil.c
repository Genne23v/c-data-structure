//
//  simutil.c
//  5_05
//
//  Created by Wonkeun No on 2020-04-12.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "simlinkedqueue.h"
#include "simdef.h"
#include "simutil.h"

void insertCustomer(int arrivalTime, int serviceTime, LinkedQueue* pQueue) {
    if (pQueue != NULL) {
        QueueNode node = {0, };
        node.data.status = arrival;
        node.data.arrivalTime = arrivalTime;
        node.data.serviceTime = serviceTime;
        node.data.startTime = 0;
        node.data.endTime = 0;
        enqueueLinkedQueue(pQueue, node);
    }
}
void processArrival(int currentTime, LinkedQueue* pArrivalQueue, LinkedQueue* pWaitQueue) {
    QueueNode* pArrivalNode = NULL;
    int isEmpty = 0;
    isEmpty = isLinkedQueueEmpty(pArrivalQueue);
    //고객 도착 큐에 노드가 없는지 확인학고 없으면 루프를 빠져나감
    while (isEmpty == FALSE) {
        pArrivalNode = peekLinkedQueue(pArrivalQueue);      //현재 고객 도착 큐의 프런트 노드를 피크함
        //피크한 고객 도착시간이 현재시간과 같으면 대기큐에 인큐하고 대기 상태가 되었음을 출력. 고객 노드가 도착시간순으로 정렬되지 않으면 함수는 오작동
        if (pArrivalNode->data.arrivalTime == currentTime) {
            enqueueLinkedQueue(pWaitQueue, *pArrivalNode);
            printSimCustomer(currentTime, pArrivalNode->data);
            
            free(dequeueLinkedQueue(pArrivalQueue));
        } else {
            break;
        }
        isEmpty = isLinkedQueueEmpty(pArrivalQueue);
    }
}
QueueNode* processServiceNodeEnd(int currentTime, QueueNode* pServiceNode, int *pServiceUserCount, int *pTotalWaitTime) {
    int endTime = 0;
    int waitTime = 0;
    QueueNode* pReturn = NULL;
    
    if (pServiceNode == NULL || pServiceUserCount == NULL || pTotalWaitTime == NULL) {
        return NULL;
    }
    endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
    
    if (endTime <= currentTime) {
        waitTime = pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
        (*pServiceUserCount)++;
        (*pTotalWaitTime) += waitTime;
        
        pServiceNode->data.status = end;
        pServiceNode->data.endTime = currentTime;
        printSimCustomer(currentTime, pServiceNode->data);
        
        free(pServiceNode);     //현재 고객이 서비스가 종료되어 시스템을 빠져나가 메모리 해제
        pReturn = NULL;
    } else {
        //do nothing
        pReturn = pServiceNode;     //현재 서비스 중인 고객이 종료되지 않았으면 현재 노드에 대한 포인터만 반환(서비스 진행중)
    }
    return pReturn;
}
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue* pWaitQueue) {
    QueueNode* pReturn = NULL;
    QueueNode* pServiceNode = NULL;
    int isEmpty = 0;
    
    if (pWaitQueue == NULL) {
        return NULL;
    }
    isEmpty = isLinkedQueueEmpty(pWaitQueue);
    if (isEmpty == FALSE) {
        pServiceNode = dequeueLinkedQueue(pWaitQueue);      //현재 고객 대기큐에서 디큐 실행

        if (pServiceNode != NULL) {
            pServiceNode->data.status = start;
            pServiceNode->data.startTime = currentTime;
            printSimCustomer(currentTime, pServiceNode->data);
            
            pReturn = pServiceNode;
        }
    }
    return pReturn;
}
void printSimCustomer(int currentTime, SimCustomer customer) {
    printf("[%d]", currentTime);
    
    switch (customer.status) {
        case arrival:
            printf("고객 도착\n");
            break;
        case start:
            printf("서비스 시작");
            printf(", 도착-%d, 대기시간-%d\n", customer.arrivalTime, (customer.startTime - customer.arrivalTime));
            break;
        case end:
            printf("서비스 종료");
            printf(", 도착-%d, 시작-%d, 대기시간-%d, 서비스 시간-%d\n", customer.arrivalTime, customer.startTime, customer.startTime - customer.arrivalTime, customer.endTime - customer.startTime);
            break;
        }
}
void printWaitQueueStatus(int currentTime, LinkedQueue* pWaitQueue) {
    printf("[%d], 현재 대기 고객 수: %d\n", currentTime, pWaitQueue->currnetElementCount);
}
void printReport(LinkedQueue* pWaitQueue, int serviceUserCount, int totalWaitTime) {
    printf("REPORT\n");
    printf("서비스 고객 수: %d\n", serviceUserCount);
    if (serviceUserCount > 0) {
        printf("평균 대기 시간: %f\n", ((float)totalWaitTime / (float)serviceUserCount));
    }
    printf("현재 대기 열의 고객 수: %d\n", pWaitQueue->currnetElementCount);
}
