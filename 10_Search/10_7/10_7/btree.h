//
//  btree.h
//  10_7
//
//  Created by Wonkeun No on 2020-04-27.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef btree_h
#define btree_h

#include <stdio.h>
#include "btreedef.h"

typedef struct BTreeType {
    BTreeNode* pRootNode;
}BTree;

BTreeNodeData* searchBT(BTree* pBTree, int key);
int insertNodeBTree(BTree* pBTree, BTreeNodeData element);
int deleteNodeBTree(BTree* pBTree, int key);

#endif /* btree_h */
