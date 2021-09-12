//
//  avltree.c
//  10_6
//
//  Created by Wonkeun No on 2020-04-26.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "avldef.h"
#include "avltree.h"
#include "avllinkedstack.h"

int insertNodeAVL(AVLTree* pAVLTree, AVLTreeNodeData element) {
    int ret = TRUE;
    AVLTreeNode* pParentNode = NULL;
    AVLTreeNode* pNewNode = NULL;
    LinkedStack* pStack = NULL;
    
//중략
    pStack = createLinkedStack();
    if (pStack != NULL) {
        ret = FALSE;
        return ret;
    }
    pParentNode = pAVLTree->pRootNode;
    while (pParentNode != NULL) {
        pushAVLTreeNode(pStack, pParentNode);
        if (element.key == pParentNode->data.key) {
            //중략
        }
    }
    pNewNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
    if (pNewNode != NULL) {
        memset(pNewNode, 0, sizeof(AVLTreeNode));
        pNewNode->data = element;
        pNewNode->height = 1;
    }
    //중략
    if (pParentNode == NULL) {
        pAVLTree->pRootNode = pNewNode;
        //중략
    }
    ret = TRUE;
    
    balanceAVLTree(pAVLTree, pStack);
    deleteLinkedStack(pStack);
    return ret;
}
void balanceAVLTree(AVLTree* pAVLTree, LinkedStack* pStack) {
    AVLTreeNode* pParentNode = NULL;
    AVLTreeNode* pNode = NULL;
    AVLTreeNode* pChildNode = NULL;
    AVLTreeNode* pNewNode = NULL;
    if (pAVLTree == NULL || pStack == NULL) {
        return;
    }
    while (isLinkedStackEmpty(pStack) == FALSE) {
        pNode = popAVLTreeNode(pStack);
        if (pNode != NULL) {
            updateHeightAndBalanceAVL(pNode);
            if (pNode->balance >= -1 && pNode->balance <= 1) {
                continue;
            }
            if (pNode->balance > 1) {
                pChildNode = pNode->pLeftChild;
                if (pChildNode->balance > 0) {
                    pNewNode = rotateLLAVLTree(pNode);
                } else {
                    pNewNode = rotateLRAVLTree(pNode);
                }
            } else if (pNode->balance < -1) {
                pChildNode = pNode->pRightChild;
                if (pChildNode->balance < 0) {
                    pNewNode = rotateRRAVLTree(pNode);
                } else {
                    pNewNode = rotateRLAVLTree(pNode);
                }
            }
            pParentNode = peekAVLTreeNode(pStack);
            if (pParentNode != NULL) {
                if (pParentNode->pLeftChild == pNode) {
                    pParentNode->pLeftChild = pNewNode;
                } else {
                    pParentNode->pRightChild = pNewNode;
                }
            }else {
                pAVLTree->pRootNode = pNewNode;
            }
        }
    }
}
int pushAVLTreeNode(LinkedStack* pStack, AVLTreeNode* data) {
    StackNode node = {0,};
    node.data = data;
    return pushLinkedStack(pStack, node);
}
AVLTreeNode* popAVLTreeNode(LinkedStack* pStack) {
    AVLTreeNode* pReturn = NULL;
    if (isLinkedStackEmpty(pStack) == FALSE) {
        StackNode* pNode = popLinkedStack(pStack);
        if (pNode != NULL) {
            pReturn = pNode->data;
            free(pNode);
        }
    }
    return pReturn;
}
AVLTreeNode* peekAVLTreenNode(LinkedStack* pStack) {
    AVLTreeNode* pReturn = NULL;
    if (isLinkedStackEmpty(pStack) == FALSE) {
        StackNode* pNode = peekLinkedStack(pStack);
        if (pNode != NULL) {
            pReturn = pNode->data;
        }
    }
    return pReturn;
}
AVLTreeNode* rotateLLAVLTree(AVLTreeNode* pParentNode) {
    AVLTreeNode* pLeftNode = NULL;
    if(pParentNode != NULL) {
        pLeftNode = pParentNode->pLeftChild;
        pParentNode->pLeftChild = pLeftNode->pRightChild;
        pLeftNode->pRightChild = pParentNode;
        
        updateHeightAndBalanceAVL(pParentNode);
        updateHeightAndBalanceAVL(pLeftNode);
    }
    return pLeftNode;
}
AVLTreeNode* rotateRRAVLTree(AVLTreeNode* pParentNode) {
    AVLTreeNode* pRightNode = NULL;
    if (pParentNode != NULL) {
        pRightNode = pParentNode->pRightChild;
        pParentNode->pRightChild = pRightNode->pLeftChild;
        pRightNode->pLeftChild = pParentNode;
        
        updateHeightAndBalanceAVL(pParentNode);
        updateHeightAndBalanceAVL(pRightNode);
    }
    return pRightNode;
}
AVLTreeNode* rotateLRAVLTree(AVLTreeNode* pParentNode) {
    AVLTreeNode* pReturn = NULL;
    AVLTreeNode* pLeftNode = NULL;
    if (pParentNode != NULL) {
        pLeftNode = pParentNode->pLeftChild;
        pParentNode->pLeftChild = rotateRRAVLTree(pLeftNode);
        pReturn = rotateLLAVLTree(pParentNode);
    }
    return pReturn;
}
AVLTreeNode* rotateRLAVLTree(AVLTreeNode* pParentNode) {
    AVLTreeNode* pReturn = NULL;
    AVLTreeNode* pRightNode = NULL;
    if (pParentNode != NULL) {
        pRightNode = pParentNode->pRightChild;
        pParentNode->pRightChild = rotateLLAVLTree(pRightNode);
        pReturn = rotateRRAVLTree(pParentNode);
    }
    return pReturn;
}
void updateHeightAndBalanceAVL(AVLTreeNode* pNode) {
    int leftHeight = 0;
    int rightHeight = 0;
    if (pNode != NULL) {
        leftHeight = pNode->pLeftChild->height;
    }
    if (pNode->pRightChild->height) {
        rightHeight = pNode->pRightChild->height;
    }
    if (leftHeight > rightHeight) {
        pNode->height = leftHeight + 1;
    } else {
        pNode->height = rightHeight + 1;
    }
    pNode->balance = leftHeight - rightHeight;
}
int deleteNodeAVL(AVLTree* pAVLTree, int key) {
    int ret = FALSE;
    AVLTreeNode* pDelNode = NULL;
    AVLTreeNode* pParentNode = NULL;
    AVLTreeNode* pPredecessor = NULL;
    AVLTreeNode* pSuccessor = NULL;
    AVLTreeNode* pChild = NULL;
    LinkedStack* pStackMain = NULL;
    LinkedStack* pStackSub = NULL;
    //중략
    pStackMain = createLinkedStack();
    pStackSub = createLinkedStack();
    if (pStackMain == NULL || pStackSub == NULL) {
        ret = FALSE;
        return ret;
    }
    pParentNode = NULL;
    pDelNode = pAVLTree->pRootNode;
    while (pDelNode != NULL) {
        if (key == pDelNode->data.key) {
            break;
        }
        pParentNode = pDelNode;
        pushAVLTreeNode(pStackMain, pParentNode);       //삭제 노드의 부모 노드를 찾는 각 경로에 해당하는 노드를 스택에 저장
        //중략
    }
    //중략
    else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) {
        pPredecessor = NULL;
        pSuccessor = pDelNode->pLeftChild;
        pushAVLTreeNode(pStackSub, pSuccessor);
        
        while (pSuccessor->pRightChild != NULL) {
            pPredecessor = pSuccessor;
            pSuccessor = pSuccessor->pRightChild;
            pushAVLTreeNode(pStackSub, pSuccessor);
        }
        pushAVLTreeNode(pStackMain, popAVLTreeNode(pStackSub));
        
        if (pPredecessor != NULL) {
            pPredecessor->pRightChild = pSuccessor->pLeftChild;
            pSuccessor->pLeftChild = pDelNode->pLeftChild;
            
            pushAVLTreeNode(pStackSub, pPredecessor->pRightChild);
        }
        pSuccessor->pRightChild = pDelNode->pRightChild;
    }
    free(pDelNode);
    
    balanceAVLTree(pAVLTree, pStackSub);
    balanceAVLTree(pAVLTree, pStackMain);
    
    deleteLinkedStack(pStackMain);
    deleteLinkedStack(pStackSub);
    
    return ret;
}
SearchAVL() {
    
}
void deleteAVLTree() {
    
}
void displayAVLTreeInternal() {
    
}
