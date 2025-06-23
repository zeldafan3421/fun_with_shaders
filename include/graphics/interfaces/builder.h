#pragma once

template<typename T>
class Builder
{
public:
    Builder() = default;
    Builder(const Builder&) = delete;
    Builder& operator=(const Builder&) = delete;

    virtual ~Builder() = default;

    virtual T Build() = 0;
    virtual void Reset() = 0;

    virtual bool IsValid() const { return true; }
};