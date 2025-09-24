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
    Screen.ShowPlayerName();
    std::string InPlayerName;
    std::cin >> InPlayerName;
    PlayerInstance.SetPlayerName(InPlayerName);

    Screen.ShowProfessorIntro(PlayerInstance);
    Select();
    Screen.ShowAfterSelect(PlayerInstance);
    Screen.TestMap();
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
    const int Up = 72; // ��
    const int Down = 80; // �Ʒ�
    bool IsStartCheck = true;
    char UserInput;

    system("mode con: cols=100 lines=30");
    Screen.ShowLogoTop();
    while (true)
    {
        if (_kbhit())
        {
            UserInput = _getch();
            if (UserInput == -32)     // 2����Ʈ Ư�� ���ڷ� �ԷµǸ�
                UserInput = _getch();

            switch (UserInput)
            {
            case Up:
                Screen.ShowLogoTop();
                IsStartCheck = true;
                break;
            case Down:
                Screen.ShowLogoBottom();
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
        Piplup piplup;                        // �ص��� ����
        PlayerInstance.AddPokemon(piplup);    // �÷��̾� ���� �߰�
        break;
    }
    case Bottom:
    {
        // Pokemon Ŭ������ ��α� ����
        Turtwig turtwig;                       // ��α� ����
        PlayerInstance.AddPokemon(turtwig);    // �÷��̾� ���� �߰�
        break;
    }
    default:
        break;
    }
}

int GameManager::StartPokemonSelect()
{
    const int Up = 72; // ��
    const int Down = 80; // �Ʒ�
    int SelectCount = 0;
    char UserInput;

    Screen.ShowPokemonSelection1(PlayerInstance);

    while (true)
    {
        if (_kbhit())
        {
            UserInput = _getch();
            if (UserInput == -32)     // 2����Ʈ Ư�� ���ڷ� �ԷµǸ�
                UserInput = _getch();

            switch (UserInput)
            {
            case Up:
                if (SelectCount != Top) SelectCount--;
                break;
            case Down:
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
                Screen.ShowPokemonSelection1(PlayerInstance);
                break;
            case Middle:
                Screen.ShowPokemonSelection2(PlayerInstance);
                break;
            case Bottom:
                Screen.ShowPokemonSelection3(PlayerInstance);
                break;
            default:
                break;
            }
        }


    }
}
