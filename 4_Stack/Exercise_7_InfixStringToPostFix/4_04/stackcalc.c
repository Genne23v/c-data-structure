//
//  stackcalc.c
//  4_04
//
//  Created by Wonkeun No on 2020-04-01.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprdef.h"
#include "exprlinkedstack.h"
#include "stackcalc.h"

int pushLinkedStackExprToken(LinkedStack* pStack, ExprToken data) {
    StackNode node = {0,};
    node.data = data;
    return pushLinkedStack(pStack, node);
}
void calcExpr(ExprToken *pExprTokens, int tokenCount) {
    LinkedStack *pStack = NULL;
    StackNode *pNode1 = NULL, *pNode2 = NULL;   //피연산자 2개용 포인터
    Precedence tokenType;       //enum값을 정의한 구조체. 연산자 & 피연산자 모두
    int i=0;
    if (pExprTokens == NULL) {
        return;
    }
    pStack = createLinkedStack();
    if (pStack != NULL)  {
        for (i=0; i<tokenCount; i++) {
            tokenType = pExprTokens[i].type;
            
            if (tokenType == operand) {
                pushLinkedStackExprToken(pStack, pExprTokens[i]);
            } else {
                pNode2 = popLinkedStack(pStack);
                if (pNode2 != NULL) {
                    pNode1 = popLinkedStack(pStack);
                    if (pNode1 != NULL) {
                        float op1 = pNode1->data.value;
                        float op2 = pNode2->data.value;
                        
                        ExprToken newToken;     //이 구조체는 왜???
                        newToken.type = operand;
                        switch(tokenType) {
                            case plus:      //영단어로 써도 연산자 인식???
                                newToken.value = op1 + op2;
                                break;
                            case minus:
                                newToken.value = op1 - op2;
                                break;
                            case times:
                                newToken.value = op1 * op2;
                                break;
                            case divide:
                                newToken.value = op1 / op2;
                                break;
                        }
                        pushLinkedStackExprToken(pStack, newToken);     //value가 아니라 구조체로 반환?
                        free(pNode1);
                }
                    free(pNode2);
                }
                } //end-of=else
        }
            pNode1 = popLinkedStack(pStack);
                 if (pNode1 != NULL) {
                     printf("수식 계산 결과[%f]\n", pNode1->data.value);
                     free(pNode1);
                 }else {
                     printf("오류, 수식에 오류가 있습니다\n");
                 }
                 deleteLinkedStack(pStack);
    }
}
void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount) {
    LinkedStack *pStack = NULL;
    StackNode *pNode = NULL;
    Precedence tokenType;
    Precedence inStackTokenType;
    int i=0;
    
    if (pExprTokens == NULL) return;
    
    pStack = createLinkedStack();
    if (pStack != NULL) {
        for (i=0; i<tokenCount; i++) {
            tokenType = pExprTokens[i].type;
            switch(tokenType) {
                case operand:
                    printf("%f\n", pExprTokens[i].value);
                    break;
                    
                case rparen:
                    pNode = popLinkedStack(pStack);     //닫는 괄호면 팝 시키면 닫는 괄호만 pNode에 들어가는데 프린트 할게 있나???
                    while (pNode != NULL && pNode->data.type != lparen) {
                        printToken(pNode->data);
                        free(pNode);
                        
                        pNode = popLinkedStack(pStack);     //계속 팝 시킨다
                    }
                    if (pNode != NULL) free(pNode);
                    break;
                    default:
                    while (isLinkedStackEmpty(pStack) == FALSE) {
                        inStackTokenType = peekLinkedStack(pStack)->data.type;
                        //스택 안에서는 닫는 괄호, */, +-, 여는 괄호순으로 높고 스택 밖에서는 (), */, +-순
                        if (outStackPrecedence(tokenType) <= inStackPrecedence(inStackTokenType)) {
                            pNode = popLinkedStack(pStack);
                            if (pNode != NULL) {
                                printToken(pNode->data);
                                free(pNode);
                            }
                        }else {
                            break;
                        }
                    }
                    pushLinkedStackExprToken(pStack, pExprTokens[i]);   //어떻게 현재 연산자가 됨?
                    break;
            }//End-of-switch
        } //End-of-for
        while (isLinkedStackEmpty(pStack) == FALSE) {
            pNode = popLinkedStack(pStack);
            if (pNode != NULL) {
                printToken(pNode->data);
                free(pNode);
            }
        }
        deleteLinkedStack(pStack);
    }
}
int inStackPrecedence(Precedence oper) {
    switch (oper) {
        case lparen:
            return 0;
        case rparen:
            return 4;
        case divide:
            return 2;
        case plus:
        case minus:
            return 1;
    }
    return -1;
}
int outStackPrecedence(Precedence oper) {
    switch(oper) {
        case lparen:
            return 5;
        case rparen:
            return 4;
        case times:
        case divide:
            return 2;
        case plus:
        minus:
            return 1;
    }
    return -1;
}
void printToken(ExprToken element) {
    switch(element.type) {
        case lparen:
            printf("(\n");
            break;
        case rparen:
            printf(")\n");
            break;
        case plus:
            printf("+\n");
            break;
        case minus:
            printf("-\n");
            break;
        case times:
            printf("*\n");
            break;
        case divide:
            printf("/\n");
            break;
        case operand:
            printf("%f\n", element.value);
            break;
    }
}
