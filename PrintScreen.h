#pragma once
#include "Player.h"
#include "Map.h"
#include "Pokemon.h"

class PrintScreen
{
public:
    // 로고 화면
    void ShowLogoTop() const;
    void ShowLogoBottom() const;

    // 플레이어 이름 입력 화면
    void ShowPlayerName() const;

    // 스크립트 출력
    void ShowScript(std::string Script) const;
    void ShowScriptSleep(std::string Script, int ScriptLen) const;

    // 오박사 대사
    void ShowProfessorIntro(const Player& PlayerInstance) const;

    // 스타터 선택 UI
    void ShowPokemonSelection1(const Player& PlayerInstance) const;
    void ShowPokemonSelection2(const Player& PlayerInstance) const;
    void ShowPokemonSelection3(const Player& PlayerInstance) const;

    // 스타터 선택 후 화면
    void ShowAfterSelect(const Player& PlayerInstance) const;

    // 맵 출력
    void ShowMap(const Map& MapData, const Position& PlayerPosition) const;

    // 전투 화면
    void ShowBattleStatus(const Pokemon& PlayerPokemon, const Pokemon& EnemyPokemon, std::string InStatus) const;
    void ShowBattleScreen(int Index) const;
    void ShowBattleScreenAttack(const Pokemon& PlayerPokemon, const Pokemon& EnemyPokemon, int Index) const;
    void ShowInventoryUI(const std::vector<InventorySlot>& Inventory, int Index) const;
    
    // 상점 출력
    void ShowShopScreen(const Player& player, const std::vector<InventorySlot>& shopItems, int selectedIndex) const;

    // 엔딩 출력
    void ShowEnding();

    // 화면 삭제
    void ClearScreen() const { system("CLS"); }

private:
};

