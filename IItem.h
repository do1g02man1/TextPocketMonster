#pragma once
#include <string>

class IItem {
public:
    virtual std::string GetName() const = 0;
    virtual int GetPrice() const = 0;
    virtual ~IItem() = default;
};