// BigNuguri.cpp

#include "BigNuguri.h"
#include <random>
#include <iostream>
#include <ctime>
#include "LogManager.h"

BigNuguri::BigNuguri(int playerLevel) : Monster("대왕너구리")
{
    int baseHP = 300 + (playerLevel * 1.1); 
    int baseAtt = 60 + (playerLevel * 1.1);  
    int randomHP = baseHP * (rand() % 11) / 100;
    int randomAtt = baseAtt * (rand() % 6) / 100;
    SetLvl(20); 
    SetGivingGold(400); 
    SetGivingExp(2600); 
    SetMaxHP(baseHP + randomHP); 
    SetCurrentHP(baseHP + randomHP); 
    SetAtt(baseAtt + randomAtt);
    SetDef(35);
    SetSpd(20);
}

void BigNuguri::Draw() const
{
    LogManager::PrintMonsterBox("         __        __", 7);
    LogManager::PrintMonsterBox("        (` \\------/` )", 8);
    LogManager::PrintMonsterBox("        / _       _  \\      ____", 9);
    LogManager::PrintMonsterBox("       / ((^)   (^))  \\    /    )", 10);
    LogManager::PrintMonsterBox("      < __         __  >  /====/ ", 11);
    LogManager::PrintMonsterBox("      < __   (_)   __  > /    /", 12);
    LogManager::PrintMonsterBox("      /                \\/====/", 13);
    LogManager::PrintMonsterBox("     /   /|________|\\   \\   /", 14);
    LogManager::PrintMonsterBox("    /   /  ________  \\   \\=/", 15);
    LogManager::PrintMonsterBox("   (   (  /        \\  )   )", 16);
    LogManager::PrintMonsterBox("    \\   \\/          \\/   /", 17);
    LogManager::PrintMonsterBox("     \\__________________/", 18);
    LogManager::PrintMonsterBox("   [ 무지막지하게 커다란 대왕너구리 출현했습니다! ]", 19);
}
