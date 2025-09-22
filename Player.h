#pragma once
#include "IItem.h"
#include "Pokemon.h"
#include <string>

class Player {
private:
    std::string name;
    int gold;
    static const int MAX_TEAM = 6;
    static const int MAX_INVENTORY = 20;
    Pokemon team[MAX_TEAM];
    int teamCount;
    std::shared_ptr<IItem> inventory[MAX_INVENTORY];
    int inventoryCount;

public:
    Player(std::string name);

    // 포켓몬 관련
    void AddPokemon(const Pokemon& p);
    void ShowTeam() const;

    // 아이템 관련
    void AddItem(std::shared_ptr<IItem> item);
    void UseItem(int index, Pokemon& target);

    // 재화 관련
    void AddGold(int amount);
    bool SpendGold(int amount);
    int GetGold() const;
};
