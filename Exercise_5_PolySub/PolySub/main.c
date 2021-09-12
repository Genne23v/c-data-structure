//
//  main.c
//  PolySub
//
//  Created by Wonkeun No on 2020-04-30.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#include "polysub.h"

int main(int argc, const char * argv[]) {
   
    LinkedList* pListA = createLinkedList();
    LinkedList* pListB = createLinkedList();
    
    addPolyNodeLast(pListA, 6, 6);
    addPolyNodeLast(pListA, 4, 5);
    addPolyNodeLast(pListA, 2, 2);
    addPolyNodeLast(pListB, 1, 5);
    addPolyNodeLast(pListB, 2, 4);
    addPolyNodeLast(pListB, 3, 2);
    addPolyNodeLast(pListB, 4, 0);
    displayPolyList(pListA);
    displayPolyList(pListB);
    
    LinkedList* pListC = polySubtract(pListA, pListB);
    if (pListC != NULL) {
        displayPolyList(pListC);
        deleteLinkedList(pListC);
    }
    deleteLinkedList(pListA);
    deleteLinkedList(pListB);
/*
    setlocale(LC_CTYPE, "");

    wchar_t *foo = L"²";
    wprintf(L"%ls\n", foo);

    wprintf(L"²\n");

    wchar_t bar[2];
    bar[0] = 178;
    bar[1] = 0;
    wprintf(L"%ls\n", bar);
    */
    
    return 0;
}

