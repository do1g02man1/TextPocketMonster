#include <stdio.h>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <iostream>
#include "PrintScreen.h"

void PrintScreen::ShowLogoTop() const
{
    system("CLS");
    printf("\n\n\n\n\n\n■");
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

void PrintScreen::ShowScript(std::string ScriptDoctor) const
{
    ClearScreen();

    printf("%s", ScriptDoctor.c_str());
}

void PrintScreen::ShowScriptSleep(std::string ScriptDoctor, int ScriptLen) const
{
    ClearScreen();

    for (int i = 0; i < ScriptLen; i++)
    {
        printf("%c", ScriptDoctor[i]);
        //Sleep(10);
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

    ShowScript(ScriptDoctor);
}

void PrintScreen::ShowPokemonSelection2(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetPlayerName();
    std::string ScriptDoctor = "[오박사]\n흠, 그렇군.\n자네 이름은 \"" + PlayerName + "\" (이)로군!\n\n[오박사]\n좋아, " + PlayerName + "!\n이제 자네의 포켓몬 모험이 막 시작되는구나!\n\n"
        "[오박사]\n허허, 하지만 모험에는 항상 든든한 동료가 필요하지.\n자네의 첫 번째 포켓몬을 고를 시간이 왔네.\n\n(오박사가 책상 위의 세 개의 몬스터볼을 가리킨다.)\n\n[오박사]\n"
        "여기 세 마리의 포켓몬이 있네.\n자네와 함께할 수 있는 친구들이지.\n\n1. 불꽃숭이 - 꼬마원숭이포켓몬\n\n☞ 2. 팽도리 - 펭귄포켓몬\n\n3. 모부기 - 어린잎포켓몬\n\n[오박사]\n자, 어떤 포켓몬을 선택하겠나?\n"
        "(방향키로 이동, Z 키로 선택)";

    ShowScript(ScriptDoctor);
}

void PrintScreen::ShowPokemonSelection3(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetPlayerName();
    std::string ScriptDoctor = "[오박사]\n흠, 그렇군.\n자네 이름은 \"" + PlayerName + "\" (이)로군!\n\n[오박사]\n좋아, " + PlayerName + "!\n이제 자네의 포켓몬 모험이 막 시작되는구나!\n\n"
        "[오박사]\n허허, 하지만 모험에는 항상 든든한 동료가 필요하지.\n자네의 첫 번째 포켓몬을 고를 시간이 왔네.\n\n(오박사가 책상 위의 세 개의 몬스터볼을 가리킨다.)\n\n[오박사]\n"
        "여기 세 마리의 포켓몬이 있네.\n자네와 함께할 수 있는 친구들이지.\n\n1. 불꽃숭이 - 꼬마원숭이포켓몬\n\n2. 팽도리 - 펭귄포켓몬\n\n☞ 3. 모부기 - 어린잎포켓몬\n\n[오박사]\n자, 어떤 포켓몬을 선택하겠나?\n"
        "(방향키로 이동, Z 키로 선택)";

    ShowScript(ScriptDoctor);
}

void PrintScreen::ShowAfterSelect(const Player& PlayerInstance) const
{
    std::string PokemonName = PlayerInstance.GetStartPokemonName();
    std::string ScriptDoctor = "[오박사]\n\n허허, 자네가 선택한 포켓몬은 바로 " + PokemonName + "구나!\n좋아, 이제 두 사람이 함께 모험을 떠날 준비가 되었네.\n\n"
        "[오박사]\n모험 중에는 다양한 포켓몬이 나타나고,\n때로는 예상치 못한 상황도 맞닥뜨릴 거야.\n하지만 자네와 " + PokemonName + "라면 문제 없을 걸세.\n\n"
        "[오박사]\n그럼 포켓몬스터의 세계로!";

    int ScriptLen = ScriptDoctor.length();
    ShowScriptSleep(ScriptDoctor, ScriptLen);
	Sleep(1000);
}

void PrintScreen::ShowMap(const Map& MapData, const Position& PlayerPosition) const
{
    ClearScreen();
    for (int y = 0; y < MapData.GetHeight(); y++)
    {
        for (int x = 0; x < MapData.GetWidth(); x++)
        {
            if (x == PlayerPosition.x && y == PlayerPosition.y)
                printf("O");  // 플레이어
            else
                printf("%c", MapData.GetTile(x, y));
        }
        printf("\n");
    }
}

void PrintScreen::ShowBattleStatus(const Pokemon& PlayerPokemon, const Pokemon& EnemyPokemon) const
{
    const int HPBarTicks = 10;
    char PlayerHPBar[HPBarTicks + 1]{ "-" };
    char EnemyHPBar[HPBarTicks + 1]{ "-" };
    // CurrentHP / (MaxHP / 10) 
    int PlayerHPRate = PlayerPokemon.GetCurrentHP() / (PlayerPokemon.GetMaxHP() / HPBarTicks);
    int EnemyHPRate = EnemyPokemon.GetCurrentHP() / (EnemyPokemon.GetMaxHP() / HPBarTicks);

    for (int i = 0; i < PlayerHPRate; i++)
    {
        PlayerHPBar[i] = '=';
    }
    PlayerHPBar[HPBarTicks] = '\0';

    for (int i = 0; i < EnemyHPRate; i++)
    {
        EnemyHPBar[i] = '=';
    }
    EnemyHPBar[HPBarTicks] = '\0';

    ClearScreen();
    printf(" 상대 [%s]\tLv.%d\n", EnemyPokemon.GetName().c_str(), EnemyPokemon.GetLevel());
    printf(" HP: [%s] %d / %d\n", EnemyHPBar, EnemyPokemon.GetCurrentHP(), EnemyPokemon.GetMaxHP());
    printf(" ────────────────────────────────────────\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf(" ────────────────────────────────────────\n");
    printf(" 자신 [%s]\tLv.%d\n", PlayerPokemon.GetName().c_str(), PlayerPokemon.GetLevel());
    printf(" HP: [%s] %d / %d\n", PlayerHPBar, PlayerPokemon.GetCurrentHP(), PlayerPokemon.GetMaxHP());
    printf(" ────────────────────────────────────────\n");
    printf(" 메시지 : 상대가 공격했다.\n"); // 상황에 맞는 대사 입력
    printf(" ────────────────────────────────────────\n");
}

void PrintScreen::ShowBattleScreen(int Index) const
{
    switch (Index)
    {
    case 0:
        printf(" ☞ [공격]\n");
        printf(" [아이템]\n");
        printf(" [포켓몬]\n");
        printf(" [도망]\n");
        break;
    case 1:
        printf(" [공격]\n");
        printf(" ☞ [아이템]\n");
        printf(" [포켓몬]\n");
        printf(" [도망]\n");
        break;
    case 2:
        printf(" [공격]\n");
        printf(" [아이템]\n");
        printf(" ☞ [포켓몬]\n");
        printf(" [도망]\n");
        break;
    case 3:
        printf(" [공격]\n");
        printf(" [아이템]\n");
        printf(" [포켓몬]\n");
        printf(" ☞ [도망]\n");
        break;
    default:
        break;
    }
    printf(" ────────────────────────────────────────\n");
}

void PrintScreen::ShowBattleScreenAttack(const Pokemon& PlayerPokemon, const Pokemon& EnemyPokemon, int Index) const
{
    switch (Index)
    {
    case 0:
        for (int i = 0; i < PlayerPokemon.GetSkillCount(); i++)
        {
            if (i == Index)
                printf("☞");
            printf(" [%s]\n", PlayerPokemon.GetSkillName(i).c_str());
        }
        break;
    case 1:
        for (int i = 0; i < PlayerPokemon.GetSkillCount(); i++)
        {
            if (i == Index)
                printf("☞");
            printf(" [%s]\n", PlayerPokemon.GetSkillName(i).c_str());
        }
        break;
    case 2:
        for (int i = 0; i < PlayerPokemon.GetSkillCount(); i++)
        {
            if (i == Index)
                printf("☞");
            printf(" [%s]\n", PlayerPokemon.GetSkillName(i).c_str());
        }
        break;
    case 3:
        for (int i = 0; i < PlayerPokemon.GetSkillCount(); i++)
        {
            if (i == Index)
                printf("☞");
            printf(" [%s]\n", PlayerPokemon.GetSkillName(i).c_str());
        }
        break;
    default:
        break;
    }
}