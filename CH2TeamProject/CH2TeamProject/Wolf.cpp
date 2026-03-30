// Wolf.cpp

#include "Wolf.h"
#include <random>
#include <iostream>
#include <ctime>
#include "LogManager.h"

Wolf::Wolf(int playerLevel) : Monster("늑대")
{
    int baseHP = 30 + (playerLevel * 1.1); 
    int baseAtt = 10 + (playerLevel * 1.1);  
    int randomHP = baseHP * (rand() % 11) / 100;
    int randomAtt = baseAtt * (rand() % 6) / 100;
    SetLvl(4); 
    SetGivingGold(50); 
    SetGivingExp(200);
    SetMaxHP(baseHP + randomHP); 
    SetCurrentHP(baseHP + randomHP); 
    SetAtt(baseAtt + randomAtt);
    SetDef(5);
    SetSpd(6);
}

void Wolf::Draw() const
{
    LogManager::PrintMonsterBox("                  ,/{}", 7);
    LogManager::PrintMonsterBox("                ,/  {|", 8);
    LogManager::PrintMonsterBox("            ,,,/    {|,", 9);
    LogManager::PrintMonsterBox("      __--~~        {| ~-,", 10);
    LogManager::PrintMonsterBox("__--~~              {     `\\", 11);
    LogManager::PrintMonsterBox("                         ,__ \\", 12);
    LogManager::PrintMonsterBox("                        `,\\{),\\,", 13);
    LogManager::PrintMonsterBox("                       __-~  `_ ~-_", 14);
    LogManager::PrintMonsterBox("                    _-~        ~~-_`~-_", 15);
    LogManager::PrintMonsterBox("                   '                `~-_`~-__", 16);
    LogManager::PrintMonsterBox("                   `,                   `~-\\_|", 17);
    LogManager::PrintMonsterBox("                    `,      _-----___    _,'", 18);
    LogManager::PrintMonsterBox("                    / /--__  ~~--__  `~,~", 19);
    LogManager::PrintMonsterBox("                     /      ~~--__  ~-',", 20);
    LogManager::PrintMonsterBox("                    /            ~~--'", 21);
    LogManager::PrintMonsterBox("   [ 늑대가 울부짖습니다. ]", 22);
}

