//
//  binsearchtree.c
//  7_06
//
//  Created by Wonkeun No on 2020-04-17.
//  Copyright © 2020 genne. All rights reserved.
//

#include "binsearchtree.h"
#include <stdio.h>
#include <stdlib.h>

BinSearchTree* createBinSearchTree() {
    BinSearchTree* pReturn = NULL;
    pReturn = (BinSearchTree*)malloc(sizeof(BinSearchTree));
    if (pReturn != NULL) {
        pReturn->pRootNode = NULL;
    } else {
        printf("오류, 메모리 할당, createBinSearchTree()\n");
    }
    return pReturn;
}
int insertElementBinSearchTree(BinSearchTree* pBinSearchTree, BinSearchTreeNode element) {
    int ret = TRUE;
    BinSearchTreeNode* pParentNode = NULL;
    BinSearchTreeNode* pNewNode = NULL;
    if (pBinSearchTree == NULL) {
        ret = FALSE;
        return ret;
    }
    pParentNode = pBinSearchTree->pRootNode;
    while(pParentNode != NULL) {
        if (element.key == pParentNode->key) {
            printf("오류, 중복된 키 - [%d], insertElementBinSearchTree()\n", element.key);
            ret = FALSE;
            return ret;
        } else if (element.key < pParentNode->key) {
            if (pParentNode->pLeftChild == NULL) {
                break;
            } else {
                pParentNode = pParentNode->pLeftChild;
            }
        } else {
            if (pParentNode->pRightChild == NULL) {
                break;
            } else {
                pParentNode = pParentNode->pRightChild;
            }
        }
    }
    pNewNode = (BinSearchTreeNode*)malloc(sizeof(BinSearchTreeNode));
    if (pNewNode != NULL) {
        *pNewNode = element;
        pNewNode->pLeftChild = NULL;
        pNewNode->pRightChild = NULL;
        if (pParentNode == NULL) {          //루트노드가 널인 경우 새로 추가되는 노드가 루트 노드가 된다 (왜 루트가 비었음?)
            pBinSearchTree->pRootNode = pNewNode;
        } else {
            if (pNewNode->key < pParentNode->key) {
                pParentNode->pLeftChild = pNewNode;     //왼쪽 끝까지 이동?
            } else {
                pParentNode->pRightChild = pNewNode;
            }
        }
        ret = TRUE;
    } else {
        printf("오류, 메모리 할당, insertElementBinSearchTree()\n");
    }
    return ret;
}
int deleteElementBinSearchTree(BinSearchTree* pBinSearchTree, int key) {
    int ret = TRUE;
    BinSearchTreeNode* pDelNode = NULL, *pParentNode = NULL;
    BinSearchTreeNode* pPredecessor = NULL, *pSuccessor = NULL;
    BinSearchTreeNode* pChildNode = NULL;
    
    if (pBinSearchTree == NULL) {
        ret = FALSE;
        return ret;
    }
    pParentNode = NULL;
    pDelNode = pBinSearchTree->pRootNode;
    while (pDelNode != NULL) {
        if (key == pDelNode->key) {
            break;
        }
        pParentNode = pDelNode;     //단말 노드시
        if (key < pDelNode->key) {
            pDelNode = pDelNode->pLeftChild;
        } else {
            pDelNode = pDelNode->pRightChild;
        }
    }//end-of-while
    if (pDelNode == NULL) {     //키 값을 찾지 못했을때
        printf("오류, 존재하지 않는 키 - [%d], deleteElementBinSearchTree()\n", key);
        ret = FALSE;
        return ret;
    }
    //왼쪽 또는 오른쪽 하나의 childNode만 있을때
    if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = NULL;
            } else {
                pParentNode->pRightChild = NULL;
            }
        } else {
            pBinSearchTree->pRootNode = NULL;       //삭제 노드가 루트인 경우
        }
    } else if ( pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL){  //두개 노드 다 있을때
        pPredecessor = pDelNode;
        pSuccessor - pDelNode->pLeftChild;
        // 왼쪽 서브트리의 가장 큰 값을 찾는다
        while (pSuccessor->pRightChild != NULL) {
            pPredecessor = pSuccessor;
            pSuccessor = pSuccessor->pRightChild;
        }
        pPredecessor->pRightChild = pSuccessor->pLeftChild;
        pSuccessor->pLeftChild = pDelNode->pLeftChild;
        pSuccessor->pRightChild = pDelNode->pRightChild;
        //pSuccessor는 삭제되는 노드를 대체할 노드를 가리킨다. DelNode의 자식노드를 Successor의 자식노드로 변견
        
        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pSuccessor;
            } else {
                pParentNode->pRightChild = pSuccessor;      //Successor노드를 삭제되는 부모노드의 자식노드로 설정
            }
        }else {
            pBinSearchTree->pRootNode = pSuccessor;
        }
    } else {
        if (pDelNode->pLeftChild != NULL) {
            pChildNode = pDelNode->pLeftChild;
        } else {
            pChildNode = pDelNode->pRightChild;
        }
        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pChildNode;
            } else {
                pParentNode->pRightChild = pChildNode;
            }
        } else {
            pBinSearchTree->pRootNode = pChildNode;
        }
    }
    free(pDelNode);
    return ret;
}
BinSearchTreeNode* searchBinSearchTree(BinSearchTree* pBinSearchTree, int key) {
    BinSearchTreeNode* pReturn = NULL;
    
    if (pBinSearchTree == NULL) {
        return NULL;
    }
    pReturn = pBinSearchTree->pRootNode;
    while (pReturn != NULL) {
        if (key == pReturn->key) {
            break;
        } else if (key < pReturn->key) {
            pReturn = pReturn->pLeftChild;
        } else {
            pReturn = pReturn->pRightChild;
        }
    }
                   return pReturn;
}
void deleteBinSearchTree(BinSearchTree* pBinSearchTree) {
    if (pBinSearchTree != NULL) {
        deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
        free(pBinSearchTree);
    }
}
void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode) {
    if (pTreeNode != NULL) {
        deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
        deleteBinSearchTreeInternal(pTreeNode->pRightChild);
        free(pTreeNode);
    }
}
