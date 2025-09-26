#include "BossBattle.h"
#include <Windows.h>
#include <time.h>
#include <conio.h>

extern bool IsFastBoss;

void BossBattle::StartBattle(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
    int SelectCount = 0;
    char UserInput;
    int GoldReward = 0;
    bool RandomCount = false;
    std::string CheckItem;

    if (PlayerPokemon.GetSpeed() > EnemyPokemon.GetSpeed())
        IsFastBoss = true;
    else
        IsFastBoss = false;

    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "��! �߻��� " + EnemyPokemon.GetName() + "(��)�� ��Ÿ����!");
    ScreenInstance.ShowBattleScreen(SelectCount);
    Sleep(2000);
    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� ������ �ұ�?");
    ScreenInstance.ShowBattleScreen(SelectCount);
    while (PlayerPokemon.GetCurrentHP() > 0
        && EnemyPokemon.GetCurrentHP() > 0)
    {
        if (IsFastBoss)
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
                        PlayerBattleAttack(PlayerInstance, PlayerPokemon, EnemyPokemon);
                        break;
                    case Item:
                        CheckItem = SelectItem(PlayerInstance, PlayerPokemon, EnemyPokemon);
                        if (CheckItem != "")
                            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� " + CheckItem + "(��)�� ����ߴ�.");
                        else
                            IsFastBoss = !IsFastBoss;   // �κ��丮�� ����ְų� x ������ ������ �� ���� ����
                        break;
                    case Pocketmon:
                        break;
                    case Run:
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "�Ұ����ϴ�.");
                        Sleep(2000);
                    default: break;
                    }
                    IsFastBoss = !IsFastBoss;
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
            EnemyBattleAttack(PlayerInstance, PlayerPokemon, EnemyPokemon);
            IsFastBoss = !IsFastBoss;
            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� ������ �ұ�?");
            ScreenInstance.ShowBattleScreen(SelectCount);
        }
    }
}

void BossBattle::PlayerBattleAttack(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
    int SelectCount = 0;
    char UserInput;
    int Gold = 0;

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
                    SelectCount++;
                break;
            case 'z':
            case 'Z':
            {
                auto Skill = PlayerPokemon.GetSkill(SelectCount);
                if (Skill != nullptr)
                {
                    // ������ ������ ��� (���ݷ� + ��ų ����)
                    int Damage = CalculateDamage(PlayerPokemon, EnemyPokemon, *Skill);

                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "�� " + Skill->GetName() + " ����!");
                    ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    Sleep(2000);
                    // ��Ȯ�� üũ (�������� ���� ���� �Ǵ�)
                    int RandValue = rand() % 100;
                    if (RandValue < Skill->GetAccuracy())   // ����
                    {
                        double Effectiveness = GetTypeEffectiveness(Skill->GetType(), EnemyPokemon.GetType());
                        std::string EffectMsg;
                        if (Effectiveness > 1.0) EffectMsg = "ȿ���� �����ߴ�!";
                        else if (Effectiveness < 1.0) EffectMsg = "ȿ���� ������ �� ����...";

                        EnemyPokemon.TakeDamage(Damage);
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, EnemyPokemon.GetName() + "���� " + std::to_string(Damage) + "�� �������� ������! " + EffectMsg);
                        ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    }
                    else  // ������
                    {
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "�׷��� " + PlayerPokemon.GetName() + "�� " + Skill->GetName() + "�� ��������!");
                        ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    }
                    Sleep(2000);
                }

                // �� ���ϸ��� ���������� üũ
                if (EnemyPokemon.IsFainted())
                {
                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, EnemyPokemon.GetName() + "(��)�� ��������!");
                    ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    Sleep(2000);
                    // GoldReward = (BaseReward + Level * 10) * RandomFactor
                    Gold = CalculateWildPokemonGold(EnemyPokemon);
                    PlayerInstance.AddGold(Gold);
                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� " + std::to_string(Gold) + "G�� ȹ���ߴ�!");
                    Sleep(2000);
                    int GetExp = CalculateExperience(EnemyPokemon);
                    int PrevLevel = PlayerPokemon.GetLevel();
                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerInstance.GetName() + "(��)�� " + std::to_string(GetExp) + "(��)�� ȹ���ߴ�!");
                    Sleep(2000);
                    PlayerPokemon.GainExp(GetExp);
                    if (PrevLevel != PlayerPokemon.GetLevel())
                    {
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� Lv." + std::to_string(PlayerPokemon.GetLevel()) + "(��)�� �Ǿ���!");
                        Sleep(2000);
                    }

                    ScreenInstance.ShowEnding(PlayerInstance, PlayerPokemon);
                }
                return;
            }
            case 'x':
            case 'X':
                IsFastBoss = !IsFastBoss;
                return;
            default:
                break;
            }
            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� ������ �ұ�?");
            ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
        }
    }
}

