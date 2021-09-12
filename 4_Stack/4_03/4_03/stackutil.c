//
//  main.c
//  4_03
//
//  Created by Wonkeun No on 2020-04-01.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackutil.h"
#include "linkedstack.h"

char* reverseString(char *pSource) {
    char* pReturn = NULL;
    int i = 0, size = 0;
    LinkedStack *pStack = NULL;
    StackNode *pNode = NULL;
    
    if (pSource == NULL) {
        return NULL;
    }
    size = strlen(pSource);
    if (size == 0) {
        return NULL;
    }
    pReturn = (char*)malloc(sizeof(char)*(size+1));
    if (pReturn == NULL) {
        printf("오류, 메모리 할당, reverseString()\n");
        return NULL;
    }
    pStack = createLinkedStack();
    if (pStack != NULL) {
        StackNode node;
        for (i=0; i<size; i++) {
            node.data = pSource[i];
            pushLinkedStack(pStack, node);
        }
        for (i=0; i<size; i++) {            //이렇게 해도 역순이 됨??
            pNode = popLinkedStack(pStack);
            if (pNode != NULL) {
                pReturn[i] = pNode->data;
                free(pNode);
            }
        }
        pReturn[i] = '\0';              //어떻게 마지막이 됨??
        deleteLinkedStack(pStack);
    } else {
        if (pReturn != NULL) {
            free(pReturn);
            pReturn = NULL;         //C에서는 메모리 해제한다고 해서 포인터 변수 값에 어떤 값을 대입하지 않아 쓰레기 값이 남아 있을 수 있음. 리턴값을 NULL로 처리하여 포인터 변수에 남아 있는 쓰레기 값으로 인한 문제가 생기지 않게 한다
        }
    }
    return pReturn;
}
int checkBracketMatching(char *pSource) {
    int ret = TRUE, i = 0, size = 0;
    char symbol = '\0', checkSymbol = '\0';
    LinkedStack *pStack = NULL;
    StackNode *pNode = NULL;
    
    if (pSource == NULL) {
        ret = TRUE;
        return ret;
    }
    size = strlen(pSource);
    //NULL 점검하고 0인지도 점검???
    if (size == 0) {
        ret = TRUE;
        return ret;
    }
    pStack = createLinkedStack();
    if (pStack != NULL) {
        StackNode node;
        //수식 문자열을 한 글자씩 읽어 FALSE이면 수식 오류로 루프를 빠져나감
        for (i=0; i<size && ret == TRUE; i++) {
            symbol = pSource[i];
            switch(symbol) {
                case '(':
                case '[':
                case '{':
                    node.data = symbol;     //굳이 여기다 넣어야 함?
                    pushLinkedStack(pStack, node);  //여는 괄호는 푸시
                    break;
                case ')':
                case ']':
                case '}':
                    pNode = popLinkedStack(pStack);     //닫는 괄호는 팝
                    if (pNode == NULL) {
                        ret = FALSE;        //널문자도 NULL로 인식?
                        break;
                    } else {
                        checkSymbol = pNode->data;      //결국은 같은 구조체안에 데이터?
                        if ((symbol == ')' && checkSymbol == '(') || (symbol == ']' && checkSymbol == '[') || (symbol == '}' && checkSymbol == '{')) {
                            ret = TRUE;
                            //Right case. Do nothing
                        } else {
                            ret = FALSE;
                        }
                        free(pNode);
                    }
                    break;
            }   //end of switch
        }   //end of for
        if (isLinkedStackEmpty(pStack) == FALSE) {
            ret = FALSE;
        }
        deleteLinkedStack(pStack);
    } else {
        printf("오류, LinkedStack이 NULL입니다, checkBracketMatching()\n");
        ret = FALSE;
    }
    return ret;
}
