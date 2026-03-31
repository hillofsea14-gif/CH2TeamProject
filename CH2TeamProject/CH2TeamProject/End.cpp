// End.cpp

#include "End.h"
#include "LogManager.h"
#include <iostream>

void ShowEnding()
{
    LogManager::ClearScreen();
    LogManager::PrintEndScreen();
    // 여기에 추가적인 엔딩 연출이나 크레딧 삽입
    system("pause");
}
