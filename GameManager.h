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

enum GameManager_Direction
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

private:
    Player PlayerInstance;
    PrintScreen ScreenInstance;
    Map MapData;
};

