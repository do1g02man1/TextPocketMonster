#pragma once
#include "Pokemon.h"

class IBattle {
public:
    virtual void StartBattle(Pokemon& player, Pokemon& enemy) = 0;
    virtual ~IBattle() = default;
};