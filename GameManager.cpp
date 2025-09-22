#include <iostream>
#include <conio.h>
#include "PrintScreen.h"
#include "GameManager.h"

void GameManager::Start()
{
    PrintScreen print;
    const int Up = 72; // 위
    const int Down = 80; // 아래
    char UserInput;

    system("mode con: cols=100 lines=30");
    PrintLogoTop();
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
                PrintLogoTop();
                break;
            case Down:
                PrintLogoBottom();
                break;
            case 'z':
            case 'Z':
                GameStart();
                break;
            default:
                break;
            }
        }
    }
}
