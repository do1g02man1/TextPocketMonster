#pragma once
#include "IBattle.h"
#include "Pokemon.h"
#include "PrintScreen.h"

enum BattleMenu
{
	Attack,
	Item,
	Pocketmon,
	Run
};

class WildBattle : public IBattle
{
public:
	// 전투 컨트롤러
	void StartBattle(Pokemon& PlayerPokemon, Pokemon& EnemyPokemon) override;
	void BattleAttack(Pokemon& PlayerPokemon, Pokemon& EnemyPokemon);
	
private:
	PrintScreen ScreenInstance;
};