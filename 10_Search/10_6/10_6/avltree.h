//
//  avltree.h
//  10_6
//
//  Created by Wonkeun No on 2020-04-26.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef avltree_h
#define avltree_h

#include <stdio.h>
#include "avldef.h"
#include "avllinkedstack.h"

typedef struct AVLTreeType {
    AVLTreeNode* pRootNode;
}AVLTree;

int insertNodeAVL(AVLTree* pAVLTree, AVLTreeNodeData element);
void balanceAVLTree(AVLTree* pAVLTree, LinkedStack* pStack);
int pushAVLTreeNode(LinkedStack* pStack, AVLTreeNode* data);
AVLTreeNode* popAVLTreeNode(LinkedStack* pStack);
AVLTreeNode* rotateLLAVLTree(AVLTreeNode* pParentNode);
AVLTreeNode* rotateRRAVLTree(AVLTreeNode* pParentNode);
AVLTreeNode* rotateLRAVLTree(AVLTreeNode* pParentNode);
AVLTreeNode* rotateRLAVLTree(AVLTreeNode* pParentNode);
void updateHeightAndBalanceAVL(AVLTreeNode* pNode);
int deleteNodeAVL(AVLTree* pAVLTree, int key);

#endif /* avltree_h */
