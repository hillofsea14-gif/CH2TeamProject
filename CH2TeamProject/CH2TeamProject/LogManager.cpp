#include <iostream>
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
    std::cout << "2. 도망간다" << std::endl;
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
