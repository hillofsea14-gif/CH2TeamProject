// Tiger.h

#include "Monster.h"
#pragma once
class Tiger : public Monster
{
public:
    Tiger(int playerLevel);
    void Draw() const override;
};


