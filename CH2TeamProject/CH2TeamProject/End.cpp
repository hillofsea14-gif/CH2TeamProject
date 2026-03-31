// End.cpp

#include <Windows.h> // PlayerSoundA
#include "End.h"
#include "LogManager.h"
#include <iostream>

#pragma comment(lib, "winmm.lib")

void ShowEnding()
{
    ::PlaySoundA("ending.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    LogManager::ClearScreen();
    LogManager::PrintEndScreen();
    // 여기에 추가적인 엔딩 연출이나 크레딧 삽입
    system("pause");
}
