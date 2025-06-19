#pragma once

#include "screen.h"

class NullScreen : public Screen
{
public:
    NullScreen() : Screen(*this) {}

    virtual void Update() {}
    virtual void Draw() {}
};