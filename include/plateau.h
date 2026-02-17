#ifndef PLATEAU_H
#define PLATEAU_H
#include "tile.h"

#define PLATEAU_WIDTH 10
#define PLATEAU_HEIGHT 10

typedef struct Plateau {
    Tile cases[PLATEAU_WIDTH][PLATEAU_HEIGHT];
}Plateau;

void CreatePlateau(Plateau *p, Texture2D texture);
void DrawPlateau(Plateau *p);

#endif