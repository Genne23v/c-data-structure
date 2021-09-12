//
//  example.c
//  4_03
//
//  Created by Wonkeun No on 2020-04-01.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"
#include "stackutil.h"

int main(int argc, char *argv[]) {
    char sourceStr[] = "ABCDEFGHIJKLMOPQRSTUVWXYZ";
    char successExpreStr[] = "((A * B) / C) - {(D + E) && (F - G)}";
    char failExpreStr[] = "((A * B) / C - {(D + E) && (F = G)))";
    int checkResult = 0;
    
    char *pReverseStr = reverseString(sourceStr);
    if (pReverseStr != NULL) {
        printf("[%s] => [%s]\n", sourceStr, pReverseStr);
        free(pReverseStr);
    }
    checkResult = checkBracketMatching(successExpreStr);
    if (checkResult == TRUE) {
        printf("SUCCESS, %s\n", successExpreStr);
    } else {
        printf("FAIL, %s\n", successExpreStr);      
    }
    checkResult = checkBracketMatching(failExpreStr);
    if (checkResult == TRUE) {
        printf("SUCCESS, %s\n", failExpreStr);
    } else {
        printf("FAIL, %s\n", failExpreStr);
    }
    return 0;
}
