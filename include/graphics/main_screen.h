#pragma once

#include "raylib.h"
#include "raymath.h"

#include "utilities/camera_builder.h"

#include "graphics/objects/instance_object.h"
#include "utilities/random.h"
#include "interfaces/screen.h"
#include "null_screen.h"

#include <functional>
#include <string>

class MainScreen : public Screen
{
public:
    MainScreen();

    virtual void Update();
    virtual void Draw();

    static std::unique_ptr<Screen> Create();

    ~MainScreen();

private:
    Camera m_Camera;
    
    InstanceObject m_Cube;
    InstanceObject m_Sphere;

    constexpr static int c_InstanceCount = 1000;
};