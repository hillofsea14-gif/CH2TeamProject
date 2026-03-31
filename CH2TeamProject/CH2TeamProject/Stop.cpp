// PlayerDead.cpp

#include <windows.h>
#include "Stop.h"
#include "LogManager.h"
#include <iostream>

#pragma comment(lib, "winmm.lib")

void ShowStopEnding()
{
    ::PlaySoundA("dead.wav", NULL, SND_FILENAME | SND_ASYNC);

    LogManager::ClearScreen();
    LogManager::PrintStopGameScreen();
    system("pause");
}
