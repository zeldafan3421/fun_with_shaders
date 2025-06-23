#pragma once

#include "raylib.h"

class Random
{
public:
    static double GetRandomSign()
    {
        return static_cast<double>(GetRandomValue(-1, 1));
    }

    static double GetRandomDouble(double scaler)
    {
        return GetRandomSign() * GetValueFromUnitInterval() * scaler;
    }

    static float GetRandomFloat(float scaler=1.0f)
    {
        return static_cast<float>(GetRandomDouble(scaler));
    }
private:
    static double GetValueFromUnitInterval()
    {
        return static_cast<double>(GetRandomValue(0, 10000)) / 10000.0;
    }
};