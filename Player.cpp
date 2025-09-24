#include "Player.h"

void Player::AddPokemon(const Pokemon& p)
{
	Team[TeamCount] = p;
	TeamCount++;
}
