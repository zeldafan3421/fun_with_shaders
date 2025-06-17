#include "application.h"

Application::Application()
{
    constexpr int width = 1280;
    constexpr int height = 720;
    constexpr char title[] = "Fun with Shaders"; 

    InitWindow(width, height, title);
}

void Application::Run()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }
}

Application::~Application()
{
    CloseWindow();
}
