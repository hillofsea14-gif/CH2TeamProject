//Snake.h

#pragma once
#include "Monster.h"

class Snake:public Monster
{
public:
    Snake(int playerLevel);
    void Draw() const override;
};

