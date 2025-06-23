#pragma once

#include "raylib.h"
#include "raymath.h"

#include <vector>
#include <string>
#include <functional>

#include "interfaces/instanciable.h"
#include "interfaces/builder.h"

struct Instance 
{   
    Matrix _transform;

    Instance(const Matrix& _matrix) : _transform(_matrix) {}
    Instance() : _transform(MatrixIdentity()) {}
};

class Instances
{
public:
    Instances();
    Instances(int _count, Instanciable& _instanciable, Builder<Matrix>& builder);

    bool Contains(Model _model);

    void Update();
    void Draw();

private:
    const Shader LoadDefaultInstanceShader();

private:
    int m_Count;

    Instanciable *m_Target;
    std::vector<Matrix> m_Transforms;

    constexpr static char c_VertexShaderPath[] = "shader.vs";
    constexpr static char c_FragmentShaderPath[] = "shader.fs";
    constexpr static char c_DebugMessage[] = "Creating %d instances.";
    constexpr static char c_WarningMessage[] = "No transforms to draw.";
};
