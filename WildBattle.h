#pragma once
#include "IBattle.h"
#include "Pokemon.h"

class WildBattle : public IBattle
{
public:
	void StartBattle(Pokemon& player, Pokemon& enemy) override;
};

