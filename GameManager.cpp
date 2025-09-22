#include <iostream>
#include <conio.h>
#include "Windows.h"
#include "PrintScreen.h"
#include "GameManager.h"

void GameManager::Start()
{
    if (Run())
    {
        Screen.ShowProfessorIntro();
    }
    else
    {
        return;
    }
}

bool GameManager::Run()
{
    const int Up = 72; // 위
    const int Down = 80; // 아래
    bool MenuCount = false;
    char UserInput;

    system("mode con: cols=100 lines=30");
    Screen.ShowLogoTop();
    while (true)
    {
        if (_kbhit())
        {
            UserInput = _getch();
            if (UserInput == -32)     // 2바이트 특수 문자로 입력되면
                UserInput = _getch();

            switch (UserInput)
            {
            case Up:
                Screen.ShowLogoTop();
                MenuCount = true;
                break;
            case Down:
                Screen.ShowLogoBottom();
                MenuCount = false;
                break;
            case 'z':
            case 'Z':
                return MenuCount;
                break;
            default:
                break;
            }
        }
    }

    return false;
}
