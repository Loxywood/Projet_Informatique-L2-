#include "raylib.h"
//Création d'une tuile :

int main(void)
{
    //Ouverture de la fenêtre :
    InitWindow(800, 450, "Test Raylib");

    //Chargement des textures :
    Texture2D tile = LoadTexture("assets/floor_tile.png");
    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
        //Dessin, reset à chaque frame.
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //Test emboîtement des tuiles.
        DrawTexture(tile,0,0,WHITE);
        DrawTexture(tile,220,125,WHITE);
        DrawTexture(tile,440,250,WHITE);
        DrawTexture(tile,0,250,WHITE);
        DrawText("Ca marche !", 300, 200, 40, DARKGRAY);
        EndDrawing();
    }

    UnloadTexture(tile);
    CloseWindow();
    return 0;
}