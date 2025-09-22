#pragma once

class PrintScreen
{
public:
	// 로고 화면
	void ShowLogoTop() const;
	void ShowLogoBottom() const;         // 로고 화면
    void ShowProfessorIntro();           // 오박사 대사
    void ShowPokemonSelection();         // 스타터 선택 UI
    void ShowBattleScreen();             // 전투 화면
    void ShowMap();                      // 맵 출력
    void ShowEnding();                   // 엔딩 출력
};

