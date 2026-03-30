//WildCat.cpp

#include "WildCat.h"
#include <random>
#include <iostream>
#include <ctime>
#include "LogManager.h"

WildCat::WildCat(int playerLevel) : Monster("살쾡이")
{
    int baseHP = 50 + (playerLevel * 1.1); 
    int baseAtt = 25 + (playerLevel * 1.1);  
    int randomHP = baseHP * (rand() % 11) / 100;
    int randomAtt = baseAtt * (rand() % 6) / 100;
    SetLvl(6); 
    SetGivingGold(70); 
    SetGivingExp(240); 
    SetMaxHP(baseHP + randomHP); 
    SetCurrentHP(baseHP + randomHP); 
    SetAtt(baseAtt + randomAtt);
    SetDef(10);
    SetSpd(12);
}

void WildCat::Draw() const  
{
    LogManager::PrintMonsterBox("       _                _", 7);
    LogManager::PrintMonsterBox("      / \\______________/ \\", 8);
    LogManager::PrintMonsterBox("     /   ___      ___    \\", 9);
    LogManager::PrintMonsterBox("    |   /   \\    /   \\   |", 10);
    LogManager::PrintMonsterBox("    |  | (0) |  | (0) |  |   ( 슬쩍... )", 11);
    LogManager::PrintMonsterBox("    |   \\___/    \\___/   |", 12);
    LogManager::PrintMonsterBox("     \\_______U__________/", 13    );
    LogManager::PrintMonsterBox("             |  |", 14);
    LogManager::PrintMonsterBox("            /    \\", 15);
    LogManager::PrintMonsterBox("           /      \\", 16);
    LogManager::PrintMonsterBox("          |        |", 17);
    LogManager::PrintMonsterBox("          |   ||   |", 18);
    LogManager::PrintMonsterBox("          |   ||   |", 19);
    LogManager::PrintMonsterBox("          /   ||   \\", 20);
    LogManager::PrintMonsterBox("         /____||____\\", 21);
    LogManager::PrintMonsterBox("   [ 살쾡이가 먹잇감을 노려보고 있습니다...]", 22);
}
