#pragma once
#include "Potion.h"
#include "Player.h"
#include <memory>

class Shop {
public:
    Shop() {
        InventorySlot Slot;
        Slot.Item = std::make_shared<Potion>();
        Slot.Count = 1;
        ItemsForSale.push_back(Slot);
    }

    const std::vector<InventorySlot>& GetItems() const { return ItemsForSale; }
    void BuyItem(Player& player, int index);

private:
    std::vector<InventorySlot> ItemsForSale;
};