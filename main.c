#include "raylib.h"
#include "plateau.h"

#include <stdio.h>

int main(void)
{
    //Ouverture de la fenêtre :
    InitWindow(1920, 1080, "Test Raylib");
    Texture2D red_grass_tile = LoadTexture("assets/red_tile.png"); // chargement en mémoire de la texture


    Plateau game;
    CreatePlateau(&game, grass_tile);
    SetTargetFPS(60);


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
    CloseWindow();
    return 0;
}