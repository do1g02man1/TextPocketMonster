#pragma once
#include "IItem.h"

class Potion : public IItem {
public:
    std::string GetName() const override { return "Potion"; }
    int GetPrice() const override { return 100; }
};

