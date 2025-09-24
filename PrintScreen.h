#pragma once
#include "Player.h"

class PrintScreen
{
public:
	void ShowLogoTop() const;
	void ShowLogoBottom() const;                                    // 로고 화면
    void ShowPlayerName() const;                                    // 플레이어 이름 선택창 
    void ShowScript(std::string ScriptDoctor, int ScriptLen) const;
    void ShowScriptSleep(std::string ScriptDoctor, int ScriptLen) const;
    void ShowProfessorIntro(const Player& PlayerInstance) const;          // 오박사 대사
    void ShowPokemonSelection1(const Player& PlayerInstance) const; 
    void ShowPokemonSelection2(const Player& PlayerInstance) const; 
    void ShowPokemonSelection3(const Player& PlayerInstance) const; // 스타터 선택 UI
    void ShowAfterSelect(const Player& PlayerInstance) const;       // 스타터 선택 후
    void ShowBattleScreen();                                        // 전투 화면
    void ShowMap();                                                 // 맵 출력
    void ShowEnding();                                              // 엔딩 출력
    
    // 화면 삭제
    void ClearScreen() const { system("CLS"); }

    void TestMap();

private:
};

