//
//  btreedef.h
//  10_7
//
//  Created by Wonkeun No on 2020-04-27.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef btreedef_h
#define btreedef_h

#define BTREE_ORDER 5

typedef struct BTreeNodeDataType {
    int key;
    char value;
}BTreeNodeData;

typedef struct BTreeNodeType {
    int elementcount;
    BTreeNodeData element[BTREE_ORDER];
    struct BTTreeNodeType* pChildren[BTREE_ORDER + 1];
}BTreeNode;

#endif

#ifndef _COMMON_BTREE_DEF_

#define TRUE 1
#define FALSE 0

#endif /* btreedef_h */
