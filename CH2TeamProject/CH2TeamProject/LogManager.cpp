#include <iostream>
#include <string>
#include <windows.h>
#include "LogManager.h"


void LogManager::PrintLine()
{
    std::cout << "========================================" << std::endl;
}

void LogManager::PrintTitle(const std::string& title)
{
    PrintLine();
    std::cout << " " << title << std::endl;
    PrintLine();
}

void LogManager::PrintMessage(const std::string& message)
{
    std::cout << message << std::endl;
}

void LogManager::PrintEncounter(const std::string& monsterName)
{
    PrintLine();
    std::cout << "몬스터 [" << monsterName << "] 와(과) 조우했습니다!" << std::endl;
    PrintLine();
}

void LogManager::PrintBattleStart()
{
    std::cout << "전투에 돌입합니다!!!" << std::endl;
}

void LogManager::PrintPlayerTurnMenu()
{
    std::cout << "\n당신의 행동을 선택하세요." << std::endl;
    std::cout << "1. 공격" << std::endl;
    std::cout << "2. 가방" << std::endl;
    std::cout << "3. 도망간다" << std::endl;
    std::cout << "선택: ";

}

void LogManager::PrintRunAway()
{
    std::cout << "당신은 도망쳤습니다..." << std::endl;
}

void LogManager::PrintInvalidInput()
{
    std::cout << "잘못된 입력입니다." << std::endl;
}

void LogManager::PrintEnemyTurn()
{
    std::cout << "상대가 공격합니다." << std::endl;
}

void LogManager::PrintMainMenu()
{
    std::cout << "\n========= 메뉴 =========" << std::endl;
    std::cout << "1. 전투 입장" << std::endl;
    std::cout << "2. 스텟창" << std::endl;
    std::cout << "3. 미정" << std::endl;
    std::cout << "4. 미정" << std::endl;
    std::cout << "5. 게임 종료" << std::endl;
    std::cout << "선택: ";
}

void LogManager::PrintStartScreen()
{
    std::cout << "\n\n\n\n\n\n";


    std::cout << "                                                ==========================\n\n";
    std::cout << "                                                         집 으 로\n\n";
    std::cout << "                                                ==========================\n\n";
    std::cout << "\n\n";

    std::cout << "                                                ==========================\n\n";
    std::cout << "                                                     당신의 이름은...?\n\n";
    std::cout << "                                                ==========================\n\n\n";
    std::cout << "\n";
    std::cout << "                                                >> ";
}

void LogManager::PrintCenter(const std::string& text)
{
    const int width = 100;
    int padding = (width - static_cast<int>(text.size())) / 2;

    if (padding < 0)
        padding = 0;

    std::cout << std::string(padding, ' ') << text << std::endl;
}

void LogManager::PrintCenterInputPrompt()
{
    const int width = 100;
    std::string prompt = ">> ";
    int padding = (width - static_cast<int>(prompt.size())) / 2;

    if (padding < 0)
        padding = 0;

    std::cout << std::string(padding, ' ') << prompt;
}

void LogManager::GoToXY(int x, int y)
{
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void LogManager::ClearScreen()
{
    system("cls");
}

void LogManager::DrawBattleUI()
{
    ClearScreen();

    const int width = 100;
    const int height = 30;

    // 바깥 테두리
    for (int x = 0; x < width; x++)
    {
        GoToXY(x, 0);
        std::cout << "=";
        GoToXY(x, height - 1);
        std::cout << "=";
    }

    for (int y = 0; y < height; y++)
    {
        GoToXY(0, y);
        std::cout << "|";
        GoToXY(width - 1, y);
        std::cout << "|";
    }

    // 왼쪽 / 오른쪽 구분선
    for (int y = 1; y < height - 1; y++)
    {
        GoToXY(41, y);
        std::cout << "|";
    }

    // 왼쪽 위 / 아래 구분선
    for (int x = 1; x < 41; x++)
    {
        GoToXY(x, 15);
        std::cout << "-";
    }

    // 제목
    GoToXY(2, 1);
    std::cout << "[ 배틀 로그 ]";

    GoToXY(2, 16);
    std::cout << "[ 정보 ]";

    GoToXY(46, 1);
    std::cout << "[ 몬스터 / 전투 화면 ]";
}

void LogManager::PrintBattleLog(const std::string& message, int line)
{
    GoToXY(2, 3 + line);
    std::cout << "                                "; 
    GoToXY(2, 3 + line);
    std::cout << message;
}

void LogManager::PrintInfoBox(const std::string& message, int line)
{
    GoToXY(2, 18 + line);
    std::cout << "                                ";
    GoToXY(2, 18 + line);
    std::cout << message;
}

void LogManager::PrintMonsterBox(const std::string& message, int line)
{
    GoToXY(46, 3 + line);
    std::cout << "                                                    ";
    GoToXY(46, 3 + line);
    std::cout << message;
}

void LogManager::PrintPlayerInfo(const std::string& name, int hp, int maxHP, int att, int def, int spd)
{
    PrintInfoBox("이름 : " + name, 0);
    PrintInfoBox("HP : " + std::to_string(hp) + " / " + std::to_string(maxHP), 1);
    PrintInfoBox("공격력 : " + std::to_string(att), 2);
    PrintInfoBox("방어력 : " + std::to_string(def), 3);
    PrintInfoBox("속도 : " + std::to_string(spd), 4);
}

void LogManager::PrintMonsterInfo(const std::string& name, int hp, int maxHP, int att, int def, int spd)
{
    PrintMonsterBox("이름 : " + name, 0);
    PrintMonsterBox("HP : " + std::to_string(hp) + " / " + std::to_string(maxHP), 1);
    PrintMonsterBox("공격력 : " + std::to_string(att), 2);
    PrintMonsterBox("방어력 : " + std::to_string(def), 3);
    PrintMonsterBox("속도 : " + std::to_string(spd), 4);
}

void LogManager::PrintBattleMenuUI()
{
    GoToXY(2, 26);
    std::cout << "1. 공격   2. 가방   3. 도망가기          ";

    GoToXY(2, 27);
    std::cout << "선택 :                    ";
}
