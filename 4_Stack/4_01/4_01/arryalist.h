//
//  arryalist.h
//  4_01
//
//  Created by Wonkeun No on 2020-03-31.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef arryalist_h
#define arryalist_h

typedef struct ArrayStackNodeType {
    char data;
} ArrayStackNode;

typedef struct ArrayStackType {
    int maxElementCount;
    int currentElementCount;
    ArrayStackNode *pElement;
}ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushArrayStack(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* popArrayStack(ArrayStack* pStack);
ArrayStackNode* peekArrayStack(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0

#endif /* arryalist_h */
