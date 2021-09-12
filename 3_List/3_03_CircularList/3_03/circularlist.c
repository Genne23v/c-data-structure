//
//  main.c
//  3_03
//
//  Created by Wonkeun No on 2020-03-27.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularlist.h"

int addCircularListElement (CircularList* pList, int position, CircularListNode element) {
    int ret = FALSE;
    int i =0;
    CircularListNode* pPreNode= NULL, *pNewNode= NULL, *pLastNode= NULL;
    //메모리 할당 및 점검
    if (pList != NULL) {
        if (position >= 0 && position <= pList->currentElementCount) {
            pNewNode = (CircularListNode*)malloc(sizeof(CircularListNode));
            if (pNewNode == NULL) {
                printf("오류, 메모리할당 addCircularListElement()\n");
                return ret;
            }
            *pNewNode = element;
            pNewNode->pLink = NULL;
            //공백 리스트에서 첫번째 노드를 추가하는 경우
            if (position == 0) {
                if (pList->currentElementCount == 0) {
                    pList->pLink = pNewNode;
                    pNewNode->pLink = pNewNode;     //원형 연결리스트의 특성으로 다시 자신을 가르키도록 한다
                } else {
                    pLastNode = pList->pLink;           //마지막 노드를 찾을때까지 이동. 첫번째 노드를 가르키는 곳을 LastNode로 지정하고 마지막을 찾을때까지 반복
                    
                    while(pLastNode->pLink != pList->pLink) {
                        pLastNode = pLastNode->pLink;
                    }
                    //공백리스트가 아닌 원형 연결 리스트에서 첫번째 노드를 추가하는 경우
                    pList->pLink = pNewNode;
                    pNewNode->pLink = pLastNode->pLink;
                    pLastNode->pLink = pNewNode;
                }
            } else {
                pPreNode = pList->pLink;        //첫번째 노드로 지정하고 찾을때까지 반복
                for (i=0; i<position-1; i++) {
                    pPreNode = pPreNode->pLink;
                }
                pNewNode->pLink = pPreNode->pLink;
                pPreNode->pLink = pNewNode;
            }
            pList->currentElementCount++;
            ret = TRUE;
        } else {
            printf("오류, 위치 인덱스-[%d] addCircularListElement()\n", position);
        }
    }
    return ret;
}
int removeCircularListElement(CircularList* pList, int position) {
    int ret= FALSE;
    int i= 0, arrayCount = 0;
    CircularListNode* pPreNode= NULL, *pDelNode= NULL, *pLastNode= NULL;
    
    if (pList != NULL) {
        arrayCount = getCircularListLength(pList);
        if (position >=0 && position < arrayCount) {
            //마지막 노드이면서 첫번째 노드를 삭제하는 경우
            if (position == 0) {
                pDelNode = pList->pLink;
                if (arrayCount == 1) {
                    free(pDelNode);
                    pList->pLink = NULL;
                } else {
                    pLastNode = pList->pLink;
                    //마지막 노드를 찾을때까지 이동
                    while(pLastNode->pLink != pList->pLink) {
                        pLastNode = pLastNode->pLink;
                    }
                    //마지막 노드가 아닌 첫번째 노드를 석제하는 경우
                    pLastNode->pLink = pDelNode->pLink;
                    pList->pLink = pDelNode->pLink;
                    free(pDelNode);
                }
            }else {
                pPreNode = pList->pLink;
                for (i=0; i<position-1; i++) {
                    pPreNode = pPreNode->pLink;
                }
                //리스트 중간 노드를 삭제하는 경우
                pDelNode = pPreNode->pLink;
                pPreNode->pLink = pDelNode->pLink;
                free(pDelNode);
            }
            pList->currentElementCount--;
            ret = TRUE;
        }else {
            printf("오류, 위치 인덱스-[%d] removeCircularListElement()\n", position);
        }
    }
    return ret;
}
CircularListNode* getCircularListElement(CircularList* pList, int position) {
    int i= 0;
    CircularListNode* pNode = NULL;
    if (pList != NULL) {
        if (position >= 0 && position < pList->currentElementCount) {
            pNode = pList->pLink;
            for (i=0; i<position; i++) {
                pNode = pNode->pLink;
            }
        }
    }
    return pNode;
}
CircularList* createCircularList() {        //괄호 안에 정수를 넣으면 갯수만큼 생성?
    CircularList *pReturn = NULL;
    //int i= 0; 왜넣냐 이거 
    
    pReturn = (CircularList*)malloc(sizeof(CircularList));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(CircularList));
    }else {
        printf("오류, 메모리 할당 createCircularList()\n");
        return NULL;
    }
    return pReturn;
}
void displayCircularList(CircularList* pList) {
    int i= 0;
    if (pList != NULL) {
        printf("현재 원소 개수: %d\n", pList->currentElementCount);
        for (i=0; i<pList->currentElementCount; i++) {
            printf("[%d], %d\n", i, getCircularListElement(pList, i)->data);
        }
    }else {
        printf("원소가 없습니다.\n");
    }
}
int getCircularListLength(CircularList* pList) {
    int ret= 0;
    if (pList != NULL) {
        ret = pList->currentElementCount;
    }
    return ret;
}
void deleteCircularList(CircularList* pList) {
    //int i= 0;     왜넣냐 이거
    if (pList != NULL) {
        clearCircularList(pList);
        free(pList);
    }
}
void clearCircularList(CircularList* pList) {
    if (pList != NULL) {
        while (pList->currentElementCount >0)removeCircularListElement(pList, 0);   //deleteCircularList는 pList 해제, clearCircularList는 모든 노드 삭제/해제
    }
}
