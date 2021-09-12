//
//  linkedgraph.h
//  8_02
//
//  Created by Wonkeun No on 2020-04-20.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef linkedgraph_h
#define linkedgraph_h
#include "graphlinkedlist.h"

typedef struct LinkedGraphType {
    int maxVertexCount;
    int currentVertexCount;
    int currentEdgeCount;
    int graphType;
    LinkedList** ppAdjEdge;
    int *pVertex;
}LinkedGraph;

LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);
void deleteLinkedGraph(LinkedGraph* pGraph);
int isEmptyLinkedGraph(LinkedGraph* pGraph);
int addVertexLinkedGraph(LinkedGraph* pGraph, int vertexID);
int addEdgeLinkedGraph(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgeWithWeightedLinkedGraph(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);
int checkVertexValid(LinkedGraph* pGraph, int vertexID);
int removeVertexLinkedGraph(LinkedGraph* pGraph, int vertexID);
int removeEdgeLinkedGraph(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedList* pList, int delVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID);
void displayLinkedGraph(LinkedGraph* pGraph);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED 1
#define NOT_USED 0

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAIL 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2

#endif /* linkedgraph_h */

