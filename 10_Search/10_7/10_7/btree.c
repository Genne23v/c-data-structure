//
//  btree.c
//  10_7
//
//  Created by Wonkeun No on 2020-04-27.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "btreedef.h"
#include "btlinkedstack.h"

BTreeNodeData* searchBT(BTree* pBTree, int key) {
    BTreeNodeData* pReturn = NULL;
    BTreeNode* pCurrentNode = NULL;
    int i=0;
    if (pBTree != NULL) {
        pCurrentNode = pBTree->pRootNode;
        while (pCurrentNode != NULL) {
            for(i=0; i<pCurrentNode->elementcount; i++) {
                int parentKey = pCurrentNode->element[i].key;
                if (key == parentKey) {
                    pReturn = &pCurrentNode->element[i];    //검색이 성공한 경우
                    return pReturn;
                } else if (key < parentKey) {         //검색 키값이 비교 대상 키값 parentKey보다 작은 경우, 루프를 빠져나와 현재 자료의 서브트리로 이동
                    break;
                }
            } //end-of-for
            pCurrentNode = pCurrentNode->pChildren;     //현재 노드의 서브트리로 내려가서 검색을 계속 수행
        } //end-of-while
    }
    return pReturn;     //여기서 반환하게 되면 항상 NULL을 반환
}
int insertNodeBTree(BTree* pBTree, BTreeNodeData element) {
    int ret = TRUE;
    int i =0;
    BTreeNode* pParentNode = NULL, *pCurrentNode = NULL, *pNewNode = NULL;
    LinkedStack* pStack = NULL;
    if (pBTree == NULL) {
        ret = FALSE;
        return ret;
    }
    pStack = createLinkedStack();
    if (pStack == NULL) {
        int ret = FALSE;
        return ret;
    }
    pCurrentNode = pBTree->pRootNode;
    while (pCurrentNode != NULL) {
        pParentNode = pCurrentNode;
        pushBTreeNode(pStack, pParentNode);     //노드를 순회하는 각 단계별로 해당 노드에 대한 포인터를 스택에 푸시
        for (i=0; i<pCurrentNode->elementcount; i++) {
            int parentKey = pCurrentNode->element[i].key;
            if (element.key == parentKey) {
                printf("오류, 중복된 키 - [%d], insertNodeBTree()\n", element.key);
                ret = FALSE;
                deleteLinkedStack(pStack);
                return ret;
            } else if (element.key < parentKey){
                break;
            }
        }
        pCurrentNode = pCurrentNode->pChildren[i];
    }
    if (pParentNode == NULL) {
        pBTree->pRootNode = createBTreeNode(element);
    } else {
        insertNodeElementBTree(pParentNode, element, NULL);
        splitNodeBTree(pBTree, pStack);
    }
    ret = TRUE;
    deleteLinkedStack(pStack);
    return ret;
}
int deleteNodeBTree(BTree* pBTree, int key) {
    int ret = TRUE;
    int i=0;
    BTreeNode* pCurrentNode = NULL, *pParentNode = NULL, *pChidren = NULL;
    LinkedStack* pStack = NULL;
    //중략
    pStack = createLinkedStack();
    if (pStack == NULL) {
        ret = FALSE;
        return ret;
    }
    pCurrentNode = pBTree->pRootNode;
    while (pCurrentNode != NULL && isFind == FALSE) {
        pParentNode = pCurrentNode;
        pushBTreeNode(pStack, pParentNode);
        //중략
        pCurrentNode = pCurrentNode->pChildren[i];
    }
    if (isFind == TRUE) {
        if (isLeafNode(pParentNode) == FALSE) {
            pParentNode = replaceLeafNodeBTree(pBTree, pParentNode, i, pStack);
        } else {
            deleteKeyBTree(pParentNode, i);
        }
        if (pParentNode->elementcount < (BTREE_ORDER/2)) {
            balanceBTree(pBTree, pStack);
            ret = TRUE;
        } else {
            ret = FALSE;
            printf("오류, 검색키 - [%d]가 발견되지 않았습니다, deleteNodeBTree()\n", key);
        }
    }
    deleteLinkedStack(pStack);
    
    return ret;
}
