// WildBoar.cpp

#include "WildBoar.h"
#include <random>
#include <iostream>
#include <ctime>
#include "LogManager.h"

WildBoar::WildBoar(int playerLevel) : Monster("멧돼지")
{
    int baseHP = 300 + (playerLevel * 1.1); 
    int baseAtt = 90 + (playerLevel * 1.1);  
    int randomHP = rand() % 21;  
    int randomAtt = rand() % 6;  
    SetLvl(21); 
    SetGivingGold(500); 
    SetGivingExp(250); 
    SetMaxHP(baseHP + randomHP); 
    SetCurrentHP(baseHP + randomHP); 
    SetAtt(baseAtt + randomAtt);
    SetDef(50);
    SetSpd(24);
}

void WildBoar::Draw() const
{
    LogManager::PrintMonsterBox("               .___------___", 7);
    LogManager::PrintMonsterBox("           ___/             \\/\\.", 8);
    LogManager::PrintMonsterBox("/      __/                   /   \\__---___", 9);
    LogManager::PrintMonsterBox("\\_O--/                      |    \\   ___ \\", 10);
    LogManager::PrintMonsterBox("    |                        \\_     / . \\ \\", 11);
    LogManager::PrintMonsterBox("    |                                -----  |", 12);
    LogManager::PrintMonsterBox("     \\        )            )               \\___", 13);
    LogManager::PrintMonsterBox("      |        )      |     )          .       \\__|", 14);
    LogManager::PrintMonsterBox("       \\       )     /     )          /|          |", 15);
    LogManager::PrintMonsterBox("        |     |__.___|    |  \\        | |______----|", 16);
    LogManager::PrintMonsterBox("         \\_______|___|    )    \\      \\ \\______. ", 17);
    LogManager::PrintMonsterBox("                \\___/    /        ----__________ )", 18);
    LogManager::PrintMonsterBox("                 \\_\\____/  ", 19);
    LogManager::PrintMonsterBox("   [ 야생의 멧돼지가 당신을 향해 돌진합니다! ]", 20);
}
