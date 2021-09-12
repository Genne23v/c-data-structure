//
//  bnitreetraversalrec.h
//  7_02
//
//  Created by Wonkeun No on 2020-04-15.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef bnitreetraversalrec_h
#define bnitreetraversalrec_h

#include <stdio.h>
#include "bintree.h"

void preorderTraversalRecursiveBinTree(BinTree* pBinTree);
void preorderTraversalRecursiveBinTreeNode(BinTreeNode* pRootNode);
void inorderTraversalRecursiveBinTree(BinTree* pBinTree);
void inorderTraversalRecursiveBinTreeNode(BinTreeNode* pRootNode);
void postorderTraversalRecursiveBinTree(BinTree* pBinTree);
void postorderTraversalRecursiveBinTreeNode(BinTreeNode* pRootNode);

#endif /* bnitreetraversalrec_h */
