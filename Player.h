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
    ArrowUp = 72,    // ��
    ArrowDown = 80,  // ��
    ArrowLeft = 75,  // ��
    ArrowRight = 77  // ��
};

class Player {
public:
    Player() = default;

    // ���ϸ� ����
    void AddPokemon(const Pokemon& PokemonToAdd);
    const Pokemon* GetTeam() const { return Team; }
    //int GetTeamCount() const { return TeamCount; }
    Pokemon& GetPokemon(int Index) { return Team[Index]; }
    void ShowTeam() const;

    // ������ ����
    void AddItem(std::shared_ptr<IItem> NewItem, int Amount = 1);
    void UseItem(int Index, Pokemon& Target);
        
    // ��ȭ ����
    void AddGold(int InGold) { Gold += InGold; }
    bool SpendGold(int InGold);
    int GetGold() const { return Gold; }

    // �̵� ����
    bool Move(MoveDirection InDirection, const Map& MapData);
    int AvailableMoves(const Position& InPosition, const Map& MapData);     // �̵��� �� ������ üũ
    MoveDirection GetMoveInput(int InMoveFlags, char InUserInput);          // ����Ű �Է�
    bool IsBlocked(int x, int y, const Map& MapData);                       // ������ üũ
    bool IsGrass(int x, int y, const Map& MapData);
    bool IsShopNearby(const Position& InPosition, const Map& MapData) const;
    bool IsBossNearby(const Position& InPosition, const Map& MapData) const;
    void FindStartPosition(Position& OutPosition, const Map& MapData);      // ���� ���� üũ 

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
