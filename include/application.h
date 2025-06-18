#pragma once

#include "raylib.h"
#include "graphics/screen.h"
#include "graphics/null_screen.h"
#include "graphics/main_screen.h"

class Application
{
public:
    Application();

    void Run();

    ~Application();

private:
    NullScreen m_NullScreen;
    MainScreen m_MainScreen;
    Screen *m_CurrentScreen;
};