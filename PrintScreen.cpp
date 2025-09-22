#include <stdio.h>
#include <Windows.h>
#include "PrintScreen.h"

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
    printf("����\n");
}

