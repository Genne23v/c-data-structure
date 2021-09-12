//
//  main.c
//  7_01
//
//  Created by Wonkeun No on 2020-04-15.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main(int argc, const char * argv[]) {
    BinTree* pBinTree = NULL;
    BinTreeNode* pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
    BinTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;
    BinTreeNode node = {0,};
    
    node.data ='A';
    pBinTree = makeBinTree(node);
    if (pBinTree != NULL) {
        pNodeA = getRootNodeBinTree(pBinTree);
        
        node.data = 'B';
        pNodeB = insertLeftChildNodeBinTree(pNodeA, node);
        
        node.data = 'C';
        pNodeC = insertRightChildNodeBinTree(pNodeA, node);
        
        if (pNodeB != NULL) {
            node.data = 'D';
            pNodeD = insertLeftChildNodeBinTree(pNodeB, node);
        }
        if (pNodeC != NULL) {
            node.data = 'E';
            pNodeE = insertLeftChildNodeBinTree(pNodeC, node);
            
            node.data = 'F';
            pNodeF = insertRightChildNodeBinTree(pNodeC, node);
        }
        deleteBinTree(pBinTree);
    }
    return 0;
}
