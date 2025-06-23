#pragma once

#include "object3D.h"
#include "../instances.h"
#include "../../utilities/random.h"

class InstanceObject : public Object3D, public Instances
{
public:
    InstanceObject(Mesh _mesh, int _count, Builder<Matrix>& builder);

    Instances& CastToInstances();

    static InstanceObject CubeObject(int _count = 1000);
    static InstanceObject SphereObject(int _count = 1000);

private:

    inline static class MatrixBuilder : public Builder<Matrix>
    {
    public:
        Matrix Build() override;

        void Reset() override;
    private:
        Matrix m_Current;
    } m_Builder;
};
