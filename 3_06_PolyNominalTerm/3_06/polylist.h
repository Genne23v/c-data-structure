//
//  polylist.h
//  3_06
//
//  Created by Wonkeun No on 2020-03-29.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef polylist_h
#define polylist_h

int addPolyNodeLast(LinkedList* pList, float coef, int degree);
LinkedList* polyAdd(LinkedList* pListA, LinkedList* pListB);
void displayPolyList(LinkedList* pList);

#endif /* polylist_h */
