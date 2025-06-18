#pragma once

#include "raylib.h"
#include "graphics/screen.h"
#include "graphics/null_screen.h"
#include "graphics/main_screen.h"
#include "graphics/start_screen.h"

class Application
{
private:
    void Update();
    void Render();
    
public:
    Application();

    void Run();

    ~Application();

private:
    StartScreen m_StartScreen;
    Screen *m_CurrentScreen;
};