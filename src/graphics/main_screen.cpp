#include "graphics/main_screen.h"

MainScreen::MainScreen()
    : Screen(NullScreen::Create()),
    m_Camera(GetCameraDefaultSettings()),
    m_Cube(InstanceObject::CubeObject(c_InstanceCount)),
    m_Sphere(InstanceObject::SphereObject(c_InstanceCount))
{  
    TraceLog(LOG_DEBUG, "Loading main screen.");
    TraceLog(LOG_DEBUG, "Main Screen size : %llu bytes", sizeof(*this));

    m_Cube.SetMaterialColor(BLUE);
    m_Sphere.SetMaterialColor(PINK);
}

void MainScreen::Update()
{
    UpdateCamera(&m_Camera, CAMERA_FREE);
}

void MainScreen::Draw()
{
    constexpr float c_GridSpacing = 1.0f;
    constexpr int c_GridSlices = 10;

    BeginMode3D(m_Camera);
        DrawGrid(10, 1.0f);

        m_Cube.CastToInstances().Draw();
        m_Sphere.CastToInstances().Draw();

        DrawGrid(c_GridSlices, c_GridSpacing);
    EndMode3D();

#if defined(DEBUG)
    DrawFPS(10, 10);
#endif
}

std::unique_ptr<Screen> MainScreen::Create()
{
    return std::make_unique<MainScreen>();
}

MainScreen::~MainScreen()
{
    TraceLog(LOG_DEBUG, "Unloading main screen.");
}
