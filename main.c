#include "raylib.h"
#include "board.h"

#include <stdio.h>

int main(void)
{
    //Ouverture de la fenêtre :
    InitWindow(1920, 1080, "Test Raylib");
    Texture2D red_grass_tile = LoadTexture("assets/red_tile.png"); // chargement en mémoire de la texture


    Board game;
    CreateBoard(&game, red_grass_tile);
    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
        //Dessin, reset à chaque frame.
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawBoard(&game);

        DrawFPS(300, 200);
        EndDrawing();
    }

    UnloadTexture(red_grass_tile);
    CloseWindow();
    return 0;
}