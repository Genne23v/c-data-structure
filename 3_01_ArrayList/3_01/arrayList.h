//
//  arrayList.h
//  3_01
//
//  Created by Wonkeun No on 2020-03-25.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef arrayList_h
#define arrayList_h

typedef struct ArrayListNodeType {
    int data;
}ArrayListNode;                 //추가하려는 데이터

typedef struct ArrayListType {
    int maxElementCount;                //최대 저장 원소 개수를 저장
    int currentElementCount;            //현재 원소개수를 저장
    ArrayListNode *pElement;            //실제 데이터를 저장하는 배열의 포인터
} ArrayList;

ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addAElement(ArrayList* pList, int position, ArrayListNode element);
int removeAElement(ArrayList* pList, int position);
ArrayListNode* getAElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif /* arrayList_h */
