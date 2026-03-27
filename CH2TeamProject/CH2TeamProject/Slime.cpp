// Slime.cpp

#include "Slime.h"
#include "Character.h"
#include <iostream>
#include <string>
#include "LogManager.h"


Slime::Slime() : Monster("슬라임")
{
    SetMaxHP(30);
    SetCurrentHP(30);
    SetAtt(5);
    SetDef(2);
    SetSpd(3);
}
void Slime::Draw() const
    {
        LogManager::PrintMonsterBox("              @", 5);
        LogManager::PrintMonsterBox("             /", 6);
        LogManager::PrintMonsterBox("         ---- ----", 7);
        LogManager::PrintMonsterBox("      --            --", 8);
        LogManager::PrintMonsterBox("     |    *    *       |", 9);
        LogManager::PrintMonsterBox("     |      __         |", 10);
        LogManager::PrintMonsterBox("      \\               /", 11);
        LogManager::PrintMonsterBox("         -----------", 12);
    }

