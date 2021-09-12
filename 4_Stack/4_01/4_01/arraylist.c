//
//  main.c
//  4_01
//
//  Created by Wonkeun No on 2020-03-31.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arryalist.h"

ArrayStack* createArrayStack(int size) {
    ArrayStack *pReturn = NULL;
    int i= 0;
    
    if (size > 0) {
        pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
        if (pReturn != NULL) {
            memset(pReturn, 0, sizeof(ArrayStack));
            pReturn->maxElementCount = size;
        } else {
            printf("오류, 메모리 할당, createArrayStack()\n");
            return NULL;
        }
        pReturn->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode)*size);
        
        if (pReturn->pElement != NULL) {
            memset(pReturn->pElement, 0, sizeof(ArrayStackNode)*size);
        } else {
            printf("오류, 메모리 할당2, createArrayStack()\n");
            free(pReturn); return NULL;
        }
    } else {
        printf("오류, 스택의 크기는 0이상이어야 합니다\n");
        return NULL;
    }
    return pReturn;
}
int pushArrayStack(ArrayStack* pStack, ArrayStackNode element) {
    int ret= FALSE, i=0;
    
    if (pStack != NULL) {
        if (isArrayStackFull(pStack) == FALSE) {
            pStack->pElement[pStack->currentElementCount] = element;    //currentElementCount? 여기다 하는게 맞음?
            pStack->currentElementCount++;
            ret= TRUE;
        }else {
            printf("오류, 스택이 가득 찼습니다, pushArrayStack()\n");
        }
    }
    return ret;
}
ArrayStackNode* popArrayStack(ArrayStack* pStack) {
    ArrayStackNode* pReturn = NULL;
    if (pStack != NULL) {
        if (isArrayStackEmpty(pStack) == FALSE) {
            pReturn = (ArrayStackNode *)malloc(sizeof(ArrayStackNode));
            if (pReturn != NULL) {
                *pReturn = pStack->pElement[pStack->currentElementCount-1];
                pStack->currentElementCount--;
            } else {
                printf("오류, 메모리할당, popArrayStack()\n");
            }
        }
    }
    return pReturn;
}
ArrayStackNode* peekArrayStack(ArrayStack* pStack) {
    ArrayStackNode* pReturn = NULL;
    if (pStack != NULL) {
        if (isArrayStackEmpty(pStack) == FALSE) {
            pReturn = &(pStack->pElement[pStack->currentElementCount-1]);
        }
    }
    return pReturn;
}
void deleteArrayStack(ArrayStack* pStack) {
    if (pStack != NULL) {
        if (pStack->pElement != NULL) {
            free(pStack->pElement);
        }
        free(pStack);
    }
}
int isArrayStackFull(ArrayStack* pStack) {
    int ret = FALSE;
    
    if (pStack != NULL) {
        if (pStack->currentElementCount == pStack->maxElementCount) {
            ret = TRUE;
        }
    }
    return ret;
}
int isArrayStackEmpty(ArrayStack* pStack) {
    int ret= FALSE;
    
    if (pStack != NULL) {
        if (pStack->currentElementCount == 0) {
            ret = TRUE;
        }
    }
    return ret;
}
