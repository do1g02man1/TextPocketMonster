#include <stdio.h>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <iostream>
#include "PrintScreen.h"
#include "Player.h"

void PrintScreen::ShowLogoTop() const
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

void PrintScreen::ShowLogoBottom() const
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

void PrintScreen::ShowPlayerName() const
{
    //system("mode con: cols=120 lines=40");
    ClearScreen();
    
    std::string ScriptDoctor = "[???] : ……오, 드디어 왔구나!\n\n(하얀 가운을 입은 노인이 천천히 다가온다.)\n\n[오박사] : 처음 보는 얼굴이군.\n나는 이 세계의 포켓몬을 연구하는 오박사라네.\n\n"
        "[오박사]\n자네는 이름이 뭐라고 했지?\n(플레이어 이름 입력) -> ";

    int ScriptLen = ScriptDoctor.length();
    ShowScriptSleep(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowScript(std::string ScriptDoctor, int ScriptLen) const
{
    ClearScreen();

    for (int i = 0; i < ScriptLen; i++)
    {
        printf("%c", ScriptDoctor[i]);
    }
}

void PrintScreen::ShowScriptSleep(std::string ScriptDoctor, int ScriptLen) const
{
    ClearScreen();

    for (int i = 0; i < ScriptLen; i++)
    {
        printf("%c", ScriptDoctor[i]);
        Sleep(10);
    }
}

void PrintScreen::ShowProfessorIntro(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetPlayerName();
    std::string ScriptDoctor = "[오박사]\n흠, 그렇군.\n자네 이름은 \"" + PlayerName + "\" (이)로군!\n\n[오박사]\n좋아, " + PlayerName + "!\n이제 자네의 포켓몬 모험이 막 시작되는구나!\n\n"
        "[오박사]\n허허, 하지만 모험에는 항상 든든한 동료가 필요하지.\n자네의 첫 번째 포켓몬을 고를 시간이 왔네.\n\n(오박사가 책상 위의 세 개의 몬스터볼을 가리킨다.)\n\n[오박사]\n"
        "여기 세 마리의 포켓몬이 있네.\n자네와 함께할 수 있는 친구들이지.\n\n1. 불꽃숭이 - 꼬마원숭이포켓몬\n\n2. 팽도리 - 펭귄포켓몬\n\n3. 모부기 - 어린잎포켓몬\n\n[오박사]\n자, 어떤 포켓몬을 선택하겠나?\n"
        "(방향키로 이동, Z 키로 선택)";

    int ScriptLen = ScriptDoctor.length();
    ShowScriptSleep(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowPokemonSelection1(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetPlayerName();
    std::string ScriptDoctor = "[오박사]\n흠, 그렇군.\n자네 이름은 \"" + PlayerName + "\" (이)로군!\n\n[오박사]\n좋아, " + PlayerName + "!\n이제 자네의 포켓몬 모험이 막 시작되는구나!\n\n"
        "[오박사]\n허허, 하지만 모험에는 항상 든든한 동료가 필요하지.\n자네의 첫 번째 포켓몬을 고를 시간이 왔네.\n\n(오박사가 책상 위의 세 개의 몬스터볼을 가리킨다.)\n\n[오박사]\n"
        "여기 세 마리의 포켓몬이 있네.\n자네와 함께할 수 있는 친구들이지.\n\n☞ 1. 불꽃숭이 - 꼬마원숭이포켓몬\n\n2. 팽도리 - 펭귄포켓몬\n\n3. 모부기 - 어린잎포켓몬\n\n[오박사]\n자, 어떤 포켓몬을 선택하겠나?\n"
        "(방향키로 이동, Z 키로 선택)";

    int ScriptLen = ScriptDoctor.length();
    ShowScript(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowPokemonSelection2(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetPlayerName();
    std::string ScriptDoctor = "[오박사]\n흠, 그렇군.\n자네 이름은 \"" + PlayerName + "\" (이)로군!\n\n[오박사]\n좋아, " + PlayerName + "!\n이제 자네의 포켓몬 모험이 막 시작되는구나!\n\n"
        "[오박사]\n허허, 하지만 모험에는 항상 든든한 동료가 필요하지.\n자네의 첫 번째 포켓몬을 고를 시간이 왔네.\n\n(오박사가 책상 위의 세 개의 몬스터볼을 가리킨다.)\n\n[오박사]\n"
        "여기 세 마리의 포켓몬이 있네.\n자네와 함께할 수 있는 친구들이지.\n\n1. 불꽃숭이 - 꼬마원숭이포켓몬\n\n☞ 2. 팽도리 - 펭귄포켓몬\n\n3. 모부기 - 어린잎포켓몬\n\n[오박사]\n자, 어떤 포켓몬을 선택하겠나?\n"
        "(방향키로 이동, Z 키로 선택)";

    int ScriptLen = ScriptDoctor.length();
    ShowScript(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowPokemonSelection3(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetPlayerName();
    std::string ScriptDoctor = "[오박사]\n흠, 그렇군.\n자네 이름은 \"" + PlayerName + "\" (이)로군!\n\n[오박사]\n좋아, " + PlayerName + "!\n이제 자네의 포켓몬 모험이 막 시작되는구나!\n\n"
        "[오박사]\n허허, 하지만 모험에는 항상 든든한 동료가 필요하지.\n자네의 첫 번째 포켓몬을 고를 시간이 왔네.\n\n(오박사가 책상 위의 세 개의 몬스터볼을 가리킨다.)\n\n[오박사]\n"
        "여기 세 마리의 포켓몬이 있네.\n자네와 함께할 수 있는 친구들이지.\n\n1. 불꽃숭이 - 꼬마원숭이포켓몬\n\n2. 팽도리 - 펭귄포켓몬\n\n☞ 3. 모부기 - 어린잎포켓몬\n\n[오박사]\n자, 어떤 포켓몬을 선택하겠나?\n"
        "(방향키로 이동, Z 키로 선택)";

    int ScriptLen = ScriptDoctor.length();
    ShowScript(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowAfterSelect(const Player& PlayerInstance) const
{
    std::string PokemonName = PlayerInstance.GetStartPokemonName();
    std::string ScriptDoctor = "[오박사]\n\n허허, 자네가 선택한 포켓몬은 바로 " + PokemonName + "구나!\n좋아, 이제 두 사람이 함께 모험을 떠날 준비가 되었네.\n\n"
        "[오박사]\n모험 중에는 다양한 포켓몬이 나타나고,\n때로는 예상치 못한 상황도 맞닥뜨릴 거야.\n하지만 자네와 " + PokemonName + "라면 문제 없을 걸세.\n\n"
        "[오박사]\n그럼 포켓몬스터의 세계로!";

    int ScriptLen = ScriptDoctor.length();
    ShowScriptSleep(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowMap(const Map& MapData) const
{
    ClearScreen();
    for (int x = 0; x < MapData.GetHeight(); x++)
    {
        for (int y = 0; y < MapData.GetWidth(); y++)
        {
            printf("%c", MapData.GetTile(x, y));
        }
        printf("\n");
    }
}

