//
//  statichashing.h
//  10_4
//
//  Created by Wonkeun No on 2020-04-25.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef statichashing_h
#define statichashing_h

#include <stdio.h>
#define HASH_KEY_SIZE 30

typedef enum HashElementStatusType {
    EMPTY = 0, USED, DELETED
}HashElementStatus;

typedef struct HashElementType {
    char key[HASH_KEY_SIZE +1];
    int value;
    HashElementStatus status;
}HashElement;

typedef struct HashTableType {
    int bucketSize;
    int currentElementCount;
    HashElement* pElement;
}HashTable;

HashTable* createHashTable(int bucketSize);
int addElementStaticHashTable(HashTable* pHashTable, HashElement element);
int isEmptyOrDeleteBucket(HashElement* pElement);
HashElement* searchHashTable(HashTable* pHashTable, char* key);
int deleteElementHashTable(HashTable* pHashTable, char* key);

#define TRUE 1
#define FALSE 0

#endif /* statichashing_h */
