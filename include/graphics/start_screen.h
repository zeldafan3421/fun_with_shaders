#pragma once

#include "raylib.h"
#include "raymath.h"
#include "screen.h"
#include "main_screen.h"

class StartScreen : public Screen
{
public:
    StartScreen();

    virtual void Update();
    virtual void Draw();
private:
    MainScreen m_MainScreen;
};