#include "utilities/camera_builder.h"

CameraBuilder::CameraBuilder()
{
    Reset();
}

bool CameraBuilder::IsValid() const
{   
    return m_Camera.projection == CAMERA_PERSPECTIVE ||
           m_Camera.projection == CAMERA_ORTHOGRAPHIC;
}

Camera CameraBuilder::Build()
{
    return m_Camera;
}

void CameraBuilder::Reset()
{
    m_Camera = Camera{};
    m_Camera.up = c_DefaultUp;
    m_Camera.fovy = c_DefaultFovy; 
    m_Camera.projection = c_DefaultProjection;
}

CameraBuilder &CameraBuilder::SetPosition(const Vector3 &position)
{
    m_Camera.position = position;

    return *this;
}

CameraBuilder &CameraBuilder::SetTarget(const Vector3 &target)
{
    m_Camera.target = target;

    return *this;
}                           
