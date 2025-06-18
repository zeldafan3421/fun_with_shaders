#pragma once

#include "raylib.h"
#include "graphics/screen.h"
#include "graphics/null_screen.h"

class Application
{
public:
    Application();

    void Run();

    ~Application();

private:
    Screen *m_CurrentScreen;
    NullScreen m_NullScreen;
};