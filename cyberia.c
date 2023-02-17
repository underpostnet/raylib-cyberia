#include "raylib.h"
#include <stdio.h>  // Required for: fopen(), fclose(), fputc(), fwrite(), printf(), fprintf(), funopen()
#include <time.h>   // Required for: time_t, tm, time(), localtime(), strftime()
#include <string.h> // Required for: strcmp()

#define SCREEN_RANGE_MAP 30
#define SCREEN_FACTOR_RENDER 15
#define SCREEN_DIM_RENDER SCREEN_RANGE_MAP *SCREEN_FACTOR_RENDER

#define MAX_TYPES 2
#define MAX_BOTS 5
#define MAX_BUILDINGS 7

// Structs
//------------------------------------------------------------------------------------
struct element
{
    int x;
    int y;
    int dim;
    char *type;
    Color color;
};

struct element bots[MAX_BOTS];
struct element buildings[MAX_BUILDINGS];
//------------------------------------------------------------------------------------

// Params
//------------------------------------------------------------------------------------
char *types[MAX_TYPES] = {"bot", "building"};
int maxElements[MAX_TYPES] = {MAX_BOTS, MAX_BUILDINGS};
//------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------
// Program main entry point
int main(void)
{
    // Initialization
    // https://www.w3schools.com/c/c_data_types.php
    // https://www.raylib.com/examples.html
    // printf("%i \n", GetRandomValue(0, 10));
    // https://github.com/oz123/awesome-c
    // https://github.com/felselva/uastar
    //--------------------------------------------------------------------------------------

    for (int i = 0; i < MAX_TYPES; i++)
    {
        for (int j = 0; j < maxElements[i]; j++)
        {

            if (strcmp(types[i], "bot") == 0)
            {
                bots[j].type = "bot";
                bots[j].dim = 1;
                bots[j].x = GetRandomValue(0, SCREEN_RANGE_MAP);
                bots[j].y = GetRandomValue(0, SCREEN_RANGE_MAP);
                bots[j].color = YELLOW;
            }
            if (strcmp(types[i], "building") == 0)
            {
                buildings[j].x = GetRandomValue(0, SCREEN_RANGE_MAP);
                buildings[j].y = GetRandomValue(0, SCREEN_RANGE_MAP);
                buildings[j].type = "building";
                buildings[j].dim = 2;
                buildings[j].color = BLACK;
            }
        }
    }

    for (int i = 0; i < MAX_TYPES; i++)
    {
        for (int j = 0; j < maxElements[i]; j++)
        {
            if (strcmp(types[i], "bot") == 0)
            {
                printf("succes load -> %s %i \n", bots[j].type, j);
            }
            if (strcmp(types[i], "building") == 0)
            {
                printf("succes load -> %s %i \n", buildings[j].type, j);
            }
        }
    }

    InitWindow(SCREEN_DIM_RENDER, SCREEN_DIM_RENDER, "CYBERIA");
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        for (int i = 0; i < MAX_TYPES; i++)
        {
            for (int j = 0; j < maxElements[i]; j++)
            {

                if (strcmp(types[i], "bot") == 0)
                {
                    bots[j].x = bots[j].x + GetRandomValue(-2, 2);
                    bots[j].y = bots[j].y + GetRandomValue(-2, 2);
                    if (bots[j].x < 0)
                        bots[j].x = 0;
                    if (bots[j].y < 0)
                        bots[j].y = 0;
                    if (bots[j].x > SCREEN_RANGE_MAP)
                        bots[j].x = SCREEN_RANGE_MAP;
                    if (bots[j].y > SCREEN_RANGE_MAP)
                        bots[j].y = SCREEN_RANGE_MAP;
                }
                if (strcmp(types[i], "building") == 0)
                {
                }
            }
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GREEN);

        for (int i = 0; i < MAX_TYPES; i++)
        {
            for (int j = 0; j < maxElements[i]; j++)
            {

                if (strcmp(types[i], "bot") == 0)
                {
                    DrawRectangle(
                        (bots[j].x * SCREEN_FACTOR_RENDER),
                        (bots[j].y * SCREEN_FACTOR_RENDER),
                        (bots[j].dim * SCREEN_FACTOR_RENDER),
                        (bots[j].dim * SCREEN_FACTOR_RENDER),
                        bots[j].color);
                }
                if (strcmp(types[i], "building") == 0)
                {
                    DrawRectangle(
                        (buildings[j].x * SCREEN_FACTOR_RENDER),
                        (buildings[j].y * SCREEN_FACTOR_RENDER),
                        (buildings[j].dim * SCREEN_FACTOR_RENDER),
                        (buildings[j].dim * SCREEN_FACTOR_RENDER),
                        buildings[j].color);
                }
            }
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    //--------------------------------------------------------------------------------------

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
//--------------------------------------------------------------------------------------