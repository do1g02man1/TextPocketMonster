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
    ArrowUp = 72,    // ��
    ArrowDown = 80,  // ��
    ArrowLeft = 75,  // ��
    ArrowRight = 77  // ��
};

class GameManager
{
public:
    GameManager() = default;

    void Run();     // ���� ����
    void PlayerMove();

    void Start();   // ���� ����
    bool IsStart(); // ���� üũ

    void Select();  // ���� üũ
    int StartPokemonSelect(); // ��Ÿ�� ���ϸ� ���� 

private:
    Player PlayerInstance;
    PrintScreen ScreenInstance;
    Map MapInstance;
};

