//
//  main.c
//  3_01
//
//  Created by Wonkeun No on 2020-03-25.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"

ArrayList* createArrayList(int maxElementCount) {
    ArrayList *pReturn = NULL;
    //int i=0; (머냐 이건)
    //입력 파라미터 유효성 점검하고 메모리 할당
    if (maxElementCount > 0) {
        pReturn = (ArrayList *)malloc(sizeof(ArrayList));       //pReturn에 할당된 주소값 저장, 결국은 가르키는 포인터가 됨. ArrayList배열 형식의 element개수만큼 메모리할당
        //메모리 할당 점검
        if (pReturn != NULL) {
            pReturn-> maxElementCount = maxElementCount;
            pReturn-> currentElementCount = 0;
            pReturn-> pElement = NULL;                  //전체 배열 ArrayListNode의 주소값 초기화??
        }
        else {
            printf("오류, 메모리 할당 createArrayList()\n");
            return NULL;
        }
    }else {
        printf("오류, 최대 원소 개수는 0을 초과하여야 합니다\n");
        return NULL;
    }
    //원소를 저장하는 배열 메모리 할당 및 점검
    pReturn-> pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode)*maxElementCount);
    if (pReturn-> pElement == NULL) {
        printf("오류, 2번째 메모리할당 createArrayList()\n");
        free(pReturn);return NULL;      //메모리 할당에 실패했어도 메모리 해제
    }
    memset(pReturn-> pElement, 0, sizeof(ArrayListNode)*maxElementCount);
    
    return pReturn;
}
// 원소 추가 함수
int addAElement(ArrayList* pList, int position, ArrayListNode element) {
    int ret = FALSE;                //일반적으로 적용하는 코드인지?
    int i=0;
    //입력 파라미터에 대한 유효성 점검
    if (pList != NULL) {
        if (isArrayListFull(pList) != TRUE) {
            if (position >= 0 && position <= pList->currentElementCount) {
                for(i= pList->currentElementCount-1; i>= position; i--) {
                    pList->pElement[i+1] = pList->pElement[i];              //기존 원소들을 한칸씩 이동시키기. *(pElement+1)=*pElement 가능?
                }
                pList->pElement[position] = element;        //새로운 원소 추가 (값 대입)
                pList->currentElementCount++;
                ret = TRUE;
            }else {
                printf("오류, 위치 인덱스-[%d] 범위 초과, addAElement()\n", position);
            }
        }else {
            printf("오류, 리스트 용량 초과-[%d]/[%d]\n", position, pList->maxElementCount);
        }
    }
    return ret;
}
//원소 제거 함수
int removeAElement(ArrayList* pList, int position) {
    int ret = FALSE;
    int i=0;
    //입력 파라미터에 대한 유효성 점검(1. 메모리 NULL 여부, 2. 제거하려는 위치의 인덱스)
    if (pList != NULL) {
        if (position >= 0 && position < pList->currentElementCount) {       //기존 원소들을 왼쪽으로 한칸씩 이동
            for(i=position; i<pList->currentElementCount-1; i++) {
                pList->pElement[i] = pList->pElement[i+1];
            }
            pList->currentElementCount--;       //현재 배열의 원소 개수 1개 감소
            ret = TRUE;
        } else {
            printf("오류, 위치 인덱스-[%d] 범위초과, removeAElement()\n", position);
        }
    }
    return ret;
}
//배열리스트의 원소를 반환하는 함수
ArrayListNode* getAElement(ArrayList* pList, int position) {
    ArrayListNode* pReturn = NULL;
    if (pList != NULL) {
        if (position >= 0 && position < getArrayListLength(pList)) {
            pReturn = &(pList->pElement[position]);     //주소값이라 할지라도 의미는 포인터가 가르키는 곳이라 생각해야 한다
            //pReturn = pList->pElement + position;과 동일
        }else {
            printf("오류, 위치 인덱스-[%d] 범위 초과, getAElement()\n", position);
        }
    }
    return pReturn;
}
void displayArrayList(ArrayList* pList) {
    int i=0;
    if (pList != NULL) {
        printf("최대 원소 개수: %d\n", pList->maxElementCount);
        printf("현재 원소 개수: %d\n", pList->currentElementCount);
        //현재 저장된 원소의 값을 출력 (->data 이건 머??)
        for(i=0; i<pList->currentElementCount; i++) {
            printf("[%d], %d\n", i, getAElement(pList, i)->data);       //실제로 pReturn이 가르키는 곳의 data 값
        }
        i = pList->currentElementCount;
        for(; i<pList->maxElementCount; i++) {
            printf("[%d], Empty\n", i);
        }
    }else {
        printf("ArrayList is NULL");
    }
}
int isArrayListFull(ArrayList* pList) {
    int ret = FALSE;
    
    if (pList != NULL) {
        if (pList->currentElementCount == pList->maxElementCount) {
            ret = TRUE;
        }
    }
    return ret;
}
int getArrayListLength(ArrayList* pList) {
    int ret = 0;
    
    if (pList != NULL) {
        ret = pList->currentElementCount;
    }
    return ret;
}
void deleteArrayList(ArrayList* pList) {
    // int i=0;     다른 컴파일러로 사용하지 않는 변수가 있으면 컴파일 안하는가?
    if (pList != NULL) {
        free(pList->pElement);
        free(pList);        //pElement를 해제하고 pList 해제하면 메모리는 어떻게 되는가?
    }
}

int addAElementFirst(ArrayList* pList, ArrayListNode element) {
    int position = 0;
    return addAElement(pList, position, element);
}
int addAElementLast(ArrayList* pList, ArrayListNode element) {
    int ret = FALSE;
    int position = 0;
    if (pList != NULL) {
        position = getArrayListLength(pList);
        ret = addAElement(pList, position, element);
    }
    return ret;
}
