#include "graphics/instances.h"

Instances::Instances()
    : m_Count(0), m_Target(nullptr)
{
    TraceLog(LOG_DEBUG, "Creating empty instances.");
}

Instances::Instances(int _count, Instanciable& _instanciable, Builder<Matrix>& builder)
    : m_Count(_count), m_Target(&_instanciable)
{
    m_Target->SetMaterialShader(LoadDefaultInstanceShader());
    m_Transforms.reserve(_count);

    for (int i = 0; i < _count; ++i)
    {
        m_Transforms.push_back(builder.Build());
        builder.Reset();
    }

    TraceLog(LOG_DEBUG, c_DebugMessage, _count);
}

bool Instances::Contains(Model _model)
{
    return _model.meshes[0].vaoId == m_Target->GetInstanceData()._mesh.vaoId;
}

void Instances::Update()
{

}

void Instances::Draw()
{
    if (m_Transforms.empty())
    {
        TraceLog(LOG_WARNING, c_WarningMessage);
        return;
    }
        
    DrawMeshInstanced(
        m_Target->GetInstanceData()._mesh, m_Target->GetInstanceData()._material, m_Transforms.data(), m_Count
    );
}

const Shader Instances::LoadDefaultInstanceShader()
{
    return LoadShader(
        c_VertexShaderPath, 
        c_FragmentShaderPath
    );
}