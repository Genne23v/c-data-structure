#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularlist.h"

typedef struct LinkedListNodeType {
    int data;
    struct LinkedListNodeType *pLink;
} LinkedListNode;

typedef struct LinkedListType {
    int             currentCount;
    LinkedListNode  headerNode;
} LinkedList;

LinkedList *createLinkedList() {
    LinkedList *pReturn = (LinkedList *)malloc(sizeof(LinkedList));
    memset(pReturn, 0, sizeof(LinkedList));
    return pReturn;
}

int getLinkedListData(LinkedList* pList, int position) {
    int i = 0;
    
    LinkedListNode *pCurrentNode = &(pList->headerNode);
    for (i = 0; i <= position; i++) {
        pCurrentNode = pCurrentNode->pLink;
    }
    
    return pCurrentNode->data;
}

int addLinkedListData(LinkedList* pList, int position, int data) {
    int i = 0;
    LinkedListNode *pNewNode = NULL;
    LinkedListNode *pPreNode = NULL;
    
    pNewNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    pNewNode->data = data;
    
    pPreNode = &(pList->headerNode);
    for (i = 0; i < position; i++) {
        pPreNode = pPreNode->pLink;
    }
    
    pNewNode->pLink = pPreNode->pLink;
    pPreNode->pLink = pNewNode;
    pList->currentCount++;
    return 0;
}

int removeLinkedListData(LinkedList* pList, int position) {
    int i = 0;
    LinkedListNode *pDelNode = NULL;
    LinkedListNode *pPreNode = NULL;
    
    pPreNode = &(pList->headerNode);
    for (i = 0; i < position; i++) {
        pPreNode = pPreNode->pLink;
    }
    
    pDelNode = pPreNode->pLink;
    pPreNode->pLink = pDelNode->pLink;
    free(pDelNode);
    pList->currentCount--;
    return 0;
}

void deleteLinkedList(LinkedList* pList) {
    LinkedListNode *pDelNode = NULL;
    LinkedListNode *pPreNode = pList->headerNode.pLink;
    while(pPreNode != NULL) {
        pDelNode = pPreNode;
        pPreNode = pPreNode->pLink;
        
        free(pDelNode);
    }
    
    free(pList);
}

int getLinkedListLength(LinkedList* pList) {
    if (NULL != pList) {
        return pList->currentCount;
    }
    return 0;
}

void iterateLinkedList(LinkedList* pList) {
    int count = 0;
    LinkedListNode* pNode = NULL;
    
    pNode = pList->headerNode.pLink;
    while(pNode != NULL) {
        printf("[%d],%d\n", count, pNode->data);
        count++;
        
        pNode = pNode->pLink;
    }
    printf("?????? ??????: %d\n", count);
}

void concatLinkedList(LinkedList* pListA, LinkedList* pListB) {
     LinkedListNode* pNodeA = NULL;
    
    if (pListA != NULL && pListB != NULL) {
        pNodeA = pListA->headerNode.pLink;
        
        while(pNodeA != NULL && pNodeA->pLink != NULL) {
            pNodeA = pNodeA->pLink;
        }
        pNodeA->pLink = pListB->headerNode.pLink;
        
        pListB->headerNode.pLink = NULL;
    }
}

int main(int argc, char *argv[]) {
    LinkedList *pListA = NULL;
    LinkedList *pListB = NULL;
    
    CircularList* pList = NULL;
    pList = createCircularList();
    CircularListNode node = {0, };
    
    node.data = 79;
    addCircularListElement(pList, 0, node);
    node.data = 86;
    addCircularListElement(pList, 1, node);
    node.data = 15;
    addCircularListElement(pList, 0, node);
    node.data = 19;
    addCircularListElement(pList, 1, node);
    node.data = 53;
    addCircularListElement(pList, 4, node);
    
    displayCircularList(pList);

    /*
    pListA = createLinkedList();
    pListB = createLinkedList();
    addLinkedListData(pListA, 0, 10);
    addLinkedListData(pListA, 1, 20);
    addLinkedListData(pListA, 2, 30);
    addLinkedListData(pListB, 0, 40);
    addLinkedListData(pListB, 1, 50);

    printf("?????? ????????? ?????? ???\n");
    printf("\n?????? ????????? A\n");
    iterateLinkedList(pListA);
    printf("\n?????? ????????? B\n");
    iterateLinkedList(pListB);
    
    concatLinkedList(pListA, pListB);
    
    printf("\n?????? ????????? ?????? ???\n");
    printf("\n?????? ????????? A\n");
    iterateLinkedList(pListA);
    printf("\n?????? ????????? B\n");
    iterateLinkedList(pListB);
    
    
    deleteLinkedList(pListA);
    deleteLinkedList(pListB);
*/
    return 0;
}

