//
//  main.c
//  9_06
//
//  Created by Wonkeun No on 2020-04-22.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void printArray(int value[], int count);
void mergeSortInternal(int value[], int buffer[], int start, int middle, int end);

void mergeSort(int value[], int buffer[], int start, int end) {
    int middle = 0;
    if (start < end) {          //원소가 1개가 될때까지 순환적으로 병합정렬
        middle = (start + end) / 2;     //2개의 부분집합으로 나누기 위해 중값을 구한다
        mergeSort(value, buffer, start, middle);
        mergeSort(value, buffer, middle+1, end);
        
        mergeSortInternal(value, buffer, start, middle, end);       //병합정렬이 완료된 2개의 부분 집합에 대해 병합
    }
}
void mergeSortInternal(int value[], int buffer[], int start, int middle, int end) {
    int i=0, j=0, k=0, t=0;
    i = start;      //첫번째 부분 집합의 원소를 가리키는 인덱스
    j = middle +1;  //두번째 부분 집합의 원소를 가리키는 인덱스
    k = start;      //결과 버퍼의 현재 위치를 가리키는 인덱스
    
    while (i <= middle && j <= end) {
        if (value[i] <= value[j]) {
            buffer[k] = value[i];
            i++;
        }else {
            buffer[k] = value[j];
            j++;
        }
        k++;
    }
    if (i > middle) {       //어느 부분집합의 원소가 남았는지 확인
        for (t = j; t <= end; t++, k++) {
            buffer[k] = value[t];
        }
    }else {
        for (t = i; t <= middle; t++, k++) {
            buffer[k] = value[t];
        }
    }
    for (t = start; t <= end; t++) {
        value[t] = buffer[t];           //정렬 결과가 저장된 버퍼의 내용을 최종적으로 복사
        printf("Start - %d, middle - %d, end - %d, ", start, middle, end);
        for (t = start; t <= end; t++) {
            printf("%d  ", value[t]);
        }
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    
    printf("Before Sort\n");
    printArray(values, 8);
    
    int *pBuffer = NULL;
    pBuffer = (int*)malloc(sizeof(int)*8);
    
    if (pBuffer != NULL) {
        mergeSort(values, pBuffer, 0, 7);
        free(pBuffer);
    }
    
    printf("\nAfter Sort\n");
    printArray(values, 8);
    
    return 0;
}
void printArray(int value[], int count) {
    int i=0;
    for (i=0; i<count; i++) {
        printf("%d  ", value[i]);
    }
    printf("\n");
}
