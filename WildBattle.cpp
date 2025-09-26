#include "WildBattle.h"
#include <Windows.h>
#include <time.h>
#include <conio.h>

bool IsFastBoss = true;

void WildBattle::StartBattle(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
// 3. 전투 루프 시작
// - 플레이어와 적이 번갈아가면서 행동
// - 루프 종료 조건: 한쪽 포켓몬의 HP 0 이하

// 4. 플레이어 행동 입력 처리
// - 공격 선택 시 기술 리스트 출력
// - 기술 사용 시 데미지 계산 및 적 HP 감소
// - 아이템 선택 시 효과 적용
// - 도망 선택 시 전투 종료 시도

// 5. 적 행동 처리
// - AI 로직에 따라 기술 선택
// - 플레이어 포켓몬 HP 감소

// 6. 전투 상태 갱신
// - HP바 갱신
// - 화면 재출력
// - 전투 메시지 출력 (예: "피카츄의 10 데미지!")

// 7. 전투 종료 체크
// - 플레이어 포켓몬이 전멸 시 패배 처리
// - 적 포켓몬이 전멸 시 승리 처리
// - 경험치 부여, 레벨업, 포켓몬 상태 초기화 등

// 8. 전투 종료 후 UI 정리
// - 화면 초기화
// - 이전 맵/게임 화면으로 복귀
    int SelectCount = 0;
    char UserInput;
    int GoldReward = 0;
    bool RandomCount = false;
    std::string CheckItem;

    if (PlayerPokemon.GetSpeed() > EnemyPokemon.GetSpeed()) 
        IsFastBoss = true;
    else 
        IsFastBoss = false;
    
    // 1. 화면 초기화
    // - 이전 UI 지우고 전투용 UI 준비

    // 2. 전투 UI 출력
    // - 플레이어 포켓몬 정보: 이름, 레벨, HP
    // - 상대 포켓몬 정보: 이름, 레벨, HP
    // - HP는 현재 HP 비율에 따라 체력바 표시
    // - 선택 가능한 행동 버튼 표시 (공격, 아이템, 도망 등)
    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "앗! 야생의 " + EnemyPokemon.GetName() + "(이)가 나타났다!");
    ScreenInstance.ShowBattleScreen(SelectCount);
    Sleep(1000);
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
                        RandomCount = rand() % 2;
                        if (RandomCount)
                        {
                            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerInstance.GetName() + "(은)는 도망쳤다!");
                            Sleep(2000);
                            return;
                        }
                        else
                        {
                            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "안돼! 승부 중에는 상대방에게 등을 보일 수 없어!");
                            Sleep(2000);
                        }
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

void WildBattle::PlayerBattleAttack(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
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
					Sleep(1000);
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
                    Sleep(1000);
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
                    return; // 전투 종료
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

void WildBattle::EnemyBattleAttack(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
    // 1. 적이 사용할 스킬을 랜덤 선택
    int EnemySkillIndex = rand() % EnemyPokemon.GetSkillCount();
    auto EnemySkill = EnemyPokemon.GetSkill(EnemySkillIndex);

    if (EnemySkill != nullptr)
    {
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "상대 " + EnemyPokemon.GetName() + "(이)가 " + EnemySkill->GetName() + "을(를) 사용했다!");
        Sleep(1000);

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

            ScreenInstance.ShowBattleStatus(
                PlayerPokemon, EnemyPokemon,
                PlayerPokemon.GetName() + "(은)는 " + std::to_string(Damage) + "의 데미지를 입었다! " + EffectMsg
            );
        }
        else
        {
            // 빗나감 처리
            ScreenInstance.ShowBattleStatus(
                PlayerPokemon, EnemyPokemon,
                "상대 " + EnemyPokemon.GetName() + "의 " + EnemySkill->GetName() + "(은)는 빗나갔다!"
            );
        }
        Sleep(1000);
    }

    // 5. 플레이어 쓰러짐 체크
    if (PlayerPokemon.IsFainted())
    {
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 쓰러졌다!");
        Sleep(1000);
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerInstance.GetName() + "(은)는 눈 앞이 깜깜해졌다!");
        Sleep(1000);
        ScreenInstance.ShowGameOver();
    }
}

std::string WildBattle::SelectItem(Player& PlayerInstance, Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
{
    int SelectCount = 0;
    char UserInput = NULL;
    std::string Item;

    if (PlayerInstance.Inventory.empty())
    {
        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "인벤토리가 비어 있습니다.");
        Sleep(1000);
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
