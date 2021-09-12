//
//  main.c
//  9_01
//
//  Created by Wonkeun No on 2020-04-21.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void printArray(int value[], int count);

void selectionSort(int value[], int count) {
    int i=0, j=0;
    int min=0, temp=0;
    
    for (i=0; i<count-1; i++) {     //마지막 자료는 최대이기 때문에 count-1 만큼 수행
        min = i;
        for (j=i+1; j<count; j++) {
            if (value[j] < value[min]) {
                min = j;
            }
        }
        temp = value[i];
        value[i] = value[min];
        value[min] = temp;
        
        printf("Step - %d,", i+1);
        printArray(value, count);
    }
}
int main(int argc, const char * argv[]) {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    
    printf("Before Sort\n");
    printArray(values, 8);
    
    selectionSort(values, 8);
    
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
