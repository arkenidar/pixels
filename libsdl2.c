
//--------------------------------------------

// compile by following gcc line or compile by cmake (cmake in vscode also and expecially):

// export PKG_CONFIG_PATH=/mingw64/lib/pkgconfig/ # for Windows MSYS2 MinGW64 this may be needed

// gcc -o libsdl2 libsdl2.c $( pkgconf sdl2 --cflags --libs ) # line for Linux and for MSYS2 MinGW64

// ./libsdl2 # to run the compiled program

//--------------------------------------------

// Include the types.h library
#include "types.h"

// Include the triangle.h library
#include "triangle.h"

// Include the SDL2 library
#include <SDL2/SDL.h>

// Include the standard I/O library
#include <stdio.h>

// Include the standard library for random numbers (and seed the random number generator)
#include <time.h>
#include <stdlib.h>

void drawRectangle(SDL_Renderer *renderer, SDL_Rect *rect, SDL_Color color)
{
    // Set draw color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Draw the rectangle
    SDL_RenderFillRect(renderer, rect);
}

void drawTriangleLines(SDL_Renderer *renderer, Point2d A, Point2d B, Point2d C, SDL_Color color)
{
    // Set draw color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Draw the triangle
    SDL_RenderDrawLine(renderer, A.x, A.y, B.x, B.y);
    SDL_RenderDrawLine(renderer, B.x, B.y, C.x, C.y);
    SDL_RenderDrawLine(renderer, C.x, C.y, A.x, A.y);
}

void drawTrianglePixels(SDL_Renderer *renderer, Point2d A, Point2d B, Point2d C, SDL_Color color)
{

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // - draw the triangle

    // - iterate the screen
    // - for each pixel
    // - check if the pixel is inside the triangle
    // - if it is, draw the pixel
    // - otherwise, skip it

    Point2d P;

    // - get the screen width and height
    SDL_DisplayMode mode;
    SDL_GetCurrentDisplayMode(0, &mode);

    // iterate i from 0 to width
    for (int i = 0; i <= mode.w; i++)
    {
        // iterate j from 0 to height
        for (int j = 0; j <= mode.h; j++)
        {
            // - set the point
            P.x = i;
            P.y = j;

            // - check if the point is inside the triangle
            if (IsPointInsideTriangle(P, A, B, C))
            {
                // - draw the point
                SDL_RenderDrawPoint(renderer, P.x, P.y);
            }
            else if (P.x == A.x)
            {
                // printf("P(%g, %g) is not inside the triangle\n", P.x, P.y);
                IsPointInsideTriangle(P, A, B, C);
            }

            double det = (B.y - C.y) * (A.x - C.x) + (C.x - B.x) * (A.y - C.y);
            det = (int)det;
            if (det == 0)
            {
                // printf("det = 0\n");
            }
        }
    }
}

void randomTriangle(Point2d *A, Point2d *B, Point2d *C)
{
    A->x = rand() % 640;
    A->y = rand() % 480;
    B->x = rand() % 640;
    B->y = rand() % 480;
    C->x = rand() % 640;
    C->y = rand() % 480;
}

int main(int argc, char *argv[])
{

    // Seed the random number generator
    srand(time(NULL));

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("SDL2 Window -- Rectangles",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main loop flag
    int quit = 0;

    // Event handler
    SDL_Event e;

    // While application is running
    while (!quit)
    {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }

            // User presses a key
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    quit = 1;
                    break;
                }
            }

        } // End SDL_PollEvent loop

        //--------------------------------------------

        // Clear screen

        // Set draw color to light gray
        SDL_SetRenderDrawColor(renderer, 0xCC, 0xCC, 0xCC, SDL_ALPHA_OPAQUE);

        // Clear the screen
        SDL_RenderClear(renderer);

        //--------------------------------------------

        // Create a rectangle
        SDL_Rect fillRect = {200, 150, 240, 180};

        // Draw the rectangle 1
        drawRectangle(renderer, &fillRect, (SDL_Color){0xFF, 0x00, 0x00, 0xFF});

        // Draw the rectangle 2

        // - modify the rectangle position
        fillRect.x = 120;
        fillRect.y = 120;

        // - draw the rectangle
        drawRectangle(renderer, &fillRect, (SDL_Color){0xFF, 0xFF, 0x00, 0xFF});

        //--------------------------------------------

        // Draw the triangle 1
        Point2d A = {100, 100}, B = {100, 110}, C = {110, 100};

        //--------------------------------------------

        // Draw the triangle 1
        drawTrianglePixels(renderer, A, B, C, (SDL_Color){0x00, 0xFF, 0x00, 0xFF});
        drawTriangleLines(renderer, A, B, C, (SDL_Color){0x00, 0x00, 0x00, 0xFF});

        //--------------------------------------------

        // Draw the triangle 2

        // - modify the triangle position
        randomTriangle(&A, &B, &C);

        // - draw the triangle
        drawTrianglePixels(renderer, A, B, C, (SDL_Color){0x00, 0xFF, 0x00, 0xFF});
        drawTriangleLines(renderer, A, B, C, (SDL_Color){0x00, 0x00, 0x00, 0xFF});

        //--------------------------------------------

        // - update the screen
        // - repeat
        // - until the user closes the window
        // - or presses the ESC key

        // Update screen
        SDL_RenderPresent(renderer);
    }

    // Destroy renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}
