//
//  main.c
//  3_02
//
//  Created by Wonkeun No on 2020-03-26.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

LinkedList* createLinkedList() {
    LinkedList *pReturn = NULL;
    // int i=0;
    //메모리 할당 점검
    pReturn = (LinkedList*)malloc(sizeof(LinkedList));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(LinkedList));     //구조체 0으로 초기화
    } else {
        printf("오류, 메모리할당 createLinkedList()\n");
        return NULL;
    }
    return pReturn;
}
int addLinkedListElement(LinkedList* pList, int position, ListNode element) {
    int ret = FALSE;
    int i=0;
    ListNode* pPreNode = NULL;
    ListNode* pNewNode = NULL;
    // 연결리스트 NULL 여부, 추가하려는 위치의 인덱스 유효성 확인
    if (pList != NULL) {
        if (position >= 0 && position <= pList->currentElementCount) {
            //메모리 할당과 점검
            pNewNode = (ListNode*)malloc(sizeof(ListNode));
            if (pNewNode != NULL) {
                *pNewNode = element;            //필드가 추가되더라도 수정할 필요가 없도록 참조 연산자 사용
                pNewNode->pLink = NULL;         //노드값 설정과 링크 초기화
                //노드를 추가될 위치로 이동. 새로운 노드가 리스트에 추가될 적절한 위치를 찾는 부분
                pPreNode = &(pList->headerNode);        //헤더가 어떤 역할을 하는건지
                for(i=0; i<position; i++) {
                    pPreNode = pPreNode->pLink;         //어떻게 찾는거지? 
                }
                pNewNode->pLink = pPreNode->pLink;     //링크 연결? 어떻게 동작?
                pPreNode->pLink = pNewNode;         //추가된 노드와 기존 노드 사이의 링크 재설정
                
                pList->currentElementCount++;
                ret = TRUE;
            }else {
                printf("오류, 메모리할당 addLinkedListElement()\n");
                return ret;
            }
        }else {
            printf("오류, 위치 인덱스-[%d], addLinkedListElement()\n", position);
        }
    }
    return ret;
}
int removeLinkedListElement(LinkedList* pList, int position) {
    int ret = FALSE;
    int i =0;
    int arrayCount=0;
    ListNode* pNode = NULL;
    ListNode* pDelNode = NULL;
    // 입력 파라미터 유효성 점검
    if (pList != NULL) {
        arrayCount = getLinkedListLength(pList);
        if (position >=0 && position < arrayCount) {
            //제거될 노드 위치로 이동
            pNode = &(pList->headerNode);
            for(i=0; i<position; i++) {
                pNode = pNode->pLink;
            }
            //제거될 노드와 기존 노드 사이의 링크 재설정
            pDelNode = pNode->pLink;
            pNode->pLink = pDelNode->pLink;     
            free(pDelNode);
            
            pList->currentElementCount--;
            ret = TRUE;
        }else {
            printf("오류, 위치 인덱스-[%d] removeLinkedListElement()\n", position);
        }
    }
    return ret;
}
ListNode* getLinkedListElement(LinkedList* pList, int position) {
    ListNode* pReturn = NULL;
    int i=0;
    ListNode* pNode = NULL;
    if (pList != NULL) {
        if (position >=0 && position < pList->currentElementCount) {
            //해당 노드로 이동
            pNode = &(pList->headerNode);
            for(i=0; i<=position; i++) {
                pNode = pNode->pLink;
            }
            pReturn = pNode;
        }
    }
    return pReturn;
}
void deleteLinkedList(LinkedList* pList) {
    // int i=0;                               //왜 자꾸 선언하는겨
    if (pList != NULL) {
        clearLinkedList(pList);
        free(pList);
    }
}
void clearLinkedList(LinkedList* pList) {
    if (pList != NULL) {
        if (pList->currentElementCount >0) {
            removeLinkedListElement(pList, 0);
        }
    }
}
int getLinkedListLength(LinkedList* pList) {
    int ret=0;
    
    if (pList != NULL) {
        ret = pList->currentElementCount;
    }
    return ret;
}
int isEmpty(LinkedList* pList) {
    int ret = FALSE;
    
    if (pList != NULL) {
        if (pList->currentElementCount == 0) {
            ret = TRUE;
        }
    }
    return ret;
}
