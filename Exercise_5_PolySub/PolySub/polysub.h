//
//  polysub.h
//  PolySub
//
//  Created by Wonkeun No on 2020-05-02.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef polysub_h
#define polysub_h

#include <stdio.h>
#include "linkedlist.h"

int addPolyNodeLast(LinkedList* pList, int coef, int degree);
LinkedList* polySubtract(LinkedList* pListA, LinkedList* pListB);
void displayPolyList(LinkedList* pList);

#define TRUE 1
#define FALSE 0

#endif /* polysub_h */
