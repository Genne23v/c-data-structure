//
//  example.c
//  4_01
//
//  Created by Wonkeun No on 2020-03-31.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "arryalist.h"

void displayArrayStack(ArrayStack* pStack) {
    int i= 0;
    if (pStack != NULL) {
        int size = pStack->maxElementCount;
        int top = pStack->currentElementCount;
        
        printf("스택 크기: %d, 현재 노드 개수: %d\n", pStack->maxElementCount, pStack->currentElementCount);
        
        for (i = size-1; i >= top; i--) {
            printf("[%d]-[Empty]\n", i);
        }
        for (i = top-1; i >= 0; i--) {
            printf("[%d]-[%c]\n", i, pStack->pElement[i].data);
        }
    }
}
int main(int argc, char *argv[]) {
    ArrayStack *pStack = NULL;
    ArrayStackNode *pNode = NULL;
    char value = 0;
    
    pStack = createArrayStack(6);
    if (pStack != NULL) {
        ArrayStackNode node1 = {'A'};
        ArrayStackNode node2 = {'B'};
        ArrayStackNode node3 = {'C'};
        ArrayStackNode node4 = {'D'};
        
        pushArrayStack(pStack, node1);
        pushArrayStack(pStack, node2);
        pushArrayStack(pStack, node3);
        pushArrayStack(pStack, node4);
        displayArrayStack(pStack);
        
        pNode = popArrayStack(pStack);
        if (pNode != NULL) {
            printf("pop 값-[%c]\n", pNode->data);
            free(pNode);
        } else {
            printf("공백(Empty) 스택\n");
        }
        displayArrayStack(pStack);
        pNode = peekArrayStack(pStack);
        if (pNode != NULL) {
            printf("Peek 값-[%c]\n", pNode->data);
        }else {
            printf("공백(Empty) 스택\n");
        }
        displayArrayStack(pStack);
    }
    return 0;
}
