#include "graphics/main_screen.h"

MainScreen::MainScreen()
    : Screen(m_NullScreen),
      m_Camera(GetCameraDefaultSettings())
{
}

void MainScreen::Update()
{
    UpdateCamera(&m_Camera, CAMERA_ORBITAL);
}

void MainScreen::Draw()
{
    constexpr float c_GridSpacing = 1.0f;
    constexpr int c_GridSlices = 10;

    BeginMode3D(m_Camera);
    DrawGrid(c_GridSlices, c_GridSpacing);
    EndMode3D();
}