#include <iostream>
#include <conio.h>
#include "Windows.h"
#include "PrintScreen.h"
#include "GameManager.h"
#include "Chimchar.h"
#include "Piplup.h"
#include "Turtwig.h"

void GameManager::Run()
{
    ScreenInstance.ShowPlayerName();
    std::string InPlayerName;
    std::cin >> InPlayerName;
    PlayerInstance.SetPlayerName(InPlayerName);

    ScreenInstance.ShowProfessorIntro(PlayerInstance);
    Select();
    ScreenInstance.ShowAfterSelect(PlayerInstance);
  
	PlayerInstance.FindStartPosition(PlayerInstance.GetCurrentPosition(), MapData);
    ScreenInstance.ShowMap(MapData, PlayerInstance.GetCurrentPosition());
    MapData.SetTile(17, 5, '.');

    while (true)
    {
        if (_kbhit())
        {
            char UserInput = _getch();
            if (UserInput == -32) UserInput = _getch();

            int MoveFlags = PlayerInstance.AvailableMoves(PlayerInstance.GetCurrentPosition(), MapData);
            MoveDirection Direction = PlayerInstance.GetMoveInput(MoveFlags, UserInput);

            if (Direction != DirNone)
                PlayerInstance.Move(Direction);

		    ScreenInstance.ShowMap(MapData, PlayerInstance.GetCurrentPosition());
        }
        Sleep(10);
    }
}

void GameManager::Start()
{
    if (IsStart())
    {
        Run();
    }
    else
    {
        return;
    }
}

bool GameManager::IsStart()
{
    bool IsStartCheck = true;
    char UserInput;

    system("mode con: cols=100 lines=30");
    ScreenInstance.ShowLogoTop();
    while (true)
    {
        if (_kbhit())
        {
            UserInput = _getch();
            if (UserInput == -32)     // 2����Ʈ Ư�� ���ڷ� �ԷµǸ�
                UserInput = _getch();

            switch (UserInput)
            {
            case ArrowUp:
                ScreenInstance.ShowLogoTop();
                IsStartCheck = true;
                break;
            case ArrowDown:
                ScreenInstance.ShowLogoBottom();
                IsStartCheck = false;
                break;
            case 'z':
            case 'Z':
                return IsStartCheck;
                break;
            default:
                break;
            }
        }
    }

    return IsStartCheck;
}

void GameManager::Select()
{
    switch (StartPokemonSelect())
    {
    case Top:
    {
        // Pokemon Ŭ������ �Ҳɼ��� ����
        Chimchar chimchar;                      // �Ҳɼ��� ����
        PlayerInstance.AddPokemon(chimchar);    // �÷��̾� ���� �߰�
        break;
    }
    case Middle:
    {
        // Pokemon Ŭ������ �ص��� ����
        Piplup piplup;                          // �ص��� ����
        PlayerInstance.AddPokemon(piplup);      // �÷��̾� ���� �߰�
        break;
    }
    case Bottom:
    {
        // Pokemon Ŭ������ ��α� ����
        Turtwig turtwig;                         // ��α� ����
        PlayerInstance.AddPokemon(turtwig);      // �÷��̾� ���� �߰�
        break;
    }
    default:
        break;
    }
}

int GameManager::StartPokemonSelect()
{
    int SelectCount = 0;
    char UserInput;

    ScreenInstance.ShowPokemonSelection1(PlayerInstance);

    while (true)
    {
        if (_kbhit())
        {
            UserInput = _getch();
            if (UserInput == -32)     // 2����Ʈ Ư�� ���ڷ� �ԷµǸ�
                UserInput = _getch();

            switch (UserInput)
            {
            case ArrowUp:
                if (SelectCount != Top) SelectCount--;
                break;
            case ArrowDown:
                if (SelectCount != Bottom) SelectCount++;
                break;
            case 'z':
            case 'Z':
                return SelectCount;
                break;
            default:
                break;
            }

            switch (SelectCount)
            {
            case Top:
                ScreenInstance.ShowPokemonSelection1(PlayerInstance);
                break;
            case Middle:
                ScreenInstance.ShowPokemonSelection2(PlayerInstance);
                break;
            case Bottom:
                ScreenInstance.ShowPokemonSelection3(PlayerInstance);
                break;
            default:
                break;
            }
        }
    }
}
