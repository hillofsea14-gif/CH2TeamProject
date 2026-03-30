// Bear.cpp

#include "Bear.h"
#include <random>
#include <iostream>
#include <ctime>
#include "LogManager.h"


Bear::Bear(int playerLevel) : Monster("곰")
{
    // [승민] 기초 스탯 결정 (레벨에 비례)
    int baseHP = 300 + (playerLevel * 1.1); // [승민] 플레이어 레벨당 체력 1.1배 증가
    int baseAtt = 90 + (playerLevel * 1.1);  // [승민] 플레이어 레벨당 공격력 1.1배 증가

    int randomHP = baseHP * (rand() % 11) / 100;  // [승민] 랜덤 난수 최소0% ~ 최대 10%
    int randomAtt = baseAtt * (rand() % 6) / 100;  // [승민] 랜덤 난수 최소0% ~ 최대 5%

    SetLvl(23); // [승민] 몬스터 레벨 설정  
    SetGivingGold(450); // [승민] 처치시 플레이어 흭득 골드
    SetGivingExp(3200); // [승민] 처치시 플레이어 흭득 경험치
    SetMaxHP(baseHP + randomHP); // [승민] HP 세분화
    SetCurrentHP(baseHP + randomHP); // [승민] HP 세분화
    SetAtt(baseAtt + randomAtt);
    SetDef(50);    
    SetSpd(26);
}

void Bear::Draw() const
{
    LogManager::PrintMonsterBox("         __         __", 7);
    LogManager::PrintMonsterBox("        /  \\.-\"\"\"-./  \\", 8);
    LogManager::PrintMonsterBox("        \\    -   -    /", 9);
    LogManager::PrintMonsterBox("         |   o   o     |", 10);
    LogManager::PrintMonsterBox("         \\  .-'''-.  /    (크오오오!)", 11);
    LogManager::PrintMonsterBox("       /  '-\\__Y__/-' \\", 12);
    LogManager::PrintMonsterBox("      /      `---`     \\", 13);
    LogManager::PrintMonsterBox("     /   ______  _______\\", 14);
    LogManager::PrintMonsterBox("    /  _______________   \\", 15);
    LogManager::PrintMonsterBox("   /  /               \\   \\", 16);
    LogManager::PrintMonsterBox("  |  |      / \\/ \\     |  |", 17);
    LogManager::PrintMonsterBox("  |  |     |      |    |  |", 18);
    LogManager::PrintMonsterBox("   \\  \\     \\____/    /  /", 19);
    LogManager::PrintMonsterBox("    \\\\__\\____________/__/", 20);
    LogManager::PrintMonsterBox("[ 거대한 곰이 바위 뒤에서 일어납니다! ]", 21);
}
