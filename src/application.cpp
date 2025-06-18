#include "application.h"

Application::Application()
    : m_NullScreen(), m_MainScreen(&m_NullScreen), m_CurrentScreen(&m_MainScreen)
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
        if (m_CurrentScreen->IsScreenFinished())
        {
            m_CurrentScreen = m_CurrentScreen->GetNextScreen();
        }

        m_CurrentScreen->Update();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        m_CurrentScreen->Draw();
        EndDrawing();
    }
}

Application::~Application()
{
    CloseWindow();
}
