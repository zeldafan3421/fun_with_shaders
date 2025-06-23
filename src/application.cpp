#include "application.h"

Application::Application():   
    m_WindowContext(1280, 720, "Fun with Shaders"), 
    m_CurrentScreen(StartScreen::Create())
{
    TraceLog(LOG_DEBUG, "Constructing application.");
}

void Application::Run()
{
    TraceLog(LOG_DEBUG, "Running application.");
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
        TraceLog(LOG_DEBUG, "Changing screen.");

        m_CurrentScreen = std::move(m_CurrentScreen->GetNextScreen());
    }

    m_CurrentScreen->Update();
}

void Application::Render()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    m_CurrentScreen->Draw();
    EndDrawing();
}

Application::WindowContext::WindowContext(int _width, int _height, const std::string &_title)
{
    InitWindow(_width, _height, _title.c_str());
    SearchAndSetResourceDir("resources");
}

Application::WindowContext::~WindowContext()
{
    CloseWindow();
}
