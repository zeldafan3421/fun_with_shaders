#include "graphics/objects/instance_object.h"

InstanceObject::InstanceObject(Mesh _mesh, int _count, Builder<Matrix> &builder)
    : Object3D(_mesh), Instances(_count, *this, builder)
{
}

Instances &InstanceObject::CastToInstances()
{
    return *this;
}

InstanceObject InstanceObject::CubeObject(int _count)
{
    return InstanceObject(GenMeshCube(1.0f, 1.0f, 1.0f), _count, m_Builder);
}

InstanceObject InstanceObject::SphereObject(int _count)
{
    return InstanceObject(GenMeshSphere(1.0f, 10, 10), _count, m_Builder);
}

Matrix InstanceObject::MatrixBuilder::Build()
{
    return m_Current;
}

void InstanceObject::MatrixBuilder::Reset()
{
    m_Current = MatrixIdentity();
    m_Current *= MatrixTranslate(
        Random::GetRandomFloat(5.0f),
        Random::GetRandomFloat(5.0f),
        Random::GetRandomFloat(5.0f));
}
