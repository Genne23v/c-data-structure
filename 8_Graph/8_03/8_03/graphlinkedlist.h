//
//  linkedlist.h
//  3_02
//
//  Created by Wonkeun No on 2020-03-26.
//  Copyright © 2020 genne. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef graphlinkedlist_h
#define graphlinkedlist_h

typedef struct ListNodeType {
    GraphVertex data;
    struct ListNodeType* pLink;     //링크 연결
}ListNode;                  //메인 리스트 구조체

typedef struct GraphVertexType {
    int vertexID;
    int weight;
}GraphVertex;

typedef struct LinkedListType {
    int currentElementCount;        //현재 저장된 원소의 개수
    ListNode headerNode;            //헤더 노드 (더미)
}LinkedList;

LinkedList* createLinkedList(void);         //void 넣어야 함? 
int addLinkedListElement(LinkedList* pList, int position, ListNode element);
int removeLinkedListElement(LinkedList* pList, int position);
ListNode* getLinkedListElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif /* linkedlist_h */
