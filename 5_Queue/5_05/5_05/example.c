//
//  main.c
//  5_05
//
//  Created by Wonkeun No on 2020-04-12.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"

int main(int argc, const char * argv[]) {
    int currentTime = 0;
    int endTime = 10;
    int serviceUserCount = 0;
    int totalWaitTime = 0;
    
    LinkedQueue* pArrivalQueue = NULL, *pWaitQueue = NULL;
    QueueNode* pServiceNode1 = NULL;
    
    pArrivalQueue = createLinkedQueue();
    pWaitQueue = createLinkedQueue();
    if(pArrivalQueue != NULL && pWaitQueue == NULL) {       //왜 하나만 널이면?
        printf("오류, createLinkedQueue()\n");
        return FALSE;
    }
    insertCustomer(0, 3, pArrivalQueue);
    insertCustomer(2, 2, pArrivalQueue);
    insertCustomer(4, 1, pArrivalQueue);
    insertCustomer(6, 1, pArrivalQueue);
    insertCustomer(8, 3, pArrivalQueue);
    
    for (currentTime =0; currentTime < endTime; currentTime++) {
        processArrival(currentTime, pArrivalQueue, pWaitQueue);
        
        if (pServiceNode1 != NULL) {
            pServiceNode1 = processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
        }
        if (pServiceNode1 == NULL) {
            pServiceNode1 = processServiceNodeStart(currentTime, pWaitQueue);
        }
        printWaitQueueStatus(currentTime, pWaitQueue);
    }
    printReport(pWaitQueue, serviceUserCount, totalWaitTime);
    
    if (pServiceNode1 != NULL) {
        free(pServiceNode1);
    }
    deleteLinkedQueue(pArrivalQueue);
    deleteLinkedQueue(pWaitQueue);
    
    return 0;
}
