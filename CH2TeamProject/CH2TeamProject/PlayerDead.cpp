// PlayerDead.cpp

#include <windows.h>
#include "PlayerDead.h"
#include "LogManager.h"
#include <iostream>

#pragma comment(lib, "winmm.lib")

void ShowDeadEnding()
{
    ::PlaySoundA("dead.wav", NULL, SND_FILENAME | SND_ASYNC);

    LogManager::ClearScreen();
    LogManager::PrintPlayerDeadScreen();
    system("pause");
}

