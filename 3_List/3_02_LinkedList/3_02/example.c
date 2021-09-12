//
//  example.c
//  3_02
//
//  Created by Wonkeun No on 2020-03-26.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void displayLinkedList(LinkedList* pList) {
    int i=0;
    if (pList != NULL) {
        printf("현재 원소 개수: %d\n", pList->currentElementCount);
        
        for(i=0; i<pList->currentElementCount; i++) {
            printf("[%d], %d\n", i, getLinkedListElement(pList, i)->data);
        }
    } else {
        printf("원소가 없습니다.\n");
    }
}
int main(int argc, char *argv[]) {
    int i=0;
    int arrayCount = 0;          //이거 왜 하는거임?
    LinkedList* pList = NULL;
    ListNode* pNode = NULL;      //필요한건가?
    ListNode node;
    //단순 연결리스트를 생성하고, 점검
    pList = createLinkedList();
    if (pList != NULL) {
        node.data = 1;
        addLinkedListElement(pList, 0, node);
        
        node.data = 3;
        addLinkedListElement(pList, 1, node);
        
        node.data = 5;
        addLinkedListElement(pList, 2, node);
        displayLinkedList(pList);
        
        removeLinkedListElement(pList, 0);
        displayLinkedList(pList);
        
        deleteLinkedList(pList);
    }
    return 0;
}
