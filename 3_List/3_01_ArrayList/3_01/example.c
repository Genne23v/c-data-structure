//
//  example.c
//  3_01
//
//  Created by Wonkeun No on 2020-03-26.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"

int main(int argc, char *argv[]) {
    int i=0;
    int arrayCount = 0;
    ArrayList *pList = NULL;
    ArrayListNode *pValue = NULL;
    //최대 원소 개수가 6개인 배열 리스트를 생성하고 리스트가 정상적으로 생성되었는지 점검
    pList = createArrayList(6);
    if (pList != NULL) {
        ArrayListNode node;     //구조체 필드값 새로 생성
        // 리스트 초기화: 1, 3, 5 추가
        node.data = 1;
        addAElement(pList, 0, node);
        
        node.data = 3;
        addAElement(pList, 1, node);
        
        node.data = 5;
        addAElement(pList, 2, node);
        displayArrayList(pList);
        
        //첫번째 원소 제거
        removeAElement(pList, 0);
        displayArrayList(pList);
        
        arrayCount = getArrayListLength(pList);
        for(i=0; i<arrayCount; i++) {
            pValue = getAElement(pList, i);
            printf("위치 [%d]-%d\n", i, pValue->data);
        }
        deleteArrayList(pList);
    }
    return 0;
}
