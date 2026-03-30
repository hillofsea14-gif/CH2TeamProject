// Spide.cpp

#include "Spider.h"
#include <random>
#include <iostream>
#include <ctime>
#include "LogManager.h"

Spider::Spider(int playerLevel) : Monster("독거미")
{
    int baseHP = 90 + (playerLevel * 1.1); 
    int baseAtt = 50 + (playerLevel * 1.1);  
    int randomHP = baseHP * (rand() % 11) / 100;
    int randomAtt = baseAtt * (rand() % 6) / 100;
    SetLvl(12); 
    SetGivingGold(140); 
    SetGivingExp(520); 
    SetMaxHP(baseHP + randomHP); 
    SetCurrentHP(baseHP + randomHP); 
    SetAtt(baseAtt + randomAtt);
    SetDef(15);
    SetSpd(14);
}   

void Spider::Draw() const
{
    LogManager::PrintMonsterBox("           / _ \\", 7);
    LogManager::PrintMonsterBox("         \\_\\(_)/_/", 8);
    LogManager::PrintMonsterBox("         _//( )\\\\_", 9);
    LogManager::PrintMonsterBox("          / / \\ \\", 10);
    LogManager::PrintMonsterBox("   [ 치명적인 독을 가진 거미가 나타났습니다! ]", 11);
}
