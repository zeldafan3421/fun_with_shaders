#pragma once

#include "raylib.h"

class Screen
{
public:
    virtual void Update() = 0;
    virtual void Draw() = 0;

    bool IsScreenFinished() const { return m_Finished; }
    virtual Screen *GetNextScreen() const = 0;

protected:
    bool m_Finished;
};
