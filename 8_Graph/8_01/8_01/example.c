//
//  main.c
//  8_01
//
//  Created by Wonkeun No on 2020-04-19.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "arraygraph.h"

int main(int argc, const char * argv[]) {
    int i=0;
    ArrayGraph* pG1 = NULL;
    ArrayGraph* pG2 = NULL;
    ArrayGraph* pG4 = NULL;
    
    pG1 = createArrayGraph(6);
    pG2 = createArrayDirectedGraph(6);
    pG4 = createArrayDirectedGraph(6);
    
    if (pG1 != NULL && pG2 != NULL && pG4 != NULL) {
        for (i=0; i<6; i++) {
            addVertexArrayGraph(pG1, i);
            addVertexArrayGraph(pG2, i);
            addVertexArrayGraph(pG4, i);
        }
        addEdgeArrayGraph(pG1, 0, 1);
        addEdgeArrayGraph(pG1, 0, 2);
        addEdgeArrayGraph(pG1, 1, 2);
        addEdgeArrayGraph(pG1, 2, 3);
        addEdgeArrayGraph(pG1, 3, 4);
        addEdgeArrayGraph(pG1, 3, 5);
        addEdgeArrayGraph(pG1, 4, 5);
        addEdgeArrayGraph(pG2, 0, 1);
        addEdgeArrayGraph(pG2, 1, 2);
        addEdgeArrayGraph(pG2, 2, 0);
        addEdgeArrayGraph(pG2, 2, 1);
        addEdgeArrayGraph(pG2, 2, 3);
        addEdgeArrayGraph(pG2, 3, 2);
        addEdgeArrayGraph(pG2, 3, 4);
        addEdgeArrayGraph(pG2, 4, 5);
        addEdgeArrayGraph(pG2, 5, 3);
        addEdgeWithWeightedArrayGraph(pG4, 0, 1, 4);
        addEdgeWithWeightedArrayGraph(pG4, 1, 2, 1);
        addEdgeWithWeightedArrayGraph(pG4, 2, 0, 2);
        addEdgeWithWeightedArrayGraph(pG4, 2, 1, 3);
        addEdgeWithWeightedArrayGraph(pG4, 2, 3, 2);
        addEdgeWithWeightedArrayGraph(pG4, 3, 2, 1);
        addEdgeWithWeightedArrayGraph(pG4, 3, 4, 1);
        addEdgeWithWeightedArrayGraph(pG4, 4, 5, 1);
        addEdgeWithWeightedArrayGraph(pG4, 5, 3, 2);
    
        printf("G1: Undirected\n");
        displayArrayGraph(pG1);
        printf("\nG2: Directed\n");
        displayArrayGraph(pG2);
        printf("\nG4: Directed Weighted\n");
        displayArrayGraph(pG4);

        deleteArrayGraph(pG1);
        deleteArrayGraph(pG2);
        deleteArrayGraph(pG4);
    }
    return 0;
}
