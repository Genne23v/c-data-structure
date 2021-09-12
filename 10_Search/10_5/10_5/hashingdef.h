//
//  Header.h
//  10_5
//
//  Created by Wonkeun No on 2020-04-25.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef Header_h
#define Header_h

#define HASH_KEY_SIZE 10

typedef struct HashElementType {
    char key[HASH_KEY_SIZE + 1];
    int value;
}HashElement;

#endif /* Header_h */
