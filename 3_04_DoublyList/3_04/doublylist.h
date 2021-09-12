//
//  doublylist.h
//  3_04
//
//  Created by Wonkeun No on 2020-03-28.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef doublylist_h
#define doublylist_h

typedef struct DoublyListNodeType {
    int data;
    struct DoublyListNodeType* pLLink;
    struct DoublyListNodeType* pRLink;
}DoublyListNode;

typedef struct DoublyListType {
    int currentElementCount;
    DoublyListNode headerNode;
}DoublyList;

DoublyList* createDoublyList(void);
void deleteDoublyList(DoublyList* pList);
int addDoublyListElement(DoublyList* pList, int position, DoublyListNode element);
int removeDoublyListElement(DoublyList* pList, int position);
void clearDoublyList(DoublyList* pList);
int getDoublyListLength(DoublyList* pList);
DoublyListNode* getDoublyListElement(DoublyList* pList, int position);
void displayDoublyList(DoublyList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif /* doublylist_h */
