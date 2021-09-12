//
//  stackcalc.h
//  4_04
//
//  Created by Wonkeun No on 2020-04-01.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef stackcalc_h
#define stackcalc_h

void calcExpr(ExprToken *pExprTokens, int tokenCount);
int pushLinkedStackExprToken(LinkedStack* pStack, ExprToken data);
void convertInfixToPostfix(ExprToken *pExprtokens, int tokenCount);
int inStackPrecedence(Precedence oper);
int outStackPrecedence(Precedence oper);
void printToken(ExprToken element);

#endif /* stackcalc_h */
