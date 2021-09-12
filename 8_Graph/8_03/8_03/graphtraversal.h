//
//  graphtraversal.h
//  8_03
//
//  Created by Wonkeun No on 2020-04-21.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef graphtraversal_h
#define graphtraversal_h

#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include <stdio.h>

void traversalDepthFirstSearch(LinkedGraph* pGraph, int startVertexID);
void traversalBreadthFirstSearch(LinkedGraph* pGraph, int startVertexID);

#endif /* graphtraversal_h */
