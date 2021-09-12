av//
//  Header.h
//  10_6
//
//  Created by Wonkeun No on 2020-04-26.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef Header_h
#define Header_h

#define VALUE_SIZE 100

typedef struct AVLTreeNodeDataType {
    int key;
    char value[VALUE_SIZE + 1];
}AVLTreeNodeData;

typedef struct AVLTreeNodeType {
    AVLTreeNodeData data;
    int balance;
    int height;
    struct AVLTreeNodeType* pLeftChild;
    struct AVLTreeNodeType* pRightChild;
}AVLTreeNode;

#endif /* Header_h */
