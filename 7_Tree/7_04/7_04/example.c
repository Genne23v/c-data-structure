//
//  main.c
//  7_04
//
//  Created by Wonkeun No on 2020-04-17.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "bintreeop.h"

BinTree* createExampleBinTree(void);

int main(int argc, const char * argv[]) {

    int compareResult = FALSE;
    int count = 0;
    BinTree* pBinTree = NULL, *pCopyBinTree = NULL;
    
    pBinTree = createExampleBinTree();
    printf("이진 트리 원본:\n");
    displayBinTree(pBinTree);
    
    pCopyBinTree = copyBinTree(pBinTree);
    printf("이진 트리 복사본:\n");
    displayBinTree(pCopyBinTree);
    
    compareResult = equalBinTree(pBinTree, pCopyBinTree);
    printf("\n이진 트리 비교 결과: (%d)\n", compareResult);
    
    count = getNodeCountBinTree(pBinTree);
    printf("\n이진 트리 노드 개수: %d\n", count);
    
    count = getLeafNodeCountBinTree(pBinTree);
    printf("\n이진 트리 단말 노드 개수: %d\n", count);
    
    count = getHeightBinTree(pBinTree);
    printf("\n이진 트리의 높이: %d\n", count);
    
    deleteBinTree(pBinTree);
    deleteBinTree(pCopyBinTree);
    
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
    
