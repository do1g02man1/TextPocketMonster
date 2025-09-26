#pragma once
#include "Shop.h"
#include "PrintScreen.h"
#include "Player.h"
#include "Map.h"
#include "WildBattle.h"
#include "Pokemon.h"
#include <string>

enum Floor
{
    Top,
    Middle,
    Bottom
};

enum GameManagerDirection
{
    Up = 72,    // 상
    Down = 80,  // 하
    Left = 75,  // 좌
    Right = 77  // 우
};

class GameManager
{
public:
    GameManager() = default;

    void Run();     // 메인 루프

    void Start();   // 게임 시작
    bool IsStart(); // 시작 체크

    void Select();  // 선택 체크
    int StartPokemonSelect(); // 스타팅 포켓몬 선택 

    void OpenShop();
    
private:
    Shop ShopInstance;
    Player PlayerInstance;
    PrintScreen ScreenInstance;
    Map MapData;
    WildBattle BattleInstance;
};

