// Gorani.cpp

#include "Gorani.h"
#include <random>
#include <iostream>
#include <ctime>
#include "LogManager.h"

Gorani::Gorani(int playerLevel) : Monster("고라니")
{
    int baseHP = 105 + (playerLevel * 1.1); 
    int baseAtt = 50 + (playerLevel * 1.1);  
    int randomHP = rand() % 21;  
    int randomAtt = rand() % 6;  
    SetLvl(9); 
    SetGivingGold(100); 
    SetGivingExp(100); 
    SetMaxHP(baseHP + randomHP); 
    SetCurrentHP(baseHP + randomHP); 
    SetAtt(baseAtt + randomAtt);
    SetDef(15);
    SetSpd(10);
}

void Gorani::Draw() const
{
    LogManager::PrintMonsterBox("   ___       ___", 7);
    LogManager::PrintMonsterBox("  /   \\     /   \\", 8);
    LogManager::PrintMonsterBox(" |     |___|     |", 9);
    LogManager::PrintMonsterBox(" |      V W V    |", 10);
    LogManager::PrintMonsterBox("  \\      ---     /", 11);
    LogManager::PrintMonsterBox("   /  ^     ^    \\", 12);
    LogManager::PrintMonsterBox("  (       _      )", 13);
    LogManager::PrintMonsterBox("   \\     \\_/    /", 14);
    LogManager::PrintMonsterBox("    \\   |V V|  /", 15);
    LogManager::PrintMonsterBox("     -- --- --", 16);
    LogManager::PrintMonsterBox("       /   \\", 17);
    LogManager::PrintMonsterBox("   [ 괴성을 지르는 야생의 고라니 출현! ]", 18);
}
