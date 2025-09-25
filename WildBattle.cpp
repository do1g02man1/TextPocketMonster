#include "WildBattle.h"
#include <Windows.h>
#include <time.h>
#include <conio.h>

void WildBattle::StartBattle(Pokemon& PlayerPokemon, Pokemon& EnemyPokemon)
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
    bool IsFast = true;

    if (PlayerPokemon.GetSpeed() > EnemyPokemon.GetSpeed()) 
        IsFast = true;
    else 
        IsFast = false;
    
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
        if (IsFast)
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
                ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 무엇을 할까?");
                ScreenInstance.ShowBattleScreen(SelectCount);
            }
        }
        else
        {
            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "상대 " + EnemyPokemon.GetName() + "(이)가 공격했다!");
            ScreenInstance.ShowBattleScreen(SelectCount);
			Sleep(1000);
			int Damage = EnemyPokemon.GetAttack();
			PlayerPokemon.TakeDamage(Damage);
			ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "은(는) " + std::to_string(Damage) + "의 데미지를 입었다!");
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
                    if (SelectCount != 3) 
                        SelectCount++;
                break;
            case 'z':
            case 'Z':
            {
                auto Skill = PlayerPokemon.GetSkill(SelectCount);
                if (Skill != nullptr)
                {
                    // 간단한 데미지 계산 (공격력 + 스킬 위력)
                    int Damage = PlayerPokemon.GetAttack() + Skill->GetPower();

                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "의 " + Skill->GetName() + " 공격!");
                    ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
					Sleep(1000);
                    // 정확도 체크 (랜덤으로 명중 여부 판단)
                    int RandValue = rand() % 100;
                    if (RandValue < Skill->GetAccuracy())
                    {
                        EnemyPokemon.TakeDamage(Damage);
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, EnemyPokemon.GetName() + "에게 " + std::to_string(Damage) + "의 데미지를 입혔다!");
                        ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    }
                    else
                    {
                        ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, "그러나 " + PlayerPokemon.GetName() + "의 " + Skill->GetName() + "는 빗나갔다!");
                        ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    }
                    Sleep(1000);
                }
            
                // 적 포켓몬이 쓰러졌는지 체크
                if (EnemyPokemon.IsFainted())
                {
                    ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, EnemyPokemon.GetName() + "은(는) 쓰러졌다!");
                    ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
                    Sleep(1000);
                    return; // 전투 종료
                }
                return;
            }
            default:
                break;
            }
            ScreenInstance.ShowBattleStatus(PlayerPokemon, EnemyPokemon, PlayerPokemon.GetName() + "(은)는 무엇을 할까?");
            ScreenInstance.ShowBattleScreenAttack(PlayerPokemon, EnemyPokemon, SelectCount);
        }
    }
}
