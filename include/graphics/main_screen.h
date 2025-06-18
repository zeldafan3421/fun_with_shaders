#pragma once

#include "raylib.h"
#include "raymath.h"
#include "screen.h"

constexpr float c_CameraDist = 4.0f;
constexpr Vector3 c_CameraTarget = Vector3{0.0f, 1.0f, 0.0f};
constexpr float c_CameraFovy = 45.0f;

class MainScreen : public Screen
{
public:
    MainScreen(Screen *_next);

    virtual void Update();
    virtual void Draw();

    virtual Screen *GetNextScreen() const;

private:
    Screen *m_NextScreen;
    Camera m_Camera;
};