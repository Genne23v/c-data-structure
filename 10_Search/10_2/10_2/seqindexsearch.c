//
//  seqindexsearch.c
//  10_2
//
//  Created by Wonkeun No on 2020-04-23.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "seqindexsearch.h"

int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key) {
    int ret = FAIL;
    int i=0;
    int start = 0, end = 0;
    
    if (key >= value[0] && key <= value[size-1]) {
        for (i=0; i<indexSize; i++) {
            if (index[i].key > key) {
                break;
            }
        }
        if (i >= indexSize) {
            start = index[i-1].position;        //마지막 인덱스 값부터 배열의 끝까지
            end = size -1;
        } else {
            start = index[i-1].position;
            end = index[i].position -1;
        }
        ret = sequentialRangeSearchAscendingSorted(value, start, end, key);
    }
    return ret;
}
int sequentialRangeSearchAscendingSorted(int value[], int start, int end, int key) {
    int ret = -1;
    int i=0;
    for (i=start; i <= end && value[i] < key; i++) {
        //do nothing
    }
    if (i <= end && value[i] == key) {
        ret = i;
    }
    return ret;
}
IndexTable* createIndexTable(int value[], int size, int indexSize) {
    IndexTable* pReturn = NULL;
    int i=0;
    int ratio = 0;
    
    if (size <= 0 || indexSize <= 0) {
        printf("인덱스 크기 및 배열의 크기는 0보다 커야합니다\n");
        return NULL;
    }
    ratio = size / indexSize;
    if (size % indexSize > 0) {
        ratio = ratio + 1;          //나머지를 위해 추가 인덱스 생성
    }
    pReturn = (IndexTable*)malloc(sizeof(IndexTable*)*indexSize);
    if (pReturn == NULL) {
        printf("오류, 메모리할당 in creteaIndexTable()\n");
        return NULL;
    }
    for (i=0; i < indexSize; i++) {
        pReturn[i].position = i * ratio;
        pReturn[i].key = value[i * ratio];      //인덱스 생성하고 각 시작 인덱스에 포지션과 키값을 기록
    }
    return pReturn;
}
