#include "graphics/objects/object3D.h"

Object3D::Object3D(Mesh _mesh)
    : m_Model(LoadModelFromMesh(_mesh))
{
    TraceLog(LOG_DEBUG, "Creating New Object. Object Size: %d.", sizeof(*this));
}

Object3D::Object3D(Object3D &&_other)
{
    std::swap(m_Model, _other.m_Model);
}

Object3D &Object3D::operator=(Object3D &&_other)
{
    if (this != &_other)
    {
        std::swap(m_Model, _other.m_Model);
    }

    return *this;
}

Model Object3D::AsModel()
{
    return m_Model;
}

bool Object3D::IsValid()
{
    return IsModelValid(m_Model);
}

void Object3D::Draw(const Matrix& _transform)
{
    Model self = this->AsModel();
    self.transform = _transform;

    DrawModel(self, Vector3Zeros, 1.0f, WHITE);
}

Mesh Object3D::GetMesh() const
{
    return m_Model.meshes[0];
}

Material Object3D::GetMaterial() const
{
    return m_Model.materials[0];
}

Object3D::~Object3D()
{
    if (IsModelValid(m_Model))
    {
        UnloadModel(m_Model);
    }
}
