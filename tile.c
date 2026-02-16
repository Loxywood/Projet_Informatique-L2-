#include "Tile.h"
#include <stdio.h>

Tile CreateTile(Texture2D texture, float delay)
{
    Tile t;
    t.posY = 1;
    t.texture = texture;
    t.delay = delay* 2;
    return t;
}

void DrawTile(Tile *t, float x, float y)
{    
    if(t->delay >0){
        t->delay-=1;
        return;
    }    
    float targetY = y;

    //animation de chute de la tuile
    if (t->posY < targetY){
        // déplacer la tuile de 10% du trajet, rapide puis de plus en plus lent au fur a mesure
        t->posY += (targetY - t->posY) * 0.1;

        // fixer l'emplacement de la tuile si la distance entre la target et la hauteur est inférieure a 1
        if ((targetY - t->posY) < 1.0){
            t->posY = targetY;
        }
    }

    //(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);
    DrawTextureEx(t->texture, (Vector2){x, t->posY}, 0.0, 0.3, WHITE);
    //0.3 pour mettre a echelle 3/10 vu que l'assets fait 500x500, a voir pour changer la taille 
}