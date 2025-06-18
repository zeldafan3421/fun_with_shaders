#pragma once

#include "raylib.h"

class Screen
{
public:
    virtual void Update() = 0;
    virtual void Draw() = 0;

    bool IsScreenFinished() const { return m_Finished; }
    virtual Screen *GetNextScreen() const { return m_NextScreen; };

protected:
    Screen(Screen& _screen) : m_Finished(false), m_NextScreen(&_screen) {}

    bool m_Finished;
    Screen* m_NextScreen;
};
