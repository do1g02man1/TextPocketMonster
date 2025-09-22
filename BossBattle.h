#pragma once
#include "IBattle.h"

class BossBattle : public IBattle
{
public:
	void StartBattle(Pokemon& player, Pokemon& boss) override;
};

