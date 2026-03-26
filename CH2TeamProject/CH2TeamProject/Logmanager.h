#pragma once
#include <string>

class LogManager
{
public:
    static void PrintLine();
    static void PrintTitle(const std::string& title);
    static void PrintMessage(const std::string& message);
    static void PrintCenter(const std::string& text);
    static void PrintEncounter(const std::string& monsterName);
    static void PrintBattleStart();
    static void PrintPlayerTurnMenu();
    static void PrintRunAway();
    static void PrintInvalidInput();
    static void PrintEnemyTurn();
    static void PrintMainMenu();
    static void PrintStartScreen();
    static void PrintCenterInputPrompt();
};
