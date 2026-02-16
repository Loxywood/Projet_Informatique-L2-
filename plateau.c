#include "plateau.h"

void CreatePlateau(Plateau *p, Texture2D texture) {
    for (int y = 0; y < PLATEAU_HEIGHT; y++) {
        for (int x = 0; x < PLATEAU_WIDTH; x++) {
            // en l'état, meme texture partout, a voir pour changer selon le contexte
            p->cases[x][y] = CreateTile(texture, x+y); //x+y pour initialiser le delay, les permieres cases tombent en premier
        }
    }
}

void DrawPlateau(Plateau *p) {
    float offset_x = 900; // valeur arbitraire a changer, position en haut a gauche de la premiere case (celle toute en haut)
    float offset_y = 100; // pareil
    for (int x = 0; x < PLATEAU_WIDTH; x++) {
        for (int y = 0; y < PLATEAU_HEIGHT; y++) {
            float isoX = offset_x + (x - y) * 65; //magic number pour bien aligner les cases
            float isoY = offset_y + (x + y) * 37;
            DrawTile(&p->cases[x][y], isoX, isoY);
        }
    }
}