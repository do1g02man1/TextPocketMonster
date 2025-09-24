#include <stdio.h>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <iostream>
#include "PrintScreen.h"
#include "Player.h"

void PrintScreen::ShowLogoTop() const
{
    system("CLS");
    printf("\n\n\n\n\n\n");
    printf("\t   _______________________________________________________________________\n");
    printf("\t       ____        __      _    _    _____     _   _       __      _     _\n");
    printf("\t       /    )    /    )    /  ,'     /    '    /  /|     /    )    /|   / \n");
    printf("\t   ---/____/----/----/----/_.'------/__-------/| /-|----/----/----/-| -/--\n");
    printf("\t     /         /    /    /  \\      /         / |/  |   /    /    /  | /   \n");
    printf("\t   _/_________(____/____/____\\____/____ ____/__/___|__(____/____/___|/____\n\n\n");
    printf("\t   *                          TEXT RPG ADVENTURE                          *\n\n\n");

    printf("\t\t\t\t  �� ����\n\n");
    printf("\t\t\t\t  ����\n\n");
    printf("\t\t\t\t  Z�� ������ �����մϴ�.");
}

void PrintScreen::ShowLogoBottom() const
{
    system("CLS");
    printf("\n\n\n\n\n\n");
    printf("\t   _______________________________________________________________________\n");
    printf("\t       ____        __      _    _    _____     _   _       __      _     _\n");
    printf("\t       /    )    /    )    /  ,'     /    '    /  /|     /    )    /|   / \n");
    printf("\t   ---/____/----/----/----/_.'------/__-------/| /-|----/----/----/-| -/--\n");
    printf("\t     /         /    /    /  \\      /         / |/  |   /    /    /  | /   \n");
    printf("\t   _/_________(____/____/____\\____/____ ____/__/___|__(____/____/___|/____\n\n\n");
    printf("\t   *                          TEXT RPG ADVENTURE                          *\n\n\n");

    printf("\t\t\t\t  ����\n\n");
    printf("\t\t\t\t  �� ����\n\n");
    printf("\t\t\t\t  Z�� ������ �����մϴ�.");
}

