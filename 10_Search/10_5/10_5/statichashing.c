//
//  statichashing.c
//  10_5
//
//  Created by Wonkeun No on 2020-04-25.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statichashing.h"
#include "hashingdef.h"
#include "hashinglinkedlist.h"

HashTable* createHashTable(int bucketSize) {
    HashTable* pReturn = NULL;
    int i=0, j=0;
    
    if (bucketSize <= 0) {
        printf("버킷 크기는 0보다 커야 합니다\n");
        return NULL;
    }
    pReturn = (HashTable*)malloc(sizeof(HashTable));
    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(HashTable));
        pReturn->bucketSize = bucketSize;
    } else {
        printf("오류, 첫번째 malloc(), createHashTable()\n");
        return NULL;
    }
    pReturn->ppElement = (LinkedList**)malloc(sizeof(LinkedList*)*bucketSize);
    
    if (pReturn->ppElement != NULL) {
        memset(pReturn->ppElement, 0, sizeof(LinkedList*)*bucketSize);
        for (i=0; i<bucketSize; i++) {
            pReturn->ppElement[i] = createLinkedList();
            //중략??
        }
    } else {
        if (pReturn != NULL) free(pReturn);
        printf("오류, 두번째 malloc(), createHashTable()\n");
        return NULL;
    }
    return pReturn;
}
int addStaticHashTable(HashTable* pHashTable, HashElement element) {
    int ret = FALSE;
    LinkedList* pList = NULL;
    if (pHashTable != NULL) {
        pList = searchBucket(pHashTable, element.key);
        if (pList != NULL) {
            addLinkedListElementLast(pList, element);
            pHashTable->currentElementCount++;
            ret = TRUE;
        } else {
            printf("오류, 잘못된 해시 테이블 주소가 계산되었습니다, addHashTable()\n");
        }
    }
    return ret;
}
LinkedList* searchBucket(HashTable* pHashTable, char* key) {
    LinkedList* pReturn = NULL;
    int bucketIndex = 0;
    
    if (pHashTable != NULL) {
        bucketIndex = hashFunction(key, pHashTable->bucketSize);
        if (bucketIndex >= 0) {
            pReturn = pHashTable->ppElement[bucketIndex];
        } else {
            printf("오류, 잘못된 해시 테이블 주소가 계산되었습니다, searchHashTable()\n");
        }
    }
    return pReturn;
}
HashElement* searchHashTable(HashTable* pHashTable, char* key) {
    HashElement* pReturn = NULL;
    LinkedList* pList = NULL;
    int position = 0;
    
    pList = searchBucket(pHashTable, key);
    if (pList != NULL) {
        pReturn = searchSlot(pList, key, &position);
    }
    return pReturn;
}
HashElement* searchSlot(LinkedList* pList, char* key, int* pPosition) {
    HashElement* pReturn = NULL;
    HashElement* pElement = NULL;
    ListNode* pNode = NULL;
    int position = 0;
    if (pList != NULL && pPosition != NULL) {
        pNode = getLinkedListElement(pList, 0);
        while (pNode != NULL) {
            if (strcmp(pNode->data.key, key) == 0) {
                pReturn = &(pNode->data);
                *pPosition = position;
                break;
            }
            pNode = pNode->pLink;
            position++;
        }
        if (pReturn == NULL) {
            printf("검색 실패, 검색키 - [%s]는 존재하지 않습니다, searchHashTable()\n", key);
        }
    }
    return pReturn;
}
int deleteElementHashTable(HashTable* pHashTable, char* key) {
    int ret = FALSE;
    HashElement* pElement = NULL;
    LinkedList* pList = NULL;
    int position = 0;
    pList = searchBucket(pHashTable, key);
    if (pList != NULL) {
        pElement = searchSlot(pList, key, &position);
        if (pElement != NULL) {
            removeLinkedListElement(pList, position);
            pHashTable->currentElementCount--;
            ret = TRUE;
        }
    }
    return ret;
}
void deleteHashTable(HashTable* pHashTable) {
    
}

void displayHashTable(HashTable* pHashTable) {
    
}
