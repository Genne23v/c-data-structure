//
//  linkedstack.h
//  4_02
//
//  Created by Wonkeun No on 2020-03-31.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef linkedstack_h
#define linkedstack_h

typedef struct DoublyStackNodeType {
    char data;
    struct DoublyStackNodeType* pRLink;
    struct DoublyStackNodeType* pLLink;
}DoublyStackNode;

typedef struct LinkedStackType {
    int currentElementCount;
    DoublyStackNode headerNode;
}LinkedStack;

LinkedStack* createLinkedStack();
int pushLinkedStack(LinkedStack* pStack, DoublyStackNode element);
DoublyStackNode* popLinkedStack(LinkedStack* pStack);
DoublyStackNode* peekLinkedStack(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0

#endif /* linkedstack_h */
