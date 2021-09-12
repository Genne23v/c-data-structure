//
//  mapdef.h
//  4_05
//
//  Created by Wonkeun No on 2020-04-02.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef mapdef_h
#define mapdef_h

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 8

//1개의 인스턴스를 가지도록 static으로 선언. 그렇지 않으면 다른 파일에서 참조하기 불편함
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
    {0,1}, {1,0}, {0,1}, {-1,0}     //0 is upward, 1 is right, 2 is downward, 3 is left
};

enum PosStatus {NOT_VISIT = 0, WALL = 1, VISIT = 2};

typedef struct MapPositionType {
    int x, y;
    int direction;
} MapPosition;

#endif /* mapdef_h */
