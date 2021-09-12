//
//  main.c
//  8_03
//
//  Created by Wonkeun No on 2020-04-21.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "graphtraversal.h"

int main(int argc, const char * argv[]) {
    int i=0;
    LinkedGraph* pG1 = NULL;
    
    pG1 = createLinkedGraph(8);
    if (pG1 != NULL) {
        for (i=0; i<8; i++) {
            addVertexLinkedGraph(pG1, i);
        }
        addEdgeLinkedGraph(pG1, 0, 1);
        addEdgeLinkedGraph(pG1, 0, 2);
        addEdgeLinkedGraph(pG1, 1, 3);
        addEdgeLinkedGraph(pG1, 1, 4);
        addEdgeLinkedGraph(pG1, 2, 5);
        addEdgeLinkedGraph(pG1, 2, 6);
        addEdgeLinkedGraph(pG1, 3, 7);
        addEdgeLinkedGraph(pG1, 4, 5);
        
        printf("G1: \n");
        displayLinkedGraph(pG1);
        
        printf("\nDepth First Search Traversal:\n");
        traversalDepthFirstSearch(pG1, 0);
        
        deleteLinkedGraph(pG1);
    }
    return 0;
}
