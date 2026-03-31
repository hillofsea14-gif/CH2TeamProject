// Main.cpp

#include "Start.h"
#include "End.h"
#include "PlayerDead.h"
#include "Stop.h"



int main()
{
    int gameState = GameStart();  //[한길] 3.31호랑이 처리하면 값을 반환하게 하고 gameState로 받아줌.

    if (gameState == 777)
    {
        ShowEnding();
    }

    if (gameState == 0)       //[한길] 3.31 플레이어 사망시 사망화면 출력.
    {
        ShowDeadEnding();
    }

    if (gameState == 1)
    {
        ShowStopEnding();
    }
}
