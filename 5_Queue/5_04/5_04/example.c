//
//  main.c
//  5_04
//
//  Created by Wonkeun No on 2020-04-11.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkeddeque.h"

int insertFrontLinkedDequeChar(LinkedDeque* pDeque, char data) {
    DequeNode node = {0,};
    node.data = data;
    return insertFrontLinkedDeque(pDeque, node);
}
int insertRearLinkedDequeChar(LinkedDeque* pDeque, char data ) {
    DequeNode node = {0,};
    node.data = data;
    return insertRearLinkedDeque(pDeque, node);
}
void displayLinkedDeque(LinkedDeque* pDeque) {
    DequeNode* pNode = NULL;
    int i=0;
    
    if (pDeque != NULL) {
        printf("현재 노드 개수: %d\n", pDeque->currentElementCount);
        pNode = pDeque->pFrontNode;
        while (pNode != NULL) {
            printf("[%d] - [%c]\n", i, pNode->data);
            i++;
            pNode = pNode->pRLink;
        }
    }
}
int main(int argc, const char * argv[]) {
    LinkedDeque* pDeque = NULL;
    DequeNode* pNode = NULL;
    
    pDeque = createLinkedDeque();
    if (pDeque != NULL) {
        insertFrontLinkedDequeChar(pDeque, 'A');
        insertFrontLinkedDequeChar(pDeque, 'B');
        insertRearLinkedDequeChar(pDeque, 'C');
        insertRearLinkedDequeChar(pDeque, 'D');
        displayLinkedDeque(pDeque);
        
        pNode = deleteRearLinkedDeque(pDeque);
        if (pNode != NULL) {
            printf("deleteRearLinkedDeque Value - [%c]\n", pNode->data);
            free(pNode);
        }
        displayLinkedDeque(pDeque);
        
        pNode = deleteFrontLinkedDeque(pDeque);
        if (pNode != NULL) {
            printf("deleteFrontLinkedDeque Value - [%c]\n", pNode->data);
        }
        free(pNode);
        displayLinkedDeque(pDeque);
        
        deleteLinkedDeque(pDeque);
    }
    return 0;
}
