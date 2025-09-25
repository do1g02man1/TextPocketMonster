#pragma once
#include "Pokemon.h"

class IBattle {
public:
    virtual void StartBattle(Pokemon& PlayerPokemon, Pokemon& EnemyPokemon) = 0;
    virtual ~IBattle() = default;
};