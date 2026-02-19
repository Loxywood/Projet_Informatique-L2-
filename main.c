#include "raylib.h"
#include "plateau.h"
#include "parcours.h"

#include <stdio.h>

int main(void)
{
    //Ouverture de la fenêtre :
    InitWindow(1920, 1000, "Test Raylib");
    Texture2D red_grass_tile = LoadTexture("assets/red_tile.png"); // chargement en mémoire de la texture
    Texture2D grass_tile = LoadTexture("assets/grass_tile.png");

    Plateau game;
    CreatePlateau(&game, grass_tile);
    SetTargetFPS(60);

    Vector lieu = {2,5} ;
    int range = 3 ;

    dataMove data_mouvement ;
    createDataMouv(&data_mouvement) ;
    
    findAcces(&data_mouvement, lieu.x, lieu.y, range) ;

    for (int vect = 0 ; vect < data_mouvement.cursor_a ; vect++ ){
        //game.cases[data_mouvement.acces[vect].x ][data_mouvement.acces[vect].y ].texture = red_grass_tile ;
    }


    while (!WindowShouldClose())
    {
        //Dessin, reset à chaque frame.
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawPlateau(&game);

        DrawFPS(300, 200);
        EndDrawing();
    }

    UnloadTexture(grass_tile);
    UnloadTexture(red_grass_tile);
    CloseWindow();
    return 0;
}