//
//  main.c
//  3_04
//
//  Created by Wonkeun No on 2020-03-28.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylist.h"

DoublyList* createDoublyList() {
    DoublyList* pReturn = NULL;
    //int i= 0;     ???
    pReturn = (DoublyList*)malloc(sizeof(DoublyList));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(DoublyList));
        
        pReturn->headerNode.pLLink = &(pReturn->headerNode);
        pReturn->headerNode.pRLink = &(pReturn->headerNode);    //이중 연결리스트의 원형을 유지하기 위해 자신을 가르키게 초기화
} else {
    printf("오류, 메모리할당 createDoublyList()\n");
    return NULL;
}
return pReturn;
}
int addDoublyListElement(DoublyList* pList, int position, DoublyListNode element) {
    int ret= FALSE, i= 0;
    DoublyListNode* pPreNode= NULL, *pNewNode= NULL; //*pTempNode= NULL;        pTempNode 어디 씀?
    if (pList != NULL) {
        if (position >=0 && position <=pList->currentElementCount) {
            pNewNode= (DoublyListNode*)malloc(sizeof(DoublyListNode));
            if (pNewNode == NULL) {
                printf("오류, 메모리할당 addDoublyListElement()\n");
                return ret;
            }
            *pNewNode = element;
            pNewNode->pLLink = NULL;
            pNewNode->pRLink = NULL;
            
            pPreNode = &(pList->headerNode);            //위치 인덱스가 노드에 접근하기 위해 헤더노드부터 다음 노드로 이동
            for(i=0; i<position; i++) {
                pPreNode = pPreNode->pRLink;
            }
            pNewNode->pLLink = pPreNode;
            pNewNode->pRLink = pPreNode->pRLink;
            pPreNode->pRLink = pNewNode;
            pNewNode->pRLink->pLLink = pNewNode;           //왜 이렇게 되는거임???
            
            pList->currentElementCount++;
            ret = TRUE;
        } else {
            printf("오류, 위치 인덱스-[%d] addDoublyListElement\n", position);
        }
    }
    return ret;
}
int removeDoublyListElement(DoublyList* pList, int position) {
    int ret= FALSE;
    int i= 0, arrayCount= 0;
    DoublyListNode* pPreNode= NULL, *pDelNode= NULL; //*pTempNode= NULL;      //pTempNode는 어디다 씀?
    
    if (pList != NULL) {
        arrayCount = getDoublyListLength(pList);
        if (position >=0 && position < arrayCount) {
            pPreNode = &(pList->headerNode);
            for (i=0; i<position; i++) {
             pPreNode = pPreNode->pRLink;
            }
                
                pPreNode->pRLink = pDelNode->pRLink;        
                pDelNode->pRLink->pLLink = pPreNode;        //삭제할 노드 오른쪽이 가르키는 왼쪽이 PreNode가 되니까
                free(pDelNode);
                
                pList->currentElementCount--;
                ret = TRUE;
            } else {
            printf("오류, 위치 인덱스-[%d] removeDoublyListElement()\n", position);
        }
    }
    return ret;
}
DoublyListNode* getDoublyListElement(DoublyList* pList, int position) {
    DoublyListNode* pReturn = NULL;
    int i= 0;
    DoublyListNode* pNode = NULL;
    if (pList != NULL) {
        if (position >=0 && position < pList->currentElementCount) {
            pNode = pList->headerNode.pRLink;
            for (i=0; i<position; i++) {
                pNode = pNode->pRLink;
            }
        } pReturn = pNode;
    } else {
        printf("오류, 위치 인덱스-[%d] getDoublyListElement()\n", position);
    }
return pReturn;
}
void displayDoublyList(DoublyList* pList) {
    //int i= 0;     왜 자꾸 선언??
    if (pList != NULL) {
        printf("현재 노드 개수: %d\n", pList->currentElementCount);
} else {
    printf("원소가 없습니다.\n");
}
}
void deleteDoublyList(DoublyList* pList) {
    if (pList != NULL) {
        clearDoublyList(pList);
        free(pList);
    }
}
void clearDoublyList(DoublyList* pList) {
    if (pList != NULL) {
        while (pList->currentElementCount >0) {
            removeDoublyListElement(pList, 0);
        }
    }
}
int getDoublyListLength(DoublyList* pList) {
    int ret= 0;
    if (pList != NULL) {
        ret = pList->currentElementCount;
    }
    return ret;
}
