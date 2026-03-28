// Gorani.h

#pragma once
#include "Monster.h"

class Gorani:public Monster
{
public:
    Gorani(int playerLevel);
    void Draw() const override;
};

