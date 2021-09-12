//
//  bintreeop.h
//  7_04
//
//  Created by Wonkeun No on 2020-04-17.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef bintreeop_h
#define bintreeop_h
#include "bintree.h"

BinTree* copyBinTree(BinTree* pSpource);
BinTreeNode* copyBinTreeNode(BinTreeNode* pSourceNode);
int equalBinTree(BinTree* pFirst, BinTree* pSecond);
int equalBinTreeNode(BinTreeNode* pFirst, BinTreeNode* pSecond);
int getNodeCountBinTree(BinTree* pSource);
int getNodeCountBinTreeNode(BinTreeNode* pSource);
int getLeafNodeCountBinTree(BinTree* pSource);
int getLeafNodeCountBinTreeNode(BinTreeNode* pSource);
int getHeightBinTree(BinTree* pSource);
int getHeightBinTreeNode(BinTreeNode* pSource);
void displayBinTree(BinTree* pTree);
void displayBinTreeNode(BinTreeNode* pNode, int level, char type);

#endif /* bintreeop_h */
