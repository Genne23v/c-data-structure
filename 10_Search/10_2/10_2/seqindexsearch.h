//
//  seqindexsearch.h
//  10_2
//
//  Created by Wonkeun No on 2020-04-23.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef seqindexsearch_h
#define seqindexsearch_h

#include <stdio.h>

typedef struct IndexTableType {
    int position;
    int key;
}IndexTable;

IndexTable* createIndexTable(int value[], int size, int indexSize);
int sequentialIndexSearch(int value[], int size, IndexTable index[], int indexSize, int key);
int sequentialRangeSearchAscendingSorted(int value[], int start, int end, int key);

#endif

#ifndef _COMMON_SEQ_INDEX_
#define _COMMON_SEQ_INDEX_

#define SUCCESS 1
#define FAIL -1

#endif /* seqindexsearch_h */
