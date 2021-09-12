//
//  statichashing.h
//  10_5
//
//  Created by Wonkeun No on 2020-04-25.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef statichashing_h
#define statichashing_h

#include <stdio.h>

typedef struct HashTableType {
    int bucketSize;
    int currentElementCount;
    struct LinkedListType **ppElement;
}HashTable;

HashTable* createHashTable(int bucketSize);
int addSearchHashTable(HashTable* pHashTable, HashElement element);
int deleteElementHashTable(HashTable* pHashTable, char* key);
int hashFunction(char *pKey, int bucketSize);
unsigned int stringToInt(char* pKey);
HashElement* searchHashTable(HashTable* pHashTable, char* key);
LinkedList* searchBucket(HashTable* pHashTable, char* key);
HashElement* searchSlot(LinkedList* pList, char* key, int* pPosition);
void deleteHashTable(HashTable* pHashTable);
void displayHashTable(HashTable* pHashTable);

#endif

#ifndef _COMMON_HASHING_DEF_
#define _COMMON_HASHING_DEF_

#define TRUE 1
#define FALSE 0

#endif /* statichashing_h */
