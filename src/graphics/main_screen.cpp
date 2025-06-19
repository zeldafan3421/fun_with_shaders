#include "graphics/main_screen.h"

MainScreen::MainScreen(Screen *_next)
    : m_NextScreen(_next),
      m_Camera{Vector3Ones * c_CameraDist, Vector3Zeros, c_CameraTarget, c_CameraFovy, CAMERA_PERSPECTIVE}
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

Screen *MainScreen::GetNextScreen() const
{
    return m_NextScreen;
}