// Snake.cpp

#include "Snake.h"
#include <random>
#include <iostream>
#include <ctime>
#include "LogManager.h"

Snake::Snake(int playerLevel) : Monster("독뱀")
{
    int baseHP = 140 + (playerLevel * 1.1);
    int baseAtt = 90 + (playerLevel * 1.1);
    int randomHP = rand() % 21;
    int randomAtt = rand() % 6;
    SetLvl(14);
    SetGivingGold(180);
    SetGivingExp(150);
    SetMaxHP(baseHP + randomHP);
    SetCurrentHP(baseHP + randomHP);
    SetAtt(baseAtt + randomAtt);
    SetDef(30);
    SetSpd(16);
}

void Snake::Draw() const
{
    LogManager::PrintMonsterBox("           ____", 7);
    LogManager::PrintMonsterBox("          / . . \\", 8);
    LogManager::PrintMonsterBox("          \\  ---<   (스스슷...)", 9);
    LogManager::PrintMonsterBox("           \\  /", 10);
    LogManager::PrintMonsterBox("  __________/ /", 11);
    LogManager::PrintMonsterBox(" / __________/", 12);
    LogManager::PrintMonsterBox("/ /", 13);
    LogManager::PrintMonsterBox("\\ \\___________", 14);
    LogManager::PrintMonsterBox(" \\___________ \\", 15);
    LogManager::PrintMonsterBox("              \\ \\", 16);
    LogManager::PrintMonsterBox("     _________/ /", 17);
    LogManager::PrintMonsterBox("    \\__________/", 18);
    LogManager::PrintMonsterBox("   [ 치명적인 독을 가진 독뱀이 풀숲에 나타났습니다! ]", 19);
}
