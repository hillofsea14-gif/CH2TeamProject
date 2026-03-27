// Bear.cpp

#include "Bear.h"
#include <random>
#include <iostream>
#include <ctime>

Bear::Bear(int playerLevel) : Monster("곰")
{
    // [승민] 기초 스탯 결정 (레벨에 비례)
    int baseHP = 100 + (playerLevel * 20); // [승민] 플레이어 레벨당 체력 20 증가
    int baseAtt = 20 + (playerLevel * 5);  // [승민] 플레이어 레벨당 공격력 5 증가

    int randomHP = rand() % 21;  // [승민] 랜덤 난수 최소0% ~ 최대 20%
    int randomAtt = rand() % 6;  // [승민] 랜덤 난수 최소0% ~ 최대 5%

    SetMaxHP(baseHP + randomHP); // [승민] HP 세분화
    SetCurrentHP(baseHP + randomHP); // [승민] HP 세분화
    SetAtt(baseAtt + randomAtt);
    SetDef(10 + playerLevel);    
    SetSpd(5);
}

void Bear::PrintBear() // [승민] 해당 몬스터 등장시 형태를 나타내는 함수
{
    std::string bear = R"(
         __         __
        /  \.-"""-./  \
        \    -   -    /
         |   o   o   |
         \  .-'''-.  /     (크오오오!)
       /  '-\__Y__/-' \
      /      `---`     \
     /   ______  _______\
    /  _______________   \
   /  /               \   \
  |  |      / \/ \     |  |
  |  |     |      |    |  |
   \  \     \____/    /  /
      \\__\____________/__/
    )";
    std::string effect = "   [ 거대한 곰이 바위 뒤에서 일어납니다! ]";

    std::cout << bear << std::endl;

    std::cout << effect << std::endl;
}
