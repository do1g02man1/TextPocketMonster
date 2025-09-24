#pragma once
#include "Player.h"
#include "Map.h"

class PrintScreen
{
public:
    // 로고 화면
    void ShowLogoTop() const;
    void ShowLogoBottom() const;

    // 플레이어 이름 입력 화면
    void ShowPlayerName() const;

    // 스크립트 출력
    void ShowScript(std::string Script, int ScriptLen) const;
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

    void ShowBattleScreen();    // 전투 화면
    void ShowEnding();          // 엔딩 출력
    
    // 화면 삭제
    void ClearScreen() const { system("CLS"); }

private:
};

