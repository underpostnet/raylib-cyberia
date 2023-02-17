#include "raylib.h"
#include <stdio.h> // Required for: fopen(), fclose(), fputc(), fwrite(), printf(), fprintf(), funopen()
#include <time.h>  // Required for: time_t, tm, time(), localtime(), strftime()

#define SCREEN_RANGE_MAP 30
#define SCREEN_FACTOR_RENDER 15
#define SCREEN_DIM_RENDER SCREEN_RANGE_MAP *SCREEN_FACTOR_RENDER
#define MAX_BOTS 5

//------------------------------------------------------------------------------------
// Structs
//------------------------------------------------------------------------------------

struct bot
{
    int y;
    int x;
    int dim;
    Color color;
};

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    // https://www.w3schools.com/c/c_data_types.php
    // https://www.raylib.com/examples.html
    // printf("%i \n", GetRandomValue(0, 10));
    //--------------------------------------------------------------------------------------

    struct bot bots[MAX_BOTS];
    for (int i = 0; i < MAX_BOTS; i++)
    {
        bots[i].x = GetRandomValue(0, SCREEN_RANGE_MAP);
        bots[i].y = GetRandomValue(0, SCREEN_RANGE_MAP);
        bots[i].dim = 2;
        bots[i].color = YELLOW;
    }

    InitWindow(SCREEN_DIM_RENDER, SCREEN_DIM_RENDER, "CYBERIA");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        for (int i = 0; i < MAX_BOTS; i++)
        {
            bots[i].x = bots[i].x + GetRandomValue(-2, 2);
            bots[i].y = bots[i].y + GetRandomValue(-2, 2);
            if (bots[i].x < 0)
                bots[i].x = 0;
            if (bots[i].y < 0)
                bots[i].y = 0;
            if (bots[i].x > SCREEN_RANGE_MAP)
                bots[i].x = SCREEN_RANGE_MAP;
            if (bots[i].y > SCREEN_RANGE_MAP)
                bots[i].y = SCREEN_RANGE_MAP;
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GREEN);

        for (int i = 0; i < MAX_BOTS; i++)
        {
            DrawRectangle(
                (bots[i].x * SCREEN_FACTOR_RENDER),
                (bots[i].y * SCREEN_FACTOR_RENDER),
                (bots[i].dim * SCREEN_FACTOR_RENDER),
                (bots[i].dim * SCREEN_FACTOR_RENDER),
                bots[i].color);
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}