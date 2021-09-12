//
//  main.c
//  9_04
//
//  Created by Wonkeun No on 2020-04-21.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void printArray(int value[], int count);

void insertionSort(int value[], int count) {
    int i=0, j=0;
    int temp = 0;
    
    for (i=1; i<count; i++) {
        temp = value[i];        //비교할 값을 임시로 복사
        j = i;
        while ((j>0) && value[j-1] > temp) {    //비교할 앞의 값이 크면 계속 value[j]에 값을 복사하고 앞으로 이동
            value[j] = value[j-1];
            j = j-1;
        }
        value[j] = temp;                    //비교할 앞의 값이 크지 않으면 이동한 배열에 비교값을 저장
        
        printf("Step - %d,", i);
        printArray(value, count);
    }
}
int main(int argc, const char * argv[]) {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    
    printf("Before Sort\n");
    printArray(values, 8);
    
    insertionSort(values, 8);
    
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
