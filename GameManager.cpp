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
                if (PlayerInstance.Move(Direction, MapData))    // Ǯ������ ������ �ɷȴٸ�
                {                                               // ��Ʋ ����
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
        Pokemon Chimchar = Pokemon(AllPokemonData[0], 5);   // �Ҳɼ��� ����
        PlayerInstance.AddPokemon(Chimchar);                // �÷��̾� ���� �߰�
        break;
    }
    case Middle:
    {
        // Pokemon Ŭ������ �ص��� ����
        Pokemon Piplup = Pokemon(AllPokemonData[1], 5);     // �ص��� ����
        PlayerInstance.AddPokemon(Piplup);                  // �÷��̾� ���� �߰�
        break;
    }
    case Bottom:
    {
        // Pokemon Ŭ������ ��α� ����
        Pokemon Turtwig = Pokemon(AllPokemonData[2], 5);    // ��α� ����
        PlayerInstance.AddPokemon(Turtwig);                 // �÷��̾� ���� �߰�
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
            if (UserInput == -32)     // ����Ű �Է��� 2����Ʈ�� �ѹ� �� ����
                UserInput = _getch();

            switch (UserInput)
            {
            case ArrowUp:   // ����
                if (SelectCount > 0) SelectCount--;
                break;

            case ArrowDown: // �Ʒ���
                if (SelectCount < (int)PlayerInstance.Inventory.size() - 1) SelectCount++;
                break;

            case 'z':   // ���� �õ�
            case 'Z':
            {
                ShopInstance.BuyItem(PlayerInstance, SelectCount);
                Sleep(500);
                break;
            }

            case 'x':   // ������
            case 'X':
                return;

            default:
                break;
            }
            ScreenInstance.ShowShopScreen(PlayerInstance, ShopInstance.GetItems(), SelectCount);
        }
    }
}
