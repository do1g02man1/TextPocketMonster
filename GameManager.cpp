#include <iostream>
#include <conio.h>
#include "Windows.h"
#include "PrintScreen.h"
#include "GameManager.h"

void GameManager::Run()
{
    srand(time(0));

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

            if (UserInput == 'z' || UserInput == 'Z')
                if (PlayerInstance.IsShopNearby(PlayerInstance.GetCurrentPosition(), MapData))
                    OpenShop();

            if (Direction != DirNone)
                if (PlayerInstance.Move(Direction, MapData))    // 풀숲에서 전투에 걸렸다면
                {                                               // 배틀 실행
                    int RandomPokemonData = rand() % AllPokemonData.size();
                    Pokemon& PlayerPokemon = PlayerInstance.GetPokemon(0);
                    Pokemon EnemyPokemon = Pokemon(AllPokemonData[RandomPokemonData], 5);

                    BattleInstance.StartBattle(PlayerInstance, PlayerPokemon, EnemyPokemon);    
                }
		    ScreenInstance.ShowMap(MapData, PlayerInstance.GetCurrentPosition());
        }
        Sleep(10);
    }
}

void GameManager::Start()
{
    if (IsStart())
        Run();
    else 
        return;
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
            if (UserInput == -32)     // 2바이트 특수 문자로 입력되면
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
        // Pokemon 클래스에 불꽃숭이 전달
        Pokemon Chimchar = Pokemon(AllPokemonData[0], 5);   // 불꽃숭이 생성
        PlayerInstance.AddPokemon(Chimchar);                // 플레이어 팀에 추가
        break;
    }
    case Middle:
    {
        // Pokemon 클래스에 팽도리 전달
        Pokemon Piplup = Pokemon(AllPokemonData[1], 5);     // 팽도리 생성
        PlayerInstance.AddPokemon(Piplup);                  // 플레이어 팀에 추가
        break;
    }
    case Bottom:
    {
        // Pokemon 클래스에 모부기 전달
        Pokemon Turtwig = Pokemon(AllPokemonData[2], 5);    // 모부기 생성
        PlayerInstance.AddPokemon(Turtwig);                 // 플레이어 팀에 추가
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
            if (UserInput == -32)     // 2바이트 특수 문자로 입력되면
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

void GameManager::OpenShop()
{
    int SelectCount = 0;
    char UserInput;

    ScreenInstance.ShowShopScreen(PlayerInstance, ShopInstance.GetItems(), SelectCount);
    while (true)
    {
        if (_kbhit())
        {
            UserInput = _getch();
            if (UserInput == -32)     // 방향키 입력은 2바이트라서 한번 더 읽음
                UserInput = _getch();

            switch (UserInput)
            {
            case ArrowUp:   // 위로
                if (SelectCount > 0) SelectCount--;
                break;

            case ArrowDown: // 아래로
                if (SelectCount < (int)PlayerInstance.Inventory.size() - 1) SelectCount++;
                break;

            case 'z':   // 구매 시도
            case 'Z':
            {
                ShopInstance.BuyItem(PlayerInstance, SelectCount);
                Sleep(500);
                break;
            }

            case 'x':   // 나가기
            case 'X':
                return;

            default:
                break;
            }
            ScreenInstance.ShowShopScreen(PlayerInstance, ShopInstance.GetItems(), SelectCount);
        }
    }
}
