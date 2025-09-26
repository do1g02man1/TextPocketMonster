#pragma once
#include "IItem.h"

class Potion : public IItem {
public:
    virtual std::string GetName() const override { return "���� ȸ����"; }
    virtual int GetPrice() const override { return 100; }
    virtual void Use(Pokemon& Target) override { Target.Heal(50); }
    
};

