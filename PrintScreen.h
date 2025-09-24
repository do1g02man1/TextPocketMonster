#pragma once
#include "Player.h"

class PrintScreen
{
public:
	void ShowLogoTop() const;
	void ShowLogoBottom() const;                                    // �ΰ� ȭ��
    void ShowPlayerName() const;                                    // �÷��̾� �̸� ����â 
    void ShowScript(std::string ScriptDoctor, int ScriptLen) const;
    void ShowScriptSleep(std::string ScriptDoctor, int ScriptLen) const;
    void ShowProfessorIntro(const Player& PlayerInstance) const;          // ���ڻ� ���
    void ShowPokemonSelection1(const Player& PlayerInstance) const; 
    void ShowPokemonSelection2(const Player& PlayerInstance) const; 
    void ShowPokemonSelection3(const Player& PlayerInstance) const; // ��Ÿ�� ���� UI
    void ShowAfterSelect(const Player& PlayerInstance) const;       // ��Ÿ�� ���� ��
    void ShowBattleScreen();                                        // ���� ȭ��
    void ShowMap();                                                 // �� ���
    void ShowEnding();                                              // ���� ���
    
    // ȭ�� ����
    void ClearScreen() const { system("CLS"); }

    void TestMap();

private:
};

