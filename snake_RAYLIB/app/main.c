#include "raylib.h"

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);              
Texture texPattern = LoadTexture("images/green.png");
    		SetTextureFilter(texPattern, TEXTURE_FILTER_TRILINEAR);
    while (!WindowShouldClose()) 
    {
        
        BeginDrawing();

        EndDrawing();
   
    }

    CloseWindow();       
    return 0;
}