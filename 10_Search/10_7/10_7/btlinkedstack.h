//
//  linkedstack.h
//  4_02
//
//  Created by Wonkeun No on 2020-03-31.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef linkedstack_h
#define linkedstack_h

typedef struct StackNodeType {
    struct BTreeNodeType* data;
    struct StackNodeType* pLink;
}StackNode;

typedef struct LinkedStackType {
    int currentElementCount;
    StackNode* pTopElement;
}LinkedStack;

LinkedStack* createLinkedStack(void);
int pushLinkedStack(LinkedStack* pStack, StackNode element);
StackNode* popLinkedStack(LinkedStack* pStack);
StackNode* peekLinkedStack(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0

#endif /* linkedstack_h */
