//
//  example.h
//  3_03
//
//  Created by Wonkeun No on 2020-03-27.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_      //대문자로 쓰는 이유

typedef struct CircularListNodeType {
    int data;
    struct CircularListNodeType* pLink;
}CircularListNode;

typedef struct CircularListType {
    int currentElementCount;
    CircularListNode* pLink;            //헤드 포인터
}CircularList;

CircularList* createCircularList(void);
void deleteCircularList(CircularList* pList);
int addCircularListElement(CircularList* pList, int position, CircularListNode element);
int removeCircularListElement(CircularList* pList, int position);
void clearCircularList(CircularList* pList);
int getCircularListLength(CircularList* pList);
CircularListNode* getCircularListElement(CircularList* pList, int position);
void displayCircularList(CircularList* pList);

#endif /* example_h */

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
