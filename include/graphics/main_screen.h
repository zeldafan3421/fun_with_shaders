#pragma once

#include "raylib.h"
#include "raymath.h"
#include "screen.h"
#include "null_screen.h"
#include <vector>
#include "../resource_dir.h"

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

    void LoadScreenData(const float c_SideLength);

    virtual void Update();
    virtual void Draw();

    ~MainScreen();
private:
    Camera m_Camera;

    Mesh m_CubeMesh;
    Material m_InstancingMaterial;
    Shader m_InstancingShader;
    std::vector<Matrix> m_Transforms;

    NullScreen m_NullScreen;
};