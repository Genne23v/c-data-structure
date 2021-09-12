//
//  exprdef.h
//  4_04
//
//  Created by Wonkeun No on 2020-04-01.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef exprdef_h
#define exprdef_h

typedef enum PrecedenceType {
    lparen, rparen, times, divide, plus, minus, operand
}Precedence;

typedef struct ExprTokenType {
    float value;
    Precedence type;
}ExprToken;

#endif /* exprdef_h */
