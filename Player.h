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

    // ���ϸ� ����
    void AddPokemon(const Pokemon& p);
    void ShowTeam() const;

    // ������ ����
    void AddItem(std::shared_ptr<IItem> item);
    void UseItem(int index, Pokemon& target);

    // ��ȭ ����
    void AddGold(int amount);
    bool SpendGold(int amount);
    int GetGold() const;
};
