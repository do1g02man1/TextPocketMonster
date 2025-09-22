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

    void Start();   // ���� ����
    bool Run();     // ���� ����

private:
    //Player player;
    PrintScreen Screen;
    //Map map;

};

