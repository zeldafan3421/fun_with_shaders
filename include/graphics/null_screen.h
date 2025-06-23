#pragma once

#include "interfaces/screen.h"

class NullScreen : public Screen
{
public:
    NullScreen() : Screen(nullptr) {}

    virtual void Update() {}
    virtual void Draw() {}

    static std::unique_ptr<Screen> Create()
    {
        return std::make_unique<NullScreen>();
    }
};