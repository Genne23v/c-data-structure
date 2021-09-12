;//
//  arraygraph.h
//  8_01
//
//  Created by Wonkeun No on 2020-04-19.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef arraygraph_h
#define arraygraph_h

#include <stdio.h>

typedef struct ArrayGraphType {
    int maxVertexCount;
    int currentVertexCount;
    int graphType;
    int **ppAdjEdge;        //간선 저장을 위한 2차원 배열
    int *pVertex;           //노드 저장을 위한 1차원 배열
}ArrayGraph;

ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);
void deleteArrayGraph(ArrayGraph* pGraph);
int checkVertexValid(ArrayGraph* pGraph, int vertexID);
int isEmptyArrayGraph(ArrayGraph* pGraph);
int addVertexArrayGraph(ArrayGraph* pGraph, int vertexID);
int addEdgeArrayGraph(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgeWithWeightedArrayGraph(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);
int removeVertexArrayGraph(ArrayGraph* pGraph, int vertexID);
int removeEdgeArrayGraph(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
void displayArrayGraph(ArrayGraph* pGraph);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0

#define TRUE 1
#define FALSE 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2

#endif /* arraygraph_h */
