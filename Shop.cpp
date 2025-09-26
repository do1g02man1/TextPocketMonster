#include "Shop.h"

void Shop::BuyItem(Player& playerInstance, int Index) 
{
    if (Index < 0 || Index >= ItemsForSale.size()) return;

    auto& Slot = ItemsForSale[Index];
    int price = Slot.Item->GetPrice();

    if (playerInstance.GetGold() >= price) {
        playerInstance.SpendGold(price);
        playerInstance.AddItem(Slot.Item); // �κ��丮�� �ֱ�
        Slot.Count++;
        printf("%s�� �����ߴ�!\n", Slot.Item->GetName().c_str());
    }
    else {
        printf("��尡 �����ϴ�!\n");
    }
}