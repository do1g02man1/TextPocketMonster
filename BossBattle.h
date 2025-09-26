#pragma once
#include "Battle.h"

class BossBattle : public Battle
{
public:
	void StartBattle(Pokemon& player, Pokemon& boss);
};

