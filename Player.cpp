#include "Player.h"
#include <conio.h>

void Player::AddPokemon(const Pokemon& PokemonToAdd)
{
	Team[TeamCount] = PokemonToAdd;
	TeamCount++;
}

void Player::FindStartPosition(Position& OutPosition)
{
	for (int x = 0; x < MapData.GetHeight(); x++)
	{
		for (int y = 0; y < MapData.GetWidth(); y++)
		{
			if (MapData.GetTile(y, x) == Start)
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

int Player::PrintAvailableMoves(Position& position)
{
	int MoveFlags = DirNone;

	if (!IsWall(position.x, position.y - 1))
	{
		MoveFlags |= DirUp;
	}
	if (!IsWall(position.x, position.y + 1))
	{
		MoveFlags |= DirDown;
	}
	if (!IsWall(position.x - 1, position.y))
	{
		MoveFlags |= DirLeft;
	}
	if (!IsWall(position.x + 1, position.y))
	{
		MoveFlags |= DirRight;
	}

	return MoveFlags;
}

MoveDirection Player::GetMoveInput(int MoveFlags)
{
	char UserInput = 0;
	MoveDirection Direction = DirNone;

	while (true)
	{
		if (_kbhit())
		{
			UserInput = _getch();
			if (UserInput == -32)     // 2바이트 특수 문자로 입력되면
				UserInput = _getch();
			
			switch (UserInput)
			{
			case ArrowUp:
				if (MoveFlags & DirUp) Direction = DirUp;
				break;
			case ArrowDown:
				if (MoveFlags & DirDown) Direction = DirDown;
				break;
			case ArrowLeft:
				if (MoveFlags & DirLeft) Direction = DirLeft;
				break;
			case ArrowRight:
				if (MoveFlags & DirRight) Direction = DirRight;
				break;
			default:
				break;
			}
		}
	}

	return Direction;
}

bool Player::IsWall(int x, int y)
{
	bool IsWallCheck = false;
	if (y < 0 || y >= MapData.GetWidth() ||
		x < 0 || x >= MapData.GetHeight() ||
		MapData.GetTile(y, x) == Wall)
		IsWallCheck = true;
	return IsWallCheck;
}
