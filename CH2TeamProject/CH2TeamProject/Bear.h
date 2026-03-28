// Bear.h

#pragma once
#include "Monster.h"

class Bear : public Monster
{
public:
    Bear(int playerLevel); // 3.27 [승민] 플레이어레벨을 매개변수로 받는 기본생성자.
    void Draw() const override;
};

