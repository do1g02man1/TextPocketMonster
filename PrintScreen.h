#pragma once
#include "Player.h"
#include "Map.h"
#include "Pokemon.h"

class PrintScreen
{
public:
    // �ΰ� ȭ��
    void ShowLogoTop() const;
    void ShowLogoBottom() const;

    // �÷��̾� �̸� �Է� ȭ��
    void ShowPlayerName() const;

    // ��ũ��Ʈ ���
    void ShowScript(std::string Script) const;
    void ShowScriptSleep(std::string Script, int ScriptLen) const;

    // ���ڻ� ���
    void ShowProfessorIntro(const Player& PlayerInstance) const;

    // ��Ÿ�� ���� UI
    void ShowPokemonSelection1(const Player& PlayerInstance) const;
    void ShowPokemonSelection2(const Player& PlayerInstance) const;
    void ShowPokemonSelection3(const Player& PlayerInstance) const;

    // ��Ÿ�� ���� �� ȭ��
    void ShowAfterSelect(const Player& PlayerInstance) const;

    // �� ���
    void ShowMap(const Map& MapData, const Position& PlayerPosition) const;

    // ���� ȭ��
    void ShowBattleStatus(const Pokemon& PlayerPokemon, const Pokemon& EnemyPokemon, std::string InStatus) const;
    void ShowBattleScreen(int Index) const;
    void ShowBattleScreenAttack(const Pokemon& PlayerPokemon, const Pokemon& EnemyPokemon, int Index) const;
    void ShowInventoryUI(const std::vector<InventorySlot>& Inventory, int Index) const;
    
    // ���� ���
    void ShowShopScreen(const Player& player, const std::vector<InventorySlot>& shopItems, int selectedIndex) const;

    // ���� ���
    void ShowEnding();

    // ȭ�� ����
    void ClearScreen() const { system("CLS"); }

private:
};

