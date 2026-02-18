#ifndef BOARD_H
#define BOARD_H
#include "tile.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10

typedef struct Board {
    Tile cases[BOARD_WIDTH][BOARD_HEIGHT];
}Board;

void CreateBoard(Board *p, Texture2D texture);
void DrawBoard(Board *p);

#endif