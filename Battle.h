#pragma once
#include "Pokemon.h"
#include "Skill.h"

class Battle
{
public:
	int CalculateDamage(const Pokemon& Attacker, const Pokemon& Defender, const ISkill& Skill);
	float GetTypeEffectiveness(PokemonType MoveType, PokemonType TargetType);
	int CalculateWildPokemonGold(const Pokemon& EnemyPokemon);
	int CalculateExperience(const Pokemon& EnemyPokemon);
};

