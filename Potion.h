#pragma once
#include "IItem.h"

class Potion : public IItem {
public:
    virtual std::string GetName() const override { return "좋은 회복약"; }
    virtual int GetPrice() const override { return 100; }
    virtual void Use(Pokemon& Target) override { Target.Heal(50); }
    
};

