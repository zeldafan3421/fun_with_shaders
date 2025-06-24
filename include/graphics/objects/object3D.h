#pragma once

#include "raylib.h"
#include <raymath.h>
#include <type_traits>
#include "../interfaces/instanciable.h"

class Object3D : public Instanciable
{
public:
    Object3D(Mesh _mesh);

    Object3D(Object3D &_other) = delete;
    Object3D &operator=(Object3D &_other) = delete;

    Object3D(Object3D &&_other);
    Object3D &operator=(Object3D &&_other);

    Model AsModel();
    bool IsValid();

    void Draw(const Matrix& _transform);
    
    template<MaterialMapIndex _index = MATERIAL_MAP_ALBEDO>
    void SetMaterialColor(Color _color)
    {
        m_Model.materials[0].maps[_index].color = _color;
    }

    virtual void SetMaterialShader(Shader _shader)
    {
        m_Model.materials[0].shader = _shader;
    }

    virtual Mesh GetMesh() const override;
    
    virtual Material GetMaterial() const override;

    ~Object3D();
private:
    Model m_Model;
};