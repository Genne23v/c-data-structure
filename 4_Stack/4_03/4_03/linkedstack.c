//
//  main.c
//  4_02
//
//  Created by Wonkeun No on 2020-03-31.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

LinkedStack* createLinkedStack() {
    LinkedStack *pReturn = NULL;
int i= 0;
pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));
if (pReturn != NULL) {
    memset(pReturn, 0, sizeof(LinkedStack));
}else {
    printf("오류, 메모리 할당, createLinkedStack()\n");
    return NULL;
}
    return pReturn;
}
int pushLinkedStack(LinkedStack* pStack, DoublyStackNode element) {
    int ret = FALSE;
    DoublyStackNode *pNode = NULL;
    
    if(pStack != NULL) {
        pNode = (DoublyStackNode*)malloc(sizeof(DoublyStackNode));
        
        if (pNode != NULL) {
            memset(pNode, 0, sizeof(DoublyStackNode));
            *pNode = element;
            pNode->pRLink = pStack->headerNode.pRLink;         //기존 탑노드를 새로 추가된 노드의 다음 노드로 링크 설정
            pNode->pLLink = &(pStack->headerNode);
            pStack->headerNode.pRLink = pNode;                //새로운 탑 노드로 링크 변경
            
            pStack->currentElementCount++;
            ret = TRUE;
        }else {
            printf("오류, 메모리할당, pushLinkedStack()\n");
        }
    }
    return ret;
}
DoublyStackNode* popLinkedStack(LinkedStack* pStack) {
    DoublyStackNode* pReturn = NULL;
    if (pStack != NULL) {
        if (isLinkedStackEmpty(pStack) == FALSE) {
            pReturn = pStack->headerNode.pRLink;
            pStack->headerNode.pRLink = pReturn->pRLink;           //탑노드 변경, 반환되는 노도의 다음 노드가 새로운 탑 노드가 됨
            pReturn->pRLink->pLLink = &(pStack->headerNode);
            
            pReturn->pRLink = NULL;                      //반환 노드의 다음 노드로 NULL 설정
            pReturn->pLLink = NULL;
            pStack->currentElementCount--;              //메모리 해제 없음?
        }
    }
    return pReturn;
}
DoublyStackNode* peekLinkedStack(LinkedStack* pStack) {
    DoublyStackNode* pReturn = NULL;
    if (pStack != NULL) {
        if (isLinkedStackEmpty(pStack) == FALSE) {
            pReturn = pStack->headerNode.pRLink;
        }
    }
    return pReturn;
}
void deleteLinkedStack(LinkedStack* pStack) {
    DoublyStackNode *pNode = NULL;
    DoublyStackNode * pDelNode = NULL;
    
    if (pStack != NULL) {
        pNode = pStack->headerNode.pRLink;
        pNode = pStack->headerNode.pLLink;
        while (pNode != NULL) {
            pDelNode = pNode;
            pNode = pNode->pRLink;           //루프를 돌면서 모든 노드의 메모리를 해제
            
            free(pDelNode);                 //메모리 해제하면 자동으로 링크 해제??
        }
        free(pStack);
    }
}
int isLinkedStackFull(LinkedStack* pStack) {
    int ret = FALSE;
    return ret;
}
int isLinkedStackEmpty(LinkedStack* pStack) {
    int ret = FALSE;
    
    if (pStack != NULL) {
        if (pStack->currentElementCount == 0) {
            ret = TRUE;
        }
    }
    return ret;
}
