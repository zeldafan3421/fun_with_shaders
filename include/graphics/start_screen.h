#pragma once

#include "raylib.h"
#include "raymath.h"

#include "interfaces/screen.h"
#include "main_screen.h"

class StartScreen : public Screen
{
public:
    StartScreen();

    virtual void Update();
    virtual void Draw();
 
    ~StartScreen();
private:
    KeyboardKey m_ContinueKey;
    
    Vector2 m_TextPosition;
    int m_TextFontSize;
    Color m_TextColor;

    constexpr static char c_StartMessage[] = "Press enter to continue.";
};