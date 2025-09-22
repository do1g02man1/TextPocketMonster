#pragma once
#include "IItem.h"

class Pokeball : public IItem {
public:
    std::string GetName() const override { return "Pokeball"; }
    int GetPrice() const override { return 200; }
};

