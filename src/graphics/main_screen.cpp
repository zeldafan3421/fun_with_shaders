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
    BeginMode3D(m_Camera);
    DrawGrid(10, 1.0f);
    EndMode3D();
}