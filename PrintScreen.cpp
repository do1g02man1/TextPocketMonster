#include <stdio.h>
#include <Windows.h>
#include "PrintScreen.h"
#include <string>
#include <conio.h>

void PrintScreen::PrintLogoTop() const
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

void PrintScreen::PrintLogoBottom() const
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

void PrintScreen::GameStart() const
{
    system("mode con: cols=120 lines=40");
    system("CLS");
    
    std::string ScriptDoctor = "??? : ������, ���� �Ա���!\n\n(�Ͼ� ������ ���� ������ õõ�� �ٰ��´�.)\n\n���ڻ� : ó�� ���� ���̱�.\n���� ���ϸ��� �����ϴ� ���ڻ��� �Ѵٳ�.\n\n"
        "���ڻ� : �ڳ״� ���� �� ������ �������� ���� Ʈ���̳���?\n�׷��ٸ� ������ ���ϸ��� �ʿ��� �Ծ�.\n\n(���ڻ簡 å�� ���� �� ���� ���ͺ��� ����Ų��.)\n\n"
        "���ڻ� : ���� �� ������ ���ϸ��� �ֳ�.\n�ڳ��� ���ᰡ �Ǿ� �� ģ��������.\n\n"
        "1. �Ҳ� ���ϸ� - ������ �ұ�� ��븦 �����Ѵ�.\n2. �� ���ϸ� - �����ϰ� �������� ���� ��Ÿ���� �ڶ�����.\n3. Ǯ ���ϸ� - ������ ��������� ���� ��Ƽ�� Ÿ���̶��.\n\n"
        "���ڻ� : ��, � ���ϸ��� �����ϰڳ�?\nZ�� ���� / ����Ű�� �̵�)";

    int ScriptLen = ScriptDoctor.length();
    char UserInput = NULL;
    
    for (int i = 0; i < ScriptLen; i++)
    {
        printf("%c", ScriptDoctor[i]);
        Sleep(20);
    }
}

