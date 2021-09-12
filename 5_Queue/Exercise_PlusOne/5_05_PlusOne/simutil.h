//
//  simutil.h
//  5_05
//
//  Created by Wonkeun No on 2020-04-12.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef simutil_h
#define simutil_h

void insertCustomer(int arrivalTime, int processTime, LinkedQueue* pQueue); //도착 고객 큐에 추가
void processArrival(int currentTime, LinkedQueue* pArrivalQueue, LinkedQueue* pWaitQueue);           //도착 고객 처리
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue* pWaitQueue);   //서비스 처리 시작
QueueNode* processServiceNodeEnd(int currentTime, QueueNode* pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);     //서비스 종료처리
void printSimCustomer(int currentTime, SimCustomer customer);       //고객의 상태를 출력
void printWaitQueueStatus(int currentTime, LinkedQueue* pWaitQueue);    //대기열의 상태를 출력
void printReport(LinkedQueue* pWaitQueue, int serviceUserCount, int totalWaitTime);     //최종 시뮬레이션 결과 출력

#endif /* simutil_h */
