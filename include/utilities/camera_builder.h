#pragma once

#include "raylib.h"
#include "raymath.h"

#include "graphics/interfaces/builder.h"

class CameraBuilder : public Builder<Camera>
{
public:
    CameraBuilder();
    CameraBuilder(const CameraBuilder&) = delete;
    CameraBuilder& operator=(const CameraBuilder&) = delete;

    ~CameraBuilder() override = default;

    Camera Build() override;

    void Reset() override;

    bool IsValid() const override;

    CameraBuilder& SetPosition(const Vector3& position);

    CameraBuilder& SetTarget(const Vector3& target);
private:
    Camera m_Camera;

    constexpr static Vector3 c_DefaultUp = {0.0f, 1.0f, 0.0f};
    constexpr static float c_DefaultFovy = 45.0f;
    constexpr static int c_DefaultProjection = CAMERA_PERSPECTIVE;
};