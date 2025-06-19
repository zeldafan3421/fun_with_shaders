#include "application.h"

Application::Application()
    : m_StartScreen(), m_CurrentScreen(&m_StartScreen)
{
    constexpr int width = 1280;
    constexpr int height = 720;
    constexpr char title[] = "Fun with Shaders";

    InitWindow(width, height, title);

#if defined(DEBUG)
    SetTraceLogLevel(LOG_ALL);
    TraceLog(LOG_DEBUG, "Debug application running.");
#endif
}

void Application::Run()
{
    while (!WindowShouldClose())
    {
        Update();
        Render();
    }
}

void Application::Update()
{
    if (m_CurrentScreen->IsScreenFinished())
    {
        m_CurrentScreen = m_CurrentScreen->GetNextScreen();
    }

    m_CurrentScreen->Update();
}

void Application::Render()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    m_CurrentScreen->Draw();
#if defined(DEBUG)
    DrawFPS(10, 10);
#endif
    EndDrawing();
}

Application::~Application()
{
    CloseWindow();
}
