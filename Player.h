#pragma once
#include "IItem.h"
#include "Pokemon.h"
#include <string>

class Player {
public:
    Player() = default;

    // 포켓몬 관련
    void AddPokemon(const Pokemon& p);
    void ShowTeam() const;

    // 아이템 관련
    void AddItem(std::shared_ptr<IItem> Item);
    void UseItem(int Index, Pokemon& Target);

    // 재화 관련
    void AddGold(int Amount);
    bool SpendGold(int Amount);
    int GetGold() const;

    // Getter 
    std::string GetPlayerName() const { return PlayerName; }
    std::string GetStartPokemonName() const { return Team[0].GetName(); }

    // Setter
    void SetPlayerName(const std::string& InPlayerName) { PlayerName = InPlayerName; }

private:
    std::string PlayerName;
    int Gold;
    static const int MAX_TEAM = 6;
    static const int MAX_INVENTORY = 20;
    Pokemon Team[MAX_TEAM];
    int TeamCount = 0;
    std::shared_ptr<IItem> Inventory[MAX_INVENTORY];
    int InventoryCount = 0;

};
