//
//  statichashing.c
//  10_4
//
//  Created by Wonkeun No on 2020-04-25.
//  Copyright © 2020 genne. All rights reserved.
//

#include "statichashing.h"

HashTable* createHashTable(int bucketSize) {
    HashTable* pReturn = NULL;
    int i=0;
    if (bucketSize <= 0) {
        printf("버킷 크기는 0보다 커야합니다\n");
        return NULL;
    }
    pReturn = (HashTable*)malloc(sizeof(HashTable));
    if (pReturn != NULL) {
        pReturn->currentElementCount = 0;
        pReturn->bucketSize = bucketSize;
        pReturn->pElement = NULL;
    } else {
        printf("오류, 첫번째 메모리할당, createHashTable()\n");
        return NULL;
    }
    pReturn->pElement = (HashElement*)malloc(sizeof(HashElement)*bucketSize);
    if (pReturn->pElement != NULL) {
        memset(pReturn->pElement, 0, sizeof(HashElement)*bucketSize);
    } else {
        if (pReturn != NULL) free(pReturn);
        printf("오류, 두번째 메모리할당, createHashTable()\n");
        return NULL;
    }
    return pReturn;
}
int addElementStaticHashTable(HashTable* pHashTable, HashElement element) {
    int ret = FALSE;
    HashElement* pElement = NULL;
    int bucketIndex = 0;
    int tempIndex = 0;
    int inc = 1;
    if (pHashTable == NULL) {
        printf("오류, NULL-해시 테이블입니다\n");
        ret = FALSE;
        return ret;
    }
    bucketIndex = hashFunction(element.key, pHashTable->bucketSize);
    if (bucketIndex < 0 || bucketIndex >= pHashTable->bucketSize) {
        printf("오류, 잘못된 해쉬 테이블 주소가 계산되었습니다, addElementStaticHashTable()\n");
        ret = FALSE;
        return ret;
    }
    tempIndex = bucketIndex;
    do {
        pElement = &(pHashTable->pElement[tempIndex]);
        if (isEmptyOrDeleteBucket(pElement) == TRUE) {
            pHashTable->pElement[tempIndex] = element;
            pHashTable->pElement[tempIndex].status = USED;
            ret = TRUE;
            break;
        } else {
            if (strcmp(pElement->key, element.key) == 0) {
                printf("오류, 중복된 키 - [%d], addStaticHashTable()\n", element.key);
                ret = FALSE;
                break;
            } else {
                tempIndex = (tempIndex + inc) % pHashTable->bucketSize;
                
                if (tempIndex == bucketIndex) {         //버킸이 서로 같다면 버킸이 가득 찬 경우
                    printf("오류, 해시 테이블이 가득찼습니다, addStaticHashTable()\n");
                    ret = FALSE;
                    break;
                }
            }
        }
    }
    while (tempIndex != bucketIndex);
    return ret;
}
int hashFunction(char *pKey, int bucketSize) {
    int ret = -1;
    unsigned int temp_key = 0;
    
    if (pKey == NULL) {
        return ret;
    }
    temp_key = stringToInt(pKey);
    if (bucketSize > 0) {
        ret = temp_key % bucketSize;
    }
    return ret;
}
unsigned int stringToInt(char *pKey) {
    unsigned int ret = 0;
    while (*pKey != '\0') {
        ret = (ret *31) + (*pKey);
        *pKey++;
    }
    return ret;
}
int isEmptyOrDeleteBucket(HashElement* pElement) {
    int ret = FALSE;
    
    if (pElement != NULL) {
        if (pElement->status == EMPTY || pElement->status == DELETED) {
            ret = TRUE;
        }
    }
    return ret;
}
HashElement* searchHashTable(HashTable* pHashTable, char* key) {
    HashElement* pReturn = NULL;
    HashElement* pElement = NULL;
    int bucketIndex = 0;
    int tempIndex = 0;
    int inc = 1;
    if (pHashTable == NULL) {
        printf("오류, NULL-해시 테이블입니다\n");
        pReturn = NULL;
        return pReturn;
    }
    bucketIndex = hashFunction(key, pHashTable->bucketSize);
    if (bucketIndex < 0) {
        printf("오류, 잘못된 해시 테이블 주소가 계산되었습니다, addStaticHashTable()\n");
        pReturn = NULL;
        return pReturn;
    }
    tempIndex = bucketIndex;
    do {
        pElement = &(pHashTable->pElement[tempIndex]);
        if (isEmptyOrDeleteBucket(pElement) == TRUE) {
            printf("검색 실패, 검색키 - [%d]는 존재하지 않습니다, searchHashTable()\n", key);
            pReturn = NULL;
            break;
        } else {
            if (pElement->status == USED && strcmp(pElement->key, key) == 0) {
                pReturn = pElement;
                break;
            } else {
                tempIndex = (tempIndex + 1) % pHashTable->bucketSize;
                if (tempIndex == bucketIndex) {
                    printf("검색 실패, 검색키 - [%d]는 존재하지 않습니다, searchHashTable()\n", key);
                    pReturn = NULL;
                    break;
                }
            }
        }
    }
    while (tempIndex != bucketIndex);
    return pReturn;
}
int isEmptyBucket(HashElement* pElement) {
    int ret = FALSE;
    if (pElement != NULL) {
        if (pElement->status == EMPTY) {
            ret = TRUE;
        }
    }
    return ret;
}
int deleteElementHashTable(HashTable* pHashTable, char* key) {
    int ret = FALSE;
    HashElement* pElement = NULL;
    int bucketIndex = 0;
    int tempIndex = 0;
    int inc = 1;
    
    if (pHashTable != NULL) {
        pElement = searchHashTable(pHashTable, key);
        if (pElement != NULL) {
            pElement->status = DELETED;
            pElement->key[0] = '\0';
            pElement->value = 0;
            ret = TRUE;
        } else {
            printf("삭제 실패, 검색키 - [%s]는 존재하지 않습니다, deleteElementHashTable()\n", key);
        }
    }
    return ret;
}
