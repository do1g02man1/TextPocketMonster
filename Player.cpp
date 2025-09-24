#include "Player.h"
#include <conio.h>

void Player::AddPokemon(const Pokemon& PokemonToAdd)
{
	Team[TeamCount] = PokemonToAdd;
	TeamCount++;
}

void Player::FindStartPosition(Position& OutPosition, const Map& MapData)
{
	for (int y = 0; y < MapData.GetHeight(); y++)
	{
		for (int x = 0; x < MapData.GetWidth(); x++)
		{
			if (MapData.GetTile(x, y) == Start)
			{
				OutPosition.x = x;
				OutPosition.y = y;
				
				return;
			}
		}
	}
	OutPosition.x = 0;
	OutPosition.y = 0;
}

void Player::Move(MoveDirection InDirection)
{
	switch (InDirection)
	{
	case DirUp:	   CurrentPosition.y--; break;
	case DirDown:  CurrentPosition.y++; break;
	case DirLeft:  CurrentPosition.x--; break;
	case DirRight: CurrentPosition.x++; break;
	case DirNone:
	default:
		break;
	}
}

int Player::AvailableMoves(const Position& InPosition, const Map& MapData)
{
	int MoveFlags = DirNone;

	if (!IsBlocked(InPosition.x, InPosition.y - 1, MapData)) MoveFlags |= DirUp;
	if (!IsBlocked(InPosition.x, InPosition.y + 1, MapData)) MoveFlags |= DirDown;
	if (!IsBlocked(InPosition.x - 1, InPosition.y, MapData)) MoveFlags |= DirLeft;
	if (!IsBlocked(InPosition.x + 1, InPosition.y, MapData)) MoveFlags |= DirRight;

	return MoveFlags;
}

MoveDirection Player::GetMoveInput(int InMoveFlags, char InUserInput)
{
	MoveDirection Direction = DirNone;

	switch (InUserInput)
	{
	case ArrowUp:
		if (InMoveFlags & DirUp) Direction = DirUp;
		break;
	case ArrowDown:
		if (InMoveFlags & DirDown) Direction = DirDown;
		break;
	case ArrowLeft:
		if (InMoveFlags & DirLeft) Direction = DirLeft;
		break;
	case ArrowRight:
		if (InMoveFlags & DirRight) Direction = DirRight;
		break;
	default:
		break;
	}

	return Direction;
}

bool Player::IsBlocked(int x, int y, const Map& MapData)
{
	if (x < 0 || x >= MapData.GetWidth() ||
		y < 0 || y >= MapData.GetHeight())
		return true;

	if (MapData.GetTile(x, y) == Wall || MapData.GetTile(x, y) == River)
		return true;

	return false;
}
