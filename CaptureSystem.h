#pragma once
#include "ICapture.h"
#include "Pokemon.h"

class CaptureSystem : public ICapture {
public:
    bool TryCapture(Pokemon& target) override;
};

