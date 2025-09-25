#include "WildBattle.h"
#include <Windows.h>
#include <time.h>
#include <conio.h>

void WildBattle::StartBattle(Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
// 3. ���� ���� ����
// - �÷��̾�� ���� �����ư��鼭 �ൿ
// - ���� ���� ����: ���� ���ϸ��� HP 0 ����

// 4. �÷��̾� �ൿ �Է� ó��
// - ���� ���� �� ��� ����Ʈ ���
// - ��� ��� �� ������ ��� �� �� HP ����
// - ������ ���� �� ȿ�� ����
// - ���� ���� �� ���� ���� �õ�

// 5. �� �ൿ ó��
// - AI ������ ���� ��� ����
// - �÷��̾� ���ϸ� HP ����

// 6. ���� ���� ����
// - HP�� ����
// - ȭ�� �����
// - ���� �޽��� ��� (��: "��ī���� 10 ������!")

// 7. ���� ���� üũ
// - �÷��̾� ���ϸ��� ���� �� �й� ó��
// - �� ���ϸ��� ���� �� �¸� ó��
// - ����ġ �ο�, ������, ���ϸ� ���� �ʱ�ȭ ��

// 8. ���� ���� �� UI ����
// - ȭ�� �ʱ�ȭ
// - ���� ��/���� ȭ������ ����
    int SelectCount = 0;
    char UserInput;
    bool IsFast = true;

    if (PlayerPokemon.GetSpeed() > EnemyPokemon.GetSpeed()) 
        IsFast = true;
    else 
        IsFast = false;
    
    // 1. ȭ�� �ʱ�ȭ
    // - ���� UI ����� ������ UI �غ�

    // 2. ���� UI ���
    // - �÷��̾� ���ϸ� ����: �̸�, ����, HP
    // - ��� ���ϸ� ����: �̸�, ����, HP
    // - HP�� ���� HP ������ ���� ü�¹� ǥ��
    // - ���� ������ �ൿ ��ư ǥ�� (����, ������, ���� ��)
    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon);
    ScreenInstance.ShowBattleScreen(SelectCount);

    while (PlayerPokemon.GetCurrentHP() > 0
        && EnemyPokemon.GetCurrentHP() > 0)
    {
        if (IsFast)
        {
            if (_kbhit())
            {
                UserInput = _getch();
                if (UserInput == -32)     // 2����Ʈ Ư�� ���ڷ� �ԷµǸ�
                    UserInput = _getch();

                switch (UserInput)
                {
                case ArrowUp:
                    if (SelectCount != Attack) SelectCount--;
                    break;
                case ArrowDown:
                    if (SelectCount != Run) SelectCount++;
                    break;
                case 'z':
                case 'Z':
                    switch (SelectCount)
                    {
                    case Attack:
                        BattleAttack(PlayerPokemon, EnemyPokemon);
                        break;
                    case Item:
                    case Pocketmon:
                    case Run:
                    default: break;
                    }
                    break;
                default:
                    break;
                }
                ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon);
                ScreenInstance.ShowBattleScreen(SelectCount);
            }
        }
        else
        {
            !(IsFast);
        }
    }
}

void WildBattle::BattleAttack(Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
    int SelectCount = 0;
    char UserInput;

    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon);
    ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);

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
                if (SelectCount != Attack) 
                    SelectCount--;
                break;
            case ArrowDown:
                if (SelectCount < PlayerPokemon.GetSkillCount() - 1)
                    if (SelectCount != Run) 
                        SelectCount++;
                break;
            case 'z':
            case 'Z':
                break;
            default:
                break;
            }
            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon);
            ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
        }
    }
}
