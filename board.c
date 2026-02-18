#include "board.h"

void CreateBoard(Board *p, Texture2D texture) {
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            // en l'état, meme texture partout, a voir pour changer selon le contexte
            p->cases[x][y] = CreateTile(texture, 2*(x+y)); //x+y pour initialiser le delay, les permieres cases tombent en premier
        }
    }
}

void DrawBoard(Board *p) {

    //position en haut a gauche de la premiere case (celle toute en haut), => début du plateau
    float offset_x = GetScreenWidth()/2;
    float offset_y = GetScreenHeight()/10;
    
    // largeur d'une tuile dans la fenetre ( largeur du png * echelle)
    float tileWidth = p->cases[0][0].texture.width * TILE_SCALE;

    for (int x = 0; x < BOARD_WIDTH; x++) {
        for (int y = 0; y < BOARD_HEIGHT; y++) {

            float posIsoX = offset_x + (x - y) * (tileWidth / 2.0);
            float posIsoY = offset_y + (x + y) * (tileWidth / 4.0);
            DrawTile(&p->cases[x][y], posIsoX, posIsoY);
        }
    }
}