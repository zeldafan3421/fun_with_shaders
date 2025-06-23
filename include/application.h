#pragma once

#include "raylib.h"
#include "graphics/interfaces/screen.h"
#include "graphics/null_screen.h"
#include "graphics/main_screen.h"
#include "graphics/start_screen.h"
#include "resource_dir.h"
#include <string>


class Application
{
private:
    void Update();
    void Render();
public:
    struct WindowContext
    {
        WindowContext(int _width, int _height, const std::string& _title);
        ~WindowContext();
    };
    
public:
    Application();

    void Run();

private:
    WindowContext m_WindowContext;
    std::unique_ptr<Screen> m_CurrentScreen;
};