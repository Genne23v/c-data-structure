//
//  polysub.c
//  PolySub
//
//  Created by Wonkeun No on 2020-05-02.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "polysub.h"

int addPolyNodeLast(LinkedList* pList, int coef, int degree) {
    int ret = FALSE;
    ListNode node = {0, };
    
    node.coef = coef;
    node.degree = degree;
    
    if (pList != NULL) {
        int length = getLinkedListLength(pList);
        ret = addLinkedListElement(pList, length, node);
    }
    return ret;
};
LinkedList* polySubtract(LinkedList* pListA, LinkedList* pListB) {
    LinkedList* pReturn = NULL;
    ListNode *pNodeA = NULL, *pNodeB = NULL;
    int coefSum = 0;
    
    if (pListA != NULL & pListB != NULL) {
        pReturn = createLinkedList();
        if (pReturn == NULL) {
            printf("메모리 할당 오류, polySubtract()\n");
            return NULL;
        }
        pNodeA = pListA->headerNode.pLink;
        pNodeB = pListB->headerNode.pLink;
        
        while (pNodeA != NULL && pNodeB != NULL) {
            int degreeA = pNodeA->degree;
            int degreeB = pNodeB->degree;
            
            if (degreeA > degreeB) {
                coefSum = pNodeA->coef;
                addPolyNodeLast(pReturn, coefSum, degreeA);
                pNodeA = pNodeA->pLink;
            } else if (degreeB > degreeA) {
                coefSum = -(pNodeB->coef);
                addPolyNodeLast(pReturn, coefSum, degreeB);
                pNodeB = pNodeB->pLink;
            } else {
                coefSum = pNodeA->coef - pNodeB->coef;
                addPolyNodeLast(pReturn, coefSum, degreeA);
                pNodeA = pNodeA->pLink;
                pNodeB = pNodeB->pLink;
            }
        }
        while (pNodeA != NULL) {
            coefSum = pNodeA->coef;
            addPolyNodeLast(pReturn, coefSum, pNodeA->degree);
            pNodeA = pNodeA->pLink;
        }
        while (pNodeB != NULL) {
            coefSum = -(pNodeB->coef);
            addPolyNodeLast(pReturn, coefSum, pNodeB->degree);
            pNodeB = pNodeB->pLink;
        }
    } else {
        printf("오류, NULL 다항식이 연결되었습니다, polySubtract()\n");
    }
    
    return pReturn;
};
void displayPolyList(LinkedList* pList) {
    int i =0;
    if (pList != NULL) {
        for (i=0; i<pList->currentElementCount; i++) {
            ListNode* pNode = getLinkedListElement(pList, i);
            if (pNode != NULL) {
                if (pNode->coef > 0) {
                printf("+%dX^%d\t", pNode->coef, pNode->degree);
                } else if (pNode->coef < 0) {
                    printf("%dX^%d\t", pNode->coef, pNode->degree);
                }
                if (i == pList->currentElementCount-1) {
                    printf("\n");
                }
            }
        }
    }
};

