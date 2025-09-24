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

enum Direction
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
    void ShowTeam() const;

    // 아이템 관련
    void AddItem(std::shared_ptr<IItem> Item);
    void UseItem(int Index, Pokemon& Target);
        
    // 재화 관련
    void AddGold(int Amount);
    bool SpendGold(int Amount);
    int GetGold() const;

    // 이동 관련
    int PrintAvailableMoves(Position& position);    // 이동한 곳 구조물 체크
    MoveDirection GetMoveInput(int MoveFlags);      // 방향키 입력
    bool IsWall(int x, int y);                      // 벽인지 체크
    void FindStartPosition(Position& OutPosition);  // 시작 지점 체크 


    // Getter 
    std::string GetPlayerName() const { return PlayerName; }
    std::string GetStartPokemonName() const { return Team[0].GetName(); }

    // Setter
    void SetPlayerName(const std::string& InPlayerName) { PlayerName = InPlayerName; }

private:
    std::string PlayerName;
    int Gold;
    static const int MAX_TEAM = 6;
    static const int MAX_INVENTORY = 20;
    Pokemon Team[MAX_TEAM];
    int TeamCount = 0;
    std::shared_ptr<IItem> Inventory[MAX_INVENTORY];
    int InventoryCount = 0;
    Map MapData;
};
