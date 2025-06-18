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
    BeginMode3D(m_Camera);
    DrawGrid(10, 1.0f);
    EndMode3D();
}

Screen *MainScreen::GetNextScreen() const
{
    return m_NextScreen;
}