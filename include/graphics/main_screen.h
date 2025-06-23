#pragma once

#include "raylib.h"
#include "raymath.h"
#include "interfaces/screen.h"
#include "null_screen.h"
#include "instances.h"
#include <vector>
#include "../resource_dir.h"
#include <functional>
#include <string>

#include "graphics/objects/object3D.h"
#include "utilities/random.h"

constexpr float c_CameraDist = 4.0f;
constexpr Vector3 c_CameraUp = Vector3{0.0f, 1.0f, 0.0f};
constexpr float c_CameraFovy = 45.0f;

constexpr Vector3 ConstVector3Scale(Vector3 v, float scalar)
{
    Vector3 result = {v.x * scalar, v.y * scalar, v.z * scalar};

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

static auto GenDefaultCube = [](){
    constexpr float c_SideLength = 1.0f;
    return GenMeshCube(c_SideLength, c_SideLength, c_SideLength);
};

class MainScreen : public Screen
{
public:
    MainScreen();

    virtual void Update();
    virtual void Draw();

    ~MainScreen();

private:
    Camera m_Camera;
    
    Object3D m_Cube;
    Object3D m_Sphere;

    Instances m_CubeInstances;
    Instances m_SphereInstances;

    constexpr static int c_InstanceCount = 1000;
};