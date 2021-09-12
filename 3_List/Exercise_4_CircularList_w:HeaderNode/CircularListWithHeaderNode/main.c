//
//  main.c
//  CircularListWithHeaderNode
//
//  Created by Wonkeun No on 2020-04-30.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

int main(int argc, const char * argv[]) {
    CircularList* pList = createCircularList();
    CircularNode node = {0, };
    
    node.data = 79;
    addCircularListElement(pList, 0, node);
    node.data = 86;
    addCircularListElement(pList, 1, node);
    node.data = 15;
    addCircularListElement(pList, 0, node);
    node.data = 19;
    addCircularListElement(pList, 1, node);
    node.data = 53;
    addCircularListElement(pList, 4, node);

    displayCircularList(pList);
    
    removeCircularListElement(pList, 0);
    removeCircularListElement(pList, 2);
    removeCircularListElement(pList, 1);
    removeCircularListElement(pList, 1);
    //removeCircularListElement(pList, 0);
    
    displayCircularList(pList);
    
    deleteCircularList(pList);
    
    return 0;
}
