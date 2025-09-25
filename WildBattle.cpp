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
    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "��! �߻��� " + EnemyPokemon.GetName() + "(��)�� ��Ÿ����!");
    ScreenInstance.ShowBattleScreen(SelectCount);
    Sleep(1000);
    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� ������ �ұ�?");
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
                        !(IsFast);
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
                ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� ������ �ұ�?");
                ScreenInstance.ShowBattleScreen(SelectCount);
            }
        }
        else
        {
            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "��� " + EnemyPokemon.GetName() + "(��)�� �����ߴ�!");
            ScreenInstance.ShowBattleScreen(SelectCount);
			Sleep(1000);
			int Damage = EnemyPokemon.GetAttack();
			PlayerPokemon.TakeDamage(Damage);
			ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "��(��) " + std::to_string(Damage) + "�� �������� �Ծ���!");
			ScreenInstance.ShowBattleScreen(SelectCount);
			Sleep(1000);
            !(IsFast);
        }
    }
}

void WildBattle::BattleAttack(Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
    int SelectCount = 0;
    char UserInput;
    std::string Script;

    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� ������ �ұ�?");
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
                if (SelectCount != 0) 
                    SelectCount--;
                break;
            case ArrowDown:
                if (SelectCount < PlayerPokemon.GetSkillCount() - 1)
                    if (SelectCount != 3) 
                        SelectCount++;
                break;
            case 'z':
            case 'Z':
            {
                auto Skill = PlayerPokemon.GetSkill(SelectCount);
                if (Skill != nullptr)
                {
                    // ������ ������ ��� (���ݷ� + ��ų ����)
                    int Damage = PlayerPokemon.GetAttack() + Skill->GetPower();

                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "�� " + Skill->GetName() + " ����!");
                    ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
					Sleep(1000);
                    // ��Ȯ�� üũ (�������� ���� ���� �Ǵ�)
                    int RandValue = rand() % 100;
                    if (RandValue < Skill->GetAccuracy())
                    {
                        EnemyPokemon.TakeDamage(Damage);
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, EnemyPokemon.GetName() + "���� " + std::to_string(Damage) + "�� �������� ������!");
                        ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    }
                    else
                    {
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "�׷��� " + PlayerPokemon.GetName() + "�� " + Skill->GetName() + "�� ��������!");
                        ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    }
                    Sleep(1000);
                }
            
                // �� ���ϸ��� ���������� üũ
                if (EnemyPokemon.IsFainted())
                {
                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, EnemyPokemon.GetName() + "��(��) ��������!");
                    ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    Sleep(1000);
                    return; // ���� ����
                }
                return;
            }
            default:
                break;
            }
            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� ������ �ұ�?");
            ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
        }
    }
}