void BossBattle::EnemyBattleAttack(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
    // 1. ���� ����� ��ų�� ���� ����
    int EnemySkillIndex = rand() % EnemyPokemon.GetSkillCount();
    auto EnemySkill = EnemyPokemon.GetSkill(EnemySkillIndex);

    if (EnemySkill != nullptr)
    {
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "��� " + EnemyPokemon.GetName() + "(��)�� " + EnemySkill->GetName() + "��(��) ����ߴ�!");
        Sleep(2000);

        // 2. ���� üũ
        int RandValue = rand() % 100;
        if (RandValue < EnemySkill->GetAccuracy())
        {
            // 3. ������ ��� (CalculateDamage ����)
            int Damage = CalculateDamage(EnemyPokemon, PlayerPokemon, *EnemySkill);
            PlayerPokemon.TakeDamage(Damage);

            // 4. ȿ�� �޽��� ���
            double Effectiveness = GetTypeEffectiveness(EnemySkill->GetType(), PlayerPokemon.GetType());
            std::string EffectMsg;
            if (Effectiveness > 1.0) EffectMsg = "ȿ���� �����ߴ�!";
            else if (Effectiveness < 1.0) EffectMsg = "ȿ���� ������ �� ����...";

            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� " + std::to_string(Damage) + "�� �������� �Ծ���! " + EffectMsg);
        }
        else
        {
            // ������ ó��
            ScreenInstance.ShowBattleStatus(
                PlayerPokemon, EnemyPokemon,
                "��� " + EnemyPokemon.GetName() + "�� " + EnemySkill->GetName() + "(��)�� ��������!"
            );
        }
        Sleep(2000);
    }

    // 5. �÷��̾� ������ üũ
    if (PlayerPokemon.IsFainted())
    {
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(��)�� ��������!");
        Sleep(2000);
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerInstance.GetName() + "(��)�� �� ���� ����������!");
        Sleep(2000);
        ScreenInstance.ShowGameOver();
    }
}

std::string BossBattle::SelectItem(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
    int SelectCount = 0;
    char UserInput = NULL;
    std::string Item;

    if (PlayerInstance.Inventory.empty())
    {
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "�κ��丮�� ��� �ֽ��ϴ�.");
        Sleep(2000);
        return "";
    }

    while (UserInput != 'z' && UserInput != 'Z')
    {
        if (_kbhit())
        {
            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "� �������� ����ұ�?");
            ScreenInstance.ShowInventoryUI(PlayerInstance.Inventory, SelectCount);

            UserInput = _getch();
            if (UserInput == -32)     // 2����Ʈ Ư�� ���ڷ� �ԷµǸ�
                UserInput = _getch();

            switch (UserInput)
            {
            case ArrowUp:
                if (SelectCount != 0) SelectCount--;
                break;
            case ArrowDown:
                if (SelectCount < PlayerInstance.Inventory.size() - 1) SelectCount++;
                break;
            case 'z':
            case 'Z':
                PlayerInstance.Inventory[SelectCount].Item->Use(PlayerPokemon);
                PlayerInstance.Inventory[SelectCount].Count--;
                if (PlayerInstance.Inventory[SelectCount].Count <= 0)
                    PlayerInstance.Inventory.erase(PlayerInstance.Inventory.begin() + SelectCount);

                switch (SelectCount)
                {
                case 0:
                    Item = "���� ȸ����";
                    break;
                case 1:
                    Item = "���Ϻ�";
                    break;
                default:
                    break;
                }
                break;
            case 'x':
            case 'X':
                return "";
            default:
                break;
            }
        }
    }

    return Item;
}
