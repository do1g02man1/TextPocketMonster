#pragma once
#include "PrintScreen.h"
#include "Player.h"
#include "Map.h"
#include <string>
class GameManager
{
public:
    GameManager() = default;

    void Run();     // 메인 루프

    void Start();   // 게임 시작
    bool IsStart(); // 시작 체크

    void Select();  // 선택 체크
    int StartPokemonSelect(); // 스타팅 포켓몬 선택 

private:
    Player PlayerInstance;
    PrintScreen Screen;
    //Map map;
};

enum Floor
{
    Top,
    Middle,
    Bottom
};