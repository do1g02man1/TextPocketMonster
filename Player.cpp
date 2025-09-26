#include "Player.h"
#include <conio.h>

void Player::AddPokemon(const Pokemon& PokemonToAdd)
{
	Team[TeamCount] = PokemonToAdd;
	TeamCount++;
}

void Player::AddItem(std::shared_ptr<IItem> NewItem, int InAmount)
{
	for (auto& Slot : Inventory) {
		if (Slot.Item->GetName() == NewItem->GetName()) {
			Slot.Count += InAmount;
			return;
		}
	}
	// 없으면 새 슬롯 추가
	Inventory.push_back({ NewItem, InAmount });
}

void Player::UseItem(int Index, Pokemon& Target)
{
	if (Index >= 0 && Index < Inventory.size()) {
		Inventory[Index].Item->Use(Target);  // 아이템 사용
		Inventory[Index].Count--;             // 갯수 감소

		if (Inventory[Index].Count <= 0) {
			Inventory.erase(Inventory.begin() + Index); // 0개이면 제거
		}
	}
}

bool Player::SpendGold(int InGold)
{
    if (Gold >= InGold)
    {
        Gold -= InGold;
        return true;  
    }
    return false;     
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

bool Player::Move(MoveDirection InDirection, const Map& MapData)
{
	const int EncounterRate = 5;
	int RandomEncounter = rand() % EncounterRate;
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
	
	if (IsGrass(CurrentPosition.x, CurrentPosition.y, MapData))
		if (RandomEncounter == 0)
			return true;
	
	return false;
}

int Player::AvailableMoves(const Position& InPosition, const Map& MapData)
{
	int MoveFlags = DirNone;

	if (!IsBlocked(InPosition.x, InPosition.y - 1, MapData)) 
		MoveFlags |= DirUp;
	if (!IsBlocked(InPosition.x, InPosition.y + 1, MapData)) 
		MoveFlags |= DirDown;
	if (!IsBlocked(InPosition.x - 1, InPosition.y, MapData)) 
		MoveFlags |= DirLeft;
	if (!IsBlocked(InPosition.x + 1, InPosition.y, MapData)) 
		MoveFlags |= DirRight;

	return MoveFlags;
}


MoveDirection Player::GetMoveInput(int InMoveFlags, char InUserInput)
{
	MoveDirection Direction = DirNone;

	switch (InUserInput)
	{
	case ArrowUp:    if (InMoveFlags & DirUp) Direction = DirUp; break;
	case ArrowDown:  if (InMoveFlags & DirDown) Direction = DirDown; break;
	case ArrowLeft:  if (InMoveFlags & DirLeft) Direction = DirLeft; break;
	case ArrowRight: if (InMoveFlags & DirRight) Direction = DirRight; break;
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

	if (MapData.GetTile(x, y) == Wall || MapData.GetTile(x, y) == River || MapData.GetTile(x, y) == NpcShop)
		return true;

	return false;
}

bool Player::IsGrass(int x, int y, const Map& MapData)
{
	if (MapData.GetTile(x, y) == Grass)
		return true;

	return false;
}

bool Player::IsShopNearby(const Position& InPosition, const Map& MapData) const
{
	int x = InPosition.x;
	int y = InPosition.y;
	int Width = MapData.GetWidth();
	int Height = MapData.GetHeight();

	// 상하좌우 타일 체크
	if (y > 0 && MapData.GetTile(x, y - 1) == NpcShop) return true;      // 위
	if (y < Height - 1 && MapData.GetTile(x, y + 1) == NpcShop) return true; // 아래
	if (x > 0 && MapData.GetTile(x - 1, y) == NpcShop) return true;      // 왼쪽
	if (x < Width - 1 && MapData.GetTile(x + 1, y) == NpcShop) return true;  // 오른쪽

	return false;
}



