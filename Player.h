#pragma once
#include "IItem.h"
#include "Pokemon.h"
#include "Position.h"
#include "Map.h"
#include <string>

enum Tile
{
    Wall = '#',
    Path = '.',
    Grass = 'M',
    River = '~',
    Start = 'O'
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
    Pokemon GetPokemon(int Index) { return Team[Index]; }
    void ShowTeam() const;

    // ������ ����
    void AddItem(std::shared_ptr<IItem> Item);
    void UseItem(int Index, Pokemon& Target);
        
    // ��ȭ ����
    void AddGold(int Amount);
    bool SpendGold(int Amount);
    int GetGold() const;

    // �̵� ����
    bool Move(MoveDirection InDirection, const Map& MapData);
    int AvailableMoves(const Position& InPosition, const Map& MapData);     // �̵��� �� ������ üũ
    MoveDirection GetMoveInput(int InMoveFlags, char InUserInput);          // ����Ű �Է�
    bool IsBlocked(int x, int y, const Map& MapData);                       // ������ üũ
    bool IsGrass(int x, int y, const Map& MapData);
    void FindStartPosition(Position& OutPosition, const Map& MapData);      // ���� ���� üũ 

    // Getter 
    std::string GetPlayerName() const { return PlayerName; }
    std::string GetStartPokemonName() const { return Team[0].GetName(); }
    Position& GetCurrentPosition() { return CurrentPosition; }

    // Setter
    void SetPlayerName(const std::string& InPlayerName) { PlayerName = InPlayerName; }

private:
    Position CurrentPosition = Position(0, 0);
    std::string PlayerName;
    int Gold;
    static const int MaxTeam = 6;
    static const int MaxInventory = 20;
    Pokemon Team[MaxTeam];
    int TeamCount = 0;
    std::shared_ptr<IItem> Inventory[MaxInventory];
    int InventoryCount = 0;
};
