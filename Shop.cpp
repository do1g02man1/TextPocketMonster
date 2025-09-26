#include "Shop.h"

void Shop::BuyItem(Player& playerInstance, int Index) 
{
    if (Index < 0 || Index >= ItemsForSale.size()) return;

    auto& Slot = ItemsForSale[Index];
    int price = Slot.Item->GetPrice();

    if (playerInstance.GetGold() >= price) {
        playerInstance.SpendGold(price);
        playerInstance.AddItem(Slot.Item); // 인벤토리에 넣기
        Slot.Count++;
        printf("%s를 구매했다!\n", Slot.Item->GetName().c_str());
    }
    else {
        printf("골드가 부족하다!\n");
    }
}