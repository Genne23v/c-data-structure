//
//  graphtraversal.c
//  8_03
//
//  Created by Wonkeun No on 2020-04-21.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "graphtraversal.h"
#include "linkedgraph.h"
#include "linkedstack.h"
#include "graphtraversal.h"

int pushLinkedStackForDepthFirstSearch(LinkedStack* pStack, int nodeID) {
    StackNode node = {0,};
    node.data = nodeID;
    return pushLinkedStack(pStack, node);
}
void traversalDepthFirstSearch(LinkedGraph* pGraph, int startVertexID) {
    int i=0;
    int vertexID = 0;
    LinkedStack* pStack = NULL;
    StackNode* pStackNode = NULL;
    ListNode* pListNode = NULL;
    int *pVisited = NULL;
    
    if (pGraph == NULL) {
        return;
    }
    
    pStack = createLinkedStack();
    if (pStack == NULL) {
        return;
    }
    
    pVisited = (int*)malloc(sizeof(int)*pGraph->maxVertexCount);
    if (pVisited == NULL) {
        printf("오류, 메모리할당 in traversalDepthFirstSearch()\n");
        return;
    }
    for (i=0; i<pGraph->maxVertexCount; i++) {
        pVisited[i] = FALSE;
    }
    pVisited[startVertexID] = TRUE;
    pushLinkedStackForDepthFirstSearch(pStack, startVertexID);
    
    while (isLinkedStackEmpty(pStack) == FALSE) {
        pStackNode = popLinkedStack(pStack);
        if (pStackNode != NULL) {
            vertexID = pStackNode->data;        //팝시킨 노드가 새로운 탐색노드가 됨
            printf("[%d] - 방문\n", vertexID);
            
            pListNode = pGraph->ppAdjEdge[vertexID]->headerNode.pLink;      //현재 탐색 노드와 연결된 모드 노드를 푸시. 이해 안감 (3장 참조)
            while (pListNode != NULL) {
                int vertexID = pListNode->data.vertexID;                    //이해 안감
                if (pVisited[vertexID] == FALSE) {
                    pVisited[vertexID] = TRUE;
                    pushLinkedStackForDepthFirstSearch(pStackNode, vertexID);
                }
                pListNode = pListNode->pLink;
            }
        }
    }
    free(pVisited);
    deleteLinkedStack(pStack);
}
