#ifndef TILE_H
#define TILE_H

#include "raylib.h"

#define TILE_SCALE 0.2

typedef struct Tile {
    Texture2D texture;
    float posX;
    float posY; // On stocke la hauteur de pixel en float, sera interprété en int pour l'affichage mais simplifie les calcul pour l'animation de chute
    float delay;
} Tile;

// Prototypes
Tile CreateTile(Texture2D texture, float delay);
void DrawTile(Tile *t, float x, float y); //prend un pointeur pour Tile pour pouvoir modifier ses attributs

#endif
