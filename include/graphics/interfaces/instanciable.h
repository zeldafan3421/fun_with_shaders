#pragma once

#include "raylib.h"

struct InstanceData
{
    Mesh _mesh;
    Material _material;
};

class Instanciable
{
public:
    virtual InstanceData GetInstanceData() = 0;
    virtual void SetMaterialShader(Shader _shader) = 0;
};