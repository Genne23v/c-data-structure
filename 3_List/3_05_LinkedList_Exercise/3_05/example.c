//
//  example.c
//  3_05
//
//  Created by Wonkeun No on 2020-03-29.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "linkedlistop.h"


int main(int argc, char *argv[]) {
    //int i= 0, arrayCount= 0;
    LinkedList *pListA= NULL, *pListB= NULL;
    ListNode node;
    
    pListA = createLinkedList();
    pListB = createLinkedList();
    if (pListA != NULL && pListB != NULL) {
        node.data = 1;
        addLinkedListElement(pListA, 0, node);
        node.data = 2;
        addLinkedListElement(pListA, 1, node);
        node.data = 3;
        addLinkedListElement(pListA, 2, node);
        node.data = 4;
        addLinkedListElement(pListB, 0, node);
        node.data = 5;
        addLinkedListElement(pListB, 1, node);
        
        iterateLinkedList(pListA);
        iterateLinkedList(pListB);
        
        concatLinkedList(pListA, pListB);
        printf("After concatLinkedList()\n");
        iterateLinkedList(pListA);
        iterateLinkedList(pListB);
        
        reverseLinkedList(pListA);
        printf("After reverseLinkedList()\n");
        iterateLinkedList(pListA);
        
        deleteLinkedList(pListA);
        deleteLinkedList(pListB);
    }
    return 0;
}
