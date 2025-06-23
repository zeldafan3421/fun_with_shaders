#pragma once

#include "raylib.h"
#include <memory>

class Screen
{
public:
    Screen() = delete;
    Screen(Screen&& other) = delete;
    Screen(Screen& other) = delete;
    
    virtual void Update() = 0;
    virtual void Draw() = 0;

    bool IsScreenFinished() const { return m_Finished; }
    virtual std::unique_ptr<Screen> GetNextScreen() { return std::move(m_NextScreen); };

    virtual ~Screen() = default;
protected:
    Screen(std::unique_ptr<Screen> _screen) : m_Finished(false), m_NextScreen(std::move(_screen)) {}

    bool m_Finished;
    std::unique_ptr<Screen> m_NextScreen;
};
