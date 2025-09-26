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
    Up = 72,    // ��
    Down = 80,  // ��
    Left = 75,  // ��
    Right = 77  // ��
};

class GameManager
{
public:
    GameManager() = default;

    void Run();     // ���� ����

    void Start();   // ���� ����
    bool IsStart(); // ���� üũ

    void Select();  // ���� üũ
    int StartPokemonSelect(); // ��Ÿ�� ���ϸ� ���� 

    void OpenShop();
    
private:
    Shop ShopInstance;
    Player PlayerInstance;
    PrintScreen ScreenInstance;
    Map MapData;
    WildBattle BattleInstance;
};

