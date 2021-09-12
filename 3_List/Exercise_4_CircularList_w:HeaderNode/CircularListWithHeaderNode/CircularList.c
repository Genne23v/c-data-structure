//
//  CircularList.c
//  CircularListWithHeaderNode
//
//  Created by Wonkeun No on 2020-04-30.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularList.h"

int addCircularListElement(CircularList* pList, int position, CircularNode element) {
    int ret = FALSE;
    int i=0;
    CircularNode* pNewNode = NULL, *pPreNode = NULL, *pLastNode = NULL;
    
    if (pList != NULL) {
        if (position >= 0 && position <= pList->currentElementCount) {
            pNewNode = (CircularNode*)malloc(sizeof(CircularNode));
            if (pNewNode == NULL) {
                printf("메모리 할당 오류\n");
                return ret;
            }
            *pNewNode = element;
            pNewNode->pLink = NULL;
            
            if (position == 0) {
                if (pList->currentElementCount == 0) {
                    pList->headerNode.pLink = pNewNode;
                    pNewNode->pLink = pNewNode;
                } else {
                    pLastNode = pList->headerNode.pLink;
                    while (pLastNode->pLink != pList->headerNode.pLink) {
                        pLastNode = pLastNode->pLink;
                    }
                    pList->headerNode.pLink = pNewNode;
                    pNewNode->pLink = pLastNode->pLink;
                    pLastNode->pLink = pNewNode;
                }
            } else {
                //pList->headerNode.pLink = pPreNode;
                pPreNode = pList->headerNode.pLink;
            for (i=0; i<position -1; i++) {
                pPreNode = pPreNode->pLink;
            }
            pNewNode->pLink = pPreNode->pLink;
            pPreNode->pLink = pNewNode;
            }
            pList->currentElementCount++;
            ret = TRUE;
        } else {
            printf("인덱스 오류 - 현재 원소 개수 [%d]\n", pList->currentElementCount);
        }
    }
        
        return ret;
}
int removeCircularListElement(CircularList* pList, int position) {
    int ret = FALSE;
    int i =0, arrayCount =0;
    CircularNode *pPreNode = NULL, *pLastNode = NULL, *pDelNode = NULL;
    
    if (pList != NULL) {
        arrayCount = getCircularListLength(pList);
        if (position >= 0 && position < arrayCount) {
            if (position == 0) {
                pDelNode = pList->headerNode.pLink;
                if (arrayCount == 1) {
                    free(pDelNode);
                    pList->headerNode.pLink = NULL;
                } else {
                    pLastNode = pList->headerNode.pLink;
                    while (pLastNode->pLink != pList->headerNode.pLink) {
                        pLastNode = pLastNode->pLink;
                    }
                    pLastNode->pLink = pDelNode->pLink;
                    pList->headerNode.pLink = pDelNode->pLink;
                    free(pDelNode);
                }
            } else {
                pPreNode = pList->headerNode.pLink;
                for (i=0; i< position -1; i++) {
                    pPreNode = pPreNode->pLink;
                }
                pDelNode = pPreNode->pLink;
                pPreNode->pLink = pDelNode->pLink;
                free(pDelNode);
            }
            pList->currentElementCount--;
            ret = TRUE;
        } else {
            printf("인덱스 오류, 현재 원소 범위: [0 ~ %d]\n", pList->currentElementCount);
        }
    }
    return ret;
}
CircularNode* getCircularListElement(CircularList* pList, int position) {
    int i =0;
    CircularNode* pNode = NULL;
    if (pList != NULL) {
        pNode = pList->headerNode.pLink;
        for (i=0; i<position; i++) {
            pNode = pNode->pLink;
        }
    }
    return pNode;
}
CircularList* createCircularList() {
    CircularList* pReturn = NULL;
    pReturn = (CircularList*)malloc(sizeof(CircularList));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(pReturn));
    } else {
        printf("메모리 할당 오류 - createCircularList()\n");
        pReturn = NULL;
    }
    return pReturn;
}
void displayCircularList(CircularList* pList) {
    int i=0;
    CircularNode* pNode = NULL;
    if (pList != NULL) {
        printf("현재 원소 개수 - %d\n", pList->currentElementCount);
        pNode = pList->headerNode.pLink;
        for (i=0; i<pList->currentElementCount; i++) {
            printf("[%d] : %d\n", i, getCircularListElement(pList, i)->data);
        }
    } else {
        printf("오류, 원소가 없습니다\n");
    }
}
int getCircularListLength(CircularList* pList) {
    int ret = 0;
    if (pList != NULL) {
        ret = pList->currentElementCount;
    }
    return ret;
}
void deleteCircularList(CircularList* pList) {
    if (pList != NULL) {
        clearCircularList(pList);
        free(pList);
    }
}
void clearCircularList(CircularList* pList) {
    if (pList != NULL) {
        while (pList->currentElementCount >0) {
            removeCircularListElement(pList, 0);
        }
    }
}


