#pragma once
#include "PrintScreen.h"
#include "Player.h"
#include "Map.h"
#include <string>

class GameManager
{
public:
    GameManager() = default;
    //GameManager(std::string playerName);

    void Start();   // 게임 시작
    bool Run();     // 메인 루프

private:
    //Player player;
    PrintScreen Screen;
    //Map map;

};

