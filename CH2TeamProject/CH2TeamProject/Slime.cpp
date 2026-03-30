// Slime.cpp

#include "Slime.h"
#include "Character.h"
#include <iostream>
#include <string>
#include "LogManager.h"


Slime::Slime(int playerLevel) : Monster("슬라임")
{
    int baseHP = 20 + (playerLevel * 1.1); 
    int baseAtt = 5 + (playerLevel * 1.1);  

    int randomHP = baseHP * (rand() % 11) / 100;
    int randomAtt = baseAtt * (rand() % 6) / 100;

    SetLvl(1); 
    SetGivingGold(30); 
    SetGivingExp(100); 
    SetMaxHP(baseHP + randomHP); 
    SetCurrentHP(baseHP + randomHP); 
    SetAtt(baseAtt + randomAtt);
    SetDef(5);
    SetSpd(4);
}
void Slime::Draw() const
    {
        LogManager::PrintMonsterBox("              @", 7);
        LogManager::PrintMonsterBox("             /", 8);
        LogManager::PrintMonsterBox("         ---- ----", 9);
        LogManager::PrintMonsterBox("      --            --", 10);
        LogManager::PrintMonsterBox("     |    *    *       |", 11);
        LogManager::PrintMonsterBox("     |      __         |", 12);
        LogManager::PrintMonsterBox("      \\               /", 13);
        LogManager::PrintMonsterBox("         -----------", 14);
    }

