// Spider.h

#pragma once
#include "Monster.h"

class Spider :public Monster
{
    public:
    Spider(int playerLevel);
    void Draw() const override;
};

