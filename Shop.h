#pragma once
#include "IItem.h"
#include <memory>

class Shop {
private:
    static const int MAX_ITEMS = 10;
    std::shared_ptr<IItem> items[MAX_ITEMS];
    int itemCount;

public:
    Shop();
    void ShowItems() const;
    void BuyItem(int index);
    void SellItem(int index);
};