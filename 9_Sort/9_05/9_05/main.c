//
//  main.c
//  9_05
//
//  Created by Wonkeun No on 2020-04-21.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void shellInsertionSort(int value[], int start, int end, int interval);
void printArray(int value[], int count);

void shellSort(int value[], int count) {
    int i=0, interval = 0;
    interval = count/2;
    
    while (interval >=1) {      //interval을 반씩 계속 줄임
        for (i=0; i<interval; i++) {
            shellInsertionSort(value, i, count-1, interval);
        }
        printf("Interval - %d,", interval);
        printArray(value, count);
        
        interval = interval/2;
    }
}
void shellInsertionSort(int value[], int start, int end, int interval) {
    int i=0;
    int item = 0, index = 0;
    
    for (i=start + interval; i<=end; i= i+interval) {
        item = value[i];
        index = i - interval;
        while ((index >= start) && item < value[index]) {
            value[index + interval] = value[index];
            index = index - interval;
        }
        value[index + interval] = item;
    }
}
int main(int argc, const char * argv[]) {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    
    printf("Before Sort\n");
    printArray(values, 8);
    
    shellSort(values, 8);
    
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
