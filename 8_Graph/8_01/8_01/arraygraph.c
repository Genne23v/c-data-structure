//
//  arraygraph.c
//  8_01
//
//  Created by Wonkeun No on 2020-04-19.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraygraph.h"

ArrayGraph* createArrayGraph(int maxVertexCount) {
    int i=0, j=0;
    ArrayGraph* pReturn = NULL;
    
    if (maxVertexCount > 0) {
        pReturn = (ArrayGraph*)malloc(sizeof(ArrayGraph));
        if (pReturn == NULL) {
            printf("오류, 메모리할당(1), in createArrayGraph()\n");
            return NULL;
        }
        pReturn->graphType = GRAPH_UNDIRECTED;
        pReturn->maxVertexCount = maxVertexCount;
    } else {
        printf("오류, 최대 노드 개수는 0보다 커야합니다\n");
        return NULL;
    }
    pReturn->pVertex = (int*)malloc(sizeof(int)*maxVertexCount);
    if (pReturn->pVertex == NULL) {
        printf("오류, 메모리할당(2), in createArrayGraph()\n");
        if (pReturn != NULL) free(pReturn);
        return NULL;
    }
    pReturn->ppAdjEdge = (int**)malloc(sizeof(int*)*maxVertexCount);
    if (pReturn->ppAdjEdge == NULL) {
        printf("오류, 메모리할당(3), in createArrayGraph()\n");
        if (pReturn->pVertex != NULL) free(pReturn->pVertex);
        if (pReturn != NULL) free(pReturn);
        return NULL;
    }
    for (i=0; i<maxVertexCount; i++) {
        pReturn->ppAdjEdge[i] = (int*)malloc(sizeof(int)*maxVertexCount);
        if (pReturn->ppAdjEdge[i] == NULL) {
            printf("오류, 메모리할당(4), in createArrayGraph()\n");        //함수 오류시 메모리 반환(왜 j까지?)
            for (j=0; j<i-1; j++) {
                if (pReturn->ppAdjEdge[j] != NULL) free(pReturn->ppAdjEdge[j]);
            }
            if (pReturn->ppAdjEdge != NULL) free(pReturn->ppAdjEdge);
            if (pReturn->pVertex != NULL) free(pReturn->pVertex);
            if (pReturn != NULL) free(pReturn);
            return NULL;
        }
    }
    memset(pReturn->pVertex, NOT_USED, sizeof(int)*maxVertexCount);
    for (i=0; i<maxVertexCount; i++) {
        memset(pReturn->ppAdjEdge[i], 0, sizeof(int)*maxVertexCount);
    }
    return pReturn;
}
ArrayGraph* createArrayDirectedGraph(int maxVertexGraph) {
    ArrayGraph* pReturn = NULL;
    pReturn = createArrayGraph(maxVertexGraph);
    if (pReturn != NULL) {
        pReturn->graphType = GRAPH_DIRECTED;
    }
    return pReturn;
}
int addVertexArrayGraph(ArrayGraph* pGraph, int VertexID) {
    int ret = SUCCESS;
    
    if (pGraph != NULL) {
        if (VertexID < pGraph->maxVertexCount) {
            if (pGraph->pVertex[VertexID] == NOT_USED) {
                pGraph->pVertex[VertexID] = USED;
                pGraph->currentVertexCount++;
            } else {
                printf("오류, 이미 존재하는 노드 [%d], in addVertexArrayGraph()\n", VertexID);
                ret = FAIL;
            }
        } else {
            printf("오류, 최대 노드 개수 초과 [%d], in addVertexArrayGraph()\n", pGraph->maxVertexCount);
            ret = FAIL;
        }
    }
    return ret;
}
int addEdgeWithWeightedArrayGraph(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight) {
    int ret = SUCCESS;
    
    if (pGraph != NULL) {
        if (checkVertexValid(pGraph, fromVertexID) != SUCCESS) {
            ret = FAIL;
            return ret;
        }
        if (checkVertexValid(pGraph, toVertexID) != SUCCESS) {
            ret = FAIL;
            return ret;
    }
        pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
        if (pGraph->graphType == GRAPH_UNDIRECTED) {
            pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
        }
}
    return ret;
}
int checkVertexValid(ArrayGraph* pGraph, int vertexID) {
    int ret = SUCCESS;
    
    if (vertexID >= pGraph->maxVertexCount || pGraph->pVertex[vertexID] == NOT_USED) {
        printf("오류, 노드 정보 [%d]\n", vertexID);
        ret = FAIL;
    }
    return ret;
}
int addEdgeArrayGraph(ArrayGraph* pGraph, int fromVerTexID, int toVertexID) {
    return addEdgeWithWeightedArrayGraph(pGraph, fromVerTexID, toVertexID, USED);
}
int removeEdgeArrayGraph(ArrayGraph* pGraph, int fromVertexID, int toVertexID) {
    int ret = SUCCESS;
    
    if (pGraph != NULL) {
        if (checkVertexValid(pGraph, fromVertexID) != SUCCESS) {
            ret = FAIL;
            return ret;
        }
        if (checkVertexValid(pGraph, toVertexID) != SUCCESS) {
            ret = FAIL;
            return ret;
        }
        pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
        
        if (pGraph->graphType == GRAPH_UNDIRECTED) {
            pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
        }
    }
    return ret;
}
int removeVertexArrayGraph(ArrayGraph* pGraph, int vertexID) {
    int ret = SUCCESS;
    int i=0;
    
    if (pGraph != NULL) {
        if (checkVertexValid(pGraph, vertexID) != SUCCESS) {
            ret = FAIL;
            return ret;
        }
        for (i=0; i<pGraph->maxVertexCount; i++) {
            removeEdgeArrayGraph(pGraph, vertexID, i);
            removeEdgeArrayGraph(pGraph, i, vertexID);
        }
        pGraph->pVertex[vertexID] = NOT_USED;
    }
    return ret;
}
int isEmptyArrayGraph(ArrayGraph* pGraph) {
    int ret = FALSE;
    if (pGraph->currentVertexCount == 0) {
        ret = TRUE;
    }
    return ret;
}
void displayArrayGraph(ArrayGraph* pGraph) {
    int i=0, j=0, count = pGraph->currentVertexCount;
    
    for (i=0; i<count; i++) {
        for (j=0; j<count; j++) {
            printf("%d\t", pGraph->ppAdjEdge[i][j]);
    }
        printf("\n");
    }
}
void deleteArrayGraph(ArrayGraph* pGraph) {
    int i, j = 0;
    int count = pGraph->maxVertexCount;
    if (pGraph != NULL) {
    for (i=0; i<count; i++) {
            free(pGraph->pVertex);
        }
    free(pGraph);
}
}