void PrintScreen::ShowPlayerName() const
{
    //system("mode con: cols=120 lines=40");
    ClearScreen();
    
    std::string ScriptDoctor = "[???] : ������, ���� �Ա���!\n\n(�Ͼ� ������ ���� ������ õõ�� �ٰ��´�.)\n\n[���ڻ�] : ó�� ���� ���̱�.\n���� �� ������ ���ϸ��� �����ϴ� ���ڻ���.\n\n"
        "[���ڻ�]\n�ڳ״� �̸��� ����� ����?\n(�÷��̾� �̸� �Է�) -> ";

    int ScriptLen = ScriptDoctor.length();
    ShowScriptSleep(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowScript(std::string ScriptDoctor, int ScriptLen) const
{
    ClearScreen();

    for (int i = 0; i < ScriptLen; i++)
    {
        printf("%c", ScriptDoctor[i]);
    }
}

void PrintScreen::ShowScriptSleep(std::string ScriptDoctor, int ScriptLen) const
{
    ClearScreen();

    for (int i = 0; i < ScriptLen; i++)
    {
        printf("%c", ScriptDoctor[i]);
        Sleep(10);
    }
}

void PrintScreen::ShowProfessorIntro(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetPlayerName();
    std::string ScriptDoctor = "[���ڻ�]\n��, �׷���.\n�ڳ� �̸��� \"" + PlayerName + "\" (��)�α�!\n\n[���ڻ�]\n����, " + PlayerName + "!\n���� �ڳ��� ���ϸ� ������ �� ���۵Ǵ±���!\n\n"
        "[���ڻ�]\n����, ������ ���迡�� �׻� ����� ���ᰡ �ʿ�����.\n�ڳ��� ù ��° ���ϸ��� �� �ð��� �Գ�.\n\n(���ڻ簡 å�� ���� �� ���� ���ͺ��� ����Ų��.)\n\n[���ڻ�]\n"
        "���� �� ������ ���ϸ��� �ֳ�.\n�ڳ׿� �Բ��� �� �ִ� ģ��������.\n\n1. �Ҳɼ��� - �������������ϸ�\n\n2. �ص��� - ������ϸ�\n\n3. ��α� - ������ϸ�\n\n[���ڻ�]\n��, � ���ϸ��� �����ϰڳ�?\n"
        "(����Ű�� �̵�, Z Ű�� ����)";

    int ScriptLen = ScriptDoctor.length();
    ShowScriptSleep(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowPokemonSelection1(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetPlayerName();
    std::string ScriptDoctor = "[���ڻ�]\n��, �׷���.\n�ڳ� �̸��� \"" + PlayerName + "\" (��)�α�!\n\n[���ڻ�]\n����, " + PlayerName + "!\n���� �ڳ��� ���ϸ� ������ �� ���۵Ǵ±���!\n\n"
        "[���ڻ�]\n����, ������ ���迡�� �׻� ����� ���ᰡ �ʿ�����.\n�ڳ��� ù ��° ���ϸ��� �� �ð��� �Գ�.\n\n(���ڻ簡 å�� ���� �� ���� ���ͺ��� ����Ų��.)\n\n[���ڻ�]\n"
        "���� �� ������ ���ϸ��� �ֳ�.\n�ڳ׿� �Բ��� �� �ִ� ģ��������.\n\n�� 1. �Ҳɼ��� - �������������ϸ�\n\n2. �ص��� - ������ϸ�\n\n3. ��α� - ������ϸ�\n\n[���ڻ�]\n��, � ���ϸ��� �����ϰڳ�?\n"
        "(����Ű�� �̵�, Z Ű�� ����)";

    int ScriptLen = ScriptDoctor.length();
    ShowScript(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowPokemonSelection2(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetPlayerName();
    std::string ScriptDoctor = "[���ڻ�]\n��, �׷���.\n�ڳ� �̸��� \"" + PlayerName + "\" (��)�α�!\n\n[���ڻ�]\n����, " + PlayerName + "!\n���� �ڳ��� ���ϸ� ������ �� ���۵Ǵ±���!\n\n"
        "[���ڻ�]\n����, ������ ���迡�� �׻� ����� ���ᰡ �ʿ�����.\n�ڳ��� ù ��° ���ϸ��� �� �ð��� �Գ�.\n\n(���ڻ簡 å�� ���� �� ���� ���ͺ��� ����Ų��.)\n\n[���ڻ�]\n"
        "���� �� ������ ���ϸ��� �ֳ�.\n�ڳ׿� �Բ��� �� �ִ� ģ��������.\n\n1. �Ҳɼ��� - �������������ϸ�\n\n�� 2. �ص��� - ������ϸ�\n\n3. ��α� - ������ϸ�\n\n[���ڻ�]\n��, � ���ϸ��� �����ϰڳ�?\n"
        "(����Ű�� �̵�, Z Ű�� ����)";

    int ScriptLen = ScriptDoctor.length();
    ShowScript(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowPokemonSelection3(const Player& PlayerInstance) const
{
    std::string PlayerName = PlayerInstance.GetPlayerName();
    std::string ScriptDoctor = "[���ڻ�]\n��, �׷���.\n�ڳ� �̸��� \"" + PlayerName + "\" (��)�α�!\n\n[���ڻ�]\n����, " + PlayerName + "!\n���� �ڳ��� ���ϸ� ������ �� ���۵Ǵ±���!\n\n"
        "[���ڻ�]\n����, ������ ���迡�� �׻� ����� ���ᰡ �ʿ�����.\n�ڳ��� ù ��° ���ϸ��� �� �ð��� �Գ�.\n\n(���ڻ簡 å�� ���� �� ���� ���ͺ��� ����Ų��.)\n\n[���ڻ�]\n"
        "���� �� ������ ���ϸ��� �ֳ�.\n�ڳ׿� �Բ��� �� �ִ� ģ��������.\n\n1. �Ҳɼ��� - �������������ϸ�\n\n2. �ص��� - ������ϸ�\n\n�� 3. ��α� - ������ϸ�\n\n[���ڻ�]\n��, � ���ϸ��� �����ϰڳ�?\n"
        "(����Ű�� �̵�, Z Ű�� ����)";

    int ScriptLen = ScriptDoctor.length();
    ShowScript(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowAfterSelect(const Player& PlayerInstance) const
{
    std::string PokemonName = PlayerInstance.GetStartPokemonName();
    std::string ScriptDoctor = "[���ڻ�]\n\n����, �ڳװ� ������ ���ϸ��� �ٷ� " + PokemonName + "����!\n����, ���� �� ����� �Բ� ������ ���� �غ� �Ǿ���.\n\n"
        "[���ڻ�]\n���� �߿��� �پ��� ���ϸ��� ��Ÿ����,\n���δ� ����ġ ���� ��Ȳ�� �´ڶ߸� �ž�.\n������ �ڳ׿� " + PokemonName + "��� ���� ���� �ɼ�.\n\n"
        "[���ڻ�]\n�׷� ���ϸ����� �����!";

    int ScriptLen = ScriptDoctor.length();
    ShowScriptSleep(ScriptDoctor, ScriptLen);
}

void PrintScreen::ShowMap(const Map& MapData) const
{
    ClearScreen();
    for (int x = 0; x < MapData.GetHeight(); x++)
    {
        for (int y = 0; y < MapData.GetWidth(); y++)
        {
            printf("%c", MapData.GetTile(x, y));
        }
        printf("\n");
    }
}

