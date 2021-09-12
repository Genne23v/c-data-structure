//
//  main.c
//  3_06
//
//  Created by Wonkeun No on 2020-03-29.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "polylist.h"

int addPolyNodeLast(LinkedList* pList, float coef, int degree) {
    int ret= FALSE, i= 0;
    
    ListNode node = {0,};
    node.coef = coef;
    node.degree = degree;
    
    if (pList != NULL) {
        int length = getLinkedListLength(pList);
        ret = addLinkedListElement(pList, length, node);
    }
    return ret;
}
LinkedList* polyAdd(LinkedList* pListA, LinkedList* pListB) {
    LinkedList* pReturn = NULL;
    ListNode *pNodeA= NULL, *pNodeB= NULL;
    float coefSum = 0;

    if (pListA != NULL && pListB != NULL) {
        pReturn = createLinkedList();
        if (pReturn == NULL) {
            printf("메모리 할당 오류, polyAdd()\n");
            return NULL;
        }
        pNodeA = pListA->headerNode.pLink;
        pNodeB = pListB->headerNode.pLink;
        //다항식 A 또는 B의 마지막 노드까지 이동하고 루프를 빠져나옴
        while (pNodeA != NULL && pNodeB != NULL) {
            int degreeA = pNodeA->degree;
            int degreeB = pNodeB->degree;

            if (degreeA > degreeB) {
                coefSum = pNodeA->coef;
                addPolyNodeLast(pReturn, coefSum, degreeA);
                pNodeA = pNodeA->pLink;         //A의 차수가 B보다 높으면 결과 다항식에 A의 항을 추가. 다음항으로 이동
            } else if (degreeA == degreeB){
                coefSum = pNodeA->coef + pNodeB->coef;
                addPolyNodeLast(pReturn, coefSum, degreeA);
                pNodeA = pNodeA->pLink;
                pNodeB = pNodeB->pLink;         //차수가 서로 같으면 계수를 더하여 결과 다항식에 항 추가. 모두 다음항으로 이동
            } else {
                coefSum = pNodeB->coef;
                addPolyNodeLast(pReturn, coefSum, degreeB);
                pNodeB = pNodeB->pLink;         //B의 차수가 높으면 다항식 B의 항을 결과 다항식에 추가. B의 다음항으로 이동
            }
        }
        while (pNodeA != NULL) {
            coefSum = pNodeA->coef;
            addPolyNodeLast(pReturn, coefSum, pNodeA->degree);
            pNodeA = pNodeA->pLink;             //다항식 A에 남은 항이 있으면 남은 항을 결과 다항식에 추가
        }
        while (pNodeB != NULL) {
            coefSum = pNodeB->coef;
            addPolyNodeLast(pReturn, coefSum, pNodeB->degree);
            pNodeB = pNodeB->pLink;             //다항식 B에 남은 항이 있으면 남은 항을 결과 다항식에 추가
        }
    }else {
        printf("오류, NULL 다항식이 전달 되었습니다, polyAdd()\n");
    }
    return pReturn;
}
void displayPolyList(LinkedList* pList) {
    int i= 0;
    if (pList != NULL) {
        for (i=0; i<pList->currentElementCount; i++) {
            ListNode* pNode = getLinkedListElement(pList, i);
            if (pNode != NULL) {
                printf("%4.1fX^%d", pNode->coef, pNode->degree);
                
                if (i == pList->currentElementCount -1) {
                    printf("\n");
                } else {
                    printf(" + ");
                }
            }
        }
    } else {
            printf("빈 다항식입니다");
    }
}
