#pragma once
#include "Pokemon.h"
#include <string>

class IItem {
public:
    virtual std::string GetName() const = 0;
    virtual int GetPrice() const = 0;
    virtual void Use(Pokemon& Target) = 0;  // Ÿ�ٿ��� ����
    virtual ~IItem() = default;
};