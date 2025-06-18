#pragma once

#include "screen.h"

class NullScreen : public Screen
{
public:
    virtual void Update() {}
    virtual void Draw() {}

    virtual Screen *GetNextScreen() const { return nullptr; } // should never run
};