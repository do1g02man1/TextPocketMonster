#include <stdio.h>
#include <Windows.h>
#include "PrintScreen.h"
#include <string>
#include <conio.h>

void PrintScreen::PrintLogoTop() const
{
    system("CLS");
    printf("\n\n\n\n\n\n");
    printf("\t   _______________________________________________________________________\n");
    printf("\t       ____        __      _    _    _____     _   _       __      _     _\n");
    printf("\t       /    )    /    )    /  ,'     /    '    /  /|     /    )    /|   / \n");
    printf("\t   ---/____/----/----/----/_.'------/__-------/| /-|----/----/----/-| -/--\n");
    printf("\t     /         /    /    /  \\      /         / |/  |   /    /    /  | /   \n");
    printf("\t   _/_________(____/____/____\\____/____ ____/__/___|__(____/____/___|/____\n\n\n");
    printf("\t   *                          TEXT RPG ADVENTURE                          *\n\n\n");

    printf("\t\t\t\t  ☞ 시작\n\n");
    printf("\t\t\t\t  종료\n\n");
    printf("\t\t\t\t  Z를 누르면 선택합니다.");
}

void PrintScreen::PrintLogoBottom() const
{
    system("CLS");
    printf("\n\n\n\n\n\n");
    printf("\t   _______________________________________________________________________\n");
    printf("\t       ____        __      _    _    _____     _   _       __      _     _\n");
    printf("\t       /    )    /    )    /  ,'     /    '    /  /|     /    )    /|   / \n");
    printf("\t   ---/____/----/----/----/_.'------/__-------/| /-|----/----/----/-| -/--\n");
    printf("\t     /         /    /    /  \\      /         / |/  |   /    /    /  | /   \n");
    printf("\t   _/_________(____/____/____\\____/____ ____/__/___|__(____/____/___|/____\n\n\n");
    printf("\t   *                          TEXT RPG ADVENTURE                          *\n\n\n");

    printf("\t\t\t\t  시작\n\n");
    printf("\t\t\t\t  ☞ 종료\n\n");
    printf("\t\t\t\t  Z를 누르면 선택합니다.");
}

void PrintScreen::GameStart() const
{
    system("mode con: cols=120 lines=40");
    system("CLS");
    
    std::string ScriptDoctor = "??? : ……오, 드디어 왔구나!\n\n(하얀 가운을 입은 노인이 천천히 다가온다.)\n\n오박사 : 처음 보는 얼굴이군.\n나는 포켓몬을 연구하는 오박사라고 한다네.\n\n"
        "오박사 : 자네는 이제 막 여행을 떠나려는 신참 트레이너지?\n그렇다면 동반할 포켓몬이 필요할 게야.\n\n(오박사가 책상 위의 세 개의 몬스터볼을 가리킨다.)\n\n"
        "오박사 : 여기 세 마리의 포켓몬이 있네.\n자네의 동료가 되어 줄 친구들이지.\n\n"
        "1. 불꽃 포켓몬 - 강력한 불길로 상대를 제압한다.\n2. 물 포켓몬 - 유연하고 안정적인 전투 스타일을 자랑하지.\n3. 풀 포켓몬 - 끈질긴 생명력으로 오래 버티는 타입이라네.\n\n"
        "오박사 : 자, 어떤 포켓몬을 선택하겠나?\nZ로 선택 / 방향키로 이동)";

    int ScriptLen = ScriptDoctor.length();
    char UserInput = NULL;
    
    for (int i = 0; i < ScriptLen; i++)
    {
        printf("%c", ScriptDoctor[i]);
        Sleep(20);
    }
}

