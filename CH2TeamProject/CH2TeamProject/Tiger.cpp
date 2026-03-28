// Tiger.cpp

#include "Tiger.h"
#include <random>
#include <iostream>
#include <ctime>
#include "LogManager.h"

Tiger::Tiger(int playerLevel) : Monster("호랑이")
{
    int baseHP = 630 + (playerLevel * 1.1); 
    int baseAtt = 180 + (playerLevel * 1.1);  
    int randomHP = rand() % 21;  
    int randomAtt = rand() % 6;  
    SetLvl(25); 
    SetGivingGold(700); 
    SetGivingExp(1100); 
    SetMaxHP(baseHP + randomHP); 
    SetCurrentHP(baseHP + randomHP); 
    SetAtt(baseAtt + randomAtt);
    SetDef(70);
    SetSpd(27);
}

void Tiger::Draw() const
{
    LogManager::PrintMonsterBox("                          __,,,,_", 7);
    LogManager::PrintMonsterBox("           _ ___.--'''`--''// ,-_ `-.", 8);
    LogManager::PrintMonsterBox("       \\`\"' ' |  \\  \\ \\\\/ / // / ,-  `,_", 9);
    LogManager::PrintMonsterBox("      /'`  \\   |  Y  | \\|/ / // / -.,__ `-.", 10);
    LogManager::PrintMonsterBox("     /<\"\\    \\ \\  |  | ||/ // | \\/    |`-._`-._", 11);
    LogManager::PrintMonsterBox("    /  _.-.  .-\\,___|  _-| / \\ \\/|_/  |    `-._", 12);
    LogManager::PrintMonsterBox("    `-'  f/ |        / __/ \\__  / |__/ |", 13);
    LogManager::PrintMonsterBox("         `-'       |  -| -|\\__ \\  |-' |", 14);
    LogManager::PrintMonsterBox("                __/   /__,-'    ),'  |'", 15);
    LogManager::PrintMonsterBox("               ((__.-'((____..-' \\__,'", 16);
    LogManager::PrintMonsterBox("   [ 숲속의 은둔자 너구리가 나타났습니다! ]", 17);
}
