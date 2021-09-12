//
//  CircularList.h
//  CircularListWithHeaderNode
//
//  Created by Wonkeun No on 2020-04-30.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef CircularList_h
#define CircularList_h

#include <stdio.h>

typedef struct CircularListNodeType {
    int data;
    struct CircularListNodeType* pLink;
}CircularNode;

typedef struct CircularListType {
    int currentElementCount;
    CircularNode headerNode;
}CircularList;

int addCircularListElement(CircularList* pList, int position, CircularNode element);
int removeCircularListElement(CircularList* pList, int position);
CircularNode* getCircularListElement(CircularList* pList, int position);
CircularList* createCircularList();
void displayCircularList(CircularList* pList);
int getCircularListLength(CircularList* pList);
void deleteCircularList(CircularList* pList);
void clearCircularList(CircularList* pList);

#define TRUE 1
#define FALSE 0

#endif /* CircularList_h */
