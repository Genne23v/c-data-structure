//
//  main.c
//  3_05
//
//  Created by Wonkeun No on 2020-03-29.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "linkedlistop.h"

void iterateLinkedList(LinkedList* pList) {
    ListNode* pNode = NULL;
    int count= 0;
    if (pList != NULL) {
        //헤더 노드를 시작으로 모든 노드를 순회
        pNode = pList->headerNode.pLink;
        while (pNode != NULL) {
            printf("[%d], %d\n", count, pNode->data);
            count++;
            
            pNode = pNode->pLink;       //다음 노드 이동시에 링크 정보 이용
        }
        printf("노드 개수: %d\n", count);
    } else {
        printf("공백리스트입니다");
    }
}
void concatLinkedList(LinkedList* pListA, LinkedList* pListB) {
    ListNode* pNodeA= NULL, *pNodeB= NULL;      //pNodeB는 왜 선언?
    
    if (pListA != NULL && pListB != NULL) {
        pNodeA = pListA->headerNode.pLink;
        while (pNodeA->pLink != NULL) {
            pNodeA= pNodeA->pLink;          //연결리스트A의 마지막 노드 찾기
        }
        pNodeA->pLink = pListB->headerNode.pLink;       //연결리시트A의 마지막 노드를 연결리스트B의 첫번째 노드로 연결
        pListA->currentElementCount += pListB->currentElementCount; //노드 개수 증가
        
        pListB->headerNode.pLink = NULL;        //연결리스트B의 첫번째 노드 끊기
        pListB->currentElementCount = 0;        //노드 개수 0으로 재설정
    }
}
void reverseLinkedList(LinkedList* pList) {
    ListNode* pNode = NULL, *pCurrentNode = NULL, *pPrevNode = NULL;
    
    if (pList != NULL) {
        pNode = pList->headerNode.pLink;        //시작 노드 설정
        //노드 순서 바꾸기
        while (pNode != NULL)  {
            pPrevNode = pCurrentNode;       //PreNode가 CurrentNode를 가리킨다 (처음에는 둘다 없는 포인터)
            pCurrentNode = pNode;
            pNode = pNode->pLink;           //pNode가 다음노드를 가리키게 한다
            pCurrentNode->pLink = pPrevNode;    //currentNode가 preNode를 가리키게 한다. 첫 루프에선 preNode가 없으므로 NULL
        }
        pList->headerNode.pLink = pCurrentNode;
    }
}
