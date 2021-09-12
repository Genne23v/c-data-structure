//
//  binsearchtree.h
//  7_06
//
//  Created by Wonkeun No on 2020-04-17.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef binsearchtree_h
#define binsearchtree_h

#include <stdio.h>

typedef struct BinSearchTreeNodeType {
    int key;
    char value;
    struct BinSearchTreeNodeType* pLeftChild;
    struct BinSearchTreeNodeType* pRightChild;
}BinSearchTreeNode;

typedef struct BinSearchTreeType {
    BinSearchTreeNode* pRootNode;
}BinSearchTree;

BinSearchTree* createBinSearchTree();
int insertElementBinSearchTree(BinSearchTree* pBinSearchTree, BinSearchTreeNode element);
int deleteElement(BinSearchTree* pBinSearchTree, int key);
BinSearchTreeNode* searchRecursiveBinSearchTree(BinSearchTree* pBinSearchTree, int key);
BinSearchTreeNode* searchInternalRecursiveBinSearchTree(BinSearchTreeNode* pTreeNode, int key);
BinSearchTreeNode* searchBinSearchTree(BinSearchTree* pBinSearchTree, int key);
void deleteBinSearchTree(BinSearchTree* pBinSearchTree);
void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE 1
#define FALSE 0

#endif /* binsearchtree_h */
