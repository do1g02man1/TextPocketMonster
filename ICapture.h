#pragma once
#include "Pokemon.h"

class ICapture {
public:
    virtual bool TryCapture(Pokemon& target) = 0;
    virtual ~ICapture() = default;
};