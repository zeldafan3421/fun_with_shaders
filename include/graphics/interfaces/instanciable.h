#pragma once

#include "raylib.h"

class Instanciable
{
public:
    virtual Mesh GetMesh() const = 0;
    virtual Material GetMaterial() const = 0;
    virtual void SetMaterialShader(Shader _shader) = 0;
};