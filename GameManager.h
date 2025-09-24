#pragma once
#include "PrintScreen.h"
#include "Player.h"
#include "Map.h"
#include <string>

enum Floor
{
    Top,
    Middle,
    Bottom
};

enum Direction
{
    ArrowUp = 72,    // 상
    ArrowDown = 80,  // 하
    ArrowLeft = 75,  // 좌
    ArrowRight = 77  // 우
};

class GameManager
{
public:
    GameManager() = default;

    void Run();     // 메인 루프
    void PlayerMove();

    void Start();   // 게임 시작
    bool IsStart(); // 시작 체크

    void Select();  // 선택 체크
    int StartPokemonSelect(); // 스타팅 포켓몬 선택 

private:
    Player PlayerInstance;
    PrintScreen ScreenInstance;
    Map MapInstance;
};

