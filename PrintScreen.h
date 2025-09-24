#pragma once
#include "Player.h"
#include "Map.h"

class PrintScreen
{
public:
    // �ΰ� ȭ��
    void ShowLogoTop() const;
    void ShowLogoBottom() const;

    // �÷��̾� �̸� �Է� ȭ��
    void ShowPlayerName() const;

    // ��ũ��Ʈ ���
    void ShowScript(std::string Script, int ScriptLen) const;
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

    void ShowBattleScreen();    // ���� ȭ��
    void ShowEnding();          // ���� ���
    
    // ȭ�� ����
    void ClearScreen() const { system("CLS"); }

private:
};

