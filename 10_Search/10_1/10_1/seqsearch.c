//
//  seqsearch.c
//  10_1
//
//  Created by Wonkeun No on 2020-04-23.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include "seqsearch.h"

int sequentialSearchNotSorted(int value[], int size, int key) {
    int ret = FAIL;
    int i=0;
    
    for (i=0; i<size && value[i] != key; i++) {
        //do nothing
    }
    if (i < size) {
        ret = i;
    }
    return ret;
}
int sequentialSearchAscendingSorted(int value[], int size, int key) {
    int ret = FAIL;
    int i=0;
    
    for (i=0; i<size && value[i] < key; i++) {
        //do nothing
    }
    if (i < size && value[i] == key) {
        ret = i;
    }
    return ret;
}
