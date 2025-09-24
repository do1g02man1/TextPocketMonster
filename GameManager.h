#pragma once
#include "PrintScreen.h"
#include "Player.h"
#include "Map.h"
#include <string>
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
    PrintScreen Screen;
    //Map map;
};

enum Floor
{
    Top,
    Middle,
    Bottom
};