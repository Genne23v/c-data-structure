//
//  maputil.h
//  4_05
//
//  Created by Wonkeun No on 2020-04-02.
//  Copyright © 2020 genne. All rights reserved.
//

#ifndef maputil_h
#define maputil_h

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLinkedStackMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack* pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);

#endif /* maputil_h */
