#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "Test Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Ca marche !", 300, 200, 40, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}