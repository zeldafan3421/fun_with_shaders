#pragma once

#include "raylib.h"
#include "raymath.h"
#include "screen.h"
#include "null_screen.h"

constexpr float c_CameraDist = 4.0f;
constexpr Vector3 c_CameraUp = Vector3{0.0f, 1.0f, 0.0f};
constexpr float c_CameraFovy = 45.0f;

constexpr Vector3 ConstVector3Scale(Vector3 v, float scalar)
{
    Vector3 result = { v.x*scalar, v.y*scalar, v.z*scalar };

    return result;
} 

static constexpr Camera GetCameraDefaultSettings()
{
    Camera response{};

    response.position = ConstVector3Scale(Vector3Ones, c_CameraDist);
    response.target = Vector3Zeros;
    response.up = c_CameraUp;
    response.fovy = c_CameraFovy;
    response.projection = CAMERA_PERSPECTIVE;

    return response;
}

class MainScreen : public Screen
{
public:
    MainScreen();

    virtual void Update();
    virtual void Draw();
private:
    Camera m_Camera;
    NullScreen m_NullScreen;
};