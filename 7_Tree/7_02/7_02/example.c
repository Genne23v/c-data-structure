//
//  main.c
//  7_02
//
//  Created by Wonkeun No on 2020-04-15.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "bintreetraversalrec.h"

BinTree* createExampleBinTree(void);

int main(int argc, const char * argv[]) {
    BinTree* pBinTree = NULL;
    pBinTree = createExampleBinTree();
    if (pBinTree != NULL) {
        printf("Preorder Recursive Traversal\n");
        preorderTraversalRecursiveBinTree(pBinTree);
        
        printf("\nInorder Recursive Traversal\n");
        inorderTraversalRecursiveBinTree(pBinTree);
        
        printf("\nPostorder Recursive Traversal\n");
        postorderTraversalRecursiveBinTree(pBinTree);
        
        deleteBinTree(pBinTree);
    }
    return 0;
}
BinTree* createExampleBinTree() {
    BinTree* pReturn = NULL;
    BinTreeNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
    BinTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;
    BinTreeNode *pNodeG = NULL, *pNodeH = NULL, *pNodeI = NULL;
    BinTreeNode *pNodeJ = NULL, *pNodeK = NULL, *pNodeL = NULL, *pNodeM = NULL;
    BinTreeNode node = {0,};
    
    node.data = 'A';
    pReturn = makeBinTree(node);
    
    if (pReturn != NULL) {
        pNodeA = getRootNodeBinTree(pReturn);
        
        node.data = 'B';
        pNodeB = insertLeftChildNodeBinTree(pNodeA, node);
        node.data = 'C';
        pNodeC = insertRightChildNodeBinTree(pNodeA, node);
        
        node.data = 'D';
        pNodeD = insertLeftChildNodeBinTree(pNodeB, node);
        node.data = 'E';
        pNodeE = insertRightChildNodeBinTree(pNodeB, node);
        
        node.data = 'F';
        pNodeF = insertLeftChildNodeBinTree(pNodeC, node);
        node.data = 'G';
        pNodeG = insertRightChildNodeBinTree(pNodeC, node);
        
        node.data = 'H';
        pNodeH = insertLeftChildNodeBinTree(pNodeD, node);
        node.data = 'I';
        pNodeI = insertRightChildNodeBinTree(pNodeD, node);
        
        node.data = 'J';
        pNodeJ = insertLeftChildNodeBinTree(pNodeE, node);
        
        node.data = 'K';
        pNodeK = insertRightChildNodeBinTree(pNodeF, node);
        
        node.data = 'L';
        pNodeL = insertLeftChildNodeBinTree(pNodeG, node);
        node.data = 'M';
        pNodeM = insertRightChildNodeBinTree(pNodeG, node);
    }
    
    return pReturn;
}
