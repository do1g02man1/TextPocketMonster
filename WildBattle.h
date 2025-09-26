#pragma once
#include "Battle.h"
#include "Pokemon.h"
#include "PrintScreen.h"

class WildBattle : public Battle
{
public:
	// 전투 컨트롤러
	void StartBattle(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon);
	void PlayerBattleAttack(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon);
	void EnemyBattleAttack(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon);
	std::string SelectItem(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon);
	
private:
	PrintScreen ScreenInstance;
};