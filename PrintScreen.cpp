#include <stdio.h>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include "PrintScreen.h"

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
        Sleep(10);
    }
}

void PrintScreen::ShowProfessorIntro(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetName();
    std::string ScriptDoctor = "[오박사]\n흠, 그렇군.\n자네 이름은 \"" + PlayerName + "\" (이)로군!\n\n[오박사]\n좋아, " + PlayerName + "!\n이제 자네의 포켓몬 모험이 막 시작되는구나!\n\n"
        "[오박사]\n허허, 하지만 모험에는 항상 든든한 동료가 필요하지.\n자네의 첫 번째 포켓몬을 고를 시간이 왔네.\n\n(오박사가 책상 위의 세 개의 몬스터볼을 가리킨다.)\n\n[오박사]\n"
        "여기 세 마리의 포켓몬이 있네.\n자네와 함께할 수 있는 친구들이지.\n\n1. 불꽃숭이 - 꼬마원숭이포켓몬\n\n2. 팽도리 - 펭귄포켓몬\n\n3. 모부기 - 어린잎포켓몬\n\n[오박사]\n자, 어떤 포켓몬을 선택하겠나?\n"
        "(방향키로 이동, Z 키로 선택)";

    int ScriptLen = ScriptDoctor.length();
    ShowScriptSleep(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowPokemonSelection1(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetName();
    std::string ScriptDoctor = "[오박사]\n흠, 그렇군.\n자네 이름은 \"" + PlayerName + "\" (이)로군!\n\n[오박사]\n좋아, " + PlayerName + "!\n이제 자네의 포켓몬 모험이 막 시작되는구나!\n\n"
        "[오박사]\n허허, 하지만 모험에는 항상 든든한 동료가 필요하지.\n자네의 첫 번째 포켓몬을 고를 시간이 왔네.\n\n(오박사가 책상 위의 세 개의 몬스터볼을 가리킨다.)\n\n[오박사]\n"
        "여기 세 마리의 포켓몬이 있네.\n자네와 함께할 수 있는 친구들이지.\n\n☞ 1. 불꽃숭이 - 꼬마원숭이포켓몬\n\n2. 팽도리 - 펭귄포켓몬\n\n3. 모부기 - 어린잎포켓몬\n\n[오박사]\n자, 어떤 포켓몬을 선택하겠나?\n"
        "(방향키로 이동, Z 키로 선택)";

    ShowScript(ScriptDoctor);
}

void PrintScreen::ShowPokemonSelection2(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetName();
    std::string ScriptDoctor = "[오박사]\n흠, 그렇군.\n자네 이름은 \"" + PlayerName + "\" (이)로군!\n\n[오박사]\n좋아, " + PlayerName + "!\n이제 자네의 포켓몬 모험이 막 시작되는구나!\n\n"
        "[오박사]\n허허, 하지만 모험에는 항상 든든한 동료가 필요하지.\n자네의 첫 번째 포켓몬을 고를 시간이 왔네.\n\n(오박사가 책상 위의 세 개의 몬스터볼을 가리킨다.)\n\n[오박사]\n"
        "여기 세 마리의 포켓몬이 있네.\n자네와 함께할 수 있는 친구들이지.\n\n1. 불꽃숭이 - 꼬마원숭이포켓몬\n\n☞ 2. 팽도리 - 펭귄포켓몬\n\n3. 모부기 - 어린잎포켓몬\n\n[오박사]\n자, 어떤 포켓몬을 선택하겠나?\n"
        "(방향키로 이동, Z 키로 선택)";

    ShowScript(ScriptDoctor);
}

void PrintScreen::ShowPokemonSelection3(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetName();
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

void PrintScreen::ShowBattleStatus(const Pokemon& PlayerPokemon, const Pokemon& EnemyPokemon, std::string InStatus) const
{
    const int HPBarTicks = 10;
    char PlayerHPBar[HPBarTicks + 1]{ ' ', };
    char EnemyHPBar[HPBarTicks + 1]{ ' ', };
    // CurrentHP / (MaxHP / 10) 
    int PlayerHPRate = (PlayerPokemon.GetCurrentHP() * HPBarTicks) / PlayerPokemon.GetMaxHP();
    int EnemyHPRate = (EnemyPokemon.GetCurrentHP() * HPBarTicks) / EnemyPokemon.GetMaxHP();

    if (EnemyHPRate > HPBarTicks) EnemyHPRate = HPBarTicks;
    if (PlayerHPRate > HPBarTicks) PlayerHPRate = HPBarTicks;

    for (int i = 0; i < HPBarTicks; i++)
    {
        if (PlayerHPRate > i) PlayerHPBar[i] = '=';
        else PlayerHPBar[i] = ' ';
    }
    PlayerHPBar[HPBarTicks] = '\0';

    for (int i = 0; i < HPBarTicks; i++)
    {
        if (EnemyHPRate > i) EnemyHPBar[i] = '=';
        else EnemyHPBar[i] = ' ';
    }
    EnemyHPBar[HPBarTicks] = '\0';

    ClearScreen();
    printf(" [야생 %s]\tLv.%d\n", EnemyPokemon.GetName().c_str(), EnemyPokemon.GetLevel());
    printf(" HP: [%s] %d / %d\n", EnemyHPBar, EnemyPokemon.GetCurrentHP(), EnemyPokemon.GetMaxHP());
    printf(" ────────────────────────────────────────\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf(" ────────────────────────────────────────\n");
    printf(" [%s]\tLv.%d\n", PlayerPokemon.GetName().c_str(), PlayerPokemon.GetLevel());
    printf(" HP: [%s] %d / %d\n", PlayerHPBar, PlayerPokemon.GetCurrentHP(), PlayerPokemon.GetMaxHP());
    printf(" ────────────────────────────────────────\n");
    printf(" %s\n", InStatus.c_str()); // 상황에 맞는 대사 입력
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
    for (int i = 0; i < PlayerPokemon.GetSkillCount(); i++)
    {
        if (i == Index)
            printf("☞");
        printf(" [%s]\n", PlayerPokemon.GetSkillName(i).c_str());
    }
}

void PrintScreen::ShowInventoryUI(const std::vector<InventorySlot>& Inventory, int Index) const
{

    for (int i = 0; i < Inventory.size(); i++)
    {
        if (i == Index)
            printf("☞ ");
        else
            printf("   ");

        printf("[%s] x%d\n", Inventory[i].Item->GetName().c_str(), Inventory[i].Count);
    }
}

void PrintScreen::ShowShopScreen(const Player& PlayerInstance, const std::vector<InventorySlot>& ShopItems, int SelectCount) const
{
    ClearScreen();
    printf(" ================== [ 상점 ] ==================\n");
    printf(" 보유 골드: %d G\n", PlayerInstance.GetGold());
    printf(" ──────────────────────────────────────────────\n");

    for (int i = 0; i < (int)ShopItems.size(); i++)
    {
        const InventorySlot& Slot = ShopItems[i];

        if (i == SelectCount)
            printf("☞ ");
        else
            printf("   ");

        printf("[%s]  가격: %d G  (보유: %d)\n",
            Slot.Item->GetName().c_str(),
            Slot.Item->GetPrice(),
            Slot.Count);
    }

    printf(" ──────────────────────────────────────────────\n");
    printf(" ↑↓ : 이동, Z : 구매, X : 나가기\n");
    printf(" ==============================================\n");
}

void PrintScreen::ShowEnding(const Player& PlayerInstance, const Pokemon& PlayerPokemon) const
{
    ClearScreen();
    printf(" ────────────────────────────────────────\n");
    printf("                 GAME CLEAR!\n");
    printf(" ────────────────────────────────────────\n\n");

    printf(" 플레이어: %s\n", PlayerInstance.GetName().c_str());
    printf(" 최종 보유 골드: %d G\n", PlayerInstance.GetGold());
    printf(" 최고 레벨 포켓몬: Lv.%d\n\n", PlayerPokemon.GetLevel());

    printf(" 축하합니다! 모든 모험을 성공적으로 마쳤습니다!\n");
    printf(" 앞으로도 새로운 도전을 계속하세요!\n\n");

    printf(" ────────────────────────────────────────\n");
    printf(" 종료하려면 ESC를 누르세요...\n");

    while (true)
    {
        if (_kbhit())
        {
            char UserInput = _getch();
            if (UserInput == 27)
            {
                exit(0);
            }
        }
    }
}

void PrintScreen::ShowGameOver() const
{
    ClearScreen();  
    printf(" ────────────────────────────────────────\n");
    printf("                 GAME OVER . . .\n");
    printf(" ────────────────────────────────────────\n\n");
    printf(" 종료하려면 ESC를 누르세요...\n");
    
    while (true)
    {
        if (_kbhit())
        {
            char UserInput = _getch();
            if (UserInput == 27)
            {
                exit(0);
            }
        }
    }
}

