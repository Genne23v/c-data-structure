//
//  bintree.c
//  7_01
//
//  Created by Wonkeun No on 2020-04-15.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode) {
    BinTree* pReturn = NULL;
    pReturn = (BinTree*)malloc(sizeof(BinTree));
    if (pReturn != NULL) {
        pReturn->pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        if (pReturn->pRootNode != NULL) {
            *(pReturn->pRootNode) = rootNode;
            pReturn->pRootNode->pLeftChild = NULL;
            pReturn->pRootNode->pRightChild = NULL;
        } else {
            printf("오류, 메모리 할당(2), makeBinTree()\n");
            free(pReturn);
            pReturn = NULL;
        }
    }else {
        printf("오류, 메모리할당(1), makeBinTree()\n");
    }
    return pReturn;;
}
BinTreeNode* insertLeftChildNodeBinTree(BinTreeNode* pParentNode, BinTreeNode element) {
    BinTreeNode* pReturn = NULL;
    if (pParentNode != NULL) {
        if (pParentNode->pLeftChild == NULL) {      //기존에 존재하는 자식 노드가 있는지 점검
            pParentNode->pLeftChild = (BinTreeNode*)malloc(sizeof(BinTreeNode));
            if (pParentNode->pLeftChild != NULL) {
                *(pParentNode->pLeftChild) = element;
                pParentNode->pLeftChild->pLeftChild = NULL;
                pParentNode->pLeftChild->pRightChild = NULL;
                pReturn = pParentNode->pLeftChild;
            } else {
                printf("오류, 메모리 할당, insertLeftChildNodeBinTree()\n");
            }
        } else {
            printf("오류, 이미 노드가 존재합니다, insertLeftChildNodeBinTree()\n");
        }
    }
    return pReturn;
}
BinTreeNode* insertRightChildNodeBinTree(BinTreeNode* pParentNode, BinTreeNode element) {
    BinTreeNode* pReturn = NULL;
    if (pParentNode != NULL) {
        if (pParentNode->pRightChild == NULL) {
            pParentNode->pRightChild = (BinTreeNode*)malloc(sizeof(BinTreeNode));
            if (pParentNode->pRightChild != NULL) {
                *(pParentNode->pRightChild) = element;
                pParentNode->pRightChild->pLeftChild = NULL;
                pParentNode->pRightChild->pRightChild = NULL;
                pReturn = pParentNode->pRightChild;
            }else {
                printf("오류, 메모리 할당, insertRightChildNodeBinTree()\n");
            }
        } else {
            printf("오류, 이미 노드가 존배합니다, insertRightChildNodeBinTree()\n");
        }
    }
    return pReturn;
}
BinTreeNode* getRootNodeBinTree(BinTree* pBinTree) {
    BinTreeNode* pReturn = NULL;
    
    if (pBinTree != NULL) {
        pReturn = pBinTree->pRootNode;
    }
    return pReturn;
}
BinTreeNode* getLeftChildNodeBinTree(BinTreeNode* pNode) {
    BinTreeNode* pReturn = NULL;
    
    if (pNode != NULL) {
        pReturn = pNode->pLeftChild;
    }
    return pReturn;
}
BinTreeNode* getRightChildNodeBinTree(BinTreeNode* pNode) {
    BinTreeNode* pReturn = NULL;
    
    if (pNode != NULL) {
        pReturn = pNode->pRightChild;
    }
    return pReturn;
}
void deleteBinTree(BinTree* pBinTree) {
    if (pBinTree != NULL) {
        deleteBinTreeNode(pBinTree->pRootNode);
        free(pBinTree);
    }
}
void deleteBinTreeNode(BinTreeNode* pNode) {
    if (pNode != NULL) {
        deleteBinTreeNode(pNode->pLeftChild);
        deleteBinTreeNode(pNode->pRightChild);
        free(pNode);
    }
}
