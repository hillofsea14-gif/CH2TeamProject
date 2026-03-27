// Bear.cpp

#include "Bear.h"
#include <random>
#include <iostream>
#include <ctime>
#include "LogManager.h"


Bear::Bear(int playerLevel) : Monster("곰")
{
    // [승민] 기초 스탯 결정 (레벨에 비례)
    int baseHP = 100 + (playerLevel * 20); // [승민] 플레이어 레벨당 체력 20 증가
    int baseAtt = 20 + (playerLevel * 5);  // [승민] 플레이어 레벨당 공격력 5 증가

    int randomHP = rand() % 21;  // [승민] 랜덤 난수 최소0% ~ 최대 20%
    int randomAtt = rand() % 6;  // [승민] 랜덤 난수 최소0% ~ 최대 5%

    SetMaxHP(baseHP + randomHP); // [승민] HP 세분화
    SetCurrentHP(baseHP + randomHP); // [승민] HP 세분화
    SetAtt(baseAtt + randomAtt);
    SetDef(10 + playerLevel);    
    SetSpd(5);
}

void Bear::PrintBear()
{
    LogManager::PrintMonsterBox("         __         __", 0);
    LogManager::PrintMonsterBox("        /  \\.-\"\"\"-./  \\", 1);
    LogManager::PrintMonsterBox("        \\    -   -    /", 2);
    LogManager::PrintMonsterBox("         |   o   o   |", 3);
    LogManager::PrintMonsterBox("         \\  .-'''-.  /    (크오오오!)", 4);
    LogManager::PrintMonsterBox("       /  '-\\__Y__/-' \\", 5);
    LogManager::PrintMonsterBox("      /      `---`     \\", 6);
    LogManager::PrintMonsterBox("     /   ______  _______\\", 7);
    LogManager::PrintMonsterBox("    /  _______________   \\", 8);
    LogManager::PrintMonsterBox("   /  /               \\   \\", 9);
    LogManager::PrintMonsterBox("  |  |      / \\/ \\     |  |", 10);
    LogManager::PrintMonsterBox("  |  |     |      |    |  |", 11);
    LogManager::PrintMonsterBox("   \\  \\     \\____/    /  /", 12);
    LogManager::PrintMonsterBox("    \\\\__\\____________/__/", 13);
    LogManager::PrintMonsterBox("[ 거대한 곰이 바위 뒤에서 일어납니다! ]", 15);
}
