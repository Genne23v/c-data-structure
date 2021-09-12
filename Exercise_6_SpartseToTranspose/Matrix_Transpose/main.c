//
//  main.c
//  Matrix_Transpose
//
//  Created by Wonkeun No on 2020-04-12.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct TermType {
    int row;
    int col;
    int value;
    struct TermType* pLink;
}Term;

typedef struct TermManage {
     int currentElementCount;
    Term* pLink;
}TermManagingData;

TermManagingData* createInitialList() {
    TermManagingData* pList = NULL;
    
    pList = (TermManagingData*)malloc(sizeof(TermManagingData));
    if (pList != NULL) {
        memset(pList, 0, sizeof(pList));
    } else {
        printf("createInitiaList(), failed to allocate memory\n");
    }
    return pList;
};
Term *transposing(Term* pMatrixA, TermManagingData* pList, int maxColumn);

int main(void) {
    int temp =0;
    int maxColumn =0, maxRow =0;
    int i =0, j =0;
    
    TermManagingData* pList = NULL;
    pList = createInitialList();
    
    printf("Input columns/rows of the matrix : ");
    scanf("%d\n", &maxColumn);
    maxRow = maxColumn;
    
    Term* pMatrixA = NULL;
    pMatrixA = (Term*)malloc(sizeof(Term*));
    
    if (pMatrixA != NULL) {
        memset(pMatrixA, 0, sizeof(pMatrixA));
    for (i=0; i < maxRow; i++) {
        for (j=0; j < maxColumn; j++) {
            printf("What is the value? : ");
            scanf("%d\n", &temp);
            if (temp != 0) {
                pMatrixA->row = i;
                pMatrixA->col = j;
                pMatrixA->value = temp;
                pList->currentElementCount++;
                pMatrixA = pMatrixA->pLink;
            }else {
                    //Do Nothing
                }
        }
    }
    }
        //{ { 6,6,8 },{ 0,0,15 },{ 0,3,22 },{ 0,5,-15 },{ 1,1,11 },{ 1,2,3 },{ 2,3,-6 },{ 4,0,91 },{ 5,2,28 } };
    
    Term* pMatrixB = transposing(pMatrixA, pList, maxRow);
    
    for (i=0; i <pList->currentElementCount; i++) {
        printf("{%d, %d, %d}\n", pMatrixA[i].row, pMatrixA[i].col, pMatrixA[i].value);
    }
    for (i=0; i <pList->currentElementCount; i++) {
        printf("{%d, %d, %d}\n", pMatrixB[i].row, pMatrixB[i].col, pMatrixB[i].value);
    }
}

Term *transposing(Term* pMatrixA, TermManagingData* pList, int maxRow) {

    //처음 부분이니 여러가지를 선언해서 세팅을 해줍시다.
    // 위의 col_Count는 여기서 rowTerms로 표현했습니다.
    int* pRowTerms = NULL;
    int* pStartPoint = NULL;
    Term* pMatrixB = NULL;
    
    pRowTerms = (int*)malloc(sizeof(int)*maxRow);
    pStartPoint = (int*)malloc(sizeof(int)*maxRow);
    
    if (pRowTerms != NULL && pStartPoint != NULL) {
    /*
     pMatrixB[0].col = pMatrixA[0].row;
    pMatrixB[0].row = pMatrixA[0].col;
    pMatrixB[0].value = pMatrixA[0].value;
    */
    //get rowTerm

    for (int i = 0; i < pList->currentElementCount; i++) {
        pRowTerms[pMatrixA[i].col]++;
    }
    
    //get startpoint

    pStartPoint = 0;
    for (int i = 0; i <pList->currentElementCount; i++) {
        pStartPoint[i] = pStartPoint[i - 1] + pRowTerms[i - 1];
    }
    }
    //transport to B

    for (int i = 0; i < pList->currentElementCount; i++) {
        int j = pStartPoint[pMatrixA[i].col]++;

        pMatrixB[j].row = pMatrixA[i].col;
        pMatrixB[j].col = pMatrixA[i].row;
        pMatrixB[j].value = pMatrixA[i].value;
    }
    return pMatrixB;
}
