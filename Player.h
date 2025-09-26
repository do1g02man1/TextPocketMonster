#pragma once
#include "IItem.h"
#include "Pokemon.h"
#include "Position.h"
#include "Map.h"
#include <string>

struct InventorySlot {
    std::shared_ptr<IItem> Item;
    int Count;
};

enum Tile
{
    Wall = '#',
    Path = '.',
    Grass = 'M',
    River = '~',
    Start = 'O',
    NpcShop = '$',
    Boss = 'X'
};

enum MoveDirection
{
    DirNone = 0,
    DirUp = 1 << 0,
    DirDown = 1 << 1,
    DirLeft = 1 << 2,
    DirRight = 1 << 3
};

enum PlayerDirection
{
    ArrowUp = 72,    // 상
    ArrowDown = 80,  // 하
    ArrowLeft = 75,  // 좌
    ArrowRight = 77  // 우
};

class Player {
public:
    Player() = default;

    // 포켓몬 관련
    void AddPokemon(const Pokemon& PokemonToAdd);
    const Pokemon* GetTeam() const { return Team; }
    //int GetTeamCount() const { return TeamCount; }
    Pokemon& GetPokemon(int Index) { return Team[Index]; }
    void ShowTeam() const;

    // 아이템 관련
    void AddItem(std::shared_ptr<IItem> NewItem, int Amount = 1);
    void UseItem(int Index, Pokemon& Target);
        
    // 재화 관련
    void AddGold(int InGold) { Gold += InGold; }
    bool SpendGold(int InGold);
    int GetGold() const { return Gold; }

    // 이동 관련
    bool Move(MoveDirection InDirection, const Map& MapData);
    int AvailableMoves(const Position& InPosition, const Map& MapData);     // 이동한 곳 구조물 체크
    MoveDirection GetMoveInput(int InMoveFlags, char InUserInput);          // 방향키 입력
    bool IsBlocked(int x, int y, const Map& MapData);                       // 벽인지 체크
    bool IsGrass(int x, int y, const Map& MapData);
    bool IsShopNearby(const Position& InPosition, const Map& MapData) const;
    bool IsBossNearby(const Position& InPosition, const Map& MapData) const;
    void FindStartPosition(Position& OutPosition, const Map& MapData);      // 시작 지점 체크 

    // Getter 
    std::string GetName() const { return Name; }
    std::string GetStartPokemonName() const { return Team[0].GetName(); }
    Position& GetCurrentPosition() { return CurrentPosition; }

    // Setter
    void SetPlayerName(const std::string& InName) { Name = InName; }

    std::vector<InventorySlot> Inventory;
private:
    Position CurrentPosition = Position(0, 0);
    std::string Name;
    int Gold = 1000;
    static const int MaxTeam = 6;
    Pokemon Team[MaxTeam];
    int TeamCount = 0;
    int InventoryCount = 0;
};
