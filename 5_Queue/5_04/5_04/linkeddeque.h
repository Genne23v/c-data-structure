//
//  linkeddeque.h
//  5_04
//
//  Created by Wonkeun No on 2020-04-11.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef linkeddeque_h
#define linkeddeque_h

#include <stdio.h>

typedef struct DequeNodeType {
    char data;
    struct DequeNodeType* pRLink;
    struct DequeNodeType* pLLink;
}DequeNode;

typedef struct LinkedDequeType {
    int currentElementCount;
    DequeNode* pFrontNode;
    DequeNode* pRearNode;
}LinkedDeque;

LinkedDeque* createLinkedDeque(void);
int insertFrontLinkedDeque(LinkedDeque* pDeque, DequeNode element);
int insertRearLinkedDeque(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLinkedDeque(LinkedDeque* pDeque);
DequeNode* deleteRearLinkedDeque(LinkedDeque* pDeque);
DequeNode* peekLinkedDeque(LinkedDeque* pDeque);
DequeNode* peekRearLinkedDeque(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE 1
#define FALSE 0

#endif /* linkeddeque_h */
