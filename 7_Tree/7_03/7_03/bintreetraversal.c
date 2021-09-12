//
//  bnitreetraversalrec.c
//  7_02
//
//  Created by Wonkeun No on 2020-04-15.
//  Copyright © 2020 genne. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include "bintreelinkedqueue.h"
#include "bintreelinkedstack.h"
#include "bintreetraversal.h"
#include "bintree.h"

int pushLinkedStackBinTreeNode(LinkedStack* pStack, BinTreeNode *pNode) {
    StackNode node = {0, };
    node.data = pNode;
    return pushLinkedStack(pStack, node);
}
int enqueueLinkedQueueBinTreeNode(LinkedQueue* pQueue, BinTreeNode* pNode) {
    QueueNode node = {0,};
    node.data = pNode;
    return enqueueLinkedQueue(pQueue, node);
}
void preorderTraversalBinTree(BinTree* pBinTree) {
    LinkedStack* pStack = NULL;
    StackNode* pStackNode = NULL;
    BinTreeNode* pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;
    
    if (pBinTree == NULL) {
        return;
    }
    pRootNode = getRootNodeBinTree(pBinTree);
    if (pRootNode == NULL) {
        return;
    }
    pStack = createLinkedStack();
    if (pStack == NULL) {
        return;
    }
    pushLinkedStackBinTreeNode(pStack, pRootNode);
    while(1) {
        if (isLinkedStackEmpty(pStack) == TRUE) {
            break;
        } else {
            pStackNode = popLinkedStack(pStack);        //스택에서 팝해서 현재 노드를 반환하고 방문 처리
            if (pStackNode != NULL) {
                pRootNode = pStackNode->data;
                printf("%c ", pRootNode->data);
                
                pLeftChildNode = getLeftChildNodeBinTree(pRootNode);
                pRightChildNode = getRightChildNodeBinTree(pRootNode);
                
                if (pRightChildNode != NULL) {
                    pushLinkedStackBinTreeNode(pStack, pRightChildNode);
                }
                if (pLeftChildNode != NULL) {
                    pushLinkedStackBinTreeNode(pStack, pLeftChildNode);
                }
                free(pStackNode);
            }
        }
    }
    deleteLinkedStack(pStack);
}
void inorderTraversalBinTree(BinTree* pBinTree) {
    LinkedStack* pStack = NULL;
    StackNode* pStackNode = NULL;
    BinTreeNode* pRootNode = NULL, *pNode = NULL;
    
    if (pBinTree == NULL) {
        return;
    }
    pRootNode = getRootNodeBinTree(pBinTree);
    if (pRootNode == NULL) {
        return;
    }
    pStack = createLinkedStack();
    if (pStack == NULL) {
        return;
    }
    pNode = pRootNode;
    while (1) {
        for (;pNode != NULL; pNode = getLeftChildNodeBinTree(pNode)) {
            pushLinkedStackBinTreeNode(pStack, pNode);      //현재 노드부터 왼쪽 서브트리를 스택에 푸시
        }
        if (isLinkedStackEmpty(pStack) == TRUE) {
            break;
        } else {
            pStackNode = popLinkedStack(pStack);        //스택에서 팝된 노드가 새로운 현재 노드가 됨
            if (pStackNode != NULL) {
                pNode = pStackNode->data;
                printf("%c ", pNode->data);             //현재 노드 방문 처리
                pNode = getRightChildNodeBinTree(pNode);
                
                free(pStackNode);
            }
        }
    }
    deleteLinkedStack(pStack);
}
void levelOrderTraversalBinTree(BinTree* pBinTree) {
    LinkedQueue* pQueue = NULL;
    QueueNode* pQueueNode = NULL;
    BinTree* pSubTree = NULL;
    BinTreeNode *pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;
    
    if (pBinTree == NULL) {
        return;
    }
    pRootNode = getRootNodeBinTree(pBinTree);
    if (pRootNode == NULL) {
        return;
    }
    pQueue = createLinkedQueue();
    if (pQueue == NULL) {
        return;
    }
    enqueueLinkedQueueBinTreeNode(pQueue, pRootNode);
    while(1) {
        if (isLinkedQueueEmpty(pQueue) == TRUE) {
            break;
        }else {
            pQueueNode = dequeueLinkedQueue(pQueue);
            if (pQueueNode != NULL) {
                pRootNode = pQueueNode->data;
                if (pRootNode != NULL) {
                    printf("%c ", pRootNode->data);
                }
                pLeftChildNode = getLeftChildNodeBinTree(pRootNode);
                pRightChildNode = getRightChildNodeBinTree(pRootNode);
                if (pLeftChildNode != NULL) {
                    enqueueLinkedQueueBinTreeNode(pQueue, pLeftChildNode);
                }
                if (pRightChildNode != NULL) {
                    enqueueLinkedQueueBinTreeNode(pQueue, pRightChildNode);
                }
                free(pQueueNode);
            }
        }
    }
    deleteLinkedQueue(pQueue);
}
