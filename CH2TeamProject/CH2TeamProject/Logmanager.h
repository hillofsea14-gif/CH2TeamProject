#pragma once
#include <string>
#include <vector>

class Item;

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
    static void GoToXY(int x, int y);
    static void ClearScreen();
    static void DrawBattleUI();
    static void PrintBattleLog(const std::string& message, int line);
    static void PrintInfoBox(const std::string& message, int line);
    static void PrintMonsterBox(const std::string& message, int line);
    static void PrintPlayerInfo(const std::string& name, int hp, int maxHP, int att, int def, int spd, int gold,  float currentExp, float maxExp, const std::vector<std::shared_ptr<Item>>& items);
    static void PrintMonsterInfo(const std::string& name, int hp, int maxHP, int att, int def, int spd);
    static void PrintBattleMenuUI();
    static void ClearRightPanel();
    static void DrawMainMenuInRightPanel();
    static void DrawPlayerStatusInRightPanel(
        const std::string& name,
        int hp,
        int maxHP,
        int att,
        int def,
        int spd,
        int gold);
    static void ClearBattleLogArea();
    static void ClearInfoArea();
    static void SetConsoleSize(int Width, int Height);

};
