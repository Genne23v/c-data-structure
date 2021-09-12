//
//  maputil.c
//  4_05
//
//  Created by Wonkeun No on 2020-04-02.
//  Copyright © 2020 genne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "mapdef.h"
#include "maplinkedstack.h"
#include "maputil.h"

int pushLinkedStackMapPosition(LinkedStack* pStack, MapPosition data) {
    StackNode node = {0,};
    node.data = data;       //StackNode의 data에 매개변수 data값을 넣는다
    return pushLinkedStack(pStack, node);
}
void findPath(int mazeArray[HEIGHT][WIDTH],
              MapPosition startPos,
              MapPosition endPos,
              LinkedStack* pStack) {
    StackNode* pNode = NULL;
    int isEmpty = FALSE, isFound = FALSE, i=0;
    int markArray[HEIGHT][WIDTH] = {0,};
    
    if (pStack != NULL) {
        MapPosition newPosition = startPos;
        newPosition.direction = 0;
        pushLinkedStackMapPosition(pStack, newPosition);       //입구 위치를 스택에 푸시
        
        //움직일 다른 곳이 있고, 아직 출구를 못 찾았다면 경로를 계속 찾는다
        while (isEmpty == FALSE && isFound == FALSE) {
            pNode = popLinkedStack(pStack);     //스택에서 위치 정보 및 방향 정보 팝. 여기서 팝은 원래 위치로 돌아감
            
            if (pNode != NULL) {
                int x = pNode->data.x;
                int y = pNode->data.y;
                int direction = pNode->data.direction;
                //현위치에서 가보지 않은 곳이 있는가
                while (isFound == FALSE && direction < NUM_DIRECTIONS) {
                    int newX = x + DIRECTION_OFFSETS[direction][0];
                    int newY = y + DIRECTION_OFFSETS[direction][1];         //direction을 이동한 새로운 x, y 값
                    //새로운 방향으로 새위치로 이동 가능한가. 왜 Y X 순서가 바뀌었나
                    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && mazeArray[newY][newX] == NOT_VISIT && markArray[newY][newX] == NOT_VISIT) {
                        MapPosition newPosition;
                        newPosition.x = x;
                        newPosition.y = y;      //x, y의 값의 정체는???
                        newPosition.direction = direction + 1;  //방향 전환??
                        pushLinkedStackMapPosition(pStack, newPosition);
                        markArray[y][x] = VISIT;
                        //새 위치로 이동. 방향 정보는 초기화
                        x = newX;
                        y = newY;
                        direction = 0;
                        
                        if (newX == endPos.x && newY == endPos.y) {
                            isFound = TRUE;
                            newPosition.x = newX;
                            newPosition.y = newY;
                            newPosition.direction = 0;
                            pushLinkedStackMapPosition(pStack, newPosition);
                            markArray [newY][newX] = VISIT;
                        }
                    } else {
                        direction++;    //46행에서 가본곳이라고 하면 방향을 변경한다
                    }
                }//end-of-while
                free(pNode);
            }//end-of-if
            isEmpty = isLinkedStackEmpty(pStack);
        }//end-of-while
    }
}
void showPath(LinkedStack* pStack, int mazeArray[HEIGHT][WIDTH]) {
    StackNode* pNode = NULL;
    int resultArray[HEIGHT][WIDTH] = {0,};
    int isEmpty = FALSE;
    int i,j;
    
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            resultArray[i][j] = mazeArray[i][j];
        }
    }
    if (pStack != NULL) {
        i=0;
        while (isEmpty == FALSE) {
            pNode = popLinkedStack(pStack);
            if (pNode != NULL) {
                int x = pNode->data.x;
                int y = pNode->data.y;
                resultArray[y][x] = VISIT;  //Stack Node들을 팝시키면서 방문한 곳으로 표시
                
                if (i>0) {
                    printf("<-");
                }
                printf(" (%d, %d) ", x, y);
                i++;    //노드를 하나씩 팝시키는 것 같은데 어떻게 i값으로??
                free(pNode);
            }
            isEmpty = isLinkedStackEmpty(pStack);
        }
        printf("\n");
        printMaze(resultArray);
    }
}
void printMaze(int mazeArray[HEIGHT][WIDTH]) {
    int i,j;
    for (i=0; i<HEIGHT; i++) {
        for (j=0; j<WIDTH; j++) {
            if (mazeArray[i][j] == WALL) {
                printf("*");
            } else if (mazeArray[i][j] == VISIT) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
