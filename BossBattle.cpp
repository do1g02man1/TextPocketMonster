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

    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "앗! 야생의 " + EnemyPokemon.GetName() + "(이)가 나타났다!");
    ScreenInstance.ShowBattleScreen(SelectCount);
    Sleep(2000);
    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 무엇을 할까?");
    ScreenInstance.ShowBattleScreen(SelectCount);
    while (PlayerPokemon.GetCurrentHP() > 0
        && EnemyPokemon.GetCurrentHP() > 0)
    {
        if (IsFastBoss)
        {
            if (_kbhit())
            {
                UserInput = _getch();
                if (UserInput == -32)     // 2바이트 특수 문자로 입력되면
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
                            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 " + CheckItem + "(을)를 사용했다.");
                        else
                            IsFastBoss = !IsFastBoss;   // 인벤토리가 비어있거나 x 눌러서 나오면 턴 종료 안함
                        break;
                    case Pocketmon:
                        break;
                    case Run:
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "불가능하다.");
                        Sleep(2000);
                    default: break;
                    }
                    IsFastBoss = !IsFastBoss;
                    break;
                default:
                    break;
                }
                ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 무엇을 할까?");
                ScreenInstance.ShowBattleScreen(SelectCount);
            }
        }
        else
        {
            EnemyBattleAttack(PlayerInstance, PlayerPokemon, EnemyPokemon);
            IsFastBoss = !IsFastBoss;
            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 무엇을 할까?");
            ScreenInstance.ShowBattleScreen(SelectCount);
        }
    }
}

void BossBattle::PlayerBattleAttack(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
    int SelectCount = 0;
    char UserInput;
    int Gold = 0;

    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 무엇을 할까?");
    ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);

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
                    // 간단한 데미지 계산 (공격력 + 스킬 위력)
                    int Damage = CalculateDamage(PlayerPokemon, EnemyPokemon, *Skill);

                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "의 " + Skill->GetName() + " 공격!");
                    ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    Sleep(2000);
                    // 정확도 체크 (랜덤으로 명중 여부 판단)
                    int RandValue = rand() % 100;
                    if (RandValue < Skill->GetAccuracy())   // 명중
                    {
                        double Effectiveness = GetTypeEffectiveness(Skill->GetType(), EnemyPokemon.GetType());
                        std::string EffectMsg;
                        if (Effectiveness > 1.0) EffectMsg = "효과가 굉장했다!";
                        else if (Effectiveness < 1.0) EffectMsg = "효과가 별로인 것 같다...";

                        EnemyPokemon.TakeDamage(Damage);
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, EnemyPokemon.GetName() + "에게 " + std::to_string(Damage) + "의 데미지를 입혔다! " + EffectMsg);
                        ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    }
                    else  // 빗나감
                    {
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "그러나 " + PlayerPokemon.GetName() + "의 " + Skill->GetName() + "는 빗나갔다!");
                        ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    }
                    Sleep(2000);
                }

                // 적 포켓몬이 쓰러졌는지 체크
                if (EnemyPokemon.IsFainted())
                {
                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, EnemyPokemon.GetName() + "(은)는 쓰러졌다!");
                    ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    Sleep(2000);
                    // GoldReward = (BaseReward + Level * 10) * RandomFactor
                    Gold = CalculateWildPokemonGold(EnemyPokemon);
                    PlayerInstance.AddGold(Gold);
                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 " + std::to_string(Gold) + "G를 획득했다!");
                    Sleep(2000);
                    int GetExp = CalculateExperience(EnemyPokemon);
                    int PrevLevel = PlayerPokemon.GetLevel();
                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerInstance.GetName() + "(은)는 " + std::to_string(GetExp) + "(을)를 획득했다!");
                    Sleep(2000);
                    PlayerPokemon.GainExp(GetExp);
                    if (PrevLevel != PlayerPokemon.GetLevel())
                    {
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 Lv." + std::to_string(PlayerPokemon.GetLevel()) + "(이)가 되었다!");
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
            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 무엇을 할까?");
            ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
        }
    }
}

void BossBattle::EnemyBattleAttack(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
    // 1. 적이 사용할 스킬을 랜덤 선택
    int EnemySkillIndex = rand() % EnemyPokemon.GetSkillCount();
    auto EnemySkill = EnemyPokemon.GetSkill(EnemySkillIndex);

    if (EnemySkill != nullptr)
    {
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "상대 " + EnemyPokemon.GetName() + "(이)가 " + EnemySkill->GetName() + "을(를) 사용했다!");
        Sleep(2000);

        // 2. 명중 체크
        int RandValue = rand() % 100;
        if (RandValue < EnemySkill->GetAccuracy())
        {
            // 3. 데미지 계산 (CalculateDamage 재사용)
            int Damage = CalculateDamage(EnemyPokemon, PlayerPokemon, *EnemySkill);
            PlayerPokemon.TakeDamage(Damage);

            // 4. 효과 메시지 출력
            double Effectiveness = GetTypeEffectiveness(EnemySkill->GetType(), PlayerPokemon.GetType());
            std::string EffectMsg;
            if (Effectiveness > 1.0) EffectMsg = "효과가 굉장했다!";
            else if (Effectiveness < 1.0) EffectMsg = "효과가 별로인 것 같다...";

            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 " + std::to_string(Damage) + "의 데미지를 입었다! " + EffectMsg);
        }
        else
        {
            // 빗나감 처리
            ScreenInstance.ShowBattleStatus(
                PlayerPokemon, EnemyPokemon,
                "상대 " + EnemyPokemon.GetName() + "의 " + EnemySkill->GetName() + "(은)는 빗나갔다!"
            );
        }
        Sleep(2000);
    }

    // 5. 플레이어 쓰러짐 체크
    if (PlayerPokemon.IsFainted())
    {
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 쓰러졌다!");
        Sleep(2000);
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerInstance.GetName() + "(은)는 눈 앞이 깜깜해졌다!");
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
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "인벤토리가 비어 있습니다.");
        Sleep(2000);
        return "";
    }

    while (UserInput != 'z' && UserInput != 'Z')
    {
        if (_kbhit())
        {
            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "어떤 아이템을 사용할까?");
            ScreenInstance.ShowInventoryUI(PlayerInstance.Inventory, SelectCount);

            UserInput = _getch();
            if (UserInput == -32)     // 2바이트 특수 문자로 입력되면
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
                    Item = "좋은 회복약";
                    break;
                case 1:
                    Item = "포켓볼";
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
